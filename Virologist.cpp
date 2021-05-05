#include "Virologist.hpp"
using namespace std;
using namespace pandemic;

Player& Virologist::treat(City c){
    if(cards.count(c) < 1){
        __throw_invalid_argument("City isn't in deck");
    }
    if(board.has_medicine(c)){
        board[c] = 0;
    }else{
        board[c]--;
    }
    return *this;
}
