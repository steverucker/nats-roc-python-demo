import tornado.ioloop
import tornado.gen
from nats.io import Client as NATS
import json

class natsClient(object):
    def __init__(self, natsRocClient):
        nc = NATS()

        @tornado.gen.coroutine
        def start():
            # establish connection to the server.
            options = { "verbose": True, "servers": ["nats://127.0.0.1:4222"] }
            yield nc.connect(**options)

            # listen for NATS messages
            def receive(msg=None):
                print("[Received]: %s" % msg.data)

                data = json.loads(msg.data)
                name = str(data["name"])
                info = data["info"]

                # send to ROC for processing
                response = getattr(natsRocClient.sdk, name)(info)

                # publish to NATS
                nc.publish("to-nats", response)

            sid = yield nc.subscribe("from-nats", "", receive)

            # keep portal open
            while True:
                yield tornado.gen.sleep(1)

        if __name__ == 'nats_client':
            tornado.ioloop.IOLoop.instance().run_sync(start)





