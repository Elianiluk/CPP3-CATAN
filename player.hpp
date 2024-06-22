#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include <string>
#include <vector>
#include "board.hpp"
#include "developmentCard.hpp"

namespace ariel
{
    class Player
    {
    private:
        std::string name;
        int wood;
        int brick;
        int ore;
        int wheat;
        int wool;
        bool turn;
        int points;
        int knightCount;
        std::vector<int> resourcesNum;
        std::vector<std::string> resourcesName;
        std::vector<Card> cards;
        int settelmentCount;
        int cityCount;
        int roadCount;

    public:
        Player(std::string name);
        std::string getName();
        void placeSettlement(int HexagonNum, int vertexID, Board &board, bool firstRound);
        void placeRoad(int HexagonNum, int edgeID, Board &board, bool firstRound);
        void trade(Player other,std::string,std::string,int amount1,int amount2);
        void addPoints(int p);
        int getPoints();
        void printPoints();
        void changeTurn();
        int rollDice();
        void buyCard();
        void playCard(std::string card,std::string type,std::string type2,Player other,Player other2);
        void printResources();
        bool resourcesNumContains(int hexID);
        bool resourcesNameContains(std::string type);
    };
} // namespace ariel

#endif