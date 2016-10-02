# coding: utf-8
import tornado.ioloop
import tornado.gen
from nats.io import Client as NATS

@tornado.gen.coroutine
def main():
    nc = NATS()

    # Establish connection to the server.
    options = { "verbose": True, "servers": ["nats://127.0.0.1:4222"] }
    yield nc.connect(**options)

    def discover(msg=None):
        print("[Received]: %s" % msg.data)

    sid = yield nc.subscribe("tornado.test", "", discover)

    yield nc.publish("msg.test", "From tornado")

    try:
        # Expect a single request and timeout after 60sec
        response = yield nc.timed_request("listening", "Hi, need help!", timeout=60.0)
        print("[Response]: %s" % response.data)
    except tornado.gen.TimeoutError, e:
        print("Request timed out.")

if __name__ == '__main__':
    tornado.ioloop.IOLoop.instance().run_sync(main)