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
			string array = "123456789012345678901234567890123456";
			string slicedarray = "123456789012345678901234567890123456";
			string returnedarray = test_slicer.SliceRGBArray(array, 3, 0, 0, 3, 4);
			Assert::IsTrue(returnedarray == slicedarray);
		}

		TEST_METHOD(TestSliceFirstRowArray) {
			CByteArraySlicer test_slicer;
			string array = "123456789012345678901234567890123456";
			string slicedarray = "123456789";
			string returnedarray = test_slicer.SliceRGBArray(array, 3, 0, 0, 3, 1);
			Assert::IsTrue(returnedarray == slicedarray);
		}

		TEST_METHOD(TestSliceBoxArray) {
			CByteArraySlicer test_slicer;
			string array = "123456789012345678901234567890123456";
			string slicedarray = "345234";
			string returnedarray = test_slicer.SliceRGBArray(array, 3, 1, 1, 2, 3);
			Assert::IsTrue(returnedarray == slicedarray);
		}
	};
}