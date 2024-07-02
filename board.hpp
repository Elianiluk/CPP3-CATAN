#pragma once

#include "hexagon.hpp"
#include "vertex.hpp"
#include "edge.hpp"
#include <vector>
#include <string>
#include <iostream>

/* author: elian iluk
email: elian10119@gmail.com
id: 214787483*/

namespace ariel {
    class Board {
    public:
        Board();
        ~Board();
        void createBoard();
        void printBoard() const;
        void createSettlement(int vertexID, int playerID);
        Hexagon* getHexagon(int hexID) const;
        std::vector<Hexagon*> getRelevantHexagons(int roll) const;
        void displayBoard();

    private:
        std::vector<Hexagon*> board;
    };
}
