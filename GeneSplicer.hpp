#pragma once
#include "Board.hpp"
#include "City.hpp"
#include "Player.hpp"
#include <set>

using namespace std;


namespace pandemic{
    class GeneSplicer : public Player{
        public:
        GeneSplicer(Board& board, City city);
        string role()const{
                return "GeneSplicer";
        }
        //Player& discover_cure(Color color);
    };
};