Change Log
==========

1.7.0 - 8/27/2016
-----------------
* Fixed bug where `roc_get_metadata` wasn't working for non-string values.
* Further clarifications to ROC_MANUAL documentation.
* Improved license file documentation.
* Documented how to compile roc-example.c on Windows
* Fixed `roc_compare_galleries` bug where an empty template in the target gallery wasn't returning a similarity score of 0.
* Introduced ROC_LIPS for estimating lips position (together or apart)
* Introduced lower face partial detector to ROC_PARTIAL.
* Introduced `roc_landmarks_to_face` for manual enrollment from user-specified landmarks.
* Consolidated PoseBin and Orientation metadata to a single Pose field.
* Renamed `ROC_POSE` to `ROC_PITCHYAW`.
* Introduced `ROC_TEMPLATE_VERSION`, SDK functions now check template version.
* Explore will no longer crash when presented with galleries containing old templates.
* Introduced liveness tab to Explore.
* Introduced algorithm options to Explore.
* Fixed Linux webcam support.
* Removed a layer of indirection. `roc_template` is now a struct instead of a struct pointer. See revised documentation for `roc_represent` and `roc_free_template`, and new enum field `ROC_INVALID`.
* Now including experimental Java, C# and Python wrappers.
* `ROC_ENSURE` macro now `roc_ensure` function.
* Introduced `roc-at -f` to extract feature vector.
* Re-wrote `roc-remove` for faster template removal, see documentation for new behavior.
* roc-example.c now examples/roc_example_verify.c, introduced examples/roc_example_search.c.
* Included the `data` folder with some sample images.

1.6.1 - 7/18/2016
-----------------
* Template metadata is now copied when using ROC_MANUAL.
* Face detection now outputs orientation and rotation metadata when applicable.
* Fixed template limit leak in `roc_compare_templates` and `roc_temporary_gallery`.
* Added checks to make sure `roc_initialize` and `roc_finalize` are called no more than once.
* Introduced `roc_flatten`, `roc_unflatten`, and `roc_flattened_bytes` for serializing/deserializing templates to/from memory buffers.
* Improved ROC_MANUAL documentation.

1.6.0 - 6/26/2016
-----------------
* Improved ROCFR and ROCID algorithm accuracy. Feature vectors increased by 16 dimensions for both algorithms to 144 and 208 dimensions respectively. Re-enrollment required.
* Values for roc_algorithm_id enum have changed.
* `false_accept_rate` API parameter now called `false_detection_rate`, `false-accept-rate` CLI flag now called `false-detection-rate`.
* Added `roc-example.c` to illustrate API usage.
* `roc_knn` optimized for high bandwidth (multiple probes considered at once)
* Introduced `roc_get_metadata` and `roc_set_metadata` for reading and writing JSON metadata.
* Introduced `roc_get_host_id` and `roc_free_host_id` for integrating license generation.
* `roc_initialize` will now return gracefully on a license check failure.
* Fixed `zlmhostid` file permissions.
* Added a recommendation to use `roc_template_type::confidence` when a face quality metric is needed.
* Added the ability to drag and drop preenrolled galleries to explore
* Added the ability to change the path at which galleries are stored for explore
* Can now use up and down arrow keys to scroll through galleries in explore
* Added the ability to drag and drop images from a browser into a gallery
* Added support for multiple face detections in explore watch
* Introduced `ROC_AGE` enum to `roc_algorithm_id` for age estimation.
* Added the ability to delete templates from a gallery in explore

1.5.0 - 6/01/2016
-----------------
* Improved face landmarking algorithm
* Webcam support fixed on Windows
* Added length `-l` parameter to `roc-represent-video` for representing video streams of undefined length.
* `roc_video_metadata::duration` now set to 0 for videos of undefined duration, i.e. webcams and IP cameras.
* Introduced `ROC_OCCLUSION` algorithm_id for classifying when a face is occluded (but detection succeeds)

1.4.3 - 4/20/2016
-----------------
* Removed `roc_compare_feature_vectors`, use one of the other comparison functions instead
* Noted that repeated calls to `roc_compare_templates` is much slower than a single call to `roc_compare_galleries`
* Renamed `roc_open_temporary_gallery` to `roc_temporary_gallery`
* Introduced `roc_template_limit` to query the available number of templates as dictated by the license file and the templates in use
* Introduced `ROC_PARTIAL` algorithm_id for partial face detector
* Switched pose `-p` switch to `-o` in `roc-represent` and `roc-represent-video`
* Added missing model files for ROC_GENDER
* Various improvements to explore application including new watchlist interface

1.4.2 - 3/23/2016
-----------------
* Upgraded our license manager, new license files needed
* Introduced roc_seek for seeking to a given timestamp of a video
* Added video width and height to roc_video_metadata struct
* Introduced roc_preload to pre-load model files needed by roc_represent
* roc_count renamed to roc_size
* Introduced ROC_MANUAL for manually specifying face detection boundary boxes
* Introduced roc_read_template_fd and roc_write_template_fd
* Thumbnail border mode changed from reflect to constant
* Introduced roc_set_thumbnail_parameters
* Android and Windows SDK bug fix for galleries larger than 2GB
* roc_enroll bug fix where a template was overwritten instead of appended to the end of the gallery after a call to roc_at
* roc_enroll now calls fsync, see documentation for details
* roc_enroll documents how to determine the roc_template_index of a template to be enrolled
* explore supports non-local galleries on Windows
* explore can now copy image or gallery file path to system clipboard
* explore now defaults to showing template thumbnails, if available

1.4.1 - 2/23/2016
-----------------
* Documented roc_open_video IP Camera example
* Fixed gallery incompatibility in Android SDK
* Improved face detection speed
* Introduced roc-represent/roc-represent-video -n adaptive minimum size
* Normalized detection confidences

1.4.0 - 2/12/2016
-----------------
* Replaced ROC_STILL_IMAGE with ROC_NO_TIMESTAMP
* Replaced roc_template_type::frame with roc_template_type::timestamp
* Changed roc_read_frame::timestamp and roc_read_keyframe::timestamp from double to roc_time
* Introduced roc_time typedef for representing time in milliseconds
* Dropped support for reporting video frames per second and frame number in roc_open_video, roc_read_frame and roc_read_keyframe
* Introduced ROC_GENDER for male/female estimation
* Introduced roc_compare_feature_vectors
* roc_compare renamed to roc_compare_galleries
* Substantial speed improvements to all algorithms, re-enrollment required
* Introduced face thumbnails to roc_template_type / roc_algorithm_options
* roc_template_type refactored to no longer use zero-length array idiom
* Substantial reductions in face detector memory footprint
* Introduced roc_rerank for re-ordering search results based on commonly occuring person_id
* Introduced roc-metadata -t for writing templates instead of metadata
* Introduced roc-metadata -p for assigning person_id from metadata values
* Renamed roc_template_type::mdSize to roc_template_type::md_size, and roc_template_type::fvSize to roc_template_type::fv_size
* (bug fix) oracle web server now sends properly formatted HTTP responses
* (bug fix) roc-search Similarity value no longer wrapped in quotes

1.3.0 - 12/4/2015
-----------------
* Substantial accuracy improvements to all algorithms
* Simplified detection options to just ROC_FULL
* Introduced roc-represent -l for constructing templates from a file list
* Decreased roc-represent/roc-represent-video default minimum face size from 64 to 36
* Added Makefile for reproducing ROC algorithm accuracy
* Introduced roc-compare binary similarity matrix format
* Introduced roc-represent "evaluation mode"
* roc-represent/roc-represent-video now warn when an invalid image/video file is opened instead of aborting
* roc_video_metadata struct added for holding pertinent information on opened videos

1.2.0 - 10/7/2015
-----------------
* Minor improvements to ROCFR and ROCID accuracy (re-enrollment required)
* Command line video representation moved to roc-represent-video
* roc_search and roc_knn now take a min_similarity parameter
* Improved roc_cluster algorithm, now sorting clusters by size and quality
* Introduced roc_const_gallery to improve API const correctness
* Introduced roc_compare, renamed roc_verify to roc_compare_templates, renamed roc-verify to roc-compare
* Moved video decoding from opencv to FFmpeg/LibAV, introduced roc_read_keyframe
* Introduced roc_open_temporary_gallery
* Removed roc_consolidate_templates, renamed roc_consolidate_gallery to roc_consolidate

1.1.0 - 9/21/2015
-----------------
* Added experimental GUI application called “Explore”
* Major improvements to documentation
* Major improvements to command line interface
* New face detector model for off-pose detection
* New pitch and yaw estimation
* Removed openbr interface
* Minor changes to API (functions renamed, new algorithms exposed)

1.0.0-beta - 8/28/2015
----------------------
* First release!
