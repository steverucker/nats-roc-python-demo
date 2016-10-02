import unittest
import sys
import json

sys.path.append('../python')
from rocsdk import RocSdk

class RocSdkTest(unittest.TestCase):

    unittest.TestCase.sdkTest = RocSdk()

    # preparing to test
    def setUp(self):
        """ Setting up for the test """
        print "setup test"

    # ending the test
    def tearDown(self):
        """Cleaning up after the test"""
        print "teardown test"

    def test_getjson(self):
        testJson = {"foo":"bar"}
        getjsonTest = self.sdkTest.getjson(testJson)
        self.assertEqual(getjsonTest, json.dumps(testJson, sort_keys=True, indent=4, separators=(',', ': ')))

    def test_detect(self):
        testInfo = {"image":"../data/josh_1.jpg"}
        testResponse = {'status': 'Complete', 'Width': 170, 'Confidence': 0.9997252821922302, 'file': '../data/josh_1.jpg', 'Y': 189, 'X': 455, 'Metadata': {u'RightEyeX': 505, u'RightEyeY': 227, u'Gender': u'Male', u'Age': 24.547245025634766, u'Pose': u'Frontal', u'ChinY': 373, u'ChinX': 535, u'LeftEyeX': 580, u'LeftEyeY': 236, u'Path': u'', u'Rotation': 0}, 'Height': 170}
        detectTest = self.sdkTest.detect(testInfo)
        self.assertEqual(json.dumps(testResponse, sort_keys=True, indent=4, separators=(',', ': ')), detectTest )

    def test_verify(self):
        testInfo = {"first_image":"../data/josh_1.jpg", "second_image":"../data/josh_2.jpg"}
        testResponse = "Similarity: 0.879709482193"
        verifyTest = self.sdkTest.verify(testInfo)
        self.assertEqual(testResponse, verifyTest )

if __name__ == '__main__':
    unittest.main()