#pragma once
#include "Board.hpp"
#include "City.hpp"
#include "Player.hpp"

using namespace std;

namespace pandemic{
    class Dispatcher : public Player{
        public:
            Dispatcher(Board& board, City city);
            //Player& fly_direct(City c);
            string role()const{
                return "Dispatcher";
            }
    };
};