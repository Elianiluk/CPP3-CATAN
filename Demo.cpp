#include <iostream>
#include <stdexcept>
#include <vector>
#include "catan.hpp"
#include "player.hpp"
#include "board.hpp"
#include "card.hpp"

using namespace std;
using namespace ariel;

void playerTurn(Player &player, Player &p1, Player &p2, Player &p3, Board &board)
{
    int choice = 0;
    while (choice != 7)
    {
        cout << player.getName() << ", it's your turn. Choose an action:" << endl;
        cout << "1 - Build Settlement" << endl;
        cout << "2 - Build Road" << endl;
        cout << "3 - Build City" << endl;
        cout << "4 - Trade" << endl;
        cout << "5 - Buy Card" << endl;
        cout << "6 - Use Card" << endl;
        cout << "7 - End Turn" << endl;
        cout << "8-  show resources" << endl;
        cout << "9-  show points" << endl;
        cout << "10- show cards" << endl;
        cout << "11- display board" << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            player.placeSettlement(board, false);
            break;
        case 2:
            player.placeRoad(board, false, false);
            break;
        case 3:
            player.placeCity(board);
            break;
        case 4:
        {
            int tradeType;
            cout << "Trade Cards or Resources? (1 for Cards, 2 for Resources): ";
            cin >> tradeType;
            int tradePartner;
            cout << "Choose a player to trade with (1 for " << p1.getName() << ", 2 for " << p2.getName() << ", 3 for " << p3.getName() << "): ";
            cin >> tradePartner;
            if ((tradePartner == 1 && player.getPlayerID() == 0) || (tradePartner == 2 && player.getPlayerID() == 1) || (tradePartner == 3 && player.getPlayerID() == 2))
            {
                cout << "You can't trade with yourself" << endl;
                break;
            }
            if (tradePartner == 1)
                if (tradeType == 1)
                    player.tradeCards(p1);
                else
                    player.tradeRescources(p1);
            else if (tradePartner == 2)
                if (tradeType == 1)
                    player.tradeCards(p2);
                else
                    player.tradeRescources(p2);
            else if (tradePartner == 3)
                if (tradeType == 1)
                    player.tradeCards(p3);
                else
                    player.tradeRescources(p3);
            else
                cout << "Invalid player choice" << endl;
        }
        break;
        case 5:
            player.buyCard();
            break;
        case 6:
        {
            std::string card;
            int targetPlayer1, targetPlayer2;
            cout << "Enter card to use: ";
            cin >> card;
            cout << "Enter first target player (1 for " << p1.getName() << ", 2 for " << p2.getName() << ", 3 for " << p3.getName() << "): ";
            cin >> targetPlayer1;
            cout << "Enter second target player (if applicable, else type 'none'): ";
            cin >> targetPlayer2;
            Player &tp1 = (targetPlayer1 == 1) ? p1 : (targetPlayer1 == 2) ? p2
                                                                           : p3;
            Player &tp2 = (targetPlayer2 == 1) ? p1 : (targetPlayer2 == 2) ? p2
                                                                           : p3;
            player.playCard(card, tp1, tp2, board);
        }
        break;
        case 7:
        {
            player.changeTurn();
            if (player.getPlayerID() == 0)
                p2.changeTurn();
            else if (player.getPlayerID() == 1)
                p3.changeTurn();
            else
                p1.changeTurn();
            break;
        }
        case 8:
            player.printResources();
            break;
        case 9:
        {
            std::cout << p1.getName() << "'s points: " << p1.getPoints() << std::endl;
            std::cout << p2.getName() << "'s points: " << p2.getPoints() << std::endl;
            std::cout << p3.getName() << "'s points: " << p3.getPoints() << std::endl;
            break;
        }
        case 10:
            player.printCards();
            break;
        case 11:
            board.displayBoard();
            break;
        default:
            cout << "Invalid choice. Try again." << endl;
        }
    }
}

int main1()
{
    // std::string name1, name2, name3;
    // std::cout << "Enter the name of the first player: ";
    // std::cin >> name1;
    // std::cout << "Enter the name of the second player: ";
    // std::cin >> name2;
    // std::cout << "Enter the name of the third player: ";
    // std::cin >> name3;
    Player p1("Amit", 0);
    Player p2("Yossi", 1);
    Player p3("Dana", 2);
    Catan catan(p1, p2, p3);

    Board board;
    board.createBoard();
    board.displayBoard();

    for (int i = 0; i < 2; i++)
    {
        catan.getPlayer(i).changeTurn();
        catan.getPlayer(i).placeSettlement(board, true);
        catan.getPlayer(i).placeSettlement(board, true);
        catan.getPlayer(i).placeRoad(board, true, false);
        catan.getPlayer(i).placeRoad(board, true, false);
        catan.getPlayer(i).changeTurn();
        board.displayBoard();
    }

    catan.ChooseStartingPlayer();

    while (true)
    {
        p1.addResource("wood", 20);
        p1.addResource("brick", 20);
        p1.addResource("ore", 20);
        p1.addResource("wheat", 20);
        p1.addResource("wool", 20);
        p2.addResource("wood", 20);
        p2.addResource("brick", 20);
        p2.addResource("ore", 20);
        p2.addResource("wheat", 20);
        p2.addResource("wool", 20);
        p3.addResource("wood", 20);
        p3.addResource("brick", 20);
        p3.addResource("ore", 20);
        p3.addResource("wheat", 20);
        p3.addResource("wool", 20);

        int roll = p1.rollDice();
        cout << "The dice rolled a " << roll << endl;
        catan.play(roll, board);
        if (p1.getTurn())
            playerTurn(p1, p1, p2, p3, board);
        else if (p2.getTurn())
            playerTurn(p2, p1, p2, p3, board);
        else if (p3.getTurn())
            playerTurn(p3, p1, p2, p3, board);

        catan.printWinner();
        if (p1.getPoints() >= 10 || p2.getPoints() >= 10 || p3.getPoints() >= 10)
        {
            break;
        }
    }

    return 0;
}
