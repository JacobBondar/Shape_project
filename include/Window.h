#pragma once
#include "Vertex.h"
#include "Rectangle.h"
#include "Utilities.h"

//-----Const Section-----------------------------------------------------------
const int COL_DEFAULT = 15;
const int ROW_DEFAULT = 25;

//-----Class Section-----------------------------------------------------------
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
    bool scale(double factor);

private:
//-----Members-----------------------------------------------------------------
    Vertex m_point = { COL_DEFAULT, ROW_DEFAULT };
    Rectangle m_rectangle = { {COL_BOTTOM_DEFAULT, ROW_BOTTOM_DEFAULT},
        {COL_TOP_DEFAULT, ROW_TOP_DEFAULT} };

//-----Private Functions-------------------------------------------------------
    bool checkingData(const Rectangle& rectangle, const Vertex& point);
    void insertVertexes(Vertex& top, Vertex& bottom, Vertex& right, 
        Vertex& left) const;
    void drawExtra(Board& board, Vertex& top, Vertex& bottom, Vertex& right,
        Vertex& left) const;
    void changingWindow(const Vertex& middleDot, Vertex& dot, double factor);
    void insertingNewValues(Rectangle& rectangle, Vertex& point,
        const Rectangle& rectangleCheck, const Vertex& pointCheck);
};