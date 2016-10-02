//! [ROC Example Search Application]

/*
 * This example application takes as input two image paths. The first image (the
 * gallery) is presumed to have multiple faces, and the second image (the probe)
 * is presumed to have one face. The application outputs the top three face
 * bounding boxes in the gallery image with the greatest similarity to the
 * probe.
 *
 * To compile this example on OS X / Linux (bash):
 *
 *     $ gcc -o roc-example-search roc_example_search.c -I ./include/ -L ./lib/ -lroc
 *
 * To compile this example on Windows (Visual Studio Command Prompt):
 *
 *     $ cl roc_example_search.c /I ./include/ ./lib/roc.lib /Feroc-example-search.exe
 *
 * To run this application using two of the example images:
 *
 *     $ ./roc-example-search ../data/roc.jpg ../data/josh_2.jpg
 */

#include <stdio.h>
#include <stdlib.h>

#include <roc.h>

int main(int argc, char *argv[])
{
    const int maximum_faces = 10;
    const int maximum_candidates = 3;
    roc_image gallery_image, probe_image;
    roc_gallery gallery;
    roc_template *gallery_templates;
    roc_template probe, candidate_template;
    roc_candidate candidate;
    roc_candidate *candidates;
    int i;

    if (argc != 3)
        roc_ensure("Expected two image path arguments:\n"
                   "    $ roc-example-search path/to/gallery.jpg path/to/probe.jpg");

    // Initialize SDK
    roc_ensure(roc_initialize(NULL));

    // Open both images
    roc_ensure(roc_read_image(argv[1], ROC_GRAY8, &gallery_image));
    roc_ensure(roc_read_image(argv[2], ROC_GRAY8, &probe_image));

    // Construct gallery by finding all faces in the gallery image
    roc_ensure(roc_temporary_gallery(&gallery));
    gallery_templates = (roc_template*) malloc(maximum_faces * sizeof(roc_template));
    roc_ensure(roc_represent(gallery_image, ROC_FR, 36, maximum_faces, 0.02f, gallery_templates));

    for (i=0; i<maximum_faces; i++) {
        if (gallery_templates[i].algorithm_id & ROC_INVALID) {
            if (i == 0)
                roc_ensure("Failed to find a face in the gallery image!");
            break;
        }
        roc_ensure(roc_enroll(gallery, gallery_templates[i]));
    }

    // Find a single face in the probe image
    roc_ensure(roc_represent(probe_image, ROC_FR, 36, 1, 0.02f, &probe));
    if (probe.algorithm_id & ROC_INVALID)
        roc_ensure("Failed to find a face in the probe image!");

    // Execute search
    candidates = (roc_candidate*) malloc(maximum_candidates * sizeof(roc_candidate));
    roc_ensure(roc_search(gallery, probe, maximum_candidates, 0.0f, candidates));

    puts("Similarity\tX\tY\tWidth\tHeight");
    for (i=0; i<maximum_candidates; i++) {
        candidate = candidates[i];
        if (candidate.index == ROC_INVALID_TEMPLATE_INDEX)
            break;

        roc_ensure(roc_at(gallery, candidate.index, &candidate_template));
        printf("%g\t%d\t%d\t%d\t%d\n", candidate.similarity, candidate_template.x, candidate_template.y, candidate_template.width, candidate_template.height);
        roc_ensure(roc_free_template(&candidate_template));
    }

    // Cleanup
    roc_ensure(roc_free_image(gallery_image));
    roc_ensure(roc_free_image(probe_image));
    roc_ensure(roc_close_gallery(gallery));
    for (i=0; i<maximum_faces; i++)
        roc_ensure(roc_free_template(&gallery_templates[i]));
    roc_ensure(roc_free_template(&probe));
    free(gallery_templates);
    free(candidates);
    roc_ensure(roc_finalize());
    return EXIT_SUCCESS;
}

//! [ROC Example Search Application]
