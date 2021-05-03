#include "Researcher.hpp"

using namespace std;
using namespace pandemic;

Researcher::Researcher(Board& board, City city) : Player(board, city){
    this->Res = 1;
}