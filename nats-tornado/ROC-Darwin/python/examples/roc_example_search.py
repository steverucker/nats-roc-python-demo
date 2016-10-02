# Compare to examples/roc_example_search.c

from roc import *
from sys import argv

if len(argv) != 3:
        roc_ensure("Expected two image path arguments:\n"
                   "    $ python roc_example_search.py path/to/gallery.jpg path/to/probe.jpg")

# Initialize SDK
roc_ensure(roc_initialize(None))

# Open both images
gallery_image = roc_image()
probe_image = roc_image()
roc_ensure(roc_read_image(argv[1], ROC_GRAY8, gallery_image))
roc_ensure(roc_read_image(argv[2], ROC_GRAY8, probe_image))

# Construct gallery by finding all faces in the gallery image
gallery = new_roc_gallery()
roc_ensure(roc_temporary_gallery(gallery))
maximum_faces = 10
gallery_templates = new_roc_template_array(maximum_faces)
roc_ensure(roc_represent(gallery_image, ROC_FR, 36, maximum_faces, 0.02, gallery_templates))

for i in range(maximum_faces):
    if roc_template_array_getitem(gallery_templates, i).algorithm_id & ROC_INVALID:
        if i == 0:
            roc_ensure("Failed to find a face in the gallery image!")
        break
    roc_ensure(roc_enroll(roc_gallery_value(gallery), roc_template_array_getitem(gallery_templates, i)))

# Find a single face in the probe image
probe = roc_template()
roc_ensure(roc_represent(probe_image, ROC_FR, 36, 1, 0.02, probe))
if probe.algorithm_id & ROC_INVALID:
    roc_ensure("Failed to find a face in the probe image!")

# Execute search
maximum_candidates = 3
candidates = new_roc_candidate_array(maximum_candidates)
roc_ensure(roc_search(roc_gallery_value(gallery), probe, maximum_candidates, 0.0, candidates))

print("Similarity\tX\tY\tWidth\tHeight")
for i in range(maximum_candidates):
    candidate = roc_candidate_array_getitem(candidates, i)
    if candidate.index == ROC_INVALID_TEMPLATE_INDEX:
        break

    candidate_template = roc_template();
    roc_ensure(roc_at(roc_gallery_value(gallery), candidate.index, candidate_template))
    print("{0}\t{1}\t{2}\t{3}\t{4}".format(candidate.similarity, candidate_template.x, candidate_template.y, candidate_template.width, candidate_template.height))
    roc_ensure(roc_free_template(candidate_template))

# Cleanup
roc_ensure(roc_free_image(gallery_image))
roc_ensure(roc_free_image(probe_image))
roc_ensure(roc_close_gallery(roc_gallery_value(gallery)))
for i in range(maximum_faces):
    roc_ensure(roc_free_template(roc_template_array_getitem(gallery_templates, i)));
roc_ensure(roc_free_template(probe));
delete_roc_gallery(gallery);
delete_roc_template_array(gallery_templates);
delete_roc_candidate_array(candidates);
roc_ensure(roc_finalize());
