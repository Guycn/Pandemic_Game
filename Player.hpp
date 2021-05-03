#pragma once
#include <set>
#include <string>
#include "Board.hpp"
#include "City.hpp"
using namespace std;


namespace pandemic{

    class Player{
        protected:
            string role_player;
            City city;
            set<City> player_cards;
            Board *board;
            set<City>temp;
            uint num;
            uint Res;
            uint Field_Doctor;
            uint dispatcher;
            uint genesplicer;
            uint operationsexpert;
            uint virologist;
        
        
        
        
        public:
            Player(Board& board, City c);
            virtual Player& drive(City c);
            virtual Player& fly_direct(City c);
            virtual Player& fly_charter(City c);
            virtual Player& fly_shuttle(City c);
            virtual Player& build();
            virtual Player& discover_cure(Color color);
            virtual Player& treat(City c);
            virtual string role()const=0;
            virtual Player& take_card(City c);



    };
};
