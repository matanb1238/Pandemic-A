#include "Medic.hpp"
using namespace std;
using namespace pandemic;

Player& Medic::treat(){
    if(!cards.count(city)){
        string str = city_string(city) + " isn't on deck";
        __throw_invalid_argument(str.c_str());
    }
    if (board[city] < 1)
    {
        string str = city_string(city) + " has no disease";
        __throw_invalid_argument(str.c_str());
    }
    board[city] = 0;
    return *this;
}
