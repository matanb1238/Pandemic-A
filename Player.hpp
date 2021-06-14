#pragma once
#include "Board.hpp"
#include "City.hpp"
#include <set>

namespace pandemic {

    class Player {

        protected:
            Board& board;
            std::set<City> cards;
            City city;
            std::string rol;

        public:
            Player(Board& b, City c, std::string r): board(b), city(c), rol(r){}

            Player& take_card(City c);
            Player& drive(City c);
            virtual Player& fly_direct(City c);
            Player& fly_charter(City c);
            Player& fly_shuttle(City c);
            virtual Player& build();
            virtual Player& discover_cure(Color c);
            virtual Player& treat(City c);
            std::string role(){return rol;}
    };

}