
#pragma once
#include "Player.hpp"
using namespace std;
using namespace pandemic;

class Scientist: public Player {
        int n;
        public:
            Scientist(Board& b, City c, int num): Player(b, c, "Scientist"), n(num) {}
            Player& discover_cure(Color c) override;
};