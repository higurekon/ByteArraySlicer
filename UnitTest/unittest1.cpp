#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\ByteArraySlicer\ByteArraySlicer.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest3
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestReturnWholeArray) {
			CByteArraySlicer test_slicer;

			BYTE array[37] = 
							{ 0, 255, 0, 255, 255, 255, 0, 0, 0, 
							255, 255, 255, 255, 255, 255, 255, 255, 255, 
							0, 0, 0, 255, 255, 255, 0, 0, 0,
							255, 255, 255, 255, 255, 255, 0, 0, 0, '\0' };
			BYTE slicedarray[37] = 
							{ 0, 0, 0, 255, 255, 255, 0, 0, 0,
							255, 255, 255, 255, 255, 255, 255, 255, 255,
							0, 0, 0, 255, 255, 255, 0, 0, 0,
							255, 255, 255, 255, 255, 255, 0, 0, 0, '\0' };
			BYTE* returnedarray = test_slicer.SliceRGBArray(array, 9, 0, 0, 8, 3);
			boolean reachedEndOfArray = false;
			int i = 0;
			while (!reachedEndOfArray) {
				Assert::IsTrue(returnedarray[i] == slicedarray[i]);
				reachedEndOfArray = (returnedarray[i] == '\0');
				i++;
			}

		}

		TEST_METHOD(TestReturnSliceArray) {
			CByteArraySlicer test_slicer;

			BYTE array[37] =
							{ 0, 0, 0, 255, 255, 255, 0, 0, 0,
							255, 255, 255, 255, 255, 255, 255, 255, 255,
							0, 0, 0, 255, 255, 255, 0, 0, 0,
							255, 255, 255, 255, 255, 255, 0, 0, 0, '\0' };
			BYTE slicedarray[37] =
							{ 255, 255, 255, 
							255, 255, 255, '\0' };
			BYTE* returnedarray = test_slicer.SliceRGBArray(array, 9, 3, 1, 5, 2);
			boolean reachedEndOfArray = false;
			int i = 0;
			while (!reachedEndOfArray) {
				Assert::IsTrue(returnedarray[i] == slicedarray[i]);
				reachedEndOfArray = (returnedarray[i] == '\0');
				i++;
			}

		}

	};
}