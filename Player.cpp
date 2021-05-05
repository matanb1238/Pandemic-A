#include "Player.hpp"
#include <stdio.h>

using namespace std;
using namespace pandemic;

Player& Player::drive(City c){
    if(!board.is_neighbors(city, c)){
        __throw_invalid_argument("Isn't connected");
    }
    city = c;
    return *this;
}

Player& Player::fly_direct(City c){
    if(cards.count(c) < 1){
        __throw_invalid_argument("Isn't on deck");
    }
    city = c;
    cards.erase(c);
    return *this;
}

Player& Player::fly_charter(City c){
    if(!(cards.count(city))){
        __throw_invalid_argument("Isn't on deck");
    }
    cards.erase(city);
    city = c;
    return *this;
}

Player& Player::fly_shuttle(City c){
    if(!board.has_station(c)||!board.has_station(city)){
        __throw_invalid_argument("One of those cities does not have research station");
    }
    city = c;
    return *this;
}

Player& Player::build(){
    if (board.has_station(city)){
        __throw_invalid_argument("There is station already");
    }
    board.build_station(city);
    cards.erase(city);
    return *this;
}

Player& Player::discover_cure(Color c){
    const int needed = 5;
    Color color = board.color_of(city);
    if(!(color == c)){
        __throw_invalid_argument("Not the color as the city wer'e in");
    }
    if(!board.has_station(city)){
        __throw_invalid_argument("Does not have research station");
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
    }else{
        __throw_invalid_argument("You don't have enough cards in the same color");
    } 
    return *this; 
}

Player& Player::treat(City c){
    if (city != c)
    {
        __throw_invalid_argument("Player isn't in this city");
    }
    if (board[c] < 1)
    {
        __throw_invalid_argument("City has no disease");
    }
    if(board.has_medicine(c)){
        board[c] = 0;
    }else{
        board[c]--;
    }
    return *this;
}


Player& Player::take_card(City c){
    cards.insert(c);
    return *this;
}
