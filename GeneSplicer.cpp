#include "GeneSplicer.hpp"
using namespace std;
using namespace pandemic;

Player& GeneSplicer::discover_cure(Color c){
    const int needed = 5;  
    if(!board.has_station(city)){
        __throw_invalid_argument("does not have research station");
    }
    int muchCards = 0;
    if (cards.size() >= needed)
    {
        for (City ci : cards)
        {
            cards.erase(ci);
            muchCards++;
            if (muchCards == needed)
            {
                board.found_med(c);
                return *this;
            }
        }
    }
    return *this;
}

