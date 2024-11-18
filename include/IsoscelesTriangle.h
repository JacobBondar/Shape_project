#pragma once

#include "Vertex.h"
#include "triangle.h"

class IsoscelesTriangle
{
public:
	IsoscelesTriangle(const Vertex vertices[3]);
	IsoscelesTriangle(const Vertex& left, const Vertex& right, double height);
	Vertex getVertex(int index) const;
	double getLength(int index) const;
	double getHeight() const;

private:
	Triangle m_triangle = { {FIRST_COL_DEFAULT, FIRST_ROW_DEFAULT},
	{SECOND_COL_DEFAULT, SECOND_ROW_DEFAULT},
	{THIRD_COL_DEFAULT, THIRD_ROW_DEFAULT} };

	void setIsoTriangle(const Vertex vertices[]);
	bool validIsoscelesTriangle(const Triangle& triangle);
};