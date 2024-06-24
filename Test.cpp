#include <iostream>
#include <stdexcept>
#include <vector>
#include "catan.hpp"
#include "player.hpp"
#include "board.hpp"
#include "card.hpp"

using namespace std;
using namespace ariel;
#include <sstream>
#include "doctest.hpp"

std::streambuf* orig = std::cout.rdbuf(); // save original buffer


void suppressOutput()
{
    std::cout.rdbuf(NULL);
}

void restoreOutput()
{
    std::cout.rdbuf(orig);
}

TEST_CASE("Test player name")
{
    Player p1("p1", 0);
    CHECK(p1.getName() == "p1");
}

TEST_CASE("Test player ID")
{
    Player p1("p1", 0);
    CHECK(p1.getPlayerID() == 0);
}

TEST_CASE("Test player points")
{
    Player p1("p1", 0);
    p1.addPoints(1);
    CHECK(p1.getPoints() == 1);
}

TEST_CASE("Test starting player")
{
    Player p1("p1", 0);
    Player p2("p2", 1);
    Player p3("p3", 2);
    Board board;
    board.createBoard();
    Catan game(p1, p2, p3);
    game.ChooseStartingPlayer();
    CHECK(p1.getTurn() == true);
    CHECK(p2.getTurn() == false);
    CHECK(p3.getTurn() == false);
}

TEST_CASE("Test player turn")
{
    Player p1("p1", 0);
    Player p2("p2", 1);
    Player p3("p3", 2);
    Board board;
    board.createBoard();
    Catan game(p1, p2, p3);
    game.ChooseStartingPlayer();
    CHECK(p1.getTurn() == true);
    CHECK(p2.getTurn() == false);
    CHECK(p3.getTurn() == false);
    p1.changeTurn();
    p2.changeTurn();
    CHECK(p1.getTurn() == false);
    CHECK(p2.getTurn() == true);
    CHECK(p3.getTurn() == false);
    p2.changeTurn();
    p3.changeTurn();
    CHECK(p1.getTurn() == false);
    CHECK(p2.getTurn() == false);
    CHECK(p3.getTurn() == true);
}

TEST_CASE("Test player add resource")
{
    Player p1("p1", 0);
    p1.addResource("wood", 1);
    p1.addResource("brick", 2);
    p1.addResource("ore", 3);
    p1.addResource("wheat", 4);
    p1.addResource("wool", 5);
    CHECK(p1.getResource("wood") == 1);
    CHECK(p1.getResource("brick") == 2);
    CHECK(p1.getResource("ore") == 3);
    CHECK(p1.getResource("wheat") == 4);
    CHECK(p1.getResource("wool") == 5);
}

TEST_CASE("Test player add card")
{
    Player p1("p1", 0);
    // p1.addCard("knight");
    p1.addCard("Road Building");
    p1.addCard("Year of Plenty");
    p1.addCard("Monopoly");
    CHECK(p1.hasCard("Knight") == false);
    CHECK(p1.hasCard("Road Building") == true);
    CHECK(p1.hasCard("Year of Plenty") == true);
    CHECK(p1.hasCard("Monopoly") == true);
}

TEST_CASE("Test player remove card")
{
    Player p1("p1", 0);
    p1.addCard("Road Building");
    p1.addCard("Year of Plenty");
    p1.addCard("Monopoly");
    p1.removeCard("Road Building");
    CHECK(p1.hasCard("Road Building") == false);
    CHECK(p1.hasCard("Year of Plenty") == true);
    CHECK(p1.hasCard("Monopoly") == true);
}

TEST_CASE("Test player trade resources-trade success")
{
    Player p1("p1", 0);
    Player p2("p2", 1);
    p2.addResource("ore", 1);
    p1.addResource("brick", 1);
    std::streambuf* orig = cin.rdbuf();
    std::istringstream input("1\nbrick 1\n1\nore 1\nyes\n");
    cin.rdbuf(input.rdbuf());
    p1.tradeRescources(p2);
    cin.rdbuf(orig);
    restoreOutput();
    CHECK(p1.getResource("ore") == 1);
    CHECK(p1.getResource("brick") == 0);
    CHECK(p2.getResource("ore") == 0);
    CHECK(p2.getResource("brick") == 1);
}

TEST_CASE("Test player trade resources-trade fail")
{
    Player p1("p1", 0);
    Player p2("p2", 1);
    p2.addResource("ore", 1);
    p1.addResource("brick", 1);
    std::streambuf* orig = cin.rdbuf();
    std::istringstream input("1\nbrick 1\n1\nore 1\nno\n");
    cin.rdbuf(input.rdbuf());
    p1.tradeRescources(p2);
    cin.rdbuf(orig);
    restoreOutput();
    CHECK(p1.getResource("ore") == 0);
    CHECK(p1.getResource("brick") == 1);
    CHECK(p2.getResource("ore") == 1);
    CHECK(p2.getResource("brick") == 0);
}

TEST_CASE("Test player trade cards-trade success")
{
    Player p1("p1", 0);
    Player p2("p2", 1);
    p1.addCard("Year of Plenty");
    p2.addCard("Road Building");
    std::streambuf* orig = cin.rdbuf();
    std::istringstream input("Year\nRoad\nyes\n");
    cin.rdbuf(input.rdbuf());
    p1.tradeCards(p2);
    cin.rdbuf(orig);
    restoreOutput();
    CHECK(p1.hasCard("Road Building") == true);
    CHECK(p1.hasCard("Year of Plenty") == false);
    CHECK(p2.hasCard("Road Building") == false);
    CHECK(p2.hasCard("Year of Plenty") == true);
}

TEST_CASE("Test player trade cards-trade fail")
{
    Player p1("p1", 0);
    Player p2("p2", 1);
    p1.addCard("Year of Plenty");
    p2.addCard("Road Building");
    std::streambuf* orig = cin.rdbuf();
    std::istringstream input("Year\nRoad\nno\n");
    cin.rdbuf(input.rdbuf());
    p1.tradeCards(p2);
    cin.rdbuf(orig);
    restoreOutput();
    CHECK(p1.hasCard("Road Building") == false);
    CHECK(p1.hasCard("Year of Plenty") == true);
    CHECK(p2.hasCard("Road Building") == true);
    CHECK(p2.hasCard("Year of Plenty") == false);
}

TEST_CASE("Test player roll dice")
{
    Player p1("p1", 0);
    int roll = p1.rollDice();
    CHECK(roll >= 2);
    CHECK(roll <= 12);
}

TEST_CASE("Test player place settlement first round")
{
    Player p1("p1", 0);
    Board board;
    board.createBoard();
    CHECK(board.getHexagon(0)->getVertex(0)->hasSettlement() == false);
    std::streambuf* orig = cin.rdbuf();
    std::istringstream input("0\n0\n");
    cin.rdbuf(input.rdbuf());
    p1.changeTurn();
    p1.placeSettlement(board, true);
    cin.rdbuf(orig);
    restoreOutput();
    CHECK(board.getHexagon(0)->getVertex(0)->hasSettlement() == true);
    CHECK(board.getHexagon(0)->getVertex(0)->hasCity() == false);
    CHECK(board.getHexagon(1)->getVertex(0)->hasSettlement() == false);
    CHECK(board.getHexagon(0)->getVertex(1)->hasSettlement() == false);

    std::streambuf* orig2 = cin.rdbuf();
    std::istringstream input2("18\n5\n");
    cin.rdbuf(input2.rdbuf());
    p1.placeSettlement(board, true);
    cin.rdbuf(orig2);
    restoreOutput();
    CHECK(board.getHexagon(18)->getVertex(5)->hasSettlement() == true);
    CHECK(board.getHexagon(18)->getVertex(5)->hasCity() == false);
}

TEST_CASE("Test player place settlement random round")
{
    Player p1("p1", 0);
    p1.addResource("wood", 2);
    p1.addResource("brick", 2);
    p1.addResource("ore", 2);
    p1.addResource("wheat", 2);
    p1.addResource("wool", 2);
    Board board;
    board.createBoard();
    CHECK(board.getHexagon(0)->getVertex(0)->hasSettlement() == false);
    std::streambuf* orig = cin.rdbuf();
    std::istringstream input("0\n0\n");
    cin.rdbuf(input.rdbuf());
    p1.changeTurn();
    p1.placeSettlement(board, false);
    cin.rdbuf(orig);
    restoreOutput();
    CHECK(board.getHexagon(0)->getVertex(0)->hasSettlement() == true);
    CHECK(board.getHexagon(0)->getVertex(0)->hasCity() == false);
    CHECK(board.getHexagon(1)->getVertex(0)->hasSettlement() == false);
    CHECK(board.getHexagon(0)->getVertex(1)->hasSettlement() == false);

    std::streambuf* orig2 = cin.rdbuf();
    std::istringstream input2("18\n5\n");
    cin.rdbuf(input2.rdbuf());
    p1.placeSettlement(board, false);
    cin.rdbuf(orig2);
    restoreOutput();
    CHECK(board.getHexagon(18)->getVertex(5)->hasSettlement() == true);
    CHECK(board.getHexagon(18)->getVertex(5)->hasCity() == false);

    // std::streambuf* orig3 = cin.rdbuf();
    // std::istringstream input3("18\n5\n");
    // cin.rdbuf(input3.rdbuf());
    // p1.placeSettlement(board, false);
    // cin.rdbuf(orig3);
    // restoreOutput();
    // CHECK_THROWS(board.getHexagon(18)->getVertex(5)->hasSettlement() == true);
}

TEST_CASE("Test player place city")
{
    Player p1("p1", 0);
    p1.addResource("wood", 22);
    p1.addResource("brick", 22);
    p1.addResource("ore", 22);
    p1.addResource("wheat", 22);
    p1.addResource("wool", 22);
    Board board;
    board.createBoard();
    std::streambuf* orig = cin.rdbuf();
    std::istringstream input("0\n0\n");
    cin.rdbuf(input.rdbuf());
    p1.changeTurn();
    p1.placeSettlement(board, true);
    cin.rdbuf(orig);
    restoreOutput();
    CHECK(board.getHexagon(0)->getVertex(0)->hasSettlement() == true);
    CHECK(board.getHexagon(0)->getVertex(0)->hasCity() == false);
    std::streambuf* orig2 = cin.rdbuf();
    std::istringstream input2("0\n0\n");
    cin.rdbuf(input2.rdbuf());
    p1.placeCity(board);
    cin.rdbuf(orig2);
    restoreOutput();
    CHECK(board.getHexagon(0)->getVertex(0)->hasSettlement() == false);
    CHECK(board.getHexagon(0)->getVertex(0)->hasCity() == true);
}

TEST_CASE("Test player place road first round")
{
    Player p1("p1", 0);
    Board board;
    board.createBoard();

    std::streambuf* orig3 = cin.rdbuf();
    std::istringstream input3("0\n0\n");
    cin.rdbuf(input3.rdbuf());
    p1.changeTurn();
    p1.placeSettlement(board, true);
    cin.rdbuf(orig3);
    restoreOutput();

    CHECK(board.getHexagon(0)->getEdge(0)->hasRoad() == false);
    std::streambuf* orig = cin.rdbuf();
    std::istringstream input("0\n0\n");
    cin.rdbuf(input.rdbuf());
    // p1.changeTurn();
    p1.placeRoad(board, true, false);
    cin.rdbuf(orig);
    restoreOutput();
    CHECK(board.getHexagon(0)->getEdge(0)->hasRoad() == true);
    CHECK(board.getHexagon(0)->getEdge(1)->hasRoad() == false);
    CHECK(board.getHexagon(1)->getEdge(0)->hasRoad() == false);

    std::streambuf* orig4 = cin.rdbuf();
    std::istringstream input4("18\n5\n");
    cin.rdbuf(input4.rdbuf());
    // p1.changeTurn();
    p1.placeSettlement(board, true);
    cin.rdbuf(orig4);
    restoreOutput();

    std::streambuf* orig2 = cin.rdbuf();
    std::istringstream input2("18\n5\n");
    cin.rdbuf(input2.rdbuf());
    p1.placeRoad(board, true, false);
    cin.rdbuf(orig2);
    restoreOutput();
    CHECK(board.getHexagon(18)->getEdge(5)->hasRoad() == true);
}

TEST_CASE("Test player place road random round")
{
    Player p1("p1", 0);
    p1.addResource("wood", 20);
    p1.addResource("brick", 20);
    p1.addResource("ore", 20);
    p1.addResource("wheat", 20);
    p1.addResource("wool", 20);
    Board board;
    board.createBoard();

    std::streambuf* orig3 = cin.rdbuf();
    std::istringstream input3("0\n0\n");
    cin.rdbuf(input3.rdbuf());
    p1.changeTurn();
    p1.placeSettlement(board, false);
    cin.rdbuf(orig3);
    restoreOutput();

    CHECK(board.getHexagon(0)->getEdge(0)->hasRoad() == false);
    std::streambuf* orig = cin.rdbuf();
    std::istringstream input("0\n0\n");
    cin.rdbuf(input.rdbuf());
    // p1.changeTurn();
    p1.placeRoad(board, false, false);
    cin.rdbuf(orig);
    restoreOutput();
    CHECK(board.getHexagon(0)->getEdge(0)->hasRoad() == true);
    CHECK(board.getHexagon(0)->getEdge(1)->hasRoad() == false);
    CHECK(board.getHexagon(1)->getEdge(0)->hasRoad() == false);

    std::streambuf* orig4 = cin.rdbuf();
    std::istringstream input4("18\n5\n");
    cin.rdbuf(input4.rdbuf());
    // p1.changeTurn();
    p1.placeSettlement(board, false);
    cin.rdbuf(orig4);
    restoreOutput();

    std::streambuf* orig2 = cin.rdbuf();
    std::istringstream input2("18\n5\n");
    cin.rdbuf(input2.rdbuf());
    p1.placeRoad(board, false, false);
    cin.rdbuf(orig2);
    restoreOutput();
    CHECK(board.getHexagon(18)->getEdge(5)->hasRoad() == true);
}

TEST_CASE("Test player play card knight")
{
    Player p1("p1", 0);
    Player p2("p2", 1);
    Player p3("p3", 2);
    Board board;
    p1.changeTurn();
    board.createBoard();
    p1.addCard("Knight");
    p1.addResource("wood", 20);
    p1.addResource("brick", 20);
    p1.addResource("ore", 20);
    p1.addResource("wheat", 20);
    p1.addResource("wool", 20);
    CHECK(p1.getKnightCount() == 1);
    CHECK(p2.getKnightCount() == 0);
    CHECK(p3.getKnightCount() == 0);
    CHECK_THROWS(p1.playCard("Knight", p2, p3, board));
}

TEST_CASE("Test winner")
{
    Player p1("p1", 0);
    Player p2("p2", 1);
    Player p3("p3", 2);
    Catan game(p1, p2, p3);
    CHECK(game.printWinner() == false);
    p1.addPoints(10);
    CHECK(p1.getPoints() == 10);
    CHECK(p2.getPoints() == 0);
    CHECK(p3.getPoints() == 0);
    CHECK(game.printWinner() == true);
}


