#pragma once

#include "hexagon.hpp"
#include "vertex.hpp"
#include "edge.hpp"
#include <vector>
#include <string>
#include <iostream>

namespace ariel {
    class Board {
    public:
        Board();
        ~Board();
        void createBoard();
        void printBoard() const;
        void createSettlement(int vertexID, int playerID);
        Hexagon* getHexagon(int hexID) const;

    private:
        std::vector<Hexagon*> board;
    };
}
