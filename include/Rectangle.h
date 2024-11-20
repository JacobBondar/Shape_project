#pragma once
#include <iostream>
#include "Vertex.h"
#include "Board.h"

//-----Const Section-----------------------------------------------------------
const double COL_BOTTOM_DEFAULT = 20;
const double ROW_BOTTOM_DEFAULT = 10;
const double COL_TOP_DEFAULT = 30;
const double ROW_TOP_DEFAULT = 20;
const int FIRST_INDEX = 0;
const int SECOND_INDEX = 1;

//-----Class Section-----------------------------------------------------------
class Rectangle
{
public:
	Rectangle(const Vertex& bottomLeft, const Vertex& topRight);
	Rectangle(const Vertex vertices[2]);
	Rectangle(double x, double y, double width, double height);
	Rectangle(const Vertex& topRight, double width, double height);
	Vertex getBottomLeft() const;
	Vertex getTopRight() const;
	double getWidth() const;
	double getHeight() const;
	void draw(Board& board) const;
	Rectangle getBoundingRectangle() const;
	double getPerimeter() const;
	double getArea() const;
	Vertex getCenter() const;
	bool scale(double factor);

private:
//-----Members-----------------------------------------------------------------
	Vertex m_bottom = { COL_BOTTOM_DEFAULT, ROW_BOTTOM_DEFAULT };
	Vertex m_top = { COL_TOP_DEFAULT, ROW_TOP_DEFAULT };

//-----Private Functions-------------------------------------------------------
	bool checkNotValidPlace(const Vertex& bottomLeft, const Vertex& topRight);
	void setData(Vertex& m_bottom, Vertex& m_top, double colLeft, double rowLeft,
		double colRight, double rowRight);
	void setBuild(const Vertex& bottomLeft, const Vertex& topRight,
		Vertex& m_bottom, Vertex& m_top);
	bool validDimension(double width, double  height);
	void insertWithDimension(const Vertex& buttomLeft, double width,
		double height, Vertex& m_bottom, Vertex& m_top, int direction);
	void afterFactor(const Vertex& center, Vertex& dot, double factor);
};