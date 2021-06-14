#pragma once
#include "City.hpp"
#include "Color.hpp"
#include <map>
#include <set>
#include <iostream>

namespace pandemic {

    class Board {

        static std::map<City, std::set<City>> connections;
        std::map<City, int> diseas_cubes;
        std::set<City> research_stations;
        // std::set<Color> cure_discoverd;
        bool cured[4] = {0};

        public:
            Board() {}
            inline void remove_cures(){ cured[0] = 0;cured[1] = 0;cured[2] = 0;cured[3]= 0;};
            int& operator[](City c);
            bool is_clean();
            bool is_connected(City& c1, City& c2);
            void build_research_station(City c);
            bool is_research_station(City c);
            void mark_cured(Color c);
            bool is_cure_discoverd(City c);
            // int disease_level(City c);
            Color color_of(City c);
            friend std::ostream& operator<<(std::ostream& out, Board& b);
    };

    const std::string LINE = "\e[1;95m";
    const std::string HEADLINE = "\e[1;93m";
    const std::string FIELDS = "\e[1;96m";
    const std::string REGULAR = "\e[0m";
//----------------------------------------------------------------------------------------------
    inline std::ostream& operator<<(std::ostream& out, Board& b) {
        out << LINE << "-------------------------- BOARD --------------------------" << std::endl;
        out << HEADLINE << "level of disease:" << FIELDS << std::endl;
        for(auto& e: b.diseas_cubes) {
            out << "\t" << city_string(e.first) << ": \t\t" << e.second << std::endl;
        }
        out << HEADLINE << "Cure discovered for colors:" << FIELDS << std::endl;
        for(int i = 0; i < 4; i++) {
            out << "\t" << color_string(i) << ":\t\t" << b.cured[i] << std::endl;
        }
        out << HEADLINE << "Research stations:" << FIELDS << std::endl;
        for(auto& rs: b.research_stations) {
            out << "\t" << city_string(rs) << std::endl;
        }
        out << LINE << "------------------------ END BOARD ------------------------" << REGULAR << std::endl;
        return out;
    }
}