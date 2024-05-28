#include <iostream>
#include <stdexcept>
#include <vector>
#include <cstdlib>
#include "catan.hpp"
#include "player.hpp"
#include  "card.hpp"

namespace ariel{
    Card:: Card(int value, std::string type) : value(value), type(type)
    {
    }
}