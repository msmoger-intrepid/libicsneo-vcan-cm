/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 4.0.0
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */


public class neodevice_t {
  private transient long swigCPtr;
  protected transient boolean swigCMemOwn;

  protected neodevice_t(long cPtr, boolean cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = cPtr;
  }

  protected static long getCPtr(neodevice_t obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  @SuppressWarnings("deprecation")
  protected void finalize() {
    delete();
  }

  public synchronized void delete() {
    if (swigCPtr != 0) {
      if (swigCMemOwn) {
        swigCMemOwn = false;
        icsneojavaJNI.delete_neodevice_t(swigCPtr);
      }
      swigCPtr = 0;
    }
  }

  public void setDevice(SWIGTYPE_p_void value) {
    icsneojavaJNI.neodevice_t_device_set(swigCPtr, this, SWIGTYPE_p_void.getCPtr(value));
  }

  public SWIGTYPE_p_void getDevice() {
    long cPtr = icsneojavaJNI.neodevice_t_device_get(swigCPtr, this);
    return (cPtr == 0) ? null : new SWIGTYPE_p_void(cPtr, false);
  }

  public void setHandle(int value) {
    icsneojavaJNI.neodevice_t_handle_set(swigCPtr, this, value);
  }

  public int getHandle() {
    return icsneojavaJNI.neodevice_t_handle_get(swigCPtr, this);
  }

  public void setType(long value) {
    icsneojavaJNI.neodevice_t_type_set(swigCPtr, this, value);
  }

  public long getType() {
    return icsneojavaJNI.neodevice_t_type_get(swigCPtr, this);
  }

  public void setSerial(String value) {
    icsneojavaJNI.neodevice_t_serial_set(swigCPtr, this, value);
  }

  public String getSerial() {
    return icsneojavaJNI.neodevice_t_serial_get(swigCPtr, this);
  }

  public neodevice_t() {
    this(icsneojavaJNI.new_neodevice_t(), true);
  }

}
