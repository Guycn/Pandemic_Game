#include "Dispatcher.hpp"

using namespace std;
using namespace pandemic;

Dispatcher::Dispatcher(Board& board, City city) : Player(board, city){
    this->dispatcher = 1;
}
/*Player& Player::fly_direct(City c){
    city = c;
    return *this;
}*/