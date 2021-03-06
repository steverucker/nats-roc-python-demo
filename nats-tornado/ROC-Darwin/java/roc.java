/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 3.0.8
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */


public class roc implements rocConstants {
  public static SWIGTYPE_p_float new_float() {
    long cPtr = rocJNI.new_float();
    return (cPtr == 0) ? null : new SWIGTYPE_p_float(cPtr, false);
  }

  public static SWIGTYPE_p_float copy_float(float value) {
    long cPtr = rocJNI.copy_float(value);
    return (cPtr == 0) ? null : new SWIGTYPE_p_float(cPtr, false);
  }

  public static void delete_float(SWIGTYPE_p_float obj) {
    rocJNI.delete_float(SWIGTYPE_p_float.getCPtr(obj));
  }

  public static void float_assign(SWIGTYPE_p_float obj, float value) {
    rocJNI.float_assign(SWIGTYPE_p_float.getCPtr(obj), value);
  }

  public static float float_value(SWIGTYPE_p_float obj) {
    return rocJNI.float_value(SWIGTYPE_p_float.getCPtr(obj));
  }

  public static SWIGTYPE_p_unsigned_char new_uint8_t() {
    long cPtr = rocJNI.new_uint8_t();
    return (cPtr == 0) ? null : new SWIGTYPE_p_unsigned_char(cPtr, false);
  }

  public static SWIGTYPE_p_unsigned_char copy_uint8_t(short value) {
    long cPtr = rocJNI.copy_uint8_t(value);
    return (cPtr == 0) ? null : new SWIGTYPE_p_unsigned_char(cPtr, false);
  }

  public static void delete_uint8_t(SWIGTYPE_p_unsigned_char obj) {
    rocJNI.delete_uint8_t(SWIGTYPE_p_unsigned_char.getCPtr(obj));
  }

  public static void uint8_t_assign(SWIGTYPE_p_unsigned_char obj, short value) {
    rocJNI.uint8_t_assign(SWIGTYPE_p_unsigned_char.getCPtr(obj), value);
  }

  public static short uint8_t_value(SWIGTYPE_p_unsigned_char obj) {
    return rocJNI.uint8_t_value(SWIGTYPE_p_unsigned_char.getCPtr(obj));
  }

  public static SWIGTYPE_p_size_t new_size_t() {
    long cPtr = rocJNI.new_size_t();
    return (cPtr == 0) ? null : new SWIGTYPE_p_size_t(cPtr, false);
  }

  public static SWIGTYPE_p_size_t copy_size_t(long value) {
    long cPtr = rocJNI.copy_size_t(value);
    return (cPtr == 0) ? null : new SWIGTYPE_p_size_t(cPtr, false);
  }

  public static void delete_size_t(SWIGTYPE_p_size_t obj) {
    rocJNI.delete_size_t(SWIGTYPE_p_size_t.getCPtr(obj));
  }

  public static void size_t_assign(SWIGTYPE_p_size_t obj, long value) {
    rocJNI.size_t_assign(SWIGTYPE_p_size_t.getCPtr(obj), value);
  }

  public static long size_t_value(SWIGTYPE_p_size_t obj) {
    return rocJNI.size_t_value(SWIGTYPE_p_size_t.getCPtr(obj));
  }

  public static SWIGTYPE_p_p_roc_gallery_type new_roc_gallery() {
    long cPtr = rocJNI.new_roc_gallery();
    return (cPtr == 0) ? null : new SWIGTYPE_p_p_roc_gallery_type(cPtr, false);
  }

  public static SWIGTYPE_p_p_roc_gallery_type copy_roc_gallery(SWIGTYPE_p_roc_gallery_type value) {
    long cPtr = rocJNI.copy_roc_gallery(SWIGTYPE_p_roc_gallery_type.getCPtr(value));
    return (cPtr == 0) ? null : new SWIGTYPE_p_p_roc_gallery_type(cPtr, false);
  }

  public static void delete_roc_gallery(SWIGTYPE_p_p_roc_gallery_type obj) {
    rocJNI.delete_roc_gallery(SWIGTYPE_p_p_roc_gallery_type.getCPtr(obj));
  }

  public static void roc_gallery_assign(SWIGTYPE_p_p_roc_gallery_type obj, SWIGTYPE_p_roc_gallery_type value) {
    rocJNI.roc_gallery_assign(SWIGTYPE_p_p_roc_gallery_type.getCPtr(obj), SWIGTYPE_p_roc_gallery_type.getCPtr(value));
  }

  public static SWIGTYPE_p_roc_gallery_type roc_gallery_value(SWIGTYPE_p_p_roc_gallery_type obj) {
    long cPtr = rocJNI.roc_gallery_value(SWIGTYPE_p_p_roc_gallery_type.getCPtr(obj));
    return (cPtr == 0) ? null : new SWIGTYPE_p_roc_gallery_type(cPtr, false);
  }

  public static SWIGTYPE_p_p_char new_roc_host_id() {
    long cPtr = rocJNI.new_roc_host_id();
    return (cPtr == 0) ? null : new SWIGTYPE_p_p_char(cPtr, false);
  }

  public static SWIGTYPE_p_p_char copy_roc_host_id(String value) {
    long cPtr = rocJNI.copy_roc_host_id(value);
    return (cPtr == 0) ? null : new SWIGTYPE_p_p_char(cPtr, false);
  }

  public static void delete_roc_host_id(SWIGTYPE_p_p_char obj) {
    rocJNI.delete_roc_host_id(SWIGTYPE_p_p_char.getCPtr(obj));
  }

  public static void roc_host_id_assign(SWIGTYPE_p_p_char obj, String value) {
    rocJNI.roc_host_id_assign(SWIGTYPE_p_p_char.getCPtr(obj), value);
  }

  public static String roc_host_id_value(SWIGTYPE_p_p_char obj) {
    return rocJNI.roc_host_id_value(SWIGTYPE_p_p_char.getCPtr(obj));
  }

  public static SWIGTYPE_p_float new_roc_similarity() {
    long cPtr = rocJNI.new_roc_similarity();
    return (cPtr == 0) ? null : new SWIGTYPE_p_float(cPtr, false);
  }

  public static SWIGTYPE_p_float copy_roc_similarity(float value) {
    long cPtr = rocJNI.copy_roc_similarity(value);
    return (cPtr == 0) ? null : new SWIGTYPE_p_float(cPtr, false);
  }

  public static void delete_roc_similarity(SWIGTYPE_p_float obj) {
    rocJNI.delete_roc_similarity(SWIGTYPE_p_float.getCPtr(obj));
  }

  public static void roc_similarity_assign(SWIGTYPE_p_float obj, float value) {
    rocJNI.roc_similarity_assign(SWIGTYPE_p_float.getCPtr(obj), value);
  }

  public static float roc_similarity_value(SWIGTYPE_p_float obj) {
    return rocJNI.roc_similarity_value(SWIGTYPE_p_float.getCPtr(obj));
  }

  public static String new_char_array(int nelements) {
    return rocJNI.new_char_array(nelements);
  }

  public static void delete_char_array(String ary) {
    rocJNI.delete_char_array(ary);
  }

  public static char char_array_getitem(String ary, int index) {
    return rocJNI.char_array_getitem(ary, index);
  }

  public static void char_array_setitem(String ary, int index, char value) {
    rocJNI.char_array_setitem(ary, index, value);
  }

  public static roc_template new_roc_template_array(int nelements) {
    long cPtr = rocJNI.new_roc_template_array(nelements);
    return (cPtr == 0) ? null : new roc_template(cPtr, false);
  }

  public static void delete_roc_template_array(roc_template ary) {
    rocJNI.delete_roc_template_array(roc_template.getCPtr(ary), ary);
  }

  public static roc_template roc_template_array_getitem(roc_template ary, int index) {
    return new roc_template(rocJNI.roc_template_array_getitem(roc_template.getCPtr(ary), ary, index), true);
  }

  public static void roc_template_array_setitem(roc_template ary, int index, roc_template value) {
    rocJNI.roc_template_array_setitem(roc_template.getCPtr(ary), ary, index, roc_template.getCPtr(value), value);
  }

  public static SWIGTYPE_p_float new_roc_similarity_array(int nelements) {
    long cPtr = rocJNI.new_roc_similarity_array(nelements);
    return (cPtr == 0) ? null : new SWIGTYPE_p_float(cPtr, false);
  }

  public static void delete_roc_similarity_array(SWIGTYPE_p_float ary) {
    rocJNI.delete_roc_similarity_array(SWIGTYPE_p_float.getCPtr(ary));
  }

  public static float roc_similarity_array_getitem(SWIGTYPE_p_float ary, int index) {
    return rocJNI.roc_similarity_array_getitem(SWIGTYPE_p_float.getCPtr(ary), index);
  }

  public static void roc_similarity_array_setitem(SWIGTYPE_p_float ary, int index, float value) {
    rocJNI.roc_similarity_array_setitem(SWIGTYPE_p_float.getCPtr(ary), index, value);
  }

  public static roc_candidate new_roc_candidate_array(int nelements) {
    long cPtr = rocJNI.new_roc_candidate_array(nelements);
    return (cPtr == 0) ? null : new roc_candidate(cPtr, false);
  }

  public static void delete_roc_candidate_array(roc_candidate ary) {
    rocJNI.delete_roc_candidate_array(roc_candidate.getCPtr(ary), ary);
  }

  public static roc_candidate roc_candidate_array_getitem(roc_candidate ary, int index) {
    return new roc_candidate(rocJNI.roc_candidate_array_getitem(roc_candidate.getCPtr(ary), ary, index), true);
  }

  public static void roc_candidate_array_setitem(roc_candidate ary, int index, roc_candidate value) {
    rocJNI.roc_candidate_array_setitem(roc_candidate.getCPtr(ary), ary, index, roc_candidate.getCPtr(value), value);
  }

  public static SWIGTYPE_p_unsigned_int new_roc_person_id_array(int nelements) {
    long cPtr = rocJNI.new_roc_person_id_array(nelements);
    return (cPtr == 0) ? null : new SWIGTYPE_p_unsigned_int(cPtr, false);
  }

  public static void delete_roc_person_id_array(SWIGTYPE_p_unsigned_int ary) {
    rocJNI.delete_roc_person_id_array(SWIGTYPE_p_unsigned_int.getCPtr(ary));
  }

  public static long roc_person_id_array_getitem(SWIGTYPE_p_unsigned_int ary, int index) {
    return rocJNI.roc_person_id_array_getitem(SWIGTYPE_p_unsigned_int.getCPtr(ary), index);
  }

  public static void roc_person_id_array_setitem(SWIGTYPE_p_unsigned_int ary, int index, long value) {
    rocJNI.roc_person_id_array_setitem(SWIGTYPE_p_unsigned_int.getCPtr(ary), index, value);
  }

  public static void roc_ensure(String error) {
    rocJNI.roc_ensure(error);
  }

  public static String roc_initialize(String sdk_path) {
    return rocJNI.roc_initialize(sdk_path);
  }

  public static String roc_finalize() {
    return rocJNI.roc_finalize();
  }

  public static String roc_get_host_id(SWIGTYPE_p_p_char host_id) {
    return rocJNI.roc_get_host_id(SWIGTYPE_p_p_char.getCPtr(host_id));
  }

  public static String roc_free_host_id(String host_id) {
    return rocJNI.roc_free_host_id(host_id);
  }

  public static String roc_free_image(roc_image image) {
    return rocJNI.roc_free_image(roc_image.getCPtr(image), image);
  }

  public static String roc_read_image(String file_name, int color_space, roc_image image) {
    return rocJNI.roc_read_image(file_name, color_space, roc_image.getCPtr(image), image);
  }

  public static String roc_decode_image(long len, SWIGTYPE_p_unsigned_char data, int color_space, roc_image image) {
    return rocJNI.roc_decode_image(len, SWIGTYPE_p_unsigned_char.getCPtr(data), color_space, roc_image.getCPtr(image), image);
  }

  public static String roc_set_thumbnail_parameters(int width, int height, float scale, float quality) {
    return rocJNI.roc_set_thumbnail_parameters(width, height, scale, quality);
  }

  public static String roc_preload(long algorithm_id) {
    return rocJNI.roc_preload(algorithm_id);
  }

  public static String roc_landmarks_to_face(float left_eye_x, float left_eye_y, float right_eye_x, float right_eye_y, float chin_x, float chin_y, SWIGTYPE_p_float face_x, SWIGTYPE_p_float face_y, SWIGTYPE_p_float face_width, SWIGTYPE_p_float face_height) {
    return rocJNI.roc_landmarks_to_face(left_eye_x, left_eye_y, right_eye_x, right_eye_y, chin_x, chin_y, SWIGTYPE_p_float.getCPtr(face_x), SWIGTYPE_p_float.getCPtr(face_y), SWIGTYPE_p_float.getCPtr(face_width), SWIGTYPE_p_float.getCPtr(face_height));
  }

  public static String roc_represent(roc_image image, long algorithm_id, long min_size, long k, float false_detection_rate, roc_template templates) {
    return rocJNI.roc_represent(roc_image.getCPtr(image), image, algorithm_id, min_size, k, false_detection_rate, roc_template.getCPtr(templates), templates);
  }

  public static String roc_free_template(roc_template template_) {
    return rocJNI.roc_free_template(roc_template.getCPtr(template_), template_);
  }

  public static String roc_flatten(roc_template template_, SWIGTYPE_p_unsigned_char buffer) {
    return rocJNI.roc_flatten(roc_template.getCPtr(template_), template_, SWIGTYPE_p_unsigned_char.getCPtr(buffer));
  }

  public static String roc_unflatten(SWIGTYPE_p_unsigned_char buffer, roc_template template_) {
    return rocJNI.roc_unflatten(SWIGTYPE_p_unsigned_char.getCPtr(buffer), roc_template.getCPtr(template_), template_);
  }

  public static String roc_flattened_bytes(roc_template template_, SWIGTYPE_p_size_t bytes) {
    return rocJNI.roc_flattened_bytes(roc_template.getCPtr(template_), template_, SWIGTYPE_p_size_t.getCPtr(bytes));
  }

  public static String roc_read_template(SWIGTYPE_p_FILE file, roc_template template_) {
    return rocJNI.roc_read_template(SWIGTYPE_p_FILE.getCPtr(file), roc_template.getCPtr(template_), template_);
  }

  public static String roc_read_template_fd(int fd, roc_template template_) {
    return rocJNI.roc_read_template_fd(fd, roc_template.getCPtr(template_), template_);
  }

  public static String roc_write_template(SWIGTYPE_p_FILE file, roc_template template_) {
    return rocJNI.roc_write_template(SWIGTYPE_p_FILE.getCPtr(file), roc_template.getCPtr(template_), template_);
  }

  public static String roc_write_template_fd(int fd, roc_template template_) {
    return rocJNI.roc_write_template_fd(fd, roc_template.getCPtr(template_), template_);
  }

  public static String roc_get_metadata(roc_template template_, String key, String value, long value_length) {
    return rocJNI.roc_get_metadata(roc_template.getCPtr(template_), template_, key, value, value_length);
  }

  public static String roc_set_metadata(roc_template template_, String key, String value) {
    return rocJNI.roc_set_metadata(roc_template.getCPtr(template_), template_, key, value);
  }

  public static String roc_open_gallery(String gallery_file, SWIGTYPE_p_p_roc_gallery_type gallery, SWIGTYPE_p_f_float__void progress) {
    return rocJNI.roc_open_gallery(gallery_file, SWIGTYPE_p_p_roc_gallery_type.getCPtr(gallery), SWIGTYPE_p_f_float__void.getCPtr(progress));
  }

  public static String roc_temporary_gallery(SWIGTYPE_p_p_roc_gallery_type gallery) {
    return rocJNI.roc_temporary_gallery(SWIGTYPE_p_p_roc_gallery_type.getCPtr(gallery));
  }

  public static String roc_enroll(SWIGTYPE_p_roc_gallery_type gallery, roc_template template_) {
    return rocJNI.roc_enroll(SWIGTYPE_p_roc_gallery_type.getCPtr(gallery), roc_template.getCPtr(template_), template_);
  }

  public static String roc_size(SWIGTYPE_p_roc_gallery_type gallery, SWIGTYPE_p_size_t size) {
    return rocJNI.roc_size(SWIGTYPE_p_roc_gallery_type.getCPtr(gallery), SWIGTYPE_p_size_t.getCPtr(size));
  }

  public static long getROC_INVALID_TEMPLATE_INDEX() {
    return rocJNI.ROC_INVALID_TEMPLATE_INDEX_get();
  }

  public static String roc_at(SWIGTYPE_p_roc_gallery_type gallery, long index, roc_template template_) {
    return rocJNI.roc_at(SWIGTYPE_p_roc_gallery_type.getCPtr(gallery), index, roc_template.getCPtr(template_), template_);
  }

  public static String roc_remove(SWIGTYPE_p_roc_gallery_type gallery, long index) {
    return rocJNI.roc_remove(SWIGTYPE_p_roc_gallery_type.getCPtr(gallery), index);
  }

  public static String roc_close_gallery(SWIGTYPE_p_roc_gallery_type gallery) {
    return rocJNI.roc_close_gallery(SWIGTYPE_p_roc_gallery_type.getCPtr(gallery));
  }

  public static String roc_template_limit(SWIGTYPE_p_size_t template_limit) {
    return rocJNI.roc_template_limit(SWIGTYPE_p_size_t.getCPtr(template_limit));
  }

  public static String roc_compare_templates(roc_template a, roc_template b, SWIGTYPE_p_float similarity) {
    return rocJNI.roc_compare_templates(roc_template.getCPtr(a), a, roc_template.getCPtr(b), b, SWIGTYPE_p_float.getCPtr(similarity));
  }

  public static String roc_compare_galleries(SWIGTYPE_p_roc_gallery_type target, SWIGTYPE_p_roc_gallery_type query, SWIGTYPE_p_float similarity_matrix) {
    return rocJNI.roc_compare_galleries(SWIGTYPE_p_roc_gallery_type.getCPtr(target), SWIGTYPE_p_roc_gallery_type.getCPtr(query), SWIGTYPE_p_float.getCPtr(similarity_matrix));
  }

  public static String roc_search(SWIGTYPE_p_roc_gallery_type gallery, roc_template probe, long k, float min_similarity, roc_candidate candidates) {
    return rocJNI.roc_search(SWIGTYPE_p_roc_gallery_type.getCPtr(gallery), roc_template.getCPtr(probe), probe, k, min_similarity, roc_candidate.getCPtr(candidates), candidates);
  }

  public static String roc_knn(SWIGTYPE_p_roc_gallery_type gallery, SWIGTYPE_p_roc_gallery_type probes, long k, float min_similarity, roc_candidate neighbors) {
    return rocJNI.roc_knn(SWIGTYPE_p_roc_gallery_type.getCPtr(gallery), SWIGTYPE_p_roc_gallery_type.getCPtr(probes), k, min_similarity, roc_candidate.getCPtr(neighbors), neighbors);
  }

  public static String roc_rerank(SWIGTYPE_p_roc_gallery_type gallery, long k, roc_candidate candidates) {
    return rocJNI.roc_rerank(SWIGTYPE_p_roc_gallery_type.getCPtr(gallery), k, roc_candidate.getCPtr(candidates), candidates);
  }

  public static String roc_cluster(SWIGTYPE_p_roc_gallery_type gallery, long k, roc_candidate neighbors, float aggressiveness) {
    return rocJNI.roc_cluster(SWIGTYPE_p_roc_gallery_type.getCPtr(gallery), k, roc_candidate.getCPtr(neighbors), neighbors, aggressiveness);
  }

  public static String roc_track(SWIGTYPE_p_roc_gallery_type gallery, SWIGTYPE_p_roc_time max_time_separation, float min_detection_overlap, float min_similarity) {
    return rocJNI.roc_track(SWIGTYPE_p_roc_gallery_type.getCPtr(gallery), SWIGTYPE_p_roc_time.getCPtr(max_time_separation), min_detection_overlap, min_similarity);
  }

  public static String roc_consolidate(SWIGTYPE_p_roc_gallery_type gallery, float max_similarity, long max_count) {
    return rocJNI.roc_consolidate(SWIGTYPE_p_roc_gallery_type.getCPtr(gallery), max_similarity, max_count);
  }

  public static String roc_person_ids(SWIGTYPE_p_roc_gallery_type gallery, SWIGTYPE_p_unsigned_int person_ids) {
    return rocJNI.roc_person_ids(SWIGTYPE_p_roc_gallery_type.getCPtr(gallery), SWIGTYPE_p_unsigned_int.getCPtr(person_ids));
  }

}
