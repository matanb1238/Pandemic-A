
#pragma once
#include "Player.hpp"
using namespace std;
using namespace pandemic;

class GeneSplicer: public Player {
        int n;
        public:
            GeneSplicer(Board& b, City c): Player(b, c, "GeneSplicer") {}
            Player& discover_cure(Color c) override;
};