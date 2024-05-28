#ifndef CATAN_HPP
#define CATAN_HPP

#include <vector>
#include "player.hpp"
#include "board.hpp"

namespace ariel {

class Catan {
public:
    Catan(Player p1, Player p2, Player p3);
    void ChooseStartingPlayer();
    Board getBoard();
    void Catan::play(int roll,Board Board);
    void printWinner();

private:
    Player p1, p2, p3;
    std::vector<Player> players;
    Board board;
};

} // namespace ariel

#endif // CATAN_HPP
