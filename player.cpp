#include <iostream>
#include "player.hpp"
#include "board.hpp"
#include <string>
#include <vector>

namespace ariel
{
    Player::Player(std::string name) : 
        name(name),wheat(0),ore(0),brick(0),wood(0),wool(0),settelmentsName({}),settelmentsPosition({}) ,roadsName({}),roadsPosition({}), turn(false),points(0){}

    void Player::placeSettelemnt(std::vector<std::string> places, std::vector<int> placesNum, Board &board)
    {
        if(turn==false){
            throw std::invalid_argument("It's not your turn.");
        }
        if (places.size() != 2 || placesNum.size() != 2)
        {
            throw std::invalid_argument("You must place two settlements.");
        }
        if (board.getTile(places[0], placesNum[0]).getOwner() != "" || board.getTile(places[1], placesNum[1]).getOwner() != "")
        {
            throw std::invalid_argument("One of the places is already taken.");
        }
        settelmentsName.push_back(places[0]);
        settelmentsName.push_back(places[1]);
        settelmentsPosition.push_back(placesNum[0]);
        settelmentsPosition.push_back(placesNum[1]);
        addPoints(2);
        // board.getTile(places[0], placesNum[0]).setOwner(name);
        // board.getTile(places[1], placesNum[1]).setOwner(name);
    }

    void Player::trade(Player other,std::string s1,std::string s2,int amount1,int amount2){
        if(turn==false){
            throw std::invalid_argument("It's not your turn.");
        }
        if(other.getName()==name){
            throw std::invalid_argument("You can't trade with yourself.");
        }
        if(amount1<0 || amount2<0){
            throw std::invalid_argument("You can't trade negative amount.");
        }

        if(s1=="wood"){
            if(wood<amount1){
                throw std::invalid_argument("You don't have enough wood.");
            }
            else
                wood-=amount1;
        }
        if(s1=="ore"){
            if(wood<amount1){
                throw std::invalid_argument("You don't have enough ore.");
            }
            else
                ore-=amount1;
        }
        if(s1=="brick"){
            if(brick<amount1){
                throw std::invalid_argument("You don't have enough brick.");
            }
            else
                brick-=amount1;
        }
        if(s1=="wheat"){
            if(wheat<amount1){
                throw std::invalid_argument("You don't have enough wheat.");
            }
            else
                wheat-=amount1;
        }
        if(s1=="wool"){
            if(wool<amount1){
                throw std::invalid_argument("You don't have enough wool.");
            }
            else
                wool-=amount1;
        }
        if(s2=="wood"){
            if(other.wood<amount2){
                throw std::invalid_argument("The other player doesn't have enough wood.");
            }
            else
                other.wood-=amount2;
        }
        if(s2=="ore"){
            if(other.ore<amount2){
                throw std::invalid_argument("The other player doesn't have enough ore.");
            }
            else
                other.ore-=amount2;
        }
        if(s2=="brick"){
            if(other.brick<amount2){
                throw std::invalid_argument("The other player doesn't have enough brick.");
            }
            else
                other.brick-=amount2;
        }
        if(s2=="wheat"){
            if(other.wheat<amount2){
                throw std::invalid_argument("The other player doesn't have enough wheat.");
            }
            else
                other.wheat-=amount2;
        }
        if(s2=="wool"){
            if(other.wool<amount2){
                throw std::invalid_argument("The other player doesn't have enough wool.");
            }
            else
                other.wool-=amount2;
        }
        std::string tradeDetails="p1 trade "+std::to_string(amount1)+" "+s1+" for "+std::to_string(amount2)+" "+s2+" with p2";
        std::cout << tradeDetails << std::endl;
    }

    std::string Player::getName()
    {
        return name;
    }

    void Player::addPoints(int p)
    {
        points += p;
    }

    void Player::printPoints()
    {
        std::cout << points << std::endl;
    }

    int Player::getPoints()
    {
        return points;
    }

    void Player::placeRoad(std::vector<std::string> places, std::vector<int> placesNum, Board &board)
    {
        if(turn==false){
            throw std::invalid_argument("It's not your turn.");
        }

        if (places.size() != 2 || placesNum.size() != 2)
        {
            throw std::invalid_argument("You must place two roads.");
        }
        if (board.getTile(places[0], placesNum[0]).getOwner() != name || board.getTile(places[1], placesNum[1]).getOwner() != name)
        {
            throw std::invalid_argument("You must place the road near your settlement.");
        }
        roadsName.push_back(places[0]);
        roadsName.push_back(places[1]);
        roadsPosition.push_back(placesNum[0]);
        roadsPosition.push_back(placesNum[1]);
    }

    void Player::changeTurn()
    {
        turn=!turn;
    }

    int Player::rollDice()
    {
        if(turn==false){
            throw std::invalid_argument("It's not your turn.");
        }

        int dice = rand() % 6 + 1 + rand() % 6 + 1;
        //std::cout << dice << std::endl;
        return dice;
    }
} // namespace ariel