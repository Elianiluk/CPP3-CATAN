#include <iostream>
#include <stdexcept>
#include <vector>
#include <cstdlib>
#include "catan.hpp"

namespace ariel
{
    Catan::Catan(Player &p1, Player &p2, Player &p3) : p1(p1), p2(p2), p3(p3), board()
    {
        players.push_back(&p1);
        players.push_back(&p2);
        players.push_back(&p3);
    }

    void Catan::ChooseStartingPlayer()
    {
        // int random = rand() % 3;
        // std::cout << players[random]->getName() << std::endl;
        players[0]->changeTurn();
    }

    Board &Catan::getBoard()
    {
        return board;
    }

    void Catan::play(int roll, Board &board)
    {
        std::vector<Hexagon *> hexas = board.getRelevantHexagons(roll);
        for (Hexagon *hex : hexas)
        {
            std::string type = hex->getType();
            for (int i = 0; i < 6; i++)
            { // go over all the vertices of the hexagon
                if (hex->getVertex(i)->getPlayerID() != -1)
                {
                    if (hex->getVertex(i)->hasCity())
                    {
                        std::cout << "Player " << hex->getVertex(i)->getPlayerID() << " gets 2 " << type << " from the hexagon " << hex->getName() << std::endl;
                        players[hex->getVertex(i)->getPlayerID()]->addResource(hex->getType(), 2);
                    }
                }
            }
            // go over all the edges
            for (int i = 0; i < 6; i++)
            {
                if (hex->getEdge(i)->getPlayerID() != -1)
                {
                    std::cout << "Player " << hex->getEdge(i)->getPlayerID() << " gets 1 " << type << " from the hexagon " << hex->getName() << std::endl;
                    players[hex->getEdge(i)->getPlayerID()]->addResource(hex->getType(), 1);
                }
            }
        }
    }

    Player &Catan::getPlayer(int i)
    {
        if (i < 0 || i >= players.size())
        {
            throw std::out_of_range("Invalid player index.");
        }
        return *players[i];
    }

    void Catan::printWinner()
    {
        int max = players[0]->getPoints();
        Player *winner = players[0];
        for (int i = 1; i < players.size(); i++)
        {
            if (players[i]->getPoints() > max)
            {
                max = players[i]->getPoints();
                winner = players[i];
            }
        }
        if (max < 10)
        {
            std::cout << "No winner yet." << std::endl;
            return;
        }
        std::cout << winner->getName() << " is the winner!" << std::endl;
    }
}
