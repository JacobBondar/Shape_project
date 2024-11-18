#include "Board.h"

#include <iostream>
#include <algorithm>
#include <cmath>

#include "macros.h"
#include "Utilities.h"

namespace
{
    const auto FILL = '*';
    const auto EMPTY = ' ';
}

Board::Board() : m_paintBoard(MAX_ROW + 1, std::string(MAX_COL + 1, EMPTY))
{
}

void Board::clear()
{
    *this = Board();
}

void Board::print()
{
    const auto separator = std::string(MAX_COL, '=');

    std::cout << separator << '\n';

    // Print the rows in descending order to get row 0 at the bottom
    for (auto it = m_paintBoard.rbegin(); it != m_paintBoard.rend(); ++it)
    {
        std::cout << *it << '\n';
    }

    std::cout << separator << '\n';
}

void Board::drawLine(const Vertex& v1, const Vertex& v2)
{
    if (!v1.isValid() || !v2.isValid())
    {
        return;
    }

    if (sameCol(v1, v2)) // parallel to the y axis
    {
        const auto rowStart = static_cast<int>(std::round(std::min(v1.m_row, v2.m_row)));
        const auto rowEnd = static_cast<int>(std::round(std::max(v1.m_row, v2.m_row)));
        const auto col = static_cast<int>(std::round(v2.m_col));
        for (auto row = rowStart; row <= rowEnd; ++row)
        {
            m_paintBoard[row][col] = FILL;
        }
        return;
    }

    if (sameRow(v1, v2)) // parallel to the x axis
    {
        const auto colStart = static_cast<int>(std::round(std::min(v1.m_col, v2.m_col)));
        const auto colEnd = static_cast<int>(std::round(std::max(v1.m_col, v2.m_col)));
        const auto row = static_cast<int>(std::round(v2.m_row));
        for (auto col = colStart; col <= colEnd; ++col)
        {
            m_paintBoard[row][col] = FILL;
        }
        return;
    }

    // use DDA algorithm to draw
    auto dRow = v2.m_row - v1.m_row;
    auto dCol = v2.m_col - v1.m_col;
    const auto step = std::max(std::abs(dRow), std::abs(dCol));
    dRow /= step;
    dCol /= step;
    for (auto [row, col, curStep] = std::make_tuple(v1.m_row, v1.m_col, 1);
        curStep <= step;
        row += dRow, col += dCol, ++curStep)
    {
        m_paintBoard[static_cast<int>(std::round(row))][static_cast<int>(std::round(col))] = FILL;
    }
}
