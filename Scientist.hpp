#pragma once
#include "Board.hpp"
#include "City.hpp"
#include "Player.hpp"

using namespace std;

namespace pandemic{
    class Scientist : public Player{
        public:
            Scientist(Board& board, City city, int num_4 = 4); 
            string role()const{
            return "Scientist";
            }
    };
};