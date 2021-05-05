#include "Scientist.hpp"

using namespace std;
using namespace pandemic;

Player& Scientist::discover_cure(Color c){
    const int needed = n;
    Color color = board.color_of(city);
    if(!(color == c)){
        __throw_invalid_argument("not the color as the city wer'e in");
    }
    if(!(board.has_station(city))){
        __throw_invalid_argument("does not have research station");
    }
    int muchCards = 0;
    for (City ci : cards)
    {
        if (board.color_of(ci) == color)
        {
            muchCards++;
        }
    }
    if(muchCards >= needed){
        muchCards = 0;
        for (City ci : cards)
        {
            if (board.color_of(ci) == color)
            {
                cards.erase(ci);
                muchCards++;
            }
            if (muchCards == needed)
            {
                board.found_med(color);
                return *this;
            }
        }
    }
    return *this;   
}