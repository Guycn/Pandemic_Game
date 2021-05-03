#include "Virologist.hpp"
using namespace std;
using namespace pandemic;


Virologist::Virologist(Board& board, City city) : Player(board, city){
    this->virologist = 1;
}

/*Player& Virologist::treat(City c){
    if(city != c){
        if(!player_cards.contains(city)){
            throw invalid_argument("illegal action: you do not have the city card");
        }
        if(board->disease_level[c]==0){
            throw invalid_argument("The disease level in the city is 0");
        }
        player_cards.erase(c);
        if(board->cure_exist(board->cities_color[c])){
            board->disease_level[c] = 0;
            return *this;
        }
        board->disease_level[c] -=1;
        return *this;
    }
    if(board->cure_exist(board->cities_color[c])){
            board->disease_level[c] = 0;
            return *this;
    }
    board->disease_level[city] -=1;
    return *this;
}*/
