#include "developmentCard.hpp"

namespace ariel
{
    // DevelopmentCard Implementation
    DevelopmentCard::DevelopmentCard(DevType type)
        : Card(0, // someValue
               (type == Monopoly) ? "Monopoly" : (type == RoadBuilding) ? "Road Building"
                                             : (type == YearOfPlenty)   ? "Year of Plenty"
                                                                        : "Unknown"),
          devType(type)
    {
    }

    DevelopmentCard::DevType DevelopmentCard::getDevType() const
    {
        return devType;
    }

    std::string DevelopmentCard::getDevTypeString() const
    {
        switch (devType)
        {
        case Monopoly:
            return "Monopoly";
        case RoadBuilding:
            return "Road Building";
        case YearOfPlenty:
            return "Year of Plenty";
        default:
            return "Unknown";
        }
    }

    // KnightCard Implementation
    int KnightCard::count = 0;

    KnightCard::KnightCard() : Card(0, "Knight")
    {
        ++count;
    }

    int KnightCard::getCount()
    {
        return count;
    }

    std::string KnightCard::getDevTypeString() const
    {
        return "Knight";
    }

    // VictoryPointCard Implementation
    int VictoryPointCard::count = 0;

    VictoryPointCard::VictoryPointCard() : Card(0, "Victory Point")
    {
        ++count;
    }

    int VictoryPointCard::getCount()
    {
        return count;
    }

    std::string VictoryPointCard::getDevTypeString() const
    {
        return "Victory Point";
    }
}
