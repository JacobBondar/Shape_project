#include <iostream>
#include "triangle.h"
#include "cmath"

Triangle::Triangle(const Vertex vertices[POINTS_IN_TRIANGLE])
{
	setBuild(vertices, m_first, m_second, m_third);
}

Triangle::Triangle(Vertex v0, Vertex v1, Vertex v2)
{
	Vertex vertices[POINTS_IN_TRIANGLE] = { v0, v1, v2 };
	setBuild(vertices, m_first, m_second, m_third);
}

Vertex Triangle::getVertex(int index) const
{
	switch (index)
	{
	case 0:
		return m_first;
	case 1:
		return m_second;
	case 2:
		return m_third;
	}
}

double Triangle::getLength(int index) const
{
	switch (index)
	{
	case 0:
		return distance(m_first, m_second);
	case 1:
		return distance(m_second, m_third);
	case 2:
		return distance(m_third, m_first);
	}
}

void Triangle::draw(Board& board) const
{
	board.drawLine(m_first, m_second);
	board.drawLine(m_second, m_third);
	board.drawLine(m_third, m_first);
}

Rectangle Triangle::getBoundingRectangle() const
{
	Vertex bottomP = m_first, topP = m_second;

	Vertex vercises[POINTS_IN_TRIANGLE] = { m_first, m_second, m_third };

	for (int point = 0; point < 3; point++)
	{
		if (vercises[point].isHigherThan(topP)) topP.m_row = vercises[point].m_row;
		if (vercises[point].isToTheRightOf(topP)) topP.m_col = vercises[point].m_col;
		if (!vercises[point].isHigherThan(bottomP)) bottomP.m_row = vercises[point].m_row;
		if (!vercises[point].isToTheRightOf(bottomP)) bottomP.m_col = vercises[point].m_col;
	}

	Rectangle newRectangle(bottomP, topP);
	return newRectangle;
}

double Triangle::getPerimeter() const
{
	return distance(m_first, m_second) +
		distance(m_second, m_third) +
		distance(m_third, m_first);
}

double Triangle::getArea() const
{
	double s = getPerimeter() / 2;
	double sum = 0;
	for (int index = 0; index < 3; index++)
	{
		sum *= (s - getLength(index));
	}

	return sqrt(s * sum);
}

Vertex Triangle::getCenter() const
{
	Vertex center;

	center.m_col = calcAvgPoint(m_first.m_col, m_second.m_col, m_third.m_col);
	center.m_row = calcAvgPoint(m_first.m_row, m_second.m_row, m_third.m_row);

	return center;
}

bool Triangle::scale(double factor)
{
	if (factor < 0) return false;

	Vertex center = getCenter();
	Vertex firstPoint = m_first, secondPoint = m_second, thirdPoint = m_third;

	afterFactor(center, firstPoint, factor);
	afterFactor(center, secondPoint, factor);
	afterFactor(center, thirdPoint, factor);

	if (!firstPoint.isValid() || !secondPoint.isValid() || !thirdPoint.isValid()) return false;

	m_first = firstPoint;
	m_second = secondPoint;
	m_third = thirdPoint;

	return true;
}

void Triangle::afterFactor(const Vertex& center, Vertex& dot, double factor)
{
	double width = (center.m_col - dot.m_col) * factor;
	double height = (center.m_row - dot.m_row) * factor;

	dot.m_col = center.m_col - width;
	dot.m_row = center.m_row - height;
}


void Triangle::setBuild(const Vertex vertices[POINTS_IN_TRIANGLE], Vertex& m_first, Vertex& m_second, Vertex& m_third)
{
	bool validTriangle = true, parallelLine = false;
	for (int point = 0; point < POINTS_IN_TRIANGLE; point++)
	{
		if (!vertices[point].isValid())
		{
			validTriangle = false;
			break;
		}
	}

	for (int point = 0; point < 2 && validTriangle; point++)
	{
		for (int secondPoint = point + 1; secondPoint < 3; secondPoint++)
		{
			if (sameRow(vertices[point], vertices[secondPoint]))
			{
				setData(m_first, m_second, m_third,
					vertices[0].m_col, vertices[0].m_row,
					vertices[1].m_col, vertices[1].m_row,
					vertices[2].m_col, vertices[2].m_row); // maybe add enum
				parallelLine = true;
			}
		}
	}
	if (!parallelLine || !validTriangle)
	{
		setData(m_first, m_second, m_third, FIRST_COL_DEFAULT,
			FIRST_ROW_DEFAULT, SECOND_COL_DEFAULT, SECOND_ROW_DEFAULT,
			THIRD_COL_DEFAULT, THIRD_ROW_DEFAULT);
	}
}

void Triangle::setData(Vertex& m_first, Vertex& m_second,
	Vertex& m_third, double firstCol, double firstRow, double secondCol,
	double secondRow, double thirdCol, double thirdRow)
{
	m_first.m_col = firstCol;
	m_first.m_row = firstRow;
	m_second.m_col = secondCol;
	m_second.m_row = secondRow;
	m_third.m_col = thirdCol;
	m_third.m_row = thirdRow;
}

double Triangle::calcAvgPoint(double val1, double val2, double val3) const
{
	return (val1 + val2 + val3) / 3;
}