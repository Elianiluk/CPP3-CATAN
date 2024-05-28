#include <iostream>
#include <stdexcept>
#include <vector>
#include <cstdlib>
#include "catan.hpp"
#include "player.hpp"
#include "board.hpp"


namespace ariel{
    Catan::Catan(Player p1, Player p2, Player p3) : p1(p1), p2(p2), p3(p3), board()
    {
        players.push_back(p1);
        players.push_back(p2);
        players.push_back(p3);
    }

    void Catan::ChooseStartingPlayer()
    {
        int random = rand() % 3;
        std::cout << players[random].getName() << std::endl;
        players[random].changeTurn();
    }

    Board Catan::getBoard()
    {
        return board;
    }

    void Catan::play(int roll,Board Board){
        
    }

    void Catan::printWinner()
    {
        int max = players[0].getPoints();
        Player winner=players[0];
        for (int i = 1; i < 3; i++)
        {
            if (players[i].getPoints() > max)
            {
                max = players[i].getPoints();
                winner = players[i];
            }
        }
        if(max<10)
        {
            std::cout << "No winner yet." << std::endl;
            return;
        }
        std::cout << winner.getName() << " is the winner!" << std::endl;
    }
};