#include "developmentCard.hpp"

namespace ariel {
    // DevelopmentCard Implementation
    DevelopmentCard::DevelopmentCard(DevType type) : Card(0, "Development"), devType(type) {}

    DevelopmentCard::DevType DevelopmentCard::getDevType() const {
        return devType;
    }

    std::string DevelopmentCard::getDevTypeString() const {
        switch (devType) {
            case Monopoly: return "Monopoly";
            case RoadBuilding: return "Road Building";
            case YearOfPlenty: return "Year of Plenty";
            default: return "Unknown";
        }
    }

    // KnightCard Implementation
    int KnightCard::count = 0;

    KnightCard::KnightCard() : Card(0, "Knight") {
        ++count;
    }

    int KnightCard::getCount() {
        return count;
    }

    // VictoryPointCard Implementation
    int VictoryPointCard::count = 0;

    VictoryPointCard::VictoryPointCard() : Card(0, "Victory Point") {
        ++count;
    }

    int VictoryPointCard::getCount() {
        return count;
    }
}
