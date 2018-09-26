#ifndef __ICSNEOC_H_
#define __ICSNEOC_H_

#include <stddef.h>
#include "device/include/neodevice.h" // For neodevice_t
#include "communication/message/include/neomessage.h" // For neomessage_t and friends
#include "platform/include/dynamiclib.h" // Dynamic library loading and exporting

#ifndef ICSNEOC_DYNAMICLOAD

#ifdef __cplusplus
extern "C" {
#endif


extern void DLLExport icsneo_findAllDevices(neodevice_t* devices, size_t* count);

extern void DLLExport icsneo_freeUnconnectedDevices();

extern bool DLLExport icsneo_serialNumToString(uint32_t num, char* str, size_t* count);

extern uint32_t DLLExport icsneo_serialStringToNum(const char* str);

extern bool DLLExport icsneo_isValidNeoDevice(const neodevice_t* device);

extern bool DLLExport icsneo_openDevice(const neodevice_t* device);

extern bool DLLExport icsneo_closeDevice(const neodevice_t* device);

extern bool DLLExport icsneo_goOnline(const neodevice_t* device);

extern bool DLLExport icsneo_goOffline(const neodevice_t* device);

extern bool DLLExport icsneo_isOnline(const neodevice_t* device);

extern bool DLLExport icsneo_enableMessagePolling(const neodevice_t* device);

extern bool DLLExport icsneo_disableMessagePolling(const neodevice_t* device);

extern bool DLLExport icsneo_getMessages(const neodevice_t* device, neomessage_t* messages, size_t* items);

extern size_t DLLExport icsneo_getPollingMessageLimit(const neodevice_t* device);

extern bool DLLExport icsneo_setPollingMessageLimit(const neodevice_t* device, size_t newLimit);

#ifdef __cplusplus
} // extern "C"
#endif

#else // ICSNEOC_DYNAMICLOAD

typedef void(*fn_icsneo_findAllDevices)(neodevice_t* devices, size_t* count);
fn_icsneo_findAllDevices icsneo_findAllDevices;

typedef void(*fn_icsneo_freeUnconnectedDevices)();
fn_icsneo_freeUnconnectedDevices icsneo_freeUnconnectedDevices;

typedef bool(*fn_icsneo_serialNumToString)(uint32_t num, char* str, size_t* count);
fn_icsneo_serialNumToString icsneo_serialNumToString;

typedef uint32_t(*fn_icsneo_serialStringToNum)(const char* str);
fn_icsneo_serialStringToNum icsneo_serialStringToNum;

typedef bool(*fn_icsneo_isValidNeoDevice)(const neodevice_t* device);
fn_icsneo_isValidNeoDevice icsneo_isValidNeoDevice;

typedef bool(*fn_icsneo_openDevice)(const neodevice_t* device);
fn_icsneo_openDevice icsneo_openDevice;

typedef bool(*fn_icsneo_closeDevice)(const neodevice_t* device);
fn_icsneo_closeDevice icsneo_closeDevice;

typedef bool(*fn_icsneo_goOnline)(const neodevice_t* device);
fn_icsneo_goOnline icsneo_goOnline;

typedef bool(*fn_icsneo_goOffline)(const neodevice_t* device);
fn_icsneo_goOffline icsneo_goOffline;

typedef bool(*fn_icsneo_isOnline)(const neodevice_t* device);
fn_icsneo_isOnline icsneo_isOnline;

typedef bool(*fn_icsneo_enableMessagePolling)(const neodevice_t* device);
fn_icsneo_enableMessagePolling icsneo_enableMessagePolling;

typedef bool(*fn_icsneo_disableMessagePolling)(const neodevice_t* device);
fn_icsneo_disableMessagePolling icsneo_disableMessagePolling;

typedef bool(*fn_icsneo_getMessages)(const neodevice_t* device, neomessage_t* messages, size_t* items);
fn_icsneo_getMessages icsneo_getMessages;

typedef size_t(*fn_icsneo_getPollingMessageLimit)(const neodevice_t* device);
fn_icsneo_getPollingMessageLimit icsneo_getPollingMessageLimit;

typedef bool(*fn_icsneo_setPollingMessageLimit)(const neodevice_t* device, size_t newLimit);
fn_icsneo_setPollingMessageLimit icsneo_setPollingMessageLimit;

#define ICSNEO_IMPORT(func) func = (fn_##func)icsneo_dynamicLibraryGetFunction(icsneo_libraryHandle, #func)
#define ICSNEO_IMPORTASSERT(func) if((ICSNEO_IMPORT(func)) == NULL) return 3
void* icsneo_libraryHandle = NULL;
bool icsneo_initialized = false;
bool icsneo_destroyed = false;
int icsneo_init() {
	icsneo_destroyed = false;
	if(icsneo_initialized)
		return 1;

	icsneo_libraryHandle = icsneo_dynamicLibraryLoad();
	if(icsneo_libraryHandle == NULL)
		return 2;

	ICSNEO_IMPORTASSERT(icsneo_findAllDevices);
	ICSNEO_IMPORTASSERT(icsneo_freeUnconnectedDevices);
	ICSNEO_IMPORTASSERT(icsneo_serialNumToString);
	ICSNEO_IMPORTASSERT(icsneo_serialStringToNum);
	ICSNEO_IMPORTASSERT(icsneo_isValidNeoDevice);
	ICSNEO_IMPORTASSERT(icsneo_openDevice);
	ICSNEO_IMPORTASSERT(icsneo_closeDevice);
	ICSNEO_IMPORTASSERT(icsneo_goOnline);
	ICSNEO_IMPORTASSERT(icsneo_goOffline);
	ICSNEO_IMPORTASSERT(icsneo_isOnline);
	ICSNEO_IMPORTASSERT(icsneo_enableMessagePolling);
	ICSNEO_IMPORTASSERT(icsneo_disableMessagePolling);
	ICSNEO_IMPORTASSERT(icsneo_getMessages);
	ICSNEO_IMPORTASSERT(icsneo_getPollingMessageLimit);
	ICSNEO_IMPORTASSERT(icsneo_setPollingMessageLimit);

	icsneo_initialized = true;
	return 0;
}

bool icsneo_close() ICSNEO_DESTRUCTOR {
	icsneo_initialized = false;
	if(icsneo_destroyed)
		return true;

	return icsneo_destroyed = icsneo_dynamicLibraryClose(icsneo_libraryHandle);
}

#endif // ICSNEOC_DYNAMICLOAD

#endif // __ICSNEOC_H_