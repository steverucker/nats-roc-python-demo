// Compare to examples/roc_example_verify.c

public class roc_example_verify {
    static {
        System.loadLibrary("_roc");
    }

    public static void main(String argv[]) {
        if (argv.length != 2)
            roc.roc_ensure("Expected two image path arguments:\n" +
                           "    $ java roc_example_verify path/to/image_a.jpg path/to/image_b.jpg");

        // Initialize SDK
        roc.roc_ensure(roc.roc_initialize(null));

        // Open both images
        roc_image[] images = { new roc_image(), new roc_image() };
        for (int i=0; i<2; i++)
            roc.roc_ensure(roc.roc_read_image(argv[i], roc_color_space.ROC_GRAY8, images[i]));

        // Find and represent one face in each image
        roc_template[] templates = { new roc_template(), new roc_template() };
        for (int i=0; i<2; i++) {
            roc.roc_ensure(roc.roc_represent(images[i], (long) roc_algorithm_options.ROC_FR, 36, 1, 0.02f, templates[i]));
            if ((templates[i].getAlgorithm_id() & (long) roc_algorithm_options.ROC_INVALID) != 0)
                roc.roc_ensure("Failed to detect face in image: " + argv[i]);
        }

        // Compare faces
        SWIGTYPE_p_float similarity = roc.new_roc_similarity();
        roc.roc_ensure(roc.roc_compare_templates(templates[0], templates[1], similarity));
        System.out.println("Similarity: " + Float.toString(roc.roc_similarity_value(similarity)));

        // Cleanup
        roc.delete_roc_similarity(similarity);
        for (int i=0; i<2; i++) {
            roc.roc_ensure(roc.roc_free_template(templates[i]));
            roc.roc_ensure(roc.roc_free_image(images[i]));
        }
        roc.roc_ensure(roc.roc_finalize());
    }
}
