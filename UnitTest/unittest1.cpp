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

			char array[37] = 
							{ '1', '0', '1', '1', '0', '1', '1', '0', '1', 
							'1', '0', '1', '1', '0', '1', '1', '0', '1', 
							'1', '0', '1', '1', '0', '1', '0', '0', '1',
							'0', '1', '1', '1', '1', '0', '0', '1', '1', '\0' };
			const char slicedarray[37] = 
							{ '1', '0', '1', '1', '0', '1', '1', '0', '1',
							'1', '0', '1', '1', '0', '1', '1', '0', '1',
							'1', '0', '1', '1', '0', '1', '0', '0', '1',
							'0', '1', '1', '1', '1', '0', '0', '1', '1', '\0' };
			char* returnedarray = test_slicer.SliceRGBArray(array, 3, 0, 0, 3, 4);
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