#pragma once
#include "Vertex.h"
#include "Rectangle.h"

const int COL_DEFAULT = 15;
const int ROW_DEFAULT = 25;

class Window
{
public:
    Window(const Rectangle& rectangle, const Vertex& point);
    Window(const Vertex& topRight, double width, double height, const Vertex& point);
    Vertex getBottomLeft() const;
    Vertex getTopRight()const;
    Vertex getPoint() const;
    void draw(Board& board) const;
    Rectangle getBoundingRectangle() const;
    double getPerimeter() const;
    double getArea() const;
    Vertex getCenter() const;

private:
    Vertex m_point;
    Rectangle m_rectangle = { {COL_BOTTOM_DEFAULT, ROW_BOTTOM_DEFAULT} ,
        {COL_TOP_DEFAULT, ROW_TOP_DEFAULT} };
    void setDefault(Vertex& m_point, Rectangle& rectangle);
    void checkingData(Rectangle m_rectangle, Vertex m_point);
    Vertex insertingToArray() const;
    double calculatingPerimeter(Vertex firstDot, Vertex secondDot) const;
};