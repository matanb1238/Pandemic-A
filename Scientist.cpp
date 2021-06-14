#include "Scientist.hpp"

using namespace std;
using namespace pandemic;

Player& Scientist::discover_cure(Color c){
    const int needed = n;
    if(!(board.is_research_station(city))){
        string str = city_string(city)+ " does not have research station";

        __throw_invalid_argument(str.c_str());
    }
    int muchCards = 0;
    for (City ci : cards)
    {
        if (board.color_of(ci) == c)
        {
            muchCards++;
        }
    }
    if(muchCards < needed){
        string str = " have only " + to_string(muchCards)+" cards instead of "+ to_string(needed);
        __throw_length_error(str.c_str());
    }
    muchCards = 0;
    for (City ci : cards)
    {
        if (board.color_of(ci) == c)
        {
            cards.erase(ci);
            muchCards++;
        }
        if (muchCards == needed)
        {
            board.mark_cured(c);
            return *this;
        }
    }
    return *this;   
}