#pragma once
#include "City.hpp"
#include "Color.hpp"
#include <map>
#include <set>
#include <iostream>

using namespace std;

namespace pandemic {

    class Board {
        map<City, int> disease_cubes;
        set<City> stations;
        static map<City, set<City>> neighbors;
        bool cured[4] = {0};

        public:
            Board() {}
            // ~Board();
            void remove_cures();
            int& operator[](City c);
            bool is_clean();
            void build_station(City c);
            bool has_station(City c);
            bool is_neighbors(City& c1, City& c2);
            void found_med(Color c);
            bool has_medicine(City c);
            Color color_of(City c);
            friend ostream& operator<<(ostream& out, Board& b);
    };

}