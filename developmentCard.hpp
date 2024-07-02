#ifndef KINDCARD_HPP
#define KINDCARD_HPP

/* author: elian iluk
email: elian10119@gmail.com
id: 214787483*/

#include "card.hpp"

namespace ariel {
    class DevelopmentCard : public Card {
    public:
        enum DevType { Monopoly, RoadBuilding, YearOfPlenty };

    private:
        DevType devType;

    public:
        DevelopmentCard(DevType type);
        DevType getDevType() const;
        std::string getDevTypeString() const;
    };

    class KnightCard : public Card {
    private:
        static int count;

    public:
        KnightCard();
        static int getCount();
        std::string getDevTypeString() const;
    };

    class VictoryPointCard : public Card {
    private:
        static int count;

    public:
        VictoryPointCard();
        static int getCount();
        std::string getDevTypeString() const;
    };
}

#endif // KINDCARD_HPP
