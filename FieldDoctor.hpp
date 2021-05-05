
#pragma once
#include "Player.hpp"
using namespace std;
using namespace pandemic;

class FieldDoctor: public Player {
        public:
            FieldDoctor(Board& b, City c): Player(b, c, "FieldDoctor") {}
            Player& treat(City c) override;
};