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

char* CByteArraySlicer::SliceRGBArray(char buffer[],
	int w, int w1, int h1, int w2, int h2) {

	string slice;

	const char* buffer_const = buffer;
	string buffer_str(buffer_const);

	long buffer_index = 0;
	for (int y = h1; y <= h2; y++) {
		for (int x = (3 * w1); x <= (3 * w2); x += 3) {
			buffer_index = (y * 3 * w) + x;
			slice.append(buffer_str.substr(buffer_index, 3));
		}
	}

	char* output = new char[slice.length() + 1];
	strcpy(output, slice.c_str());
	return output;
}
