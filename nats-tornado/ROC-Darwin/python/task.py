class Task(object):
    '''A task from the NATs server to the ROC Worker.

    Attributes:
        name: The name of the task
        info: The info needed to perform the task in json
    '''

    def __init__(self, name, info):
        self.name = name
        self.info = info