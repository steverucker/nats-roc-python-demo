//------------------------------------------------------------------------------
// <auto-generated />
//
// This file was automatically generated by SWIG (http://www.swig.org).
// Version 3.0.8
//
// Do not make changes to this file unless you know what you are doing--modify
// the SWIG interface file instead.
//------------------------------------------------------------------------------


public class roc_candidate : global::System.IDisposable {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;
  protected bool swigCMemOwn;

  internal roc_candidate(global::System.IntPtr cPtr, bool cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(roc_candidate obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  ~roc_candidate() {
    Dispose();
  }

  public virtual void Dispose() {
    lock(this) {
      if (swigCPtr.Handle != global::System.IntPtr.Zero) {
        if (swigCMemOwn) {
          swigCMemOwn = false;
          rocPINVOKE.delete_roc_candidate(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
      global::System.GC.SuppressFinalize(this);
    }
  }

  public uint index {
    set {
      rocPINVOKE.roc_candidate_index_set(swigCPtr, value);
    } 
    get {
      uint ret = rocPINVOKE.roc_candidate_index_get(swigCPtr);
      return ret;
    } 
  }

  public float similarity {
    set {
      rocPINVOKE.roc_candidate_similarity_set(swigCPtr, value);
    } 
    get {
      float ret = rocPINVOKE.roc_candidate_similarity_get(swigCPtr);
      return ret;
    } 
  }

  public roc_candidate() : this(rocPINVOKE.new_roc_candidate(), true) {
  }

}