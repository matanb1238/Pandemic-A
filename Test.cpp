#include "doctest.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdexcept>
#include <string>

#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "OperationsExpert.hpp"
#include "Dispatcher.hpp"
#include "Scientist.hpp"
#include "Researcher.hpp"
#include "Medic.hpp"
#include "FieldDoctor.hpp"
#include "GeneSplicer.hpp"
#include "Virologist.hpp"

using namespace std;
using namespace pandemic;

const vector<City> cities_vec {
    City::Algiers,City::Atlanta,City::Baghdad,City::Bangkok,City::Beijing,City::Bogota,City::BuenosAires,City::Cairo,City::Chennai,
    City::Chicago,City::Delhi,City::Essen,City::HoChiMinhCity,City::HongKong,City::Istanbul,City::Jakarta,City::Johannesburg,
    City::Karachi,City::KePasio,City::Khartoum,City::Kinshasa,City::Kolkata,City::Lagos,City::Lima,City::London,City::LosAngeles,
    City::Madrid,City::Manila,City::MexicoCity,City::Miami,City::Milan,City::Montreal,City::Moscow,City::Mumbai,City::NewYork,
    City::Osaka,City::Paris,City::Riyadh,City::SanFrancisco,City::Santiago,City::SaoPaulo,City::Seoul,City::Shanghai,City::StPetersburg,
    City::Sydney,City::Taipei,City::Tehran,City::Tokyo,City::Washington
};


const map<City, vector<City>> cities_and_neighbors {
    { City::Algiers, {City::Madrid, City::Paris, City::Istanbul, City::Cairo } },
    { City::Atlanta, {City::Chicago, City::Miami, City::Washington } },
    { City::Baghdad, {City::Tehran, City::Istanbul, City::Cairo, City::Riyadh, City::Karachi } },
    { City::Bangkok, {City::Kolkata, City::Chennai, City::Jakarta, City::HoChiMinhCity, City::HongKong } },
    { City::Beijing, {City::Shanghai, City::Seoul } },
    { City::Bogota, {City::MexicoCity, City::Lima, City::Miami, City::SaoPaulo, City::BuenosAires } },
    { City::BuenosAires, {Bogota, SaoPaulo } },
    { City::Cairo, {Algiers, Istanbul, Baghdad, Khartoum, Riyadh } },
    { City::Chennai, {Mumbai, Delhi, Kolkata, Bangkok, Jakarta } },
    { City::Chicago, {SanFrancisco, LosAngeles, MexicoCity, Atlanta, Montreal } },
    { City::Delhi, {Tehran, Karachi, Mumbai, Chennai, Kolkata } },
    { City::Essen, {London, Paris, Milan, StPetersburg } },
    { City::HoChiMinhCity, {Jakarta, Bangkok, HongKong, Manila } },
    { City::HongKong, {Bangkok, Kolkata, HoChiMinhCity, Shanghai, Manila, Taipei } },
    { City::Istanbul, {Milan, Algiers, StPetersburg, Cairo, Baghdad, Moscow } },
    { City::Jakarta, {Chennai, Bangkok, HoChiMinhCity, Sydney } },
    { City::Johannesburg, {Kinshasa, Khartoum } },
    { City::Karachi, {Tehran, Baghdad, Riyadh, Mumbai, Delhi } },
    { City::Khartoum, {Cairo, Lagos, Kinshasa, Johannesburg } },
    { City::Kinshasa, {Lagos, Khartoum, Johannesburg } },
    { City::Kolkata, {Delhi, Chennai, Bangkok, HongKong } },
    { City::Lagos, {SaoPaulo, Khartoum, Kinshasa } },
    { City::Lima, {MexicoCity, Bogota, Santiago } },
    { City::London, {NewYork, Madrid, Essen, Paris } },
    { City::LosAngeles, {SanFrancisco, Chicago, MexicoCity, Sydney } },
    { City::Madrid, {London, NewYork, Paris, SaoPaulo, Algiers } },
    { City::Manila, {Taipei, SanFrancisco, HoChiMinhCity, Sydney } },
    { City::MexicoCity, {LosAngeles, Chicago, Miami, Lima, Bogota } },
    { City::Miami, {Atlanta, MexicoCity, Washington, Bogota } },
    { City::Milan, {Essen, Paris, Istanbul } },
    { City::Montreal, {Chicago, Washington, NewYork } },
    { City::Moscow, {StPetersburg, Istanbul, Tehran } },
    { City::Mumbai, {Karachi, Delhi, Chennai } },
    { City::NewYork, {Montreal, Washington, London, Madrid } },
    { City::Osaka, {Taipei, Tokyo } },
    { City::Paris, {Algiers, Essen, Madrid, Milan, London } },
    { City::Riyadh, {Baghdad, Cairo, Karachi } },
    { City::SanFrancisco, {LosAngeles, Chicago, Tokyo, Manila } },
    { City::Santiago, {Lima } },
    { City::SaoPaulo, {Bogota, BuenosAires, Lagos, Madrid } },
    { City::Seoul, {Beijing, Shanghai, Tokyo } },
    { City::Shanghai, {Beijing, HongKong, Taipei, Seoul, Tokyo } },
    { City::StPetersburg, {Essen, Istanbul, Moscow } },
    { City::Sydney, {Jakarta, Manila, LosAngeles } },
    { City::Taipei, {Shanghai, HongKong, Osaka, Manila } },
    { City::Tehran, {Baghdad, Moscow, Karachi, Delhi } },
    { City::Tokyo, {Seoul, Shanghai, Osaka, SanFrancisco } },
    { City::Washington, {Atlanta, NewYork, Montreal, Miami } }
};


City random_city() {
    size_t t = (size_t)rand() % 48;
    int i = 0;
    for(const auto& city: cities_and_neighbors) {
        if(i == t) {
            return city.first;
        }
        i++;
    }
    return City::Atlanta;
}

//8 tests
TEST_CASE("OperationsExpert"){
    Board _board;
    City _city = City::Atlanta;
    OperationsExpert ox{_board, _city};
    Dispatcher di{_board, _city};
    //havn't the ability build without throwing card
    CHECK_THROWS(di.build());
    CHECK_NOTHROW(ox.build());
    //tried to fly direct without throwing a matching card
    CHECK_THROWS(ox.fly_direct(City::London));
    ox.take_card(City::London);
    //dispatcher can fly without card
    CHECK_NOTHROW(ox.fly_direct(City::London));
    CHECK_NOTHROW(di.fly_direct(City::London));
    CHECK_THROWS(di.build());
    //logicly we could have the london card after he was thrown by ox to fly london
    di.take_card(City::London);
    //now should work
    CHECK_NOTHROW(di.build());
    //already have research station
    CHECK_THROWS(ox.build());
}

//16 tests
TEST_CASE("Test Dispatcher"){
    Board _board;
    City _city = random_city();
    Dispatcher dis{_board, _city};
    OperationsExpert ox{_board, _city};
    //special ability of dispatcher
    CHECK_NOTHROW(dis.fly_direct(City::Madrid));
    CHECK_NOTHROW(dis.fly_direct(_city));
    CHECK_NOTHROW(dis.fly_direct(City::London));
    //don't have same ability
    CHECK_THROWS(ox.fly_direct(City::Madrid));
    CHECK_THROWS(ox.fly_direct(_city));
    CHECK_THROWS(ox.fly_direct(City::London));
    ox.take_card(City::Madrid);
    ox.take_card(City::London);
    ox.take_card(_city);
    //just after taking the cards
    CHECK_NOTHROW(ox.fly_direct(City::Madrid));
    CHECK_NOTHROW(ox.fly_direct(_city));
    CHECK_NOTHROW(ox.fly_direct(City::London));
    //don't have loindon card
    CHECK_THROWS(dis.build());
    dis.take_card(City::London);
    //now have london card
    CHECK_NOTHROW(dis.build());
    dis.take_card(_city);
    Color c1 = _board.color_of(_city);
    CHECK_NOTHROW(dis.fly_direct(_city));
    //try to find cure without reasearch station
    CHECK_THROWS(dis.discover_cure(c1));
    int mone = 0;
    for(City c : cities_vec){
        if(_board.color_of(c)==_board.color_of(_city)){
            dis.take_card(c);
            mone++;
        }
        if(mone >= 5){
            break;
        }
    }
    
    CHECK_NOTHROW(dis.fly_direct(_city));
    //build research station in _city
    CHECK_NOTHROW(dis.build());
    //can discover cure beacause we have 5 cards other than city card we throwed
    CHECK_NOTHROW(dis.discover_cure(c1));
}


//7 tests   
TEST_CASE("Test Scientist"){
    Board _board;
    City _city = Atlanta; //blue city
    int n = 3;
    Scientist scientist{_board, _city, n};
    scientist.take_card(_city); //Atlanta
    Color c1 = _board.color_of(_city);// blue
    //does not have reasearch station
    CHECK_THROWS(scientist.discover_cure(c1));
    scientist.build();
    //not enought cards
    CHECK_THROWS(scientist.discover_cure(c1));
    int mone  = 0;
    for(City c : cities_vec){
        if(_board.color_of(c)==_board.color_of(Algiers)){
            scientist.take_card(c);
            mone++;
        }
        if(mone >= 3){
            break;
        }
    }
    Color c3 = _board.color_of(Riyadh);//black
    Color c2 = _board.color_of(_city);
    //there is 3 cards in the same color as _city
    CHECK_NOTHROW(scientist.discover_cure(c2));
    //already discoverd
    CHECK_THROWS(scientist.discover_cure(c2));

    //there is 3 cards *NOT* the same color as _city
    CHECK_THROWS(scientist.discover_cure(c3));
    mone  = 0;
    for(City c : cities_vec){
        if(_board.color_of(c)==_board.color_of(_city)){
            scientist.take_card(c);
            mone++;
        }
        if(mone >= 3){
            break;
        }
    }
    //there is 3 cards same color as _city
    CHECK_NOTHROW(scientist.discover_cure(c2));
    //already throwd the 3 cards he had
    CHECK_THROWS(scientist.discover_cure(c2));  
}

TEST_CASE("Test Researcher"){
    Board _board;
    City _city = City::Atlanta;
    Researcher res{_board, _city};
    Color _color = _board.color_of(_city);
    _board.found_med(_color);
    CHECK_THROWS(res.discover_cure(_color)); // Doesn't have 5 cards
    int count_res = 0;
    for (City c : cities_vec){
        if (count_res == 5){
            break;
        }
        if(_board.color_of(c) == _color){
            res.take_card(c);
            count_res++;
        }
    }
    CHECK_NOTHROW(res.discover_cure(_color)); // Has 5 cards
    OperationsExpert ox{_board, _city};
    ox.take_card(_city);
    CHECK_THROWS(res.discover_cure(_color)); // Doesn't have 5 cards
    int count_ox = 0;
    for (City c : cities_vec){
        if (count_ox == 5){
            break;
        }
        if(_board.color_of(c) == _color){
            ox.take_card(c);
            count_ox++;
        }
    }
    CHECK_THROWS(ox.discover_cure(_color)); // City doesn't have research station
    ox.build();
    CHECK_NOTHROW(ox.discover_cure(_color)); // Has 5 cards and research station
}


TEST_CASE("Test Medic"){
    Board _board;
    City _city = City::Atlanta;
    OperationsExpert ox{_board, _city};
    Color _color = _board.color_of(_city);
    _board.found_med(_color);
    _board[_city] = 4;
    int count = 0;
    for (City c : cities_vec){
        if (count == 5){
            break;
        }
        if(_board.color_of(c) == _color){
            ox.take_card(c);
            count++;
        }
    }
    ox.build();
    ox.discover_cure(_color);
    ox.treat(_city);
    CHECK(_board[_city]==3); // Treat is decreasing the level by 1
    Medic med{_board, _city};
    CHECK(_board[_city]==0); // Should reset the level of disease to 0 
    _board.found_med(_color);
    _board[_city] = 4;
    med.treat();
    CHECK(_board[_city]==0); // By treating, medic should reset the level of disease to 0
}


TEST_CASE("Test Virologist"){
    Board _board;
    City _city = City::Atlanta;
    OperationsExpert ox{_board, _city};
    ox.take_card(_city);
    _board[_city] = 1;
    _board[City::Algiers] = 1;
    _board[City::Beijing] = 1;
    _board[City::Johannesburg] = 1;
    CHECK_NOTHROW(ox.treat(City::Atlanta)); // atlanta 3
    CHECK_THROWS(ox.treat(City::Chicago)); // Isn't in this city
    ox.take_card(City::Chicago);
    ox.fly_direct(City::Chicago);
    CHECK_THROWS(ox.treat(City::Chicago)); // "Blue disease" has already been treated
    _board[_city] = 1;
    _board[City::Algiers] = 1;
    _board[City::Beijing] = 1;
    _board[City::Johannesburg] = 1;
    Virologist vir{_board, _city};
    vir.take_card(City::Atlanta);
    vir.take_card(City::Algiers);
    vir.take_card(City::Beijing);
    vir.take_card(City::Johannesburg);
    vir.take_card(City::Chicago);
    CHECK_NOTHROW(vir.treat(City::Atlanta)); // Blue
    CHECK_NOTHROW(vir.treat(City::Algiers)); // Black
    CHECK_NOTHROW(vir.treat(City::Beijing)); // Red
    CHECK_NOTHROW(vir.treat(City::Johannesburg)); // Yellow
    CHECK_THROWS(ox.treat(City::Chicago)); // "Blue disease" has already been treated
    CHECK_THROWS(vir.treat(City::Atlanta)); // Hasn't the card
}


TEST_CASE("Test GeneSplicer"){
    Board _board;
    City _city = City::Taipei;
    GeneSplicer gs{_board, _city};
    Dispatcher di{_board, _city};
    gs.take_card(City::Atlanta);
    gs.take_card(City::Bangkok);
    gs.take_card(City::Cairo);
    gs.take_card(City::Washington);
    gs.take_card(City::Tokyo);

    di.take_card(City::Istanbul);
    di.take_card(City::Baghdad);
    di.take_card(City::Mumbai);
    di.take_card(City::Riyadh);
    di.take_card(City::Tehran);
    
    //ability
    CHECK_NOTHROW(gs.discover_cure(Color::Red));
    //discovered already
    CHECK_THROWS(di.discover_cure(Color::Red));
    //there is five of the same color
    CHECK_NOTHROW(di.discover_cure(Color::Black));
    gs.take_card(City::Atlanta);
    gs.take_card(City::Bangkok);
    gs.take_card(City::Cairo);
    gs.take_card(City::Washington);
    gs.take_card(City::Tokyo);
    CHECK_THROWS(gs.discover_cure(Color::Black));
}

TEST_CASE("Test FieldDoctor"){
    Board _board;
    City _city = City::Taipei;
    FieldDoctor fd{_board, _city};
    Dispatcher ox{_board, _city};
    City conCity = City::Seoul;
    City notConCity = City::Algiers;
    //can treat connected city
    CHECK_NOTHROW(fd.treat(conCity));
    //can treat his city
    CHECK_NOTHROW(ox.treat(_city));
    //cannot treat a cured city
    CHECK_THROWS(fd.treat(_city));
    //cannot treat unconnected city
    CHECK_THROWS(fd.treat(notConCity));
    ox.fly_direct(notConCity);
    //because he is over there
    CHECK_NOTHROW(fd.treat(notConCity));
}