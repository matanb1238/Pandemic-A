
#pragma once
#include "Player.hpp"
using namespace std;
using namespace pandemic;

class OperationsExpert: public Player {
        public:
            OperationsExpert(Board& b, City c): Player(b, c, "OperationsExpert") {}
            Player& build() override;
};