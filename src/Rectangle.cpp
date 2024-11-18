#include <iostream>
#include "Rectangle.h"
#include "macros.h"

Rectangle::Rectangle(const Vertex& bottomLeft, const Vertex& topRight)
{
	setBuild(bottomLeft, topRight, m_bottom, m_top);
}

Rectangle::Rectangle(const Vertex vertices[2])
{
	setBuild(vertices[FIRST_INDEX], vertices[SECOND_INDEX], m_bottom, m_top);
}

Rectangle::Rectangle(double x, double y, double width, double height)
{
	Vertex buttomLeft, topRight;
	buttomLeft.m_col = x;
	buttomLeft.m_row = y;

	insertWithDimension(buttomLeft, width, height, m_bottom, m_top, 1);
}

Rectangle::Rectangle(const Vertex& topRight, double width, double height)
{
	insertWithDimension(topRight, width, height, m_bottom, m_top, -1);
}

Vertex Rectangle::getBottomLeft() const
{
	return m_bottom;
}

Vertex Rectangle::getTopRight() const
{
	return m_top;
}

double Rectangle::getWidth() const
{
	return m_top.m_col - m_bottom.m_col;
}

double Rectangle::getHeight() const
{
	return m_top.m_row - m_bottom.m_row;
}

void Rectangle::draw(Board& board) const
{
	Vertex bottomRight = { m_top.m_col, m_bottom.m_row },
		topLeft = { m_bottom.m_col, m_top.m_row };

	board.drawLine(m_bottom, bottomRight);
	board.drawLine(bottomRight, m_top);
	board.drawLine(m_top, topLeft);
	board.drawLine(topLeft, m_bottom);
}

Rectangle Rectangle::getBoundingRectangle() const
{
	Rectangle newRectangle(m_bottom, m_top);
	return newRectangle;
}

double Rectangle::getPerimeter() const
{
	return 2 * getWidth() + 2 * getHeight();
}

double Rectangle::getArea() const
{
	return getWidth() * getHeight();
}

Vertex Rectangle::getCenter() const
{
	Vertex center;
	center.m_col = (m_bottom.m_col + m_top.m_col) / 2;
	center.m_row = (m_bottom.m_row + m_top.m_row) / 2;

	return center;
}

bool Rectangle::scale(double factor)
{
	if (factor < 0) return false;

	Vertex center = getCenter();
	Vertex bottomLeft = m_bottom, topRight = m_top;

	afterFactor(center, bottomLeft, factor);
	afterFactor(center, topRight, factor);

	if (!bottomLeft.isValid() || !topRight.isValid()) return false;

	m_top = topRight;
	m_bottom = bottomLeft;

	return true;
}

void Rectangle::afterFactor(const Vertex& center, Vertex& dot, double factor)
{
	double width = (center.m_col - dot.m_col) * factor;
	double height = (center.m_row - dot.m_row) * factor;

	dot.m_col = center.m_col - width;
	dot.m_row = center.m_row - height;
}

void Rectangle::insertWithDimension(const Vertex& point, double width,
	double height, Vertex& m_bottom, Vertex& m_top, int direction)
{
	if (checkDimension(width, height))
	{
		setData(m_bottom, m_top, COL_BOTTOM_DEFAULT, ROW_BOTTOM_DEFAULT,
			COL_TOP_DEFAULT, ROW_TOP_DEFAULT);
	}

	else
	{
		Vertex secondPoint;
		secondPoint.m_col = point.m_col + width * direction;
		secondPoint.m_row = point.m_row + height * direction;
		setBuild(point, secondPoint, m_bottom, m_top);
	}
}

void Rectangle::setBuild(const Vertex& bottomLeft, const Vertex& topRight,
	Vertex& m_bottom, Vertex& m_top)
{
	if (!bottomLeft.isValid() || !topRight.isValid() ||
		checkNotValidPlace(bottomLeft, topRight))
	{
		setData(m_bottom, m_top, COL_BOTTOM_DEFAULT, ROW_BOTTOM_DEFAULT,
			COL_TOP_DEFAULT, ROW_TOP_DEFAULT);
	}

	else setData(m_bottom, m_top, bottomLeft.m_col, bottomLeft.m_row,
		topRight.m_col, topRight.m_row);
}

bool Rectangle::checkNotValidPlace(const Vertex& bottomLeft, const Vertex& topRight)
{
	return bottomLeft.isHigherThan(topRight) ||
		bottomLeft.isToTheRightOf(topRight);
}

void Rectangle::setData(Vertex& m_bottom, Vertex& m_top, double colLeft, double rowLeft,
	double colRight, double rowRight)
{
	m_bottom.m_col = colLeft;
	m_bottom.m_row = rowLeft;
	m_top.m_col = colRight;
	m_top.m_row = rowRight;
}

bool Rectangle::checkDimension(double width, double height)
{
	if (width < 0 || height < 0)
	{
		return true;
	}

	return false;
}