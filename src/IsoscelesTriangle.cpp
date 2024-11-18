#include <iostream>
#include "IsoscelesTriangle.h"

IsoscelesTriangle::IsoscelesTriangle(const Vertex vertices[3])
{
	setIsoTriangle(vertices);
}

IsoscelesTriangle::IsoscelesTriangle(const Vertex& left, const Vertex& right,
	double height)
{
	double x = (left.m_col + right.m_col) / 2;
	double y = left.m_row + height;

	Vertex top = { x, y };
	Vertex vercies[] = { top, left, right };

	setIsoTriangle(vercies);
}

void IsoscelesTriangle::setIsoTriangle(const Vertex vertices[])
{
	Triangle triangleUser(vertices);

	if (validIsoscelesTriangle(triangleUser))
	{
		m_triangle = triangleUser;
	}
}

Vertex IsoscelesTriangle::getVertex(int index) const
{
	m_triangle.getVertex(index);
}

double IsoscelesTriangle::getLength(int index) const
{
	m_triangle.getLength(index);
}

double IsoscelesTriangle::getHeight() const
{
	Vertex top = m_triangle.getVertex(0).m_row > m_triangle.getVertex(1).m_row
		? m_triangle.getVertex(0) : ;
}



bool IsoscelesTriangle::validIsoscelesTriangle(const Triangle& triangle)
{
	return doubleEqual(triangle.getLength(0), triangle.getLength(1)) ||
		doubleEqual(triangle.getLength(1), triangle.getLength(2)) ||
		doubleEqual(triangle.getLength(2), triangle.getLength(0));
}
