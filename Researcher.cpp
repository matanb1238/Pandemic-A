#include "Researcher.hpp"

using namespace std;
using namespace pandemic;

Player& Researcher::discover_cure(Color c){
    const int needed = 5;
    int muchCards = 0;
    for (City ci : cards)
    {
        if (board.color_of(ci) == c)
        {
            muchCards++;
        }
    }
    if(muchCards < needed){
        string str = " have only " + to_string(muchCards) + " cards instead of "+ to_string(needed);
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