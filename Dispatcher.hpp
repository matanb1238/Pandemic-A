
#pragma once
#include "Player.hpp"
using namespace std;
using namespace pandemic;

class Dispatcher: public Player {
        public:
            Dispatcher(Board& b, City c): Player(b, c, "Dispatcher") {}
            Player& fly_direct(City c) override;
};