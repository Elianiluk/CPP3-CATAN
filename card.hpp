// card.hpp
#ifndef CARD_HPP
#define CARD_HPP


#include <iostream>
#include <stdexcept>
#include <vector>
#include <cstdlib>
// #include "catan.hpp"
// #include "player.hpp"
// #include "board.hpp"
#include <string>

namespace ariel {
    class Card {
    protected:
        int value;
        std::string type;

    public:
        Card(int value, std::string type);
        virtual ~Card() = default;
        int getValue() const;
        std::string getType() const;
    };
}

#endif // CARD_HPP