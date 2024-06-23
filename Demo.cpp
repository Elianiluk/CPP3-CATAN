/**
 * Demo file for Ex3.
 *
 */
#include <iostream>
#include <stdexcept>
#include <vector>
#include "catan.hpp"
#include "player.hpp"
#include "board.hpp"
#include "card.hpp"
using namespace std;
using namespace ariel;


int main()
{
    Player p1("Amit",0);
    Player p2("Yossi",1);
    Player p3("Dana",2);
    ariel::Catan catan(p1, p2, p3);
    int roll=0;
    // Starting of the game. Every player places two settlements and two roads.
    catan.ChooseStartingPlayer();   // should print the name of the starting player, assume it is Amit.
    Board board; // get the board of the game.
    board.createBoard();
    // board.printBoard();
    
    // board.createSettlement(18, 1); // Amit 
    // board.createSettlement(0, 1); // Amit

    // p1.changeTurn();
    p1.placeSettlement(3,4, board,true);
    std::cout << board.getHexagon(2)->getVertex(4)->hasSettlement() <<std::endl;
    p1.placeSettlement(11,5, board,true);
    // p1.printResources();
    p1.placeRoad(3, 4, board,true);
    p1.placeRoad(7, 4, board,true);
    // p1.printResources();
    p1.printPoints();
    p1.changeTurn();

    // catan.getPlayer(0).printPoints(); // p1 has 2 points because it has two settelments.

    p1.changeTurn();
    roll=p1.rollDice();  
    std::cout << roll << std::endl; 
    p1.printResources();
    catan.play(roll,board);                       // Lets say it's print 6. Then, p1 gets bricks from the hills.
    p1.printResources();
    // p1.trade(p2, "wood", "brick", 1, 1); // p1 trades 1 wood for 1 brick with p2.
    p1.changeTurn();                        // p1 ends his turn.

    p2.changeTurn();
    roll=p2.rollDice();   
    catan.play(roll,board);           // Lets say it's print 9. Then, p3 gets wool from the Pasture Land, p2 gets wool from the Pasture Land.
    // p2.buyCard(); // p2 buys a development card. Lets say it is a bonus points card.
    p2.changeTurn();            // p2 ends his turn.

    p1.printPoints(); // p1 has 2 points because it has two settelments.
    p2.printPoints(); // p2 has 3 points because it has two settelments and a bonus points card.
    p3.printPoints(); // p3 has 2 points because it has two settelments.

    catan.printWinner(); // Should print None because no player reached 10 points.
}