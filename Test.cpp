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

/* author: elian iluk
email: elian10119@gmail.com
id: 214787483*/

std::streambuf *orig = std::cout.rdbuf(); // save original buffer

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
    std::streambuf *orig = cin.rdbuf();
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
    std::streambuf *orig = cin.rdbuf();
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
    std::streambuf *orig = cin.rdbuf();
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
    std::streambuf *orig = cin.rdbuf();
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
    std::streambuf *orig = cin.rdbuf();
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

    std::streambuf *orig2 = cin.rdbuf();
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
    std::streambuf *orig = cin.rdbuf();
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

    std::streambuf *orig2 = cin.rdbuf();
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
    std::streambuf *orig = cin.rdbuf();
    std::istringstream input("0\n0\n");
    cin.rdbuf(input.rdbuf());
    p1.changeTurn();
    p1.placeSettlement(board, true);
    cin.rdbuf(orig);
    restoreOutput();
    CHECK(board.getHexagon(0)->getVertex(0)->hasSettlement() == true);
    CHECK(board.getHexagon(0)->getVertex(0)->hasCity() == false);
    std::streambuf *orig2 = cin.rdbuf();
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

    std::streambuf *orig3 = cin.rdbuf();
    std::istringstream input3("0\n0\n");
    cin.rdbuf(input3.rdbuf());
    p1.changeTurn();
    p1.placeSettlement(board, true);
    cin.rdbuf(orig3);
    restoreOutput();

    CHECK(board.getHexagon(0)->getEdge(0)->hasRoad() == false);
    std::streambuf *orig = cin.rdbuf();
    std::istringstream input("0\n0\n");
    cin.rdbuf(input.rdbuf());
    // p1.changeTurn();
    p1.placeRoad(board, true, false);
    cin.rdbuf(orig);
    restoreOutput();
    CHECK(board.getHexagon(0)->getEdge(0)->hasRoad() == true);
    CHECK(board.getHexagon(0)->getEdge(1)->hasRoad() == false);
    CHECK(board.getHexagon(1)->getEdge(0)->hasRoad() == false);

    std::streambuf *orig4 = cin.rdbuf();
    std::istringstream input4("18\n5\n");
    cin.rdbuf(input4.rdbuf());
    // p1.changeTurn();
    p1.placeSettlement(board, true);
    cin.rdbuf(orig4);
    restoreOutput();

    std::streambuf *orig2 = cin.rdbuf();
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

    std::streambuf *orig3 = cin.rdbuf();
    std::istringstream input3("0\n0\n");
    cin.rdbuf(input3.rdbuf());
    p1.changeTurn();
    p1.placeSettlement(board, false);
    cin.rdbuf(orig3);
    restoreOutput();

    CHECK(board.getHexagon(0)->getEdge(0)->hasRoad() == false);
    std::streambuf *orig = cin.rdbuf();
    std::istringstream input("0\n0\n");
    cin.rdbuf(input.rdbuf());
    // p1.changeTurn();
    p1.placeRoad(board, false, false);
    cin.rdbuf(orig);
    restoreOutput();
    CHECK(board.getHexagon(0)->getEdge(0)->hasRoad() == true);
    CHECK(board.getHexagon(0)->getEdge(1)->hasRoad() == false);
    CHECK(board.getHexagon(1)->getEdge(0)->hasRoad() == false);

    std::streambuf *orig4 = cin.rdbuf();
    std::istringstream input4("18\n5\n");
    cin.rdbuf(input4.rdbuf());
    // p1.changeTurn();
    p1.placeSettlement(board, false);
    cin.rdbuf(orig4);
    restoreOutput();

    std::streambuf *orig2 = cin.rdbuf();
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

TEST_CASE("Test player play card monopoly")
{
    Player p1("p1", 0);
    Player p2("p2", 1);
    Player p3("p3", 2);
    Board board;
    p1.changeTurn();
    board.createBoard();
    p1.addCard("Monopoly");
    p1.addResource("wood", 1);
    p2.addResource("wood", 1);
    p3.addResource("wood", 1);
    std::streambuf *orig = cin.rdbuf();
    std::istringstream input("wood\n");
    cin.rdbuf(input.rdbuf());
    p1.playCard("Monopoly", p2, p3, board);
    cin.rdbuf(orig);
    restoreOutput();
    CHECK(p1.getResource("wood") == 3);
    CHECK(p2.getResource("wood") == 0);
    CHECK(p3.getResource("wood") == 0);
}

TEST_CASE("Test player play card year of plenty")
{
    Player p1("p1", 0);
    Player p2("p2", 1);
    Player p3("p3", 2);
    Board board;
    p1.changeTurn();
    board.createBoard();
    p1.addCard("Year of Plenty");
    p1.addResource("wood", 1);
    p1.addResource("brick", 1);
    p1.addResource("ore", 1);
    p1.addResource("wheat", 1);
    p1.addResource("wool", 1);
    std::streambuf *orig = cin.rdbuf();
    std::istringstream input("wood\nbrick\n");
    cin.rdbuf(input.rdbuf());
    p1.playCard("Year", p2, p3, board);
    cin.rdbuf(orig);
    restoreOutput();
    CHECK(p1.getResource("wood") == 2);
    CHECK(p1.getResource("brick") == 2);
    CHECK(p1.getResource("ore") == 1);
    CHECK(p1.getResource("wheat") == 1);
    CHECK(p1.getResource("wool") == 1);
}

TEST_CASE("Test player play card road building")
{
    Player p1("p1", 0);
    Player p2("p2", 1);
    Player p3("p3", 2);
    Board board;
    p1.changeTurn();
    board.createBoard();
    p1.addCard("Road Building");
    p1.addResource("wood", 20);
    p1.addResource("brick", 20);
    p1.addResource("ore", 20);
    p1.addResource("wheat", 20);
    p1.addResource("wool", 20);
    std::streambuf *orig = cin.rdbuf();
    std::istringstream input("0\n0\n4\n4\n0\n0\n4\n4\n");
    cin.rdbuf(input.rdbuf());
    p1.placeSettlement(board, true);
    p1.placeSettlement(board, true);
    p1.playCard("Road", p2, p3, board);
    cin.rdbuf(orig);
    restoreOutput();
    CHECK(board.getHexagon(0)->getEdge(0)->hasRoad() == true);
    CHECK(board.getHexagon(4)->getEdge(4)->hasRoad() == true);
    CHECK(board.getHexagon(0)->getEdge(1)->hasRoad() == false);
    CHECK(board.getHexagon(1)->getEdge(0)->hasRoad() == false);
}

TEST_CASE("Test player play card victory point")
{
    Player p1("p1", 0);
    Player p2("p2", 1);
    Player p3("p3", 2);
    Board board;
    p1.changeTurn();
    board.createBoard();
    CHECK(p1.getPoints() == 0);
    p1.addCard("Victory Point");
    p1.playCard("Victory", p2, p3, board);
    CHECK(p1.getPoints() == 1);
}

TEST_CASE("Test roll dice")
{
    Player p1("p1", 0);
    CHECK(p1.rollDice() >= 2);
    CHECK(p1.rollDice() <= 12);
}

TEST_CASE("Test for vertices and edges in borad creation")
{
    Player player1("Player1", 0);
    Player player2("Player2", 1);
    Player player3("Player3", 2);
    Catan game(player1, player2, player3);
    Board board;
    board.createBoard();

    // Check vertices

    vector<int> ans = {10, 9, 8, 11, 12, 13};
    for (size_t i = 0; i < 6; i++)
    {
        CHECK(board.getHexagon(2)->getVertex(i)->getNum() == ans[i]);
    }
    ans = {4, 3, 17, 18, 19, 7};
    for (size_t i = 0; i < 6; i++)
    {
        CHECK(board.getHexagon(4)->getVertex(i)->getNum() == ans[i]);
    }
    ans = {19, 18, 30, 31, 32, 20};
    for (size_t i = 0; i < 6; i++)
    {
        CHECK(board.getHexagon(9)->getVertex(i)->getNum() == ans[i]);
    }
    ans = {28, 27, 38, 39, 40, 29};
    for (size_t i = 0; i < 6; i++)
    {
        CHECK(board.getHexagon(12)->getVertex(i)->getNum() == ans[i]);
    }
    ans = {44, 43, 51, 52, 53, 45};
    for (size_t i = 0; i < 6; i++)
    {
        CHECK(board.getHexagon(18)->getVertex(i)->getNum() == ans[i]);
    }

    // Check edges

    vector<int> ans2 = {6, 4, 7, 8, 9, 10};
    for (size_t i = 0; i < 6; i++)
    {
        CHECK(board.getHexagon(1)->getEdge(i)->getNum() == ans2[i]);
    }
    ans2 = {13, 26, 27, 28, 29, 30};
    for (size_t i = 0; i < 6; i++)
    {
        CHECK(board.getHexagon(6)->getEdge(i)->getNum() == ans2[i]);
    }
    ans2 = {31, 32, 33, 34, 35, 18};
    for (size_t i = 0; i < 6; i++)
    {
        CHECK(board.getHexagon(7)->getEdge(i)->getNum() == ans2[i]);
    }
    ans2 = {40, 55, 56, 57, 58, 42};
    for (size_t i = 0; i < 6; i++)
    {
        CHECK(board.getHexagon(14)->getEdge(i)->getNum() == ans2[i]);
    }
    ans2 = {54, 65, 66, 67, 68, 56};
    for (size_t i = 0; i < 6; i++)
    {
        CHECK(board.getHexagon(17)->getEdge(i)->getNum() == ans2[i]);
    }
}