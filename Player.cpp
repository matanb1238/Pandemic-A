#include "Player.hpp"
#include <stdio.h>

using namespace std;
using namespace pandemic;

Player& Player::take_card(City c){
    cards.insert(c);
    return *this;
}

Player& Player::drive(City c){
    if(!board.is_connected(city, c)){
        string str = city_string(c)+" and " + city_string(city);
        __throw_invalid_argument(str.c_str());
    }
    std::cout << "drive from " +city_string(city) +" current city: " << city_string(c) << std::endl;

    city = c;
    return *this;
}

Player& Player::fly_direct(City c){
    if(!(cards.count(c))){
        string str = city_string(c) + " isn't on deck";
        __throw_invalid_argument(str.c_str());
    }
    city = c;
    cards.erase(c);
    return *this;
}

Player& Player::fly_charter(City c){
    if(!(cards.count(city))){
        string str = city_string(city) + " isn't on deck";
        __throw_invalid_argument(str.c_str());
    }
    cards.erase(city);
    std::cout << "fly charter from " +city_string(city) +" current city: " << city_string(c) << std::endl;

    city = c;
    return *this;
}

Player& Player::fly_shuttle(City c){
    if (!board.is_research_station(c))
    {
        string str = city_string(c) + " does not have research station";
        __throw_invalid_argument(str.c_str());
    }
    if (!board.is_research_station(city))
    {
        string str = city_string(city) + " does not have research station";
        __throw_invalid_argument(str.c_str());
    }
    std::cout << "fly shuttle from " +city_string(city) +" current city: " << city_string(c) << std::endl;
    city = c;
    return *this;
}

Player& Player::build(){
    if(board.is_research_station(city)){
        string str = "There is already a research station in " + city_string(city);
        __throw_invalid_argument(str.c_str());
    }
    if(!cards.count(city)){
        string str = "there isn't city card of " + city_string(city);
        __throw_logic_error(str.c_str());
    }
    std::cout << "build research station in " +city_string(city) << std::endl;
    board.build_research_station(city);
    cards.erase(city);
    return *this;
}

Player& Player::discover_cure(Color c){
    const int needed = 5;
    if(!board.is_research_station(city)){
        string str = city_string(city)+" does not have research station";
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
    if(muchCards >= needed){
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
    }else{
        string str = "only have "+ to_string(muchCards) + " cards instead of " + to_string(needed);
        __throw_invalid_argument(str.c_str());
    } 
    std::cout << "discoverd cure color of " + color_string(c) +" in " << city_string(city) << std::endl;

    return *this; 
}

Player& Player::treat(City c){
    if (city != c)
    {           
        string str = "Player isn't in this "+ city_string(c);
        __throw_invalid_argument(str.c_str());
    }
    if (board[c] < 1)
    {
        string str =  city_string(c) + " has no disease";
        __throw_invalid_argument(str.c_str());
    }
    if(board.is_cure_discoverd(c)){
        board[c] = 0;
    }else{
        board[c]--;
    }
    return *this;
}
