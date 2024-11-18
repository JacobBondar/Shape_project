#include "Utilities.h"
#include <cmath>

bool doubleEqual(double a, double b)
{
    return std::abs(a - b) < 0.1;
}

double distance(const Vertex& v1, const Vertex& v2)
{
    return std::hypot(v1.m_col - v2.m_col, v1.m_row - v2.m_row);
}

bool sameCol(const Vertex& v1, const Vertex& v2)
{
    return std::round(v1.m_col) == std::round(v2.m_col);
}

bool sameRow(const Vertex& v1, const Vertex& v2)
{
    return std::round(v1.m_row) == std::round(v2.m_row);
}
