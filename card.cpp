#include "card.hpp"

namespace ariel {
    Card::Card(int value, std::string type) : value(value), type(type) {}

    int Card::getValue() const {
        return value;
    }

    std::string Card::getType() const {
        return type;
    }
}
