#include "Medic.hpp"
using namespace std;
using namespace pandemic;


Medic::Medic(Board& board, City city) : Player(board, city){}

Player& Medic::treat(City c){
    return *this;
}