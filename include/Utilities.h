#pragma once
#include "Vertex.h"

bool doubleEqual(double a, double b);

// Some helper functions for Board::drawLine()
double distance(const Vertex& v1, const Vertex& v2);
bool sameCol(const Vertex& v1, const Vertex& v2);
bool sameRow(const Vertex& v1, const Vertex& v2);
