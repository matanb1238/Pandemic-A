#include "Dispatcher.hpp"
using namespace std;
using namespace pandemic;

Player& Dispatcher::fly_direct(City c){
    if(board.has_station(city))
        city = c;
    return *this;
}
