#include "Researcher.hpp"

using namespace std;
using namespace pandemic;

Player& Researcher::discover_cure(Color c){
    const int needed = 5;
    Color color = board.color_of(city);
    if(!(color == c)){
        __throw_invalid_argument("not the color as the city wer'e in");
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