#include <iostream>
#include "Window.h"

Window::Window(const Rectangle& rectangle, const Vertex& point)
{
	m_rectangle = rectangle;
	m_point = point;

	checkingData(m_rectangle, m_point);
}
//------------------------------------
void Window::setDefault(Vertex& m_point, Rectangle& rectangle)
{
	Rectangle rectangleNew({ COL_BOTTOM_DEFAULT, ROW_BOTTOM_DEFAULT }, { COL_TOP_DEFAULT  , ROW_TOP_DEFAULT });
	rectangle = rectangleNew;
	m_point = { COL_DEFAULT  , ROW_DEFAULT };
}
//----------------------------------
Window::Window(const Vertex& topRight, double width, double height, const Vertex& point)
{
	Vertex newDot = { topRight.m_col - width , topRight.m_row - height };
	Rectangle newRectangle({ newDot, topRight });

	m_point = point;

	checkingData(m_rectangle, m_point);
}
//-------------------------------------------
void Window::checkingData(Rectangle m_rectangle, Vertex m_point)
{
	if (m_point.isHigherThan(m_rectangle.getTopRight()) ||
		m_point.isToTheRightOf(m_rectangle.getTopRight()) ||
		m_rectangle.getBottomLeft().isHigherThan(m_point) ||
		m_rectangle.getBottomLeft().isToTheRightOf(m_point))
	{
		setDefault(m_point, m_rectangle);
	}
}
//-------------------------------------------
Vertex Window::getBottomLeft() const
{
	return m_rectangle.getBottomLeft();
}
//--------------------------------------------
Vertex Window::getTopRight()const
{
	return m_rectangle.getTopRight();
}
//------------------------------------------
Vertex Window::getPoint() const
{
	return m_point;
}

void Window::draw(Board& board) const
{

	Vertex dots[4];

	dots[4] = insertingToArray();


	for (int index = 0; index < 4; index++)
	{
		board.drawLine(m_point, dots[index]);
	}

	m_rectangle.draw(board);
}
//-----------------------------------------
Vertex Window::insertingToArray() const
{
	Vertex dots[4];
	Vertex tempDown = m_rectangle.getBottomLeft();
	Vertex tempUp = m_rectangle.getTopRight();

	dots[0].m_col = dots[1].m_col = m_point.m_col;
	dots[0].m_row = tempUp.m_row;
	dots[1].m_row = tempDown.m_row;
	dots[2].m_row = dots[3].m_row = m_point.m_row;
	dots[3].m_col = tempDown.m_col;
	dots[2].m_col = tempUp.m_col;
	return dots[4];
}
//-----------------------------------------
Rectangle Window::getBoundingRectangle() const
{
	return m_rectangle;
}
//---------------------------------------
double  Window::getPerimeter() const
{
	double perimeter = 0.0;
	Vertex dots[4];
	dots[4] = insertingToArray();
	perimeter += calculatingPerimeter(m_point, m_rectangle.getTopRight());
	perimeter += calculatingPerimeter(m_rectangle.getBottomLeft(), m_point);
	perimeter += calculatingPerimeter(dots[1], dots[2]);
	perimeter += calculatingPerimeter(dots[3], dots[0]);
	perimeter += m_rectangle.getPerimeter();
	return perimeter;

}
//----------------------------------
double Window::calculatingPerimeter(Vertex firstDot, Vertex secondDot) const
{
	double perimeterX = 0.0, perimeterY = 0.0;
	perimeterX = secondDot.m_col - firstDot.m_col;
	perimeterY = secondDot.m_row - firstDot.m_row;
	perimeterX *= 2;
	perimeterY *= 2;

	return perimeterX + perimeterY;
}
//--------------------------------------------
double Window::getArea() const
{
	//זה הכוונה או למשהו אחר?
	return m_rectangle.getArea();
}
//-------------------------------------------
Vertex  Window::getCenter() const
{
	return m_point;
}
//------------------------------------------
bool scale(double factor)
{

}