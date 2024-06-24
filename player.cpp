#include "player.hpp"

namespace ariel
{
    Player::Player(std::string name, int playerID)
        : name(name), wood(0), brick(0), ore(0), wheat(0), wool(0), turn(false),
          points(0), knightCount(0), resourcesNum({}), resourcesName({}), cards({}), settelmentCount(0), cityCount(0), roadCount(0), playerID(playerID)
    {
        if (playerID == 0)
            color = 1;
        if (playerID == 1)
            color = 2;
        if (playerID == 2)
            color = 3;
    }

    std::string Player::getColor()
    {
        if (playerID == 0)
            return "\033[1;31m";
        if (playerID == 1)
            return "\033[1;34m";
        if (playerID == 2)
            return "\033[1;32m";
        return "\033[1;37m";
    }

    int Player::getKnightCount()
    {
        return knightCount;
    }

    int Player::getPlayerID()
    {
        return playerID;
    }
    void Player::placeSettlement(Board &board, bool firstRound)
    {
        int HexagonNum;
        int vertexID;
        std::cout << "Enter the hexagon number and vertex ID for building a settelment: ";
        std::cin >> HexagonNum >> vertexID;

        if (turn == false)
        {
            std::cout << ("It's not your turn.") << std::endl;
        }
        if (vertexID < 0 || vertexID > 5)
        {
            std::cout << ("Invalid vertex ID.") << std::endl;
            std::cout << "try again" << std::endl;
            placeSettlement(board, firstRound);
            return;
        }
        if (HexagonNum < 0 || HexagonNum > 18)
        {
            std::cout << ("Invalid hexagon number.") << std::endl;
            std::cout << "try again" << std::endl;
            placeSettlement(board, firstRound);
            return;
        }

        Hexagon *hex = board.getHexagon(HexagonNum); // Assuming Board has a getHexagon method
        if (!hex)
        {
            std::cout << ("Hexagon not found.") << std::endl;
            std::cout << "try again" << std::endl;
            placeSettlement(board, firstRound);
            return;
        }

        Vertex *vertex = hex->getVertex(vertexID);
        if (!vertex)
        {
            std::cout << ("Vertex not found.") << std::endl;
            std::cout << "try again" << std::endl;
            placeSettlement(board, firstRound);
            return;
        }

        std::vector<Vertex *> vertices = vertex->getNeighbors();
        for (Vertex *v : vertices)
        {
            if (!v)
                continue;
            if (v->hasSettlement())
            {
                std::cout << ("Cannot place a settlement next to another settlement.") << std::endl;
                std::cout << "try again" << std::endl;
                placeSettlement(board, firstRound);
                return;
            }
        }

        if (vertex->hasSettlement())
        {
            std::cout << "Vertex " << vertexID << " already has a settlement." << std::endl;
            std::cout << "try again" << std::endl;
            placeSettlement(board, firstRound);
            return;
        }

        if (!firstRound)
        {
            if (wood == 0 || brick == 0 || wool == 0 || wheat == 0)
            {
                std::cout << ("You don't have enough resources to build a settlement.") << std::endl;
                return;
            }
            wood--;
            brick--;
            wool--;
            wheat--;
        }

        vertex->setSettlement(playerID);
        std::cout << "Settlement created at vertex " << vertex->getNum() << " for " << name << "." << std::endl;
        addPoints(1);

        if (!firstRound)
            return;

        // Add resources
        std::vector<int> resources = vertex->getHexagons();
        for (int hexID : resources)
        {
            if (!resourcesNumContains(hexID) || !resourcesNameContains(board.getHexagon(hexID)->getType()))
            {
                resourcesNum.push_back(hexID);
                resourcesName.push_back(board.getHexagon(hexID)->getType());
            }
            Hexagon *hex = board.getHexagon(hexID);
            if (!hex)
            {
                std::cout << ("Hexagon not found.") << std::endl;
                return;
            }
            std::cout << "Hexagon " << hexID << " has " << hex->getType() << " resources." << "with hexId:" << hexID << "name:" << hex->getName() << std::endl;
            std::string type = hex->getType();
            if (type == "wood")
            {
                wood++;
            }
            else if (type == "ore")
            {
                ore++;
            }
            else if (type == "brick")
            {
                brick++;
            }
            else if (type == "wheat")
            {
                wheat++;
            }
            else if (type == "wool")
            {
                wool++;
            }
        }
        settelmentCount++;
    }

    void Player::placeRoad(Board &board, bool firstRound, bool card)
    {
        int HexagonNum;
        int edgeID;
        std::cout << "Enter the hexagon number and edge ID for building a road: ";
        std::cin >> HexagonNum >> edgeID;

        if (turn == false)
        {
            std::cout << ("It's not your turn.") << std::endl;
            return;
        }
        if (edgeID < 0 || edgeID > 5)
        {
            std::cout << ("Invalid edge ID.") << std::endl;
            std::cout << "try again" << std::endl;
            placeRoad(board, firstRound, card);
            return;
        }
        if (HexagonNum < 0 || HexagonNum > 18)
        {
            std::cout << ("Invalid hexagon number.") << std::endl;
            std::cout << "try again" << std::endl;
            placeRoad(board, firstRound, card);
            return;
        }

        Hexagon *hex = board.getHexagon(HexagonNum); // Assuming Board has a getHexagon method
        if (!hex)
        {
            std::cout << ("Hexagon not found.") << std::endl;
            std::cout << "try again" << std::endl;
            placeRoad(board, firstRound, card);
            return;
        }

        Edge *edge = hex->getEdge(edgeID);
        if (!edge)
        {
            std::cout << ("Edge not found.") << std::endl;
            std::cout << "try again" << std::endl;
            placeRoad(board, firstRound, card);
            return;
        }

        std::vector<Edge *> edges = edge->getNeighbors();
        for (Edge *e : edges)
        {
            if (!e)
                continue;
            if (e->hasRoad())
            {
                std::cout << ("Cannot place a road next to another road.") << std::endl;
                std::cout << "try again" << std::endl;
                placeRoad(board, firstRound, card);
                return;
            }
        }

        Vertex *vertex1 = edge->getVertex1();
        Vertex *vertex2 = edge->getVertex2();

        if (!vertex1->hasSettlement() && !vertex2->hasSettlement())
        {
            std::cout << ("Cannot place a road without a settlement.") << std::endl;
            std::cout << "try again" << std::endl;
            placeRoad(board, firstRound, card);
            return;
        }

        if (edge->hasRoad())
        {
            std::cout << "Edge " << edgeID << " already has a road." << std::endl;
            std::cout << "try again" << std::endl;
            placeRoad(board, firstRound, card);
            return;
        }

        if (!firstRound && !card)
        {
            if (wood == 0 || brick == 0)
            {
                std::cout << ("You don't have enough resources to build a road.") << std::endl;
                return;
            }
            wood--;
            brick--;
        }

        edge->setRoad(playerID);
        std::cout << "Road created at edge " << edge->getNum() << " for " << name << "." << std::endl;

        if (!firstRound || card)
            return;

        std::vector<int> resources = edge->getHexagons();
        for (int hexID : resources)
        {
            if (!resourcesNumContains(hexID) || !resourcesNameContains(board.getHexagon(hexID)->getType()))
            {
                resourcesNum.push_back(hexID);
                resourcesName.push_back(board.getHexagon(hexID)->getType());
            }
            Hexagon *hex = board.getHexagon(hexID);
            if (!hex)
            {
                std::cout << ("Hexagon not found.") << std::endl;
                return;
            }
            std::cout << "Hexagon " << hexID << " has " << hex->getType() << " resources." << "with hexId:" << hexID << "name:" << hex->getName() << std::endl;
            std::string type = hex->getType();
            if (type == "wood")
            {
                wood++;
            }
            else if (type == "ore")
            {
                ore++;
            }
            else if (type == "brick")
            {
                brick++;
            }
            else if (type == "wheat")
            {
                wheat++;
            }
            else if (type == "wool")
            {
                wool++;
            }
        }
        roadCount++;
    }

    void Player::placeCity(Board &board)
    {
        if (wheat < 2 || ore < 3)
        {
            std::cout << ("You don't have enough resources to build a city.") << std::endl;
            return;
        }
        if (turn == false)
        {
            std::cout << ("It's not your turn.") << std::endl;
            return;
        }

        int HexagonNum;
        int vertexID;
        std::cout << "Enter the hexagon number and vertex ID for building a city: ";
        std::cin >> HexagonNum >> vertexID;

        if (vertexID < 0 || vertexID > 5)
        {
            std::cout << ("Invalid vertex ID.") << std::endl;
            std::cout << "try again" << std::endl;
            placeCity(board);
            return;
        }
        if (HexagonNum < 0 || HexagonNum > 18)
        {
            std::cout << ("Invalid hexagon number.") << std::endl;
            std::cout << "try again" << std::endl;
            placeCity(board);
            return;
        }

        Hexagon *hex = board.getHexagon(HexagonNum); // Assuming Board has a getHexagon method
        if (!hex)
        {
            std::cout << ("Hexagon not found.") << std::endl;
            std::cout << "try again" << std::endl;
            placeCity(board);
            return;
        }

        Vertex *vertex = hex->getVertex(vertexID);
        if (!vertex)
        {
            std::cout << ("Vertex not found.") << std::endl;
            std::cout << "try again" << std::endl;
            placeCity(board);
            return;
        }

        if (!vertex->hasSettlement())
        {
            std::cout << ("Cannot place a city without a settlement.") << std::endl;
            std::cout << "try again" << std::endl;
            placeCity(board);
            return;
        }

        if (vertex->hasCity())
        {
            std::cout << "Vertex " << vertexID << " already has a city." << std::endl;
            std::cout << "try again" << std::endl;
            placeCity(board);
            return;
        }
        if (brick < 3 || wheat < 2)
        {
            std::cout << ("You don't have enough resources to build a settlement.") << std::endl;
            return;
        }
        else
        {
            brick -= 3;
            wheat -= 2;
        }

        vertex->setCity();
        std::cout << "City created at vertex " << vertex->getNum() << " for " << name << "." << std::endl;
        addPoints(-1);
        addPoints(2);
        cityCount++;
        settelmentCount--;

        std::vector<int> resources = vertex->getHexagons();
        for (int hexID : resources)
        {
            if (!resourcesNumContains(hexID) || !resourcesNameContains(board.getHexagon(hexID)->getType()))
            {
                resourcesNum.push_back(hexID);
                resourcesName.push_back(board.getHexagon(hexID)->getType());
            }
        }
    }

    bool Player::resourcesNumContains(int hexID)
    {
        for (size_t i = 0; i < resourcesNum.size(); i++)
        {
            if (resourcesNum[i] == hexID)
            {
                return true;
            }
        }
        return false;
    }

    bool Player::resourcesNameContains(std::string type)
    {
        for (size_t i = 0; i < resourcesName.size(); i++)
        {
            if (resourcesName[i] == type)
            {
                return true;
            }
        }
        return false;
    }

    void Player::tradeRescources(Player &other)
    {
        std::map<std::string, int> offer;
        std::map<std::string, int> request;

        int numItems;
        std::string resource;
        int quantity;

        std::cout << name << ", what do you want to offer?" << std::endl;
        std::cout << "How many different resources are you offering? ";
        std::cin >> numItems;

        for (int i = 0; i < numItems; ++i)
        {
            std::cout << "Enter resource and quantity (e.g., wood 2): ";
            std::cin >> resource >> quantity;
            offer[resource] = quantity;
        }

        std::cout << name << ", what do you want in return?" << std::endl;
        std::cout << "How many different resources are you requesting? ";
        std::cin >> numItems;

        for (int i = 0; i < numItems; ++i)
        {
            std::cout << "Enter resource and quantity (e.g., brick 1): ";
            std::cin >> resource >> quantity;
            request[resource] = quantity;
        }

        std::cout << other.getName() << ", do you accept this trade? (yes/no): ";
        std::string response;
        std::cin >> response;

        if (response == "yes")
        {
            // Check if the current player has enough resources to offer
            for (const auto &item : offer)
            {
                if ((item.first == "wood" && wood < item.second) ||
                    (item.first == "brick" && brick < item.second) ||
                    (item.first == "ore" && ore < item.second) ||
                    (item.first == "wheat" && wheat < item.second) ||
                    (item.first == "wool" && wool < item.second))
                {
                    std::cout << "Trade failed: " << name << " does not have enough " << item.first << "." << std::endl;
                    return;
                }
            }

            // Check if the other player has enough resources to fulfill the request
            for (const auto &item : request)
            {
                if ((item.first == "wood" && other.wood < item.second) ||
                    (item.first == "brick" && other.brick < item.second) ||
                    (item.first == "ore" && other.ore < item.second) ||
                    (item.first == "wheat" && other.wheat < item.second) ||
                    (item.first == "wool" && other.wool < item.second))
                {
                    std::cout << "Trade failed: " << other.getName() << " does not have enough " << item.first << "." << std::endl;
                    return;
                }
            }

            // Execute the trade
            for (const auto &item : offer)
            {
                if (item.first == "wood")
                {
                    wood -= item.second;
                    other.wood += item.second;
                }
                else if (item.first == "brick")
                {
                    brick -= item.second;
                    other.brick += item.second;
                }
                else if (item.first == "ore")
                {
                    ore -= item.second;
                    other.ore += item.second;
                }
                else if (item.first == "wheat")
                {
                    wheat -= item.second;
                    other.wheat += item.second;
                }
                else if (item.first == "wool")
                {
                    wool -= item.second;
                    other.wool += item.second;
                }
            }

            for (const auto &item : request)
            {
                if (item.first == "wood")
                {
                    other.wood -= item.second;
                    wood += item.second;
                }
                else if (item.first == "brick")
                {
                    other.brick -= item.second;
                    brick += item.second;
                }
                else if (item.first == "ore")
                {
                    other.ore -= item.second;
                    ore += item.second;
                }
                else if (item.first == "wheat")
                {
                    other.wheat -= item.second;
                    wheat += item.second;
                }
                else if (item.first == "wool")
                {
                    other.wool -= item.second;
                    wool += item.second;
                }
            }

            std::cout << "Trade successful!" << std::endl;
        }
        else
        {
            std::cout << "Trade declined." << std::endl;
        }
    }

    void Player::tradeCards(Player &other)
    {
        std::string card1T, card2T;
        std::string card1, card2;

        std::cout << name << ", enter the name of the card you want to give:";
        std::cin >> card1T;
        // std::getline(std::cin, card1);
        if(card1T=="Monopoly")
            card1="Monopoly";
        if(card1T=="Road")
            card1="Road Building";
        if(card1T=="Year")
            card1="Year of Plenty";
        if(card1T=="Knight")
            card1="Knight";
        if(card1T=="Victory")
            card1="Victory Point";
        

        std::cout << name << ", enter the name of the card you want to get:" << std::endl;
        std::cin >> card2T;
        // std::getline(std::cin, card2);
        if(card2T=="Monopoly")
            card2="Monopoly";
        if(card2T=="Road")
            card2="Road Building";
        if(card2T=="Year")
            card2="Year of Plenty";
        if(card2T=="Knight")
            card2="Knight";
        if(card2T=="Victory")
            card2="Victory Point";

        if (!hasCard(card1))
        {
            std::cout << name << " does not have the card: " << card1 << std::endl;
            return;
        }

        if (!other.hasCard(card2))
        {
            std::cout << other.getName() << " does not have the card: " << card2 << std::endl;
            return;
        }

        std::cout << other.getName() << ", do you accept the trade? (" << name << "'s " << card1 << " for your " << card2 << ") (yes/no): ";
        std::string response;
        std::cin >> response;

        if (response == "yes")
        {
            removeCard(card1);
            other.removeCard(card2);
            addCard(card2);
            other.addCard(card1);

            std::cout << "Trade successful!" << name << " traded " << card1 << " with " << other.getName() << " for " << card2 << std::endl;
        }
        else
        {
            std::cout << other.getName() << " declined the trade." << std::endl;
        }
    }

    std::string Player::getName()
    {
        return name;
    }

    void Player::addPoints(int p)
    {
        points += p;
    }

    void Player::addCard(std::string card)
    {
        if (card == "Monopoly")
            cards.push_back(new ariel::DevelopmentCard(ariel::DevelopmentCard::Monopoly));
        else if (card == "Road Building")
            cards.push_back(new ariel::DevelopmentCard(ariel::DevelopmentCard::RoadBuilding));
        else if (card == "Year of Plenty")
            cards.push_back(new ariel::DevelopmentCard(ariel::DevelopmentCard::YearOfPlenty));
        else if (card == "Knight")
            cards.push_back(new ariel::KnightCard());
        else if (card == "Victory Point")
            cards.push_back(new ariel::VictoryPointCard());
        else
            std::cout << "Invalid card name." << std::endl;
    }

    void Player::removeCard(std::string card)
    {
        for (unsigned long i = 0; i < cards.size(); i++)
        {
            if (cards[i]->getType() == card)
            {
                cards.erase(cards.begin() + i);
                return;
            }
        }
        std::cout << "Card not found." << std::endl;
    }

    bool Player::hasCard(std::string card)
    {
        for (unsigned long i = 0; i < cards.size(); i++)
        {
            if (cards[i]->getType() == card)
            {
                return true;
            }
        }
        return false;
    }

    void Player::printPoints()
    {
        std::cout << points << std::endl;
    }

    int Player::getPoints()
    {
        return points;
    }

    void Player::changeTurn()
    {
        turn = !turn;
        if (turn == true)
        {
            std::cout << name << "'s turn" << std::endl;
        }
        else
        {
            std::cout << name << "'s turn ended" << std::endl;
        }
        if (points >= 10)
        {
            std::cout << name << " wins!" << std::endl;
            exit(0);
        }
        // std::cout << "there is no winner yet" << std::endl;
    }

    int Player::rollDice()
    {
        std::vector<int> dices = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::shuffle(dices.begin(), dices.end(), std::default_random_engine(seed));
        std::cout << dices[0] << std::endl;
        return dices[0];
        // return 12;
    }

    void Player::buyCard()
    {
        if (turn == false)
        {
            std::cout << "It's not your turn." << std::endl;
            return;
        }

        // Cost of a development card: 1 wheat, 1 ore, 1 wool
        if (wheat < 1 || ore < 1 || wool < 1)
        {
            std::cout << "You don't have enough resources to buy a development card." << std::endl;
            return;
        }

        // Randomly choose a card
        std::vector<std::string> names = {"Monopoly", "Road Building", "Year of Plenty", "Knight", "Victory Point"};
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::shuffle(names.begin(), names.end(), std::default_random_engine(seed));
        std::shuffle(names.begin(), names.end(), std::default_random_engine(seed));

        // int randIndex = rand() % 5;
        // std::string cardName = names[randIndex];
        std::string cardName = names[0];

        // Deduct the resources
        wheat -= 1;
        ore -= 1;
        wool -= 1;

        // Create the card based on the cardName and add to the player's cards
        if (cardName == "Monopoly")
        {
            cards.push_back(new ariel::DevelopmentCard(ariel::DevelopmentCard::Monopoly));
        }
        else if (cardName == "Road Building")
        {
            cards.push_back(new ariel::DevelopmentCard(ariel::DevelopmentCard::RoadBuilding));
        }
        else if (cardName == "Year of Plenty")
        {
            cards.push_back(new ariel::DevelopmentCard(ariel::DevelopmentCard::YearOfPlenty));
        }
        else if (cardName == "Knight")
        {
            cards.push_back(new ariel::KnightCard());
            knightCount++;
        }
        else if (cardName == "Victory Point")
        {
            cards.push_back(new ariel::VictoryPointCard());
        }
        else
        {
            std::cout << "Invalid card name." << std::endl;
            return;
        }

        std::cout << name << " bought a " << cardName << " card." << std::endl;
    }

    void Player::playCard(std::string cardType, Player &other1, Player &other2, Board &board)
    {
        if (turn == false)
        {
            std::cout << ("It's not your turn.") << std::endl;
            return;
        }

        if (cards.size() == 0)
        {
            std::cout << ("You don't have any cards to play.") << std::endl;
            return;
        }

        if (cardType != "Monopoly" && cardType != "Road" && cardType != "Year" && cardType != "Knight" && cardType != "Victory")
        {
            std::cout << ("Invalid card type.") << std::endl;
            return;
        }

        if (cardType == "Knight" && knightCount == 0)
        {
            std::cout << ("You don't have any Knight cards.") << std::endl;
            return;
        }

        if (cardType == "Monopoly")
        {
            bool monopoly = false;
            for (unsigned long i = 0; i < cards.size(); i++)
            {
                if (cards[i]->getType() == "Monopoly")
                {
                    monopoly = true;
                    break;
                }
            }
            if (monopoly == false)
            {
                std::cout << ("You don't have any Monopoly cards.") << std::endl;
                return;
            }
        }

        if (cardType == "Road")
        {
            bool roadBuilding = false;
            for (unsigned long i = 0; i < cards.size(); i++)
            {
                if (cards[i]->getType() == "Road Building")
                {
                    roadBuilding = true;
                    break;
                }
            }
            if (roadBuilding == false)
            {
                std::cout << ("You don't have any Road Building cards.") << std::endl;
                return;
            }
        }

        if (cardType == "Year")
        {
            bool yearOfPlenty = false;
            for (unsigned long i = 0; i < cards.size(); i++)
            {
                if (cards[i]->getType() == "Year of Plenty")
                {
                    yearOfPlenty = true;
                    break;
                }
            }
            if (yearOfPlenty == false)
            {
                std::cout << ("You don't have any Year of Plenty cards.") << std::endl;
                return;
            }
        }

        if (cardType == "Victory")
        {
            bool victoryPoint = false;
            for (unsigned long i = 0; i < cards.size(); i++)
            {
                if (cards[i]->getType() == "Victory Point")
                {
                    victoryPoint = true;
                    break;
                }
            }
            if (victoryPoint == false)
            {
                std::cout << ("You don't have any Victory Point cards.") << std::endl;
                return;
            }
        }

        if (cardType == "Knight")
        {
            bool knight = false;
            for (unsigned long i = 0; i < cards.size(); i++)
            {
                if (cards[i]->getType() == "Knight")
                {
                    knight = true;
                    break;
                }
            }
            if (knight == false)
            {
                std::cout << ("You don't have any Knight cards.") << std::endl;
                return;
            }
        }

        int inedx = 0;
        for (unsigned long i = 0; i < cards.size(); i++)
        {
            if (cards[i]->getType() == cardType)
            {
                inedx = i;
                break;
            }
        }

        if (cardType == "Monopoly")
        {
            std::string type;
            std::cout << name << " played a Monopoly card. choose resource" << std::endl;
            std::cin >> type;
            if (type == "wood")
            {
                if (other1.wood <= 0 || other2.wood <= 0)
                {
                    std::cout << "one of the players has no wood, try again" << std::endl;
                    return;
                }
                wood++;
                other1.wood--;
                other2.wood--;
                std::cout << "wood added to " << name << "and was taken of from the others" << std::endl;
            }
            else if (type == "ore")
            {
                if (other1.ore <= 0 || other2.ore <= 0)
                {
                    std::cout << "one of the players has no ore, try again" << std::endl;
                    return;
                }
                ore++;
                other1.ore--;
                other2.ore--;
            }
            else if (type == "brick")
            {
                if (other1.brick <= 0 || other2.brick <= 0)
                {
                    std::cout << "one of the players has no brick, try again" << std::endl;
                    return;
                }
                brick++;
                other1.brick--;
                other2.brick--;
            }
            else if (type == "wheat")
            {
                if (other1.wheat <= 0 || other2.wheat <= 0)
                {
                    std::cout << "one of the players has no wheat, try again" << std::endl;
                    return;
                }
                wheat++;
                other1.wheat--;
                other2.wheat--;
            }
            else if (type == "wool")
            {

                wool++;
                other1.wool--;
                other2.wool--;
            }
            else
            {
                std::cout << ("Invalid resource type in used card.") << std::endl;
                return;
            }
        }
        else if (cardType == "Road")
        {
            std::cout << name << " played a Road Building card." << std::endl;
            this->placeRoad(board, false, true);
            this->placeRoad(board, false, true);
        }
        else if (cardType == "Year")
        {
            std::cout << name << " played a Year of Plenty card." << std::endl;
            std::cout << "Choose two resources to add: ";
            std::string type2, type;
            std::cin >> type2;
            std::cin >> type;
            if (type2 == "wood" || type == "wood")
            {
                wood++;
            }
            if (type2 == "ore" || type == "ore")
            {
                ore++;
            }
            if (type2 == "brick" || type == "brick")
            {
                brick++;
            }
            if (type2 == "wheat" || type == "wheat")
            {
                wheat++;
            }
            if (type2 == "wool" || type == "wool")
            {
                wool++;
            }
            // } else if (cardType == "Knight") {
            //     std::cout << name << " played a Knight card." << std::endl;
        }
        else if (cardType == "Victory")
        {
            std::cout << name << " played a Victory Point card." << std::endl;
            addPoints(1);
        }
        else
        {
            std::cout << ("Invalid card type.") << std::endl;
            return;
        }
        cards.erase(cards.begin() + inedx);
    }

    void Player::printResources()
    {
        std::cout << "Resources for " << name << ":" << std::endl;
        std::cout << "Wood: " << wood << std::endl;
        std::cout << "Ore: " << ore << std::endl;
        std::cout << "Brick: " << brick << std::endl;
        std::cout << "Wheat: " << wheat << std::endl;
        std::cout << "Wool: " << wool << std::endl;
    }

    std::vector<int> Player::getResourcesNum() const
    {
        return resourcesNum;
    }

    void Player::addResource(std::string type, int n)
    {
        if (type == "wood")
        {
            wood += n;
        }
        if (type == "ore")
        {
            ore += n;
        }
        if (type == "brick")
        {
            brick += n;
        }
        if (type == "wheat")
        {
            wheat += n;
        }
        if (type == "wool")
        {
            wool += n;
        }
        std::cout << "Resource added to " << name << "." << std::endl;
    }

    bool Player::getTurn()
    {
        return turn;
    }

    void Player::printCards()
    {
        std::cout << "Cards for " << name << ":" << std::endl;
        for (unsigned long i = 0; i < cards.size(); i++)
        {
            std::cout << cards[i]->getType() << std::endl;
        }
    }

    int Player::numOfResource()
    {
        return wood + ore + brick + wheat + wool;
    }
} // namespace ariel