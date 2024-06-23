#ifndef CATAN_HPP
#define CATAN_HPP

#include <vector>
#include "player.hpp"
#include "board.hpp"

namespace ariel {

class Catan {
public:
    Catan(Player& p1, Player& p2, Player& p3);
    void ChooseStartingPlayer();
    Board& getBoard();
    void play(int roll,Board &board);
    void printWinner();
    Player& getPlayer(int i);

private:
    Player& p1;
    Player& p2;
    Player& p3;
    std::vector<Player*> players;
    Board board;
};

} // namespace ariel

#endif // CATAN_HPP