#include "Virologist.hpp"
using namespace std;
using namespace pandemic;

Player& Virologist::treat(City c){
    if(!cards.count(c)){
        string str = city_string(c) + " City isn't in deck";
        __throw_invalid_argument(str.c_str());
    }
    if(board.is_cure_discoverd(c)){
        board[c] = 0;
    }else{
        board[c]--;
    }
    return *this;
}
