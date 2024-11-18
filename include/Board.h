#pragma once

#include <vector>
#include <string>

#include "Vertex.h"

class Board
{
public:
    Board();

    /*
     * Empties the board
     */
    void clear();

    /*
     * Prints the current board to the console
     */
    void print();

    /*
     * Adds the given line to the board. If one of the argument
     * isn't valid, draws nothing
     *
     * Arguments: v1, v2 - the two ends of the line
     */
    void drawLine(const Vertex& v1, const Vertex& v2);

private:
    std::vector<std::string> m_paintBoard;
};
