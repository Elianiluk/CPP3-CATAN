#include <iostream>
#include <stdexcept>
#include <vector>
#include "catan.hpp"
#include "player.hpp"
#include "board.hpp"
#include "card.hpp"

using namespace std;
using namespace ariel;

void playerTurn(Player &player, Player &p1, Player &p2, Player &p3, Board &board) {
    int choice = 0;
    while (choice != 7) {
        cout << player.getName() << ", it's your turn. Choose an action:" << endl;
        cout << "1 - Build Settlement" << endl;
        cout << "2 - Build Road" << endl;
        cout << "3 - Build City" << endl;
        cout << "4 - Trade" << endl;
        cout << "5 - Buy Card" << endl;
        cout << "6 - Use Card" << endl;
        cout << "7 - End Turn" << endl;
        cout << "8-  show resources"<<endl;
        cin >> choice;

        switch (choice) {
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
                    int tradePartner;
                    cout << "Choose a player to trade with (1 for " << p1.getName() << ", 2 for " << p2.getName() << ", 3 for " << p3.getName() << "): ";
                    cin >> tradePartner;
                    if((tradePartner==1 && player.getPlayerID()==0) || (tradePartner==2 && player.getPlayerID()==1) || (tradePartner==3 && player.getPlayerID()==2))
                    {
                        cout<<"You can't trade with yourself"<<endl;
                        break;
                    }
                    if (tradePartner == 1)
                        player.trade(p1);
                    else if (tradePartner == 2)
                        player.trade(p2);
                    else if (tradePartner == 3)
                        player.trade(p3);
                }
                break;
            case 5:
                player.buyCard();
                break;
            case 6:
                {
                    string card, type, type2;
                    int targetPlayer1, targetPlayer2;
                    cout << "Enter card to use: ";
                    cin >> card;
                    cout << "Enter type: ";
                    cin >> type;
                    cout << "Enter type2 (if applicable, else type 'none'): ";
                    cin >> type2;
                    cout << "Enter first target player (1 for " << p1.getName() << ", 2 for " << p2.getName() << ", 3 for " << p3.getName() << "): ";
                    cin >> targetPlayer1;
                    cout << "Enter second target player (if applicable, else type 'none'): ";
                    cin >> targetPlayer2;
                    Player &tp1 = (targetPlayer1 == 1) ? p1 : (targetPlayer1 == 2) ? p2 : p3;
                    Player &tp2 = (targetPlayer2 == 1) ? p1 : (targetPlayer2 == 2) ? p2 : p3;
                    player.playCard(card, tp1, tp2, board);
                }
                break;
            case 7:{
                player.changeTurn();
                if(player.getPlayerID()==0)
                    p2.changeTurn();
                else if(player.getPlayerID()==1)
                    p3.changeTurn();
                else
                    p1.changeTurn();
                break;
            }
            case 8:
                player.printResources();
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
        }
    }
}

int main() {
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

    for(int i=0;i<1;i++)
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

    while (true) {
        int roll = p1.rollDice();
        cout << "The dice rolled a " << roll << endl;
        catan.play(roll, board);
        if (p1.getTurn()) playerTurn(p1, p1, p2, p3, board);
        else if (p2.getTurn()) playerTurn(p2, p1, p2, p3, board);
        else if (p3.getTurn()) playerTurn(p3, p1, p2, p3, board);

        catan.printWinner();
        if (p1.getPoints() >= 10 || p2.getPoints() >= 10 || p3.getPoints() >= 10) {
            break;
        }
    }

    return 0;
}
