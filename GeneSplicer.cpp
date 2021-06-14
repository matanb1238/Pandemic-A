#include "GeneSplicer.hpp"
using namespace std;
using namespace pandemic;

Player& GeneSplicer::discover_cure(Color c){
    const int needed = 5;  
    if(!board.is_research_station(city)){
        string str = city_string(city) + " does not have research station";
        __throw_invalid_argument(str.c_str());
    }
    if (cards.size() < 5){
        __throw_invalid_argument("deck isn't big enought to draw 5 cards");
    }
    int muchCards = 0;
    for (City ci : cards)
    {
        cards.erase(ci);
        muchCards++;
        if (muchCards == needed)
        {
            board.mark_cured(c);
            return *this;
        }
    }
    return *this;
}

