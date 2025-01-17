#ifndef CATAN_HPP
#define CATAN_HPP

#include <vector>
#include "player.hpp"
#include "board.hpp"

/* author: elian iluk
email: elian10119@gmail.com
id: 214787483*/

namespace ariel {

class Catan {
public:
    Catan(Player& p1, Player& p2, Player& p3);
    void ChooseStartingPlayer();
    void play(int roll,Board &board);
    bool printWinner();
    Player& getPlayer(int i);

private:
    std::vector<Player*> players;
};

} // namespace ariel

#endif // CATAN_HPP
