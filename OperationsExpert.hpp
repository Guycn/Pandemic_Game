#pragma once
#include "Board.hpp"
#include "City.hpp"
#include "Player.hpp"

using namespace std;


namespace pandemic{
    class OperationsExpert : public Player{
        public:
        OperationsExpert(Board& board, City city);
        //Player& build();
        string role()const{
            return "OperationsExpert";
        }
    };
};

