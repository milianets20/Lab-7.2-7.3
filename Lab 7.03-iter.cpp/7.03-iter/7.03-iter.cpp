#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab 7.03-iter/Lab 7.03-iter.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace My703iter
{
	TEST_CLASS(My703iter)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int** a = new int* [2];
			a[0] = new int[2] { 0, -5 };
			a[1] = new int[2] { 6, 0 };
			int count;
			int tmp = Count(a, 2, 2, count);
			Assert::AreEqual(1, tmp);
		}
	};
}
