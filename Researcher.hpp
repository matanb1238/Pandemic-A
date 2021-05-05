
#pragma once
#include "Player.hpp"
using namespace std;
using namespace pandemic;

class Researcher: public Player {
        int n;
        public:
            Researcher(Board& b, City c): Player(b, c, "Researcher") {}
            Player& discover_cure(Color c) override;
};