// Compare to examples/roc_example_verify.c

using System;
using static roc;
using static roc_algorithm_options;
using static roc_color_space;

public class roc_example_verify
{
    static void Main(string[] args)
    {
        if (args.Length != 2)
            roc_ensure("Expected two image path arguments:\n" +
                       "    $ mono roc_example_verify.exe path/to/image_a.jpg path/to/image_b.jpg");

        // Initialize SDK
        roc_ensure(roc_initialize(null));

        // Open both images
        roc_image[] images = { new roc_image(), new roc_image() };
        for (int i=0; i<2; i++)
            roc_ensure(roc_read_image(args[i], ROC_GRAY8, images[i]));

        // Find and represent one face in each image
        roc_template[] templates = { new roc_template(), new roc_template() };
        for (int i=0; i<2; i++) {
            roc_ensure(roc_represent(images[i], (uint) ROC_FR, 36, 1, 0.02f, templates[i]));
            if ((templates[i].algorithm_id & (uint) ROC_INVALID) != 0)
                roc_ensure("Failed to detect face in image: " + args[i]);
        }

        // Compare faces
        SWIGTYPE_p_float similarity = new_roc_similarity();
        roc_ensure(roc_compare_templates(templates[0], templates[1], similarity));
        System.Console.WriteLine("Similarity: " + roc_similarity_value(similarity));

        // Cleanup
        delete_roc_similarity(similarity);
        for (int i=0; i<2; i++) {
            roc_ensure(roc_free_template(templates[i]));
            roc_ensure(roc_free_image(images[i]));
        }
        roc_ensure(roc_finalize());
    }
}
