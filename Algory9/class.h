#pragma once
#include <math.h>

class Point
{
private:
	double m_x;
	double m_y;
public:
	Point(const double x = 0, const double y = 0) : m_x{ x }, m_y{ y } {};

	double getX() const { return m_x; }
	double getY() const { return m_y; }
};

class Segment
{
private:
	Point m_A;
	Point m_B;
public:
	Segment(const Point& A, const Point& B) : m_A{ A }, m_B{ B } {};

	double getLength() const
	{
		return sqrt(pow((m_B.getX() - m_A.getX()), 2) + pow(m_B.getY() - m_A.getY(), 2));
	}
};

class Triangle
{
private:
	Point m_A;
	Point m_B;
	Point m_C;
public:
	Triangle(const Point& A, const Point& B, const Point& C) : m_A{ A }, m_B{ B }, m_C{ C } {};

	double getArea() const		//Рассчёт по длинам сторон(формула Герона).
	{
		double semiPerimeter = this->getPerimeter() / 2;
		return sqrt(semiPerimeter
			* (semiPerimeter - Segment(m_A, m_B).getLength())		//разность полупериметра и стороны
			* (semiPerimeter - Segment(m_B, m_C).getLength())
			* (semiPerimeter - Segment(m_A, m_C).getLength()));
	}

	double getPerimeter() const		//Используя анонимные объекты класса "Сегмент", суммируем длины сторон.
	{
		return  (Segment(m_A, m_B).getLength() + Segment(m_B, m_C).getLength() + Segment(m_A, m_C).getLength());
	}

	double compareArea(const Triangle& with) const
	{
		return this->getArea() - with.getArea();
	}
};