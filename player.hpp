#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include <string>
#include <vector>
#include "board.hpp"
#include "developmentCard.hpp"
#include <map>
#include <chrono>
#include <random>
#include <algorithm>

/* author: elian iluk
email: elian10119@gmail.com
id: 214787483*/

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
        std::vector<Card*> cards;
        int settelmentCount;
        int cityCount;
        int roadCount;
        int playerID;
        int color;

    public:
        Player(std::string name, int playerID);
        std::string getName();
        void placeSettlement(Board &board, bool firstRound);
        void placeRoad(Board &board, bool firstRound,bool card);
        void placeCity(Board &board);
        void tradeRescources(Player& other);
        void tradeCards(Player& other);
        void addPoints(int p);
        int getPoints();
        void printPoints();
        void changeTurn();
        int rollDice();
        void buyCard();
        void playCard(std::string card,Player& other,Player& other2,Board& board);
        void printResources();
        bool resourcesNumContains(int hexID);
        bool resourcesNameContains(std::string type);
        std::vector<int> getResourcesNum() const;
        void addResource(std::string type,int n);
        int getPlayerID();
        bool getTurn();
        std::string getColor();
        void printCards();
        int numOfResource();
        int getKnightCount();
        void addCard(std::string card);
        void removeCard(std::string card);
        bool hasCard(std::string card);
        int getResource(std::string type);
    };
} // namespace ariel

#endif