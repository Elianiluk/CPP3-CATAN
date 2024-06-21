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
        std::vector<std::string> settelmentsName;
        std::vector<int> settelmentsPosition;
        std::vector<std::string> roadsName;
        std::vector<int> roadsPosition;
        std::vector<Card> cards;

    public:
        Player(std::string name);
        std::string getName();
        void placeSettelemnt(std::vector<std::string> places, std::vector<int> placesNum, Board &board);
        void placeRoad(std::vector<std::string> places, std::vector<int> placesNum, Board &board);
        void trade(Player other,std::string,std::string,int amount1,int amount2);
        void addPoints(int p);
        int getPoints();
        void printPoints();
        void changeTurn();
        int rollDice();
        void buyCard();
        void playCard(std::string card,std::string type,std::string type2,Player other,Player other2);
    };
} // namespace ariel

#endif