//! [ROC Example Verify Application]

/*
 * This example application takes as input two image paths (presumed to have one
 * face in each image) and outputs the similarity between the face in each
 * image. Similarity values toward one indicate the two faces appear to be the
 * same person. Similarity values toward zero indicate the two faces appear to
 * be different people. See the API documentation for details regarding how
 * similarity scores are normalized.
 *
 * To compile this example on OS X / Linux (bash):
 *
 *     $ gcc -o roc-example-verify roc_example_verify.c -I ./include/ -L ./lib/ -lroc
 *
 * To compile this example on Windows (Visual Studio Command Prompt):
 *
 *     $ cl roc_example_verify.c /I ./include/ ./lib/roc.lib /Feroc-example-verify.exe
 *
 * To run this application using two of the example images:
 *
 *     $ ./roc-example-verify ../data/josh_1.jpg ../data/josh_2.jpg
 */

#include <stdio.h>
#include <stdlib.h>

#include <roc.h>

int main(int argc, char *argv[])
{
    roc_image images[2];
    roc_template templates[2];
    roc_similarity similarity;
    int i;

    if (argc != 3)
        roc_ensure("Expected two image path arguments:\n"
                   "    $ roc-example-verify path/to/image_a.jpg path/to/image_b.jpg");

    // Initialize SDK
    roc_ensure(roc_initialize(NULL));

    // Open both images
    for (i=0; i<2; i++)
        roc_ensure(roc_read_image(argv[i+1], ROC_GRAY8, &images[i]));

    // Find and represent one face in each image
    for (i=0; i<2; i++) {
        roc_ensure(roc_represent(images[i], ROC_FR, 36, 1, 0.02f, &templates[i]));
        if (templates[i].algorithm_id & ROC_INVALID) {
            printf("Failed to detect face in image: %s\n", argv[i+1]);
            return EXIT_FAILURE;
        }
    }

    // Compare faces
    roc_ensure(roc_compare_templates(templates[0], templates[1], &similarity));
    printf("Similarity: %g\n", similarity);

    // Cleanup
    for (i=0; i<2; i++) {
        roc_ensure(roc_free_template(&templates[i]));
        roc_ensure(roc_free_image(images[i]));
    }
    roc_ensure(roc_finalize());
    return EXIT_SUCCESS;
}

//! [ROC Example Verify Application]
