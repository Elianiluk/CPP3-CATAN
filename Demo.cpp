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
    Player p1("Amit");
    Player p2("Yossi");
    Player p3("Dana");
    Catan catan(p1, p2, p3);
    int roll=0;
    // Starting of the game. Every player places two settlements and two roads.
    catan.ChooseStartingPlayer();   // should print the name of the starting player, assume it is Amit.
    Board board; // get the board of the game.
    board.createBoard();
    board.printBoard();
    // vector<string> places = {"Forest", "Hills"};
    // vector<int> placesNum = {5, 6};
    // p1.placeSettelemnt(places, placesNum, board);
    // p1.placeRoad(places, placesNum, board);
    // vector<string> places = {"Agricultural Land", "Desert"};
    // vector<int> placesNum = {3, 4};
    // p1.placeSettelemnt(places, placesNum, board);
    // p1.placeRoad(places, placesNum, board); // p1 chooses Forest, hills, Agricultural Land, Desert with numbers 5, 6, 3, 4.

    // vector<string> places = {"Mountains", "Pasture Land"};
    // vector<int> placesNum = {4, 9};
    // p2.placeSettelemnt(places, placesNum, board);
    // p2.placeRoad(places, placesNum, board);
    // try
    // {
    //     p3.placeSettelemnt(places, placesNum, board); // p3 tries to place a settlement in the same location as p2.
    // }
    // catch (const std::exception &e)
    // {
    //     cout << e.what() << endl;
    // }
    // vector<string> places = {"Forest", "Pasture Land"};
    // vector<int> placesNum = {5, 9};
    // p2.placeSettelemnt(places, placesNum, board);
    // p2.placeRoad(places, placesNum, board); // p2 chooses Mountains, Pasture Land, and Forest with numbers 4, 9, 5.

    // vector<string> places = {"Mountains", "Pasture Land"};
    // vector<int> placesNum = {3, 8};
    // p3.placeSettelemnt(places, placesNum, board);
    // p3.placeRoad(places, placesNum, board);
    // vector<string> places = {"Agricultural Land", "Pasture Land"};
    // vector<int> placesNum = {3, 9};
    // p3.placeSettelemnt(places, placesNum, board);
    // p3.placeRoad(places, placesNum, board); // p3 chooses Mountains, Pasture Land, Agricultural Land, Pasture Land with numbers 3, 8, 3, 9.

    // p1 has wood,bricks, and wheat, p2 has wood, ore, and wool, p3 has ore, wool, wheat.
    p1.changeTurn();
    roll=p1.rollDice();   
    catan.play(roll,board);                                 // Lets say it's print 4. Then, p2 gets ore from the mountations.
    p1.placeRoad({"Forest", "Hills"}, {5, 6}, board); // p1 continues to build a road.
    p1.changeTurn();                                     // p1 ends his turn.

    p2.changeTurn(); // p2 starts his turn.
    roll=p2.rollDice();   
    catan.play(roll,board);
    p2.changeTurn();  // p2 ends his turn.

    p3.changeTurn();
    roll=p3.rollDice();   
    catan.play(roll,board);     
    p3.buyCard(); // p3 buys a knight card.
    p3.playCard("Knight Card", "None", "None", p1, p2); // p3 plays the knight card and moves the robber to the Forest.
    p3.changeTurn();  // p3 ends his turn.

    try
    {
        roll=p2.rollDice(); // p2 tries to roll the dice again, but it's not his turn.
    }
    catch (const std::exception &e)
    {
        cout << e.what() << endl;
    }

    p1.changeTurn();
    roll=p1.rollDice();   
    catan.play(roll,board);                       // Lets say it's print 6. Then, p1 gets bricks from the hills.
    p1.trade(p2, "wood", "brick", 1, 1); // p1 trades 1 wood for 1 brick with p2.
    p1.changeTurn();                        // p1 ends his turn.

    p2.changeTurn();
    roll=p2.rollDice();   
    catan.play(roll,board);           // Lets say it's print 9. Then, p3 gets wool from the Pasture Land, p2 gets wool from the Pasture Land.
    p2.buyCard(); // p2 buys a development card. Lets say it is a bonus points card.
    p2.changeTurn();            // p2 ends his turn.

    p1.printPoints(); // p1 has 2 points because it has two settelments.
    p2.printPoints(); // p2 has 3 points because it has two settelments and a bonus points card.
    p3.printPoints(); // p3 has 2 points because it has two settelments.

    catan.printWinner(); // Should print None because no player reached 10 points.
}