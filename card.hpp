#include <iostream>
#include <stdexcept>
#include <vector>
#include <cstdlib>
#include "catan.hpp"
#include "player.hpp"
#include "board.hpp"

namespace ariel{
    class Card{
    public:
        Card(int value, std::string type);
    private:
        int value;
        std::string type;
    };
}