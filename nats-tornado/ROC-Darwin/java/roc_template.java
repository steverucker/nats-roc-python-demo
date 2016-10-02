/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 3.0.8
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */


public class roc_template {
  private transient long swigCPtr;
  protected transient boolean swigCMemOwn;

  protected roc_template(long cPtr, boolean cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = cPtr;
  }

  protected static long getCPtr(roc_template obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public synchronized void delete() {
    if (swigCPtr != 0) {
      if (swigCMemOwn) {
        swigCMemOwn = false;
        rocJNI.delete_roc_template(swigCPtr);
      }
      swigCPtr = 0;
    }
  }

  public void setAlgorithm_id(long value) {
    rocJNI.roc_template_algorithm_id_set(swigCPtr, this, value);
  }

  public long getAlgorithm_id() {
    return rocJNI.roc_template_algorithm_id_get(swigCPtr, this);
  }

  public void setTimestamp(SWIGTYPE_p_roc_time value) {
    rocJNI.roc_template_timestamp_set(swigCPtr, this, SWIGTYPE_p_roc_time.getCPtr(value));
  }

  public SWIGTYPE_p_roc_time getTimestamp() {
    return new SWIGTYPE_p_roc_time(rocJNI.roc_template_timestamp_get(swigCPtr, this), true);
  }

  public void setX(int value) {
    rocJNI.roc_template_x_set(swigCPtr, this, value);
  }

  public int getX() {
    return rocJNI.roc_template_x_get(swigCPtr, this);
  }

  public void setY(int value) {
    rocJNI.roc_template_y_set(swigCPtr, this, value);
  }

  public int getY() {
    return rocJNI.roc_template_y_get(swigCPtr, this);
  }

  public void setWidth(long value) {
    rocJNI.roc_template_width_set(swigCPtr, this, value);
  }

  public long getWidth() {
    return rocJNI.roc_template_width_get(swigCPtr, this);
  }

  public void setHeight(long value) {
    rocJNI.roc_template_height_set(swigCPtr, this, value);
  }

  public long getHeight() {
    return rocJNI.roc_template_height_get(swigCPtr, this);
  }

  public void setConfidence(float value) {
    rocJNI.roc_template_confidence_set(swigCPtr, this, value);
  }

  public float getConfidence() {
    return rocJNI.roc_template_confidence_get(swigCPtr, this);
  }

  public void setPerson_id(long value) {
    rocJNI.roc_template_person_id_set(swigCPtr, this, value);
  }

  public long getPerson_id() {
    return rocJNI.roc_template_person_id_get(swigCPtr, this);
  }

  public void setMd_size(long value) {
    rocJNI.roc_template_md_size_set(swigCPtr, this, value);
  }

  public long getMd_size() {
    return rocJNI.roc_template_md_size_get(swigCPtr, this);
  }

  public void setFv_size(long value) {
    rocJNI.roc_template_fv_size_set(swigCPtr, this, value);
  }

  public long getFv_size() {
    return rocJNI.roc_template_fv_size_get(swigCPtr, this);
  }

  public void setTn_size(long value) {
    rocJNI.roc_template_tn_size_set(swigCPtr, this, value);
  }

  public long getTn_size() {
    return rocJNI.roc_template_tn_size_get(swigCPtr, this);
  }

  public void setMd(String value) {
    rocJNI.roc_template_md_set(swigCPtr, this, value);
  }

  public String getMd() {
    return rocJNI.roc_template_md_get(swigCPtr, this);
  }

  public void setFv(SWIGTYPE_p_unsigned_char value) {
    rocJNI.roc_template_fv_set(swigCPtr, this, SWIGTYPE_p_unsigned_char.getCPtr(value));
  }

  public SWIGTYPE_p_unsigned_char getFv() {
    long cPtr = rocJNI.roc_template_fv_get(swigCPtr, this);
    return (cPtr == 0) ? null : new SWIGTYPE_p_unsigned_char(cPtr, false);
  }

  public void setTn(SWIGTYPE_p_unsigned_char value) {
    rocJNI.roc_template_tn_set(swigCPtr, this, SWIGTYPE_p_unsigned_char.getCPtr(value));
  }

  public SWIGTYPE_p_unsigned_char getTn() {
    long cPtr = rocJNI.roc_template_tn_get(swigCPtr, this);
    return (cPtr == 0) ? null : new SWIGTYPE_p_unsigned_char(cPtr, false);
  }

  public roc_template() {
    this(rocJNI.new_roc_template(), true);
  }

}