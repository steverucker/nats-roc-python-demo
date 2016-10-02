# Compare to examples/roc_example_verify.c

from roc import *
from sys import argv

if len(argv) != 3:
        roc_ensure("Expected two image path arguments:\n"
                   "    $ python roc_example_verify.py path/to/image_a.jpg path/to/image_b.jpg")

# Initialize SDK
roc_ensure(roc_initialize(None))

# Open both images
images = [roc_image(), roc_image()]
for i in range(2):
        roc_ensure(roc_read_image(argv[i+1], ROC_GRAY8, images[i]))

# Find and represent one face in each image
templates = [roc_template(), roc_template()]
for i in range(2):
    roc_ensure(roc_represent(images[i], ROC_FR, 36, 1, 0.02, templates[i]))
    if templates[i].algorithm_id & ROC_INVALID:
        roc_ensure("Failed to detect face in image: " + argv[i+1])

# Compare faces
similarity = new_roc_similarity()
roc_ensure(roc_compare_templates(templates[0], templates[1], similarity))
print("Similarity: {0}".format(roc_similarity_value(similarity)))

# Cleanup
delete_roc_similarity(similarity)
for i in range(2):
        roc_ensure(roc_free_image(images[i]))
        roc_ensure(roc_free_template(templates[i]))
roc_ensure(roc_finalize())
