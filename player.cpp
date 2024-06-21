#include "player.hpp"

namespace ariel
{
    Player::Player(std::string name)
        : name(name), wood(0), brick(0), ore(0), wheat(0), wool(0), turn(false),
          points(0), knightCount(0), settelmentsName({}), settelmentsPosition({}),
          roadsName({}), roadsPosition({}), cards({}) {}
          
    void Player::placeSettelemnt(std::vector<std::string> places, std::vector<int> placesNum, Board &board)
    {
        if(turn==false){
            throw std::invalid_argument("It's not your turn.");
        }
        if (places.size() != 2 || placesNum.size() != 2)
        {
            throw std::invalid_argument("You must place two settlements.");
        }
        // if (board.getTile(places[0], placesNum[0]).getOwner() != "" || board.getTile(places[1], placesNum[1]).getOwner() != "")
        // {
        //     throw std::invalid_argument("One of the places is already taken.");
        // }
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
        // if (board.getTile(places[0], placesNum[0]).getOwner() != name || board.getTile(places[1], placesNum[1]).getOwner() != name)
        // {
        //     throw std::invalid_argument("You must place the road near your settlement.");
        // }
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

    void Player::buyCard() {
        if (turn == false) {
            throw std::invalid_argument("It's not your turn.");
        }

        // Cost of a development card: 1 wheat, 1 ore, 1 wool
        if (wheat < 1 || ore < 1 || wool < 1) {
            throw std::invalid_argument("You don't have enough resources to buy a development card.");
        }

        // Randomly choose a card
        std::string names[5] = {"Monopoly", "Road Building", "Year of Plenty", "Knight", "Victory Point"};
        int randIndex = rand() % 5;
        std::string cardName = names[randIndex]; // cardName = names[rand() % 5


        // Deduct the resources
        wheat -= 1;
        ore -= 1;
        wool -= 1;

        // Create the card based on the cardName
        if (cardName == "Monopoly") {
            DevelopmentCard card(DevelopmentCard::Monopoly);
            cards.push_back(card);
        } else if (cardName == "Road Building") {
            DevelopmentCard card(DevelopmentCard::RoadBuilding);
            cards.push_back(card);
        } else if (cardName == "Year of Plenty") {
            DevelopmentCard card(DevelopmentCard::YearOfPlenty);
            cards.push_back(card);
        } else if (cardName == "Knight") {
            if (KnightCard::getCount() >= 3) {
                throw std::runtime_error("Cannot create more than 3 Knight Cards.");
            }
            KnightCard card;
            knightCount++;
            cards.push_back(card);
        } else if (cardName == "Victory Poines") {
            VictoryPointCard card;
            cards.push_back(card);
        } else {
            throw std::invalid_argument("Invalid card name.");
        }

        std::cout << name << " bought a " << cardName << " card." << std::endl;
    }

    void Player::playCard(std::string cardType,std::string type,std::string type2,Player other1,Player other2) {
        if (turn == false) {
            throw std::invalid_argument("It's not your turn.");
        }

        if (cards.size() == 0) {
            throw std::invalid_argument("You don't have any cards to play.");
        }

        if(cardType!="Monopoly" && cardType!="Road Building" && cardType!="Year of Plenty" && cardType!="Knight" && cardType!="Victory Point"){
            throw std::invalid_argument("Invalid card type.");
        }

        if(cardType=="Knight" && knightCount==0){
            throw std::invalid_argument("You don't have any Knight cards.");
        }

        if(cardType=="Monopoly"){
            bool monopoly=false;
            for(unsigned long i=0;i<cards.size();i++){
                if(cards[i].getType()=="Monopoly"){
                    monopoly=true;
                    break;
                }
            }
            if(monopoly==false){
                throw std::invalid_argument("You don't have any Monopoly cards.");
            }
        }

        if(cardType=="Road Building"){
            bool roadBuilding=false;
            for(unsigned long i=0;i<cards.size();i++){
                if(cards[i].getType()=="Road Building"){
                    roadBuilding=true;
                    break;
                }
            }
            if(roadBuilding==false){
                throw std::invalid_argument("You don't have any Road Building cards.");
            }
        }

        if(cardType=="Year of Plenty"){
            bool yearOfPlenty=false;
            for(unsigned long i=0;i<cards.size();i++){
                if(cards[i].getType()=="Year of Plenty"){
                    yearOfPlenty=true;
                    break;
                }
            }
            if(yearOfPlenty==false){
                throw std::invalid_argument("You don't have any Year of Plenty cards.");
            }
        }

        if(cardType=="Victory Point"){
            bool victoryPoint=false;
            for(unsigned long i=0;i<cards.size();i++){
                if(cards[i].getType()=="Victory Point"){
                    victoryPoint=true;
                    break;
                }
            }
            if(victoryPoint==false){
                throw std::invalid_argument("You don't have any Victory Point cards.");
            }
        }

        if(cardType=="Knight"){
            bool knight=false;
            for(unsigned long i=0;i<cards.size();i++){
                if(cards[i].getType()=="Knight"){
                    knight=true;
                    break;
                }
            }
            if(knight==false){
                throw std::invalid_argument("You don't have any Knight cards.");
            }
        }

        int inedx=0;
        for(unsigned long i=0;i<cards.size();i++){
            if(cards[i].getType()==cardType){
                inedx=i;
                break;
            }
        }

        if (cardType == "Monopoly") {
            std::cout << name << " played a Monopoly card." << std::endl;
            if(type=="wood"){
                wood++;
                other1.wood--;
                other2.wood--;
            }
            if(type=="ore"){
                ore++;
                other1.ore--;
                other2.ore--;
            }
            if(type=="brick"){
                brick++;
                other1.brick--;
                other2.brick--;
            }
            if(type=="wheat"){
                wheat++;
                other1.wheat--;
                other2.wheat--;
            }
            if(type=="wool"){
                wool++;
                other1.wool--;
                other2.wool--;
            }
        } else if (cardType == "Road Building") {
            std::cout << name << " played a Road Building card." << std::endl;
        } else if (cardType == "Year of Plenty") {
            std::cout << name << " played a Year of Plenty card." << std::endl;
            if(type2=="wood" || type=="wood"){
                wood++;
            }
            if(type2=="ore" || type=="ore"){
                ore++;
            }
            if(type2=="brick" || type=="brick"){
                brick++;
            }
            if(type2=="wheat" || type=="wheat"){
                wheat++;
            }
            if(type2=="wool" || type=="wool"){
                wool++;
            }
        // } else if (cardType == "Knight") {
        //     std::cout << name << " played a Knight card." << std::endl;
        } else if (cardType == "Victory Point") {
            std::cout << name << " played a Victory Point card." << std::endl;
            addPoints(1);
        } else {
            throw std::invalid_argument("Invalid card type.");
        }
        cards.erase(cards.begin() + inedx);
    }
} // namespace ariel