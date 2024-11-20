#include <iostream>
#include "IsoscelesTriangle.h"

//-----------------------------------------------------------------------------

IsoscelesTriangle::IsoscelesTriangle(const Vertex vertices[3])
{
	setIsoscelesTriangle(vertices);
}

//-----------------------------------------------------------------------------

IsoscelesTriangle::IsoscelesTriangle(const Vertex& left, const Vertex& right,
	double height)
{
	double x = (left.m_col + right.m_col) / 2;
	double y = left.m_row + height;

	Vertex top = { x, y };
	Vertex vercies[] = { top, left, right };

	setIsoscelesTriangle(vercies);
}

//-----------------------------------------------------------------------------

Vertex IsoscelesTriangle::getVertex(int index) const
{
	return m_triangle.getVertex(index);
}

//-----------------------------------------------------------------------------

double IsoscelesTriangle::getLength(int index) const
{
	return m_triangle.getLength(index);
}

//-----------------------------------------------------------------------------

double IsoscelesTriangle::getHeight() const
{
	double bottom_row = 0;
	Vertex top = findTop(m_triangle, bottom_row);

	return abs(top.m_row - bottom_row);
}

//-----------------------------------------------------------------------------

void IsoscelesTriangle::draw(Board& board) const
{
	m_triangle.draw(board);
}

//-----------------------------------------------------------------------------

Rectangle IsoscelesTriangle::getBoundingRectangle() const
{
	return m_triangle.getBoundingRectangle();
}

//-----------------------------------------------------------------------------

double IsoscelesTriangle::getPerimeter() const
{
	return m_triangle.getPerimeter();
}

//-----------------------------------------------------------------------------

double IsoscelesTriangle::getArea() const
{
	return m_triangle.getArea();
}

//-----------------------------------------------------------------------------

Vertex IsoscelesTriangle::getCenter() const
{
	return m_triangle.getCenter();
}

//-----------------------------------------------------------------------------

bool IsoscelesTriangle::scale(double factor)
{
	if (factor < 0) return false;

	Vertex center = getCenter();
	Vertex firstPoint = m_triangle.getVertex(0),
		secondPoint = m_triangle.getVertex(1),
		thirdPoint = m_triangle.getVertex(2);

	afterFactor(center, firstPoint, factor);
	afterFactor(center, secondPoint, factor);
	afterFactor(center, thirdPoint, factor);

	
	if (!firstPoint.isValid()
		|| !secondPoint.isValid()
		|| !thirdPoint.isValid()) return false;

	Triangle triangle = { firstPoint , secondPoint, thirdPoint };
	m_triangle = triangle;

	return true;
}

//-----------------------------------------------------------------------------

void IsoscelesTriangle::afterFactor(const Vertex& center, Vertex& dot, double factor)
{
	double width = (center.m_col - dot.m_col) * factor;
	double height = (center.m_row - dot.m_row) * factor;

	dot.m_col = center.m_col - width;
	dot.m_row = center.m_row - height;
}

//-----------------------------------------------------------------------------

Vertex IsoscelesTriangle::findTop(const Triangle& triangle, double& bottom) const
{
	Vertex top;

	if (sameRow(triangle.getVertex(0), triangle.getVertex(1)))
	{
		top = triangle.getVertex(2);
		bottom = triangle.getVertex(0).m_row;
	}
	else
	{
		top = triangle.getVertex(0).isHigherThan(triangle.getVertex(1))
			? triangle.getVertex(0) : triangle.getVertex(1);

		bottom = triangle.getVertex(2).m_row;
	}

	return top;
}

//-----------------------------------------------------------------------------

bool IsoscelesTriangle::validIsoscelesTriangle(const Triangle& triangle)
{
	bool equal = doubleEqual(triangle.getLength(0), triangle.getLength(1)) ||
		doubleEqual(triangle.getLength(1), triangle.getLength(2)) ||
		doubleEqual(triangle.getLength(2), triangle.getLength(0));

	bool parallel = sameRow(triangle.getVertex(0), triangle.getVertex(1)) ||
		sameRow(triangle.getVertex(1), triangle.getVertex(2)) ||
		sameRow(triangle.getVertex(2), triangle.getVertex(0));

	return equal && parallel;
}

//-----------------------------------------------------------------------------

void IsoscelesTriangle::setIsoscelesTriangle(const Vertex vertices[])
{
	Triangle triangleUser(vertices);

	if (validIsoscelesTriangle(triangleUser))
	{
		m_triangle = triangleUser;
	}
}