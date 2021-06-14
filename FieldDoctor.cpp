#include "FieldDoctor.hpp"
using namespace std;
using namespace pandemic;

Player& FieldDoctor::treat(City c){
    if (board[c] < 1)
    {
        string str = city_string(city) + " has no disease";
        __throw_invalid_argument(str.c_str());
    }
    if(!board.is_connected(city,c)){
        string str = city_string(city) + " and " + city_string(c) + "are not connected";
        __throw_invalid_argument(str.c_str());
    }
    board[c] = 0;
    return *this;
}
