#pragma once
#include "City.hpp"


using namespace std;

enum Color{
    Blue,
    Red,
    Black,
    Yellow
};

const map<string, Color> str_color{
    { "Blue", Blue },
    { "Yellow", Yellow },
    {"Red", Red },
    { "Black", Black }
};

const map<City, Color> colors_of_cities {
    { Algiers, Black },
    { Atlanta, Blue },
    { Baghdad, Black },
    { Bangkok, Red },
    { Beijing, Red },
    { Bogota, Yellow },
    { BuenosAires, Yellow },
    { Cairo, Black },
    { Chennai, Black },
    { Chicago, Blue },
    { Delhi, Black },
    { Essen, Blue },
    { HoChiMinhCity, Red },
    { HongKong, Red },
    { Istanbul, Black },
    { Jakarta, Red },
    { Johannesburg, Yellow },
    { Karachi, Black },
    { Khartoum, Yellow },
    { Kinshasa, Yellow },
    { Kolkata, Black },
    { Lagos, Yellow },
    { Lima, Yellow },
    { London, Blue },
    { LosAngeles, Yellow },
    { Madrid, Blue },
    { Manila, Red },
    { MexicoCity, Yellow },
    { Miami, Yellow },
    { Milan, Blue },
    { Montreal, Blue },
    { Moscow, Black },
    { Mumbai, Black },
    { NewYork, Blue },
    { Osaka, Red },
    { Paris, Blue },
    { Riyadh, Black },
    { SanFrancisco, Blue },
    { Santiago, Yellow },
    { SaoPaulo, Yellow },
    { Seoul, Red },
    { Shanghai, Red },
    { StPetersburg, Blue },
    { Sydney, Red },
    { Taipei, Red },
    { Tehran, Black },
    { Tokyo, Red },
    { Washington, Blue }
};