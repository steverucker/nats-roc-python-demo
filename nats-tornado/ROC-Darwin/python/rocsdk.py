

from roc import *
import json
from StringIO import StringIO

class RocSdk(object):
    def __init__(self):
        """Initialize the ROC SDK"""
        roc_ensure(roc_initialize(None))

    def ensure(self, message):
        roc_ensure(message)

    def getjson(self, json_data):
        return json.dumps(json_data, sort_keys=True, indent=4, separators=(',', ': '))

    def detect(self, info):
        image = info['image']
        max_faces = info['max_faces'] if 'max_faces' in info else 1

        # Open probe image
        probe_image = roc_image()
        roc_ensure(roc_read_image(str(image), ROC_GRAY8, probe_image))

        # Find a single face in the probe image
        probe = roc_template()
        roc_ensure(roc_represent(probe_image, ROC_FR | ROC_GENDER | ROC_AGE, 36, max_faces, 0.02, probe))

        if probe.algorithm_id & ROC_INVALID:
            result = {'error':'Failed to find a face in the probe image'}
        else:
            result = {
                'status':'Complete',
                'file': image,
                'X': probe.x,
                'Y': probe.y,
                'Width': probe.width,
                'Height': probe.height,
                'Confidence': probe.confidence,
                'Metadata': json.loads(probe.md)
            }

        return self.getjson(result)

    def verify(self, info):
        first_image = info['first_image']
        second_image = info['second_image']
        images = [roc_image(), roc_image()]

        roc_ensure(roc_read_image(str(first_image), ROC_GRAY8, images[0]))
        roc_ensure(roc_read_image(str(second_image), ROC_GRAY8, images[1]))

        # Find and represent one face in each image
        templates = [roc_template(), roc_template()]

        for i in range(2):
            roc_ensure(roc_represent(images[i], ROC_FR, 36, 1, 0.02, templates[i]))
            if templates[i].algorithm_id & ROC_INVALID:
                roc_ensure("Failed to detect face in image: " + i+1 )

        # Compare faces
        similarity = new_roc_similarity()

        roc_ensure(roc_compare_templates(templates[0], templates[1], similarity))

        result = "Similarity: {0}".format(roc_similarity_value(similarity))

        return result

