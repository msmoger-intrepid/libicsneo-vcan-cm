//------------------------------------------------------------------------------
// <auto-generated />
//
// This file was automatically generated by SWIG (http://www.swig.org).
// Version 4.0.0
//
// Do not make changes to this file unless you know what you are doing--modify
// the SWIG interface file instead.
//------------------------------------------------------------------------------


public class neomessage_can_t : global::System.IDisposable {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;
  protected bool swigCMemOwn;

  internal neomessage_can_t(global::System.IntPtr cPtr, bool cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(neomessage_can_t obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  ~neomessage_can_t() {
    Dispose(false);
  }

  public void Dispose() {
    Dispose(true);
    global::System.GC.SuppressFinalize(this);
  }

  protected virtual void Dispose(bool disposing) {
    lock(this) {
      if (swigCPtr.Handle != global::System.IntPtr.Zero) {
        if (swigCMemOwn) {
          swigCMemOwn = false;
          icsneocsharpPINVOKE.delete_neomessage_can_t(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
    }
  }

  public neomessage_statusbitfield_t status {
    set {
      icsneocsharpPINVOKE.neomessage_can_t_status_set(swigCPtr, neomessage_statusbitfield_t.getCPtr(value));
    } 
    get {
      global::System.IntPtr cPtr = icsneocsharpPINVOKE.neomessage_can_t_status_get(swigCPtr);
      neomessage_statusbitfield_t ret = (cPtr == global::System.IntPtr.Zero) ? null : new neomessage_statusbitfield_t(cPtr, false);
      return ret;
    } 
  }

  public ulong timestamp {
    set {
      icsneocsharpPINVOKE.neomessage_can_t_timestamp_set(swigCPtr, value);
    } 
    get {
      ulong ret = icsneocsharpPINVOKE.neomessage_can_t_timestamp_get(swigCPtr);
      return ret;
    } 
  }

  public ulong timestampReserved {
    set {
      icsneocsharpPINVOKE.neomessage_can_t_timestampReserved_set(swigCPtr, value);
    } 
    get {
      ulong ret = icsneocsharpPINVOKE.neomessage_can_t_timestampReserved_get(swigCPtr);
      return ret;
    } 
  }

  public byte[] data {
	set {
		icsneocsharpPINVOKE.neomessage_can_t_data_set(swigCPtr, value);
	}

	get {
		byte[] ret = new byte[this.length]; 
        System.IntPtr data = icsneocsharpPINVOKE.neomessage_can_t_data_get(swigCPtr); 
        System.Runtime.InteropServices.Marshal.Copy(data, ret, 0, (int)this.length);
		return ret; 
	}

  }

  public uint length {
    set {
      icsneocsharpPINVOKE.neomessage_can_t_length_set(swigCPtr, value);
    } 
    get {
      uint ret = icsneocsharpPINVOKE.neomessage_can_t_length_get(swigCPtr);
      return ret;
    } 
  }

  public uint arbid {
    set {
      icsneocsharpPINVOKE.neomessage_can_t_arbid_set(swigCPtr, value);
    } 
    get {
      uint ret = icsneocsharpPINVOKE.neomessage_can_t_arbid_get(swigCPtr);
      return ret;
    } 
  }

  public ushort netid {
    set {
      icsneocsharpPINVOKE.neomessage_can_t_netid_set(swigCPtr, value);
    } 
    get {
      ushort ret = icsneocsharpPINVOKE.neomessage_can_t_netid_get(swigCPtr);
      return ret;
    } 
  }

  public byte type {
    set {
      icsneocsharpPINVOKE.neomessage_can_t_type_set(swigCPtr, value);
    } 
    get {
      byte ret = icsneocsharpPINVOKE.neomessage_can_t_type_get(swigCPtr);
      return ret;
    } 
  }

  public byte dlcOnWire {
    set {
      icsneocsharpPINVOKE.neomessage_can_t_dlcOnWire_set(swigCPtr, value);
    } 
    get {
      byte ret = icsneocsharpPINVOKE.neomessage_can_t_dlcOnWire_get(swigCPtr);
      return ret;
    } 
  }

  public SWIGTYPE_p_unsigned_char reserved {
    set {
      icsneocsharpPINVOKE.neomessage_can_t_reserved_set(swigCPtr, SWIGTYPE_p_unsigned_char.getCPtr(value));
    } 
    get {
      global::System.IntPtr cPtr = icsneocsharpPINVOKE.neomessage_can_t_reserved_get(swigCPtr);
      SWIGTYPE_p_unsigned_char ret = (cPtr == global::System.IntPtr.Zero) ? null : new SWIGTYPE_p_unsigned_char(cPtr, false);
      return ret;
    } 
  }

  public neomessage_can_t() : this(icsneocsharpPINVOKE.new_neomessage_can_t(), true) {
  }

}
