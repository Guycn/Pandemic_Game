#include "Scientist.hpp"
using namespace std;
using namespace pandemic;

Scientist::Scientist(Board& board, City city, uint num_4) : Player(board, city){
    this->num = num_4;
}