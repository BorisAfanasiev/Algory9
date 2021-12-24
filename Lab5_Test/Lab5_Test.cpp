#include "pch.h"
#include "CppUnitTest.h"
#include "..\Algory9\class.h"
#include <math.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Lab5Test
{
	TEST_CLASS(Point_Test)
	{
	public:
		
		TEST_METHOD(ConstructorWithParameters)
		{
			Point point(1.234, 4.321);
			Assert::IsTrue(point.getX() == 1.234 && point.getY() == 4.321);
		}
		TEST_METHOD(ConstructorWithoutParameters)
		{
			Point point;
			Assert::IsTrue(point.getX() == 0 && point.getY() == 0);
		}
	};

	TEST_CLASS(Segment_Test)
	{
	public:

		TEST_METHOD(GetLengthMethod)
		{
			Segment segment{ Point(1,2), Point(3,4) };		//~~2.82
			double approx{ 0.01 };
			Assert::IsTrue(fabs(segment.getLength() - 2.82) < approx);			
		}
	};

	TEST_CLASS(Triangle_Test)
	{
	public:

		TEST_METHOD(GetAreaMethod)
		{
			Triangle triangle{ Point(2,3), Point(1,1), Point(-3,4) };		//area 5.5
			Assert::IsTrue(triangle.getArea() == 5.5);
		}
		TEST_METHOD(GetPerimeterMethod)
		{
			Triangle triangle{ Point(2,3), Point(1,1), Point(-3,4) };		//perimeter ~~12.335
			double approx{ 0.01 };
			Assert::IsTrue((triangle.getPerimeter() - 12.335) < approx);
		}
		TEST_METHOD(CompareAreaMethod)
		{
			Triangle one{ Point(2,3), Point(1,1), Point(-3,4) };		//area 5.5
			Triangle two{ Point(2,3), Point(1,2), Point(-3,4) };		//area 3
			double approx{ 0.01 };
			Assert::IsTrue(fabs(one.compareArea(two) - 2.5) < approx);
		}
	};
}
