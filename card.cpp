#include "card.hpp"

/* author: elian iluk
email: elian10119@gmail.com
id: 214787483*/

namespace ariel {
    Card::Card(int value, std::string type) : value(value), type(type) {}

    int Card::getValue() const {
        return value;
    }

    std::string Card::getType() const {
        return type;
    }
}
