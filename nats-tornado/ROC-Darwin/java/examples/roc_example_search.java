// Compare to examples/roc_example_search.c

public class roc_example_search {
    static {
        System.loadLibrary("_roc");
    }

    public static void main(String argv[]) {
        if (argv.length != 2)
            roc.roc_ensure("Expected two image path arguments:\n" +
                           "    $ java roc_example_verify path/to/gallery.jpg path/to/probe.jpg");

        // Initialize SDK
        roc.roc_ensure(roc.roc_initialize(null));

        // Open both images
        roc_image gallery_image = new roc_image();
        roc_image probe_image = new roc_image();
        roc.roc_ensure(roc.roc_read_image(argv[0], roc_color_space.ROC_GRAY8, gallery_image));
        roc.roc_ensure(roc.roc_read_image(argv[1], roc_color_space.ROC_GRAY8, probe_image));

        // Construct gallery by finding all faces in the gallery image
        SWIGTYPE_p_p_roc_gallery_type gallery = roc.new_roc_gallery();
        roc.roc_ensure(roc.roc_temporary_gallery(gallery));
        final int maximum_faces = 10;
        roc_template gallery_templates = roc.new_roc_template_array(maximum_faces);
        roc.roc_ensure(roc.roc_represent(gallery_image, (long) roc_algorithm_options.ROC_FR, 36, maximum_faces, 0.02f, gallery_templates));

        for (int i=0; i<maximum_faces; i++) {
            if ((roc.roc_template_array_getitem(gallery_templates, i).getAlgorithm_id() & (long) roc_algorithm_options.ROC_INVALID) != 0) {
                if (i == 0)
                    roc.roc_ensure("Failed to find a face in the gallery image!");
                break;
            }
            roc.roc_ensure(roc.roc_enroll(roc.roc_gallery_value(gallery), roc.roc_template_array_getitem(gallery_templates, i)));
        }

        // Find a single face in the probe image
        roc_template probe = new roc_template();
        roc.roc_ensure(roc.roc_represent(probe_image, (long) roc_algorithm_options.ROC_FR, 36, 1, 0.02f, probe));
        if ((probe.getAlgorithm_id() & (long) roc_algorithm_options.ROC_INVALID) != 0)
            roc.roc_ensure("Failed to find a face in the probe image!");

        // Execute search
        final int maximum_candidates = 3;
        roc_candidate candidates = roc.new_roc_candidate_array(maximum_candidates);
        roc.roc_ensure(roc.roc_search(roc.roc_gallery_value(gallery), probe, maximum_candidates, 0.0f, candidates));

        System.out.println("Similarity\tX\tY\tWidth\tHeight");
        for (int i=0; i<maximum_candidates; i++) {
            roc_candidate candidate = roc.roc_candidate_array_getitem(candidates, i);
            if (candidate.getIndex() == roc.getROC_INVALID_TEMPLATE_INDEX())
                break;

            roc_template candidate_template = new roc_template();
            roc.roc_ensure(roc.roc_at(roc.roc_gallery_value(gallery), candidate.getIndex(), candidate_template));
            System.out.printf("%g\t%d\t%d\t%d\t%d\n", candidate.getSimilarity(), candidate_template.getX(), candidate_template.getY(), candidate_template.getWidth(), candidate_template.getHeight());
            roc.roc_ensure(roc.roc_free_template(candidate_template));
        }

        // Cleanup
        roc.roc_ensure(roc.roc_free_image(gallery_image));
        roc.roc_ensure(roc.roc_free_image(probe_image));
        roc.roc_ensure(roc.roc_close_gallery(roc.roc_gallery_value(gallery)));
        for (int i=0; i<maximum_faces; i++)
            roc.roc_ensure(roc.roc_free_template(roc.roc_template_array_getitem(gallery_templates, i)));
        roc.roc_ensure(roc.roc_free_template(probe));
        roc.delete_roc_gallery(gallery);
        roc.delete_roc_template_array(gallery_templates);
        roc.delete_roc_candidate_array(candidates);
        roc.roc_ensure(roc.roc_finalize());
    }
}
