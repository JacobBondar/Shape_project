#pragma once

#include "Vertex.h"
#include "triangle.h"

//-----Class Section-----------------------------------------------------------
class IsoscelesTriangle
{
public:
	IsoscelesTriangle(const Vertex vertices[3]);
	IsoscelesTriangle(const Vertex& left, const Vertex& right, double height);
	Vertex getVertex(int index) const;
	double getLength(int index) const;
	double getHeight() const;
	void draw(Board& board) const;
	Rectangle getBoundingRectangle() const;
	double getPerimeter() const;
	double getArea() const;
	Vertex getCenter() const;
	bool scale(double factor);

private:
//-----Members-----------------------------------------------------------------
	Triangle m_triangle = { {FIRST_COL_DEFAULT, FIRST_ROW_DEFAULT},
	{SECOND_COL_DEFAULT, SECOND_ROW_DEFAULT},
	{THIRD_COL_DEFAULT, THIRD_ROW_DEFAULT} };

//-----Private Functions-------------------------------------------------------
	void setIsoscelesTriangle(const Vertex vertices[]);
	bool validIsoscelesTriangle(const Triangle& triangle);
	Vertex findTop(const Triangle& triangle, double& bottom) const;
	void afterFactor(const Vertex& center, Vertex& dot, double factor);
};