#pragma once
#include <iostream>
#include <map>
#include <string>
#include <set>
#include "City.hpp"
#include "Color.hpp"
using namespace std;

namespace pandemic{
    class Board{
        public:
            Board();
            int& operator[](City c);
            friend ostream& operator<<(ostream& o, const Board& board);
            bool is_clean() const;   //const from right mean --> this is a const
            bool research_station(City c) const;
            void build_research_station(City c);
            bool is_connected(City& c1, City& c2);
            Color get_city_color(City c) const;
            bool cure_exist(Color color) const;
            void insert_cure(Color color);
            void remove_cures();
            void remove_stations();

        
        map<City, set<City>> city_connections;
        set<City> existing_research_station;
        map<City,int> disease_level;
        set<Color> color_cure;
        map<City,Color> cities_color;
        map<string, Color> _Color;
            
            
            /*const map<City,Color> cities_color{
            {Algiers, Black}, {Atlanta, Blue}, {Baghdad, Black}
            {Bangkok, Red}, {Beijing, Red}, {Bogota, Yellow}, {BuenosAires, Yellow}, {Cairo, Black}, 
            {Chennai, Black}, {Chicago, Blue}, {Delhi, Black}, {Essen, Blue}, {HoChiMinhCity, Red}, 
            {HongKong, Red}, {Istanbul, Black}, {Jakarta, Red}, {Johannesburg, Yellow}, {Karachi, Black}, 
            {Khartoum, Yellow}, {Kinshasa, Yellow}, {Kolkata, Black}, {Lagos, Yellow}, {Lima, Yellow},
            {London, Blue}, {LosAngeles, Yellow}, {Madrid, Blue}, {Manila, Red}, {MexicoCity, Yellow},
            {Miami, Yellow}, {Milan, Blue}, {Montreal, Blue}, {Moscow, Black}, {Mumbai, Black}, 
            {NewYork, Blue}, {Osaka, Red}, {Paris, Blue}, {Riyadh, Black}, {SanFrancisco, Blue}, 
            {Santiago, Yellow}, {SaoPaulo, Yellow}, {Seoul, Red}, {Shanghai, Red}, {StPetersburg, Blue}
            {Sydney, Red}, {Taipei, Red}, {Tehran, Black}, {Tokyo, Red}, {Washington, Blue}
            };*/



    };



};