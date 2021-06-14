#include "OperationsExpert.hpp"
using namespace std;
using namespace pandemic;

Player& OperationsExpert::build(){
    if(board.is_research_station(city)){
        string str = "There is already a research station in "+ city_string(city) ;
        __throw_logic_error(str.c_str());
    }
    board.build_research_station(city);
    return *this;
}