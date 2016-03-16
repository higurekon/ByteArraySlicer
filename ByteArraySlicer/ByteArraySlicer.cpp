// ByteArraySlicer.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "ByteArraySlicer.h"

// This is an example of an exported variable
BYTEARRAYSLICER_API int nByteArraySlicer=0;

// This is an example of an exported function.
BYTEARRAYSLICER_API int fnByteArraySlicer(void)
{
    return 42;
}

// This is the constructor of a class that has been exported.
// see ByteArraySlicer.h for the class definition
CByteArraySlicer::CByteArraySlicer()
{
    return;
}

BYTE* CByteArraySlicer::SliceRGBArray(BYTE buffer[],
	int w, int w1, int h1, int w2, int h2) {


	BYTE* slice = new BYTE[(w2 - w1) * (h2 - h1)+1];

	long buffer_index = 0;
	long slice_index = 0;
	for (int y = h1; y <= h2; y++) {
		for (int x = w1; x <= w2; x++) {
			buffer_index = (y * w) + x;
			slice[slice_index] = buffer[buffer_index];
			slice_index++;
		}
	}
	slice[slice_index] = '\0';

	return slice;
}
