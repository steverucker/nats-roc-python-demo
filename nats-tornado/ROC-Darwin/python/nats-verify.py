from roc import *
import tornado.ioloop
import tornado.gen
from nats.io import Client as NATS
import json

@tornado.gen.coroutine
def main():
    nc = NATS()

    # Establish connection to the server.
    options = { "verbose": True, "servers": ["nats://127.0.0.1:4222"] }
    yield nc.connect(**options)

     # Initialize SDK
    roc_ensure(roc_initialize(None))

    def discover(msg=None):
        print("[Received]: %s" % msg.data)
        images = []
        templates = []
        images = [roc_image(), roc_image()]
        parsed_json = json.loads(msg.data)

        roc_ensure(roc_read_image(str(parsed_json['first_image']), ROC_GRAY8, images[0]))
        roc_ensure(roc_read_image(str(parsed_json['second_image']), ROC_GRAY8, images[1]))
        # Find and represent one face in each image
        templates = [roc_template(), roc_template()]

        for i in range(2):
            roc_ensure(roc_represent(images[i], ROC_FR, 36, 1, 0.02, templates[i]))
            if templates[i].algorithm_id & ROC_INVALID:
                roc_ensure("Failed to detect face in image: " + i+1 )

        # Compare faces
        similarity = new_roc_similarity()
        print "similarity"
        roc_ensure(roc_compare_templates(templates[0], templates[1], similarity))

        analysis = "Similarity: {0}".format(roc_similarity_value(similarity))
        print(analysis)

        # # Cleanup
        delete_roc_similarity(similarity)
        for i in range(2):
                roc_ensure(roc_free_image(images[i]))
                roc_ensure(roc_free_template(templates[i]))
        # roc_ensure(roc_finalize())

        nc.publish("to-nats", analysis)

    sid = yield nc.subscribe("from-nats", "", discover)

    try:
        # Expect a single request and timeout after 120sec
        response = yield nc.timed_request("listening", "Message", timeout=120.0)
        print("[Response]: %s" % response.data)
    except tornado.gen.TimeoutError, e:
        print("Request timed out.")

if __name__ == '__main__':
    tornado.ioloop.IOLoop.instance().run_sync(main)
