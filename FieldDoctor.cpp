#include "FieldDoctor.hpp"
using namespace std;
using namespace pandemic;

Player& FieldDoctor::treat(City c){
    if (board[c] < 1)
    {
        __throw_invalid_argument("City has no disease");
    }
    if(!board.is_neighbors(city,c)){
        __throw_invalid_argument("Cities are not connected");
    }
    board[c] = 0;
    return *this;
}
