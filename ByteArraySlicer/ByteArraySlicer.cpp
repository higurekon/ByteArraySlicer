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

string CByteArraySlicer::SliceRGBArray(string Buffer,
	int w, int w1, int h1, int w2, int h2) {

	const int slice_size = (w2 - w1) * (h2 - h1) * 3;
	string slice;

	long buffer_index = 0;
	for (int y = h1; y < h2; y++) {
		for (int x = (3 * w1); x < (3 * w2); x += 3) {
			buffer_index = (y * 3 * w) + x;
			slice.append(Buffer.substr(buffer_index, 3));
		}
	}
	return slice;
}
