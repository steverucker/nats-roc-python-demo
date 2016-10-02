// Compare to examples/roc_example_search.c

using System;
using static roc;
using static roc_algorithm_options;
using static roc_color_space;

public class roc_example_search
{
    static void Main(string[] args)
    {
        if (args.Length != 2)
            roc_ensure("Expected two image path arguments:\n" +
                       "    $ mono roc_example_search.exe path/to/gallery.jpg path/to/probe.jpg");

        // Initialize SDK
        roc_ensure(roc_initialize(null));

        // Open both images
        roc_image gallery_image = new roc_image();
        roc_image probe_image = new roc_image();
        roc_ensure(roc_read_image(args[0], ROC_GRAY8, gallery_image));
        roc_ensure(roc_read_image(args[1], ROC_GRAY8, probe_image));

        // Construct gallery by finding all faces in the gallery image
        SWIGTYPE_p_p_roc_gallery_type gallery = new_roc_gallery();
        roc_ensure(roc_temporary_gallery(gallery));
        const int maximum_faces = 10;
        roc_template gallery_templates = new_roc_template_array(maximum_faces);
        roc_ensure(roc_represent(gallery_image, (uint) ROC_FR, 36, maximum_faces, 0.02f, gallery_templates));

        for (int i=0; i<maximum_faces; i++) {
            if ((roc_template_array_getitem(gallery_templates, i).algorithm_id & (uint) ROC_INVALID) != 0) {
                if (i == 0)
                    roc_ensure("Failed to find a face in the gallery image!");
                break;
            }
            roc_ensure(roc_enroll(roc_gallery_value(gallery), roc_template_array_getitem(gallery_templates, i)));
        }

        // Find a single face in the probe image
        roc_template probe = new roc_template();
        roc_ensure(roc_represent(probe_image, (uint) ROC_FR, 36, 1, 0.02f, probe));
        if ((probe.algorithm_id & (uint) ROC_INVALID) != 0)
            roc_ensure("Failed to find a face in the probe image!");

        // Execute search
        const int maximum_candidates = 3;
        roc_candidate candidates = new_roc_candidate_array(maximum_candidates);
        roc_ensure(roc_search(roc_gallery_value(gallery), probe, maximum_candidates, 0.0f, candidates));

        Console.WriteLine("Similarity\tX\tY\tWidth\tHeight");
        for (int i=0; i<maximum_candidates; i++) {
            roc_candidate candidate = roc_candidate_array_getitem(candidates, i);
            if (candidate.index == ROC_INVALID_TEMPLATE_INDEX)
                break;

            roc_template candidate_template = new roc_template();
            roc_ensure(roc_at(roc_gallery_value(gallery), candidate.index, candidate_template));
            Console.Write("{0}\t{1}\t{2}\t{3}\t{4}\n", candidate.similarity, candidate_template.x, candidate_template.y, candidate_template.width, candidate_template.height);
            roc_ensure(roc_free_template(candidate_template));
        }

        // Cleanup
        roc_ensure(roc_free_image(gallery_image));
        roc_ensure(roc_free_image(probe_image));
        roc_ensure(roc_close_gallery(roc_gallery_value(gallery)));
        for (int i=0; i<maximum_faces; i++)
            roc_ensure(roc_free_template(roc_template_array_getitem(gallery_templates, i)));
        roc_ensure(roc_free_template(probe));
        delete_roc_gallery(gallery);
        delete_roc_template_array(gallery_templates);
        delete_roc_candidate_array(candidates);
        roc_ensure(roc_finalize());
    }
}
