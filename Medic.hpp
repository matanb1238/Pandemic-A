
#pragma once
#include "Player.hpp"
using namespace std;
using namespace pandemic;

class Medic: public Player {
        public:
            Medic(Board& b, City c): Player(b, c, "Medic") {
                if(board.is_cure_discoverd(c)){
                    board[c] = 0;
                }
            }
            Player& treat();
};