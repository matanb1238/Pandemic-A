#pragma once
#include "Board.hpp"
#include "City.hpp"
#include <set>

using namespace std;

namespace pandemic {

    class Player {

        protected:
            Board& board;
            City city;
            set<City> cards;
            string rol;

        public:
            Player(Board& b, City c, string r): board(b), city(c), rol(r){}
            
            Player& drive(City c);
            virtual Player& fly_direct(City c);
            Player& fly_charter(City c);
            Player& fly_shuttle(City c);
            virtual Player& build();
            virtual Player& discover_cure(Color c);
            virtual Player& treat(City c);
            string role(){return rol;}
            Player& take_card(City c);
    };

}