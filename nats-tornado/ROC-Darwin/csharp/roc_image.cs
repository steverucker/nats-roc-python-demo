//------------------------------------------------------------------------------
// <auto-generated />
//
// This file was automatically generated by SWIG (http://www.swig.org).
// Version 3.0.8
//
// Do not make changes to this file unless you know what you are doing--modify
// the SWIG interface file instead.
//------------------------------------------------------------------------------


public class roc_image : global::System.IDisposable {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;
  protected bool swigCMemOwn;

  internal roc_image(global::System.IntPtr cPtr, bool cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(roc_image obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  ~roc_image() {
    Dispose();
  }

  public virtual void Dispose() {
    lock(this) {
      if (swigCPtr.Handle != global::System.IntPtr.Zero) {
        if (swigCMemOwn) {
          swigCMemOwn = false;
          rocPINVOKE.delete_roc_image(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
      global::System.GC.SuppressFinalize(this);
    }
  }

  public SWIGTYPE_p_unsigned_char data {
    set {
      rocPINVOKE.roc_image_data_set(swigCPtr, SWIGTYPE_p_unsigned_char.getCPtr(value));
    } 
    get {
      global::System.IntPtr cPtr = rocPINVOKE.roc_image_data_get(swigCPtr);
      SWIGTYPE_p_unsigned_char ret = (cPtr == global::System.IntPtr.Zero) ? null : new SWIGTYPE_p_unsigned_char(cPtr, false);
      return ret;
    } 
  }

  public uint width {
    set {
      rocPINVOKE.roc_image_width_set(swigCPtr, value);
    } 
    get {
      uint ret = rocPINVOKE.roc_image_width_get(swigCPtr);
      return ret;
    } 
  }

  public uint height {
    set {
      rocPINVOKE.roc_image_height_set(swigCPtr, value);
    } 
    get {
      uint ret = rocPINVOKE.roc_image_height_get(swigCPtr);
      return ret;
    } 
  }

  public uint step {
    set {
      rocPINVOKE.roc_image_step_set(swigCPtr, value);
    } 
    get {
      uint ret = rocPINVOKE.roc_image_step_get(swigCPtr);
      return ret;
    } 
  }

  public roc_color_space color_space {
    set {
      rocPINVOKE.roc_image_color_space_set(swigCPtr, (int)value);
    } 
    get {
      roc_color_space ret = (roc_color_space)rocPINVOKE.roc_image_color_space_get(swigCPtr);
      return ret;
    } 
  }

  public roc_image() : this(rocPINVOKE.new_roc_image(), true) {
  }

}
