#include "Scientist.hpp"
using namespace std;
using namespace pandemic;

Scientist::Scientist(Board& board, City city, int num_4) : Player(board, city){
    this->num = num_4;
}