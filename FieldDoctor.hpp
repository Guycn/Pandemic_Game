#pragma once
#include "Board.hpp"
#include "City.hpp"
#include "Player.hpp"
#include <set>
#include <string>

using namespace std;


namespace pandemic{
    class FieldDoctor : public Player{
        public:
        FieldDoctor(Board& board, City city);
        string role()const{
            return "FieldDoctor";
        }
    };
};