#include <iostream>
#include <stdexcept>
#include <vector>
#include "catan.hpp"
#include "player.hpp"

namespace ariel{
    class Board{
    public:
        Board();
    private:
        std::vector<std::vector<std::string>> board;
    };
}