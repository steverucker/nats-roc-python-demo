/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 3.0.8
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */


public class rocJNI {
  public final static native long new_float();
  public final static native long copy_float(float jarg1);
  public final static native void delete_float(long jarg1);
  public final static native void float_assign(long jarg1, float jarg2);
  public final static native float float_value(long jarg1);
  public final static native long new_uint8_t();
  public final static native long copy_uint8_t(short jarg1);
  public final static native void delete_uint8_t(long jarg1);
  public final static native void uint8_t_assign(long jarg1, short jarg2);
  public final static native short uint8_t_value(long jarg1);
  public final static native long new_size_t();
  public final static native long copy_size_t(long jarg1);
  public final static native void delete_size_t(long jarg1);
  public final static native void size_t_assign(long jarg1, long jarg2);
  public final static native long size_t_value(long jarg1);
  public final static native long new_roc_gallery();
  public final static native long copy_roc_gallery(long jarg1);
  public final static native void delete_roc_gallery(long jarg1);
  public final static native void roc_gallery_assign(long jarg1, long jarg2);
  public final static native long roc_gallery_value(long jarg1);
  public final static native long new_roc_host_id();
  public final static native long copy_roc_host_id(String jarg1);
  public final static native void delete_roc_host_id(long jarg1);
  public final static native void roc_host_id_assign(long jarg1, String jarg2);
  public final static native String roc_host_id_value(long jarg1);
  public final static native long new_roc_similarity();
  public final static native long copy_roc_similarity(float jarg1);
  public final static native void delete_roc_similarity(long jarg1);
  public final static native void roc_similarity_assign(long jarg1, float jarg2);
  public final static native float roc_similarity_value(long jarg1);
  public final static native String new_char_array(int jarg1);
  public final static native void delete_char_array(String jarg1);
  public final static native char char_array_getitem(String jarg1, int jarg2);
  public final static native void char_array_setitem(String jarg1, int jarg2, char jarg3);
  public final static native long new_roc_template_array(int jarg1);
  public final static native void delete_roc_template_array(long jarg1, roc_template jarg1_);
  public final static native long roc_template_array_getitem(long jarg1, roc_template jarg1_, int jarg2);
  public final static native void roc_template_array_setitem(long jarg1, roc_template jarg1_, int jarg2, long jarg3, roc_template jarg3_);
  public final static native long new_roc_similarity_array(int jarg1);
  public final static native void delete_roc_similarity_array(long jarg1);
  public final static native float roc_similarity_array_getitem(long jarg1, int jarg2);
  public final static native void roc_similarity_array_setitem(long jarg1, int jarg2, float jarg3);
  public final static native long new_roc_candidate_array(int jarg1);
  public final static native void delete_roc_candidate_array(long jarg1, roc_candidate jarg1_);
  public final static native long roc_candidate_array_getitem(long jarg1, roc_candidate jarg1_, int jarg2);
  public final static native void roc_candidate_array_setitem(long jarg1, roc_candidate jarg1_, int jarg2, long jarg3, roc_candidate jarg3_);
  public final static native long new_roc_person_id_array(int jarg1);
  public final static native void delete_roc_person_id_array(long jarg1);
  public final static native long roc_person_id_array_getitem(long jarg1, int jarg2);
  public final static native void roc_person_id_array_setitem(long jarg1, int jarg2, long jarg3);
  public final static native int ROC_VERSION_MAJOR_get();
  public final static native int ROC_VERSION_MINOR_get();
  public final static native int ROC_VERSION_PATCH_get();
  public final static native String ROC_VERSION_STRING_get();
  public final static native void roc_ensure(String jarg1);
  public final static native String roc_initialize(String jarg1);
  public final static native String roc_finalize();
  public final static native String roc_get_host_id(long jarg1);
  public final static native String roc_free_host_id(String jarg1);
  public final static native int ROC_GRAY8_get();
  public final static native int ROC_BGR24_get();
  public final static native void roc_image_data_set(long jarg1, roc_image jarg1_, long jarg2);
  public final static native long roc_image_data_get(long jarg1, roc_image jarg1_);
  public final static native void roc_image_width_set(long jarg1, roc_image jarg1_, long jarg2);
  public final static native long roc_image_width_get(long jarg1, roc_image jarg1_);
  public final static native void roc_image_height_set(long jarg1, roc_image jarg1_, long jarg2);
  public final static native long roc_image_height_get(long jarg1, roc_image jarg1_);
  public final static native void roc_image_step_set(long jarg1, roc_image jarg1_, long jarg2);
  public final static native long roc_image_step_get(long jarg1, roc_image jarg1_);
  public final static native void roc_image_color_space_set(long jarg1, roc_image jarg1_, int jarg2);
  public final static native int roc_image_color_space_get(long jarg1, roc_image jarg1_);
  public final static native long new_roc_image();
  public final static native void delete_roc_image(long jarg1);
  public final static native String roc_free_image(long jarg1, roc_image jarg1_);
  public final static native String roc_read_image(String jarg1, int jarg2, long jarg3, roc_image jarg3_);
  public final static native String roc_decode_image(long jarg1, long jarg2, int jarg3, long jarg4, roc_image jarg4_);
  public final static native String roc_set_thumbnail_parameters(int jarg1, int jarg2, float jarg3, float jarg4);
  public final static native int ROC_FRONTAL_get();
  public final static native int ROC_FULL_get();
  public final static native int ROC_PARTIAL_get();
  public final static native int ROC_MANUAL_get();
  public final static native int ROC_FR_get();
  public final static native int ROC_ID_get();
  public final static native int ROC_PITCHYAW_get();
  public final static native int ROC_GENDER_get();
  public final static native int ROC_AGE_get();
  public final static native int ROC_OCCLUSION_get();
  public final static native int ROC_LIPS_get();
  public final static native int ROC_THUMBNAIL_get();
  public final static native int ROC_INVALID_get();
  public final static native int ROC_TEMPLATE_VERSION_get();
  public final static native int ROC_TEMPLATE_VERSION_MASK_get();
  public final static native String roc_preload(long jarg1);
  public final static native String roc_landmarks_to_face(float jarg1, float jarg2, float jarg3, float jarg4, float jarg5, float jarg6, long jarg7, long jarg8, long jarg9, long jarg10);
  public final static native int ROC_NO_TIMESTAMP_get();
  public final static native int ROC_UNKNOWN_PERSON_get();
  public final static native void roc_template_algorithm_id_set(long jarg1, roc_template jarg1_, long jarg2);
  public final static native long roc_template_algorithm_id_get(long jarg1, roc_template jarg1_);
  public final static native void roc_template_timestamp_set(long jarg1, roc_template jarg1_, long jarg2);
  public final static native long roc_template_timestamp_get(long jarg1, roc_template jarg1_);
  public final static native void roc_template_x_set(long jarg1, roc_template jarg1_, int jarg2);
  public final static native int roc_template_x_get(long jarg1, roc_template jarg1_);
  public final static native void roc_template_y_set(long jarg1, roc_template jarg1_, int jarg2);
  public final static native int roc_template_y_get(long jarg1, roc_template jarg1_);
  public final static native void roc_template_width_set(long jarg1, roc_template jarg1_, long jarg2);
  public final static native long roc_template_width_get(long jarg1, roc_template jarg1_);
  public final static native void roc_template_height_set(long jarg1, roc_template jarg1_, long jarg2);
  public final static native long roc_template_height_get(long jarg1, roc_template jarg1_);
  public final static native void roc_template_confidence_set(long jarg1, roc_template jarg1_, float jarg2);
  public final static native float roc_template_confidence_get(long jarg1, roc_template jarg1_);
  public final static native void roc_template_person_id_set(long jarg1, roc_template jarg1_, long jarg2);
  public final static native long roc_template_person_id_get(long jarg1, roc_template jarg1_);
  public final static native void roc_template_md_size_set(long jarg1, roc_template jarg1_, long jarg2);
  public final static native long roc_template_md_size_get(long jarg1, roc_template jarg1_);
  public final static native void roc_template_fv_size_set(long jarg1, roc_template jarg1_, long jarg2);
  public final static native long roc_template_fv_size_get(long jarg1, roc_template jarg1_);
  public final static native void roc_template_tn_size_set(long jarg1, roc_template jarg1_, long jarg2);
  public final static native long roc_template_tn_size_get(long jarg1, roc_template jarg1_);
  public final static native void roc_template_md_set(long jarg1, roc_template jarg1_, String jarg2);
  public final static native String roc_template_md_get(long jarg1, roc_template jarg1_);
  public final static native void roc_template_fv_set(long jarg1, roc_template jarg1_, long jarg2);
  public final static native long roc_template_fv_get(long jarg1, roc_template jarg1_);
  public final static native void roc_template_tn_set(long jarg1, roc_template jarg1_, long jarg2);
  public final static native long roc_template_tn_get(long jarg1, roc_template jarg1_);
  public final static native long new_roc_template();
  public final static native void delete_roc_template(long jarg1);
  public final static native String roc_represent(long jarg1, roc_image jarg1_, long jarg2, long jarg3, long jarg4, float jarg5, long jarg6, roc_template jarg6_);
  public final static native String roc_free_template(long jarg1, roc_template jarg1_);
  public final static native String roc_flatten(long jarg1, roc_template jarg1_, long jarg2);
  public final static native String roc_unflatten(long jarg1, long jarg2, roc_template jarg2_);
  public final static native String roc_flattened_bytes(long jarg1, roc_template jarg1_, long jarg2);
  public final static native String roc_read_template(long jarg1, long jarg2, roc_template jarg2_);
  public final static native String roc_read_template_fd(int jarg1, long jarg2, roc_template jarg2_);
  public final static native String roc_write_template(long jarg1, long jarg2, roc_template jarg2_);
  public final static native String roc_write_template_fd(int jarg1, long jarg2, roc_template jarg2_);
  public final static native String roc_get_metadata(long jarg1, roc_template jarg1_, String jarg2, String jarg3, long jarg4);
  public final static native String roc_set_metadata(long jarg1, roc_template jarg1_, String jarg2, String jarg3);
  public final static native String roc_open_gallery(String jarg1, long jarg2, long jarg3);
  public final static native String roc_temporary_gallery(long jarg1);
  public final static native String roc_enroll(long jarg1, long jarg2, roc_template jarg2_);
  public final static native String roc_size(long jarg1, long jarg2);
  public final static native long ROC_INVALID_TEMPLATE_INDEX_get();
  public final static native String roc_at(long jarg1, long jarg2, long jarg3, roc_template jarg3_);
  public final static native String roc_remove(long jarg1, long jarg2);
  public final static native String roc_close_gallery(long jarg1);
  public final static native String roc_template_limit(long jarg1);
  public final static native String roc_compare_templates(long jarg1, roc_template jarg1_, long jarg2, roc_template jarg2_, long jarg3);
  public final static native String roc_compare_galleries(long jarg1, long jarg2, long jarg3);
  public final static native void roc_candidate_index_set(long jarg1, roc_candidate jarg1_, long jarg2);
  public final static native long roc_candidate_index_get(long jarg1, roc_candidate jarg1_);
  public final static native void roc_candidate_similarity_set(long jarg1, roc_candidate jarg1_, float jarg2);
  public final static native float roc_candidate_similarity_get(long jarg1, roc_candidate jarg1_);
  public final static native long new_roc_candidate();
  public final static native void delete_roc_candidate(long jarg1);
  public final static native String roc_search(long jarg1, long jarg2, roc_template jarg2_, long jarg3, float jarg4, long jarg5, roc_candidate jarg5_);
  public final static native String roc_knn(long jarg1, long jarg2, long jarg3, float jarg4, long jarg5, roc_candidate jarg5_);
  public final static native String roc_rerank(long jarg1, long jarg2, long jarg3, roc_candidate jarg3_);
  public final static native String roc_cluster(long jarg1, long jarg2, long jarg3, roc_candidate jarg3_, float jarg4);
  public final static native String roc_track(long jarg1, long jarg2, float jarg3, float jarg4);
  public final static native String roc_consolidate(long jarg1, float jarg2, long jarg3);
  public final static native String roc_person_ids(long jarg1, long jarg2);
}
