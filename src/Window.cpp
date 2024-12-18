﻿#include <iostream>
#include "Window.h"

//-----------------------------------------------------------------------------

Window::Window(const Rectangle& rectangle, const Vertex& point)
{
    insertingNewValues(m_rectangle, m_point, rectangle, point);
}

//-----------------------------------------------------------------------------

void Window::insertingNewValues(Rectangle& rectangle, Vertex& point,
    const Rectangle& rectangleCheck, const Vertex& pointCheck)
{
    if (checkingData(rectangleCheck, pointCheck))
    {
        rectangle = rectangleCheck;
        point = pointCheck;
    }
}

//-----------------------------------------------------------------------------

Window::Window(const Vertex& topRight, double width, double height, 
    const Vertex& point)
{
    Vertex newDot = { topRight.m_col - width , topRight.m_row - height };
    Rectangle newRectangle(newDot, topRight);

    insertingNewValues(m_rectangle, m_point, newRectangle, point);

}

//-----------------------------------------------------------------------------

bool Window::checkingData(const Rectangle& rectangle, const Vertex& point)
{
    if (point.isHigherThan(rectangle.getTopRight()) ||
        point.isToTheRightOf(rectangle.getTopRight()) ||
        rectangle.getBottomLeft().isHigherThan(point) ||
        rectangle.getBottomLeft().isToTheRightOf(point))
    {
        return false;
    }

    return true;
}

//-----------------------------------------------------------------------------

Vertex Window::getBottomLeft() const
{
    return m_rectangle.getBottomLeft();
}

//-----------------------------------------------------------------------------

Vertex Window::getTopRight()const
{
    return m_rectangle.getTopRight();
}

//-----------------------------------------------------------------------------

Vertex Window::getPoint() const
{
    return m_point;
}

//-----------------------------------------------------------------------------

void Window::draw(Board& board) const
{
    Vertex top, bottom, right, left;

    insertVertexes(top, bottom, right, left);

    drawExtra(board, top, bottom, right, left);
}

//-----------------------------------------------------------------------------

void Window::insertVertexes(Vertex &top, Vertex &bottom, Vertex &right, 
    Vertex &left) const
{
    top = { m_point.m_col, m_rectangle.getTopRight().m_row };
    bottom = { m_point.m_col, m_rectangle.getBottomLeft().m_row };
    right = { m_rectangle.getTopRight().m_col, m_point.m_row };
    left = { m_rectangle.getBottomLeft().m_col, m_point.m_row };
}

void Window::drawExtra(Board& board, Vertex& top, Vertex& bottom, 
    Vertex& right, Vertex& left) const
{
    board.drawLine(top, bottom);
    board.drawLine(left, right);
    m_rectangle.draw(board);
}

//-----------------------------------------------------------------------------

Rectangle Window::getBoundingRectangle() const
{
    return m_rectangle;
}

//-----------------------------------------------------------------------------

double  Window::getPerimeter() const
{
    return m_rectangle.getPerimeter() * 1.5;
}

//-----------------------------------------------------------------------------

double Window::getArea() const
{
    return m_rectangle.getArea();
}

//-----------------------------------------------------------------------------

Vertex  Window::getCenter() const
{
    return m_point;
}

//-----------------------------------------------------------------------------

bool Window::scale(double factor)
{
    if (factor < 0)
    {
        return false;
    }

    Vertex tempBottom = m_rectangle.getBottomLeft();
    Vertex tempTop = m_rectangle.getTopRight();

    changingWindow(m_point, tempTop, factor);
    changingWindow(m_point, tempBottom, factor);

    Rectangle tempRectangle(tempBottom, tempTop);

    if (checkingData(tempRectangle, m_point) && 
        tempTop.isValid() && tempBottom.isValid())
    {
        m_rectangle = tempRectangle;
        return true;
    }

    return false;
}

//-----------------------------------------------------------------------------

void Window::changingWindow(const Vertex& middleDot, Vertex& dot, 
    double factor)
{
    double width = (middleDot.m_col - dot.m_col) * factor;
    double height = (middleDot.m_row - dot.m_row) * factor;

    dot.m_col = middleDot.m_col - width;
    dot.m_row = middleDot.m_row - height;
}