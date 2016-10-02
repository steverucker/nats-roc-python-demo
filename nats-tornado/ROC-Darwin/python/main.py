from rocsdk import RocSdk
from task import Task
from nats_client import natsClient

class natsRocClient(object):
    def __init__(self):

        #Initialize ROC SDK
        self.sdk = RocSdk()

        #Listen/Subscribe to Queue
        natsClient(self)

nrc = natsRocClient()

