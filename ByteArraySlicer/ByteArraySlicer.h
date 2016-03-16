// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the BYTEARRAYSLICER_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// BYTEARRAYSLICER_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef BYTEARRAYSLICER_EXPORTS
#define BYTEARRAYSLICER_API __declspec(dllexport)
#else
#define BYTEARRAYSLICER_API __declspec(dllimport)
#endif
#include <string>
#include <cstring>
#include <windows.h>
#include <windef.h>

using namespace std;

// This class is exported from the ByteArraySlicer.dll
class BYTEARRAYSLICER_API CByteArraySlicer {
public:
	CByteArraySlicer(void);
	BYTE* SliceArray(BYTE buffer[], int w, int w1, int h1, int w2, int h2);
	BYTE* RotateArray(BYTE buffer[], int w, int h);
	// TODO: add your methods here.
};

extern BYTEARRAYSLICER_API int nByteArraySlicer;

BYTEARRAYSLICER_API int fnByteArraySlicer(void);
