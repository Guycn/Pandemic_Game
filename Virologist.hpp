#pragma once
#include "Board.hpp"
#include "City.hpp"
#include "Player.hpp"

using namespace std;


namespace pandemic{
    class Virologist : public Player{
        public:
        Virologist(Board& board, City city);
        string role()const{
            return "Virologist";
        }
        //Player& treat(City c);
    };
};