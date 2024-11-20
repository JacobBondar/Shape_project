#pragma once
#include <iostream>
#include "Vertex.h"
#include "Board.h"
#include "Rectangle.h"
#include "Utilities.h"

//-----Const Section-------------------------------------------------------------
const double FIRST_COL_DEFAULT = 20 + sqrt(75);
const double FIRST_ROW_DEFAULT = 25;
const double SECOND_COL_DEFAULT = 20;
const double SECOND_ROW_DEFAULT = 20;
const double THIRD_COL_DEFAULT = 30;
const double THIRD_ROW_DEFAULT = 20;
const int POINTS_IN_TRIANGLE = 3;

//-----Class Section-----------------------------------------------------------
class Triangle
{
public:
	Triangle(const Vertex vertices[POINTS_IN_TRIANGLE]);
	Triangle(Vertex v0, Vertex v1, Vertex v2);
	Vertex getVertex(int index) const;
	double getLength(int index) const;
	void draw(Board& board) const;
	Rectangle getBoundingRectangle() const;
	double getPerimeter() const;
	double getArea() const;
	Vertex getCenter() const;
	bool scale(double factor);

private:
//-----Members-----------------------------------------------------------------
	Vertex m_first = { FIRST_COL_DEFAULT, FIRST_ROW_DEFAULT };
	Vertex m_second = { SECOND_COL_DEFAULT, SECOND_ROW_DEFAULT };
	Vertex m_third = { THIRD_COL_DEFAULT, THIRD_ROW_DEFAULT };

//-----Private Functions-------------------------------------------------------
	void setData(Vertex& m_first, Vertex& m_second,
		Vertex& m_third, double firstCol, double firstRow, double secondCol,
		double secondRow, double thirdCol, double thirdRow);
	void setBuild(const Vertex vertices[POINTS_IN_TRIANGLE], Vertex& m_first,
		Vertex& m_second, Vertex& m_third);
	double calcAvgPoint(double val1, double val2, double val3) const;
	void afterFactor(const Vertex& center, Vertex& dot, double factor);
};