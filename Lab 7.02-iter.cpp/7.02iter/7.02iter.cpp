#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab 7.02-iter/Lab 7.02-iter.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace My702iter
{
	TEST_CLASS(My702iter)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int a[] = { 2, -4, 5, 9, 10 };
			int tmp = smallestInRow(a, 5);
			Assert::AreEqual(1, tmp);
		}
	};
}
