#include "GeneSplicer.hpp"
using namespace std;
using namespace pandemic;

GeneSplicer::GeneSplicer(Board& board, City city): Player(board, city){
    this->genesplicer = 1;
}

/*Player& GeneSplicer::discover_cure(Color color){
    if(!board->research_station(city)){
        throw invalid_argument("There is no research station in the city");
    }

    if(player_cards.size()<NUM_5){
        throw invalid_argument("Not enough cards");
    }
    int tmp=0;
    for(const auto& var : player_cards){
        player_cards.erase(var);
        tmp++;
        if(tmp==NUM_5){
            break;
        }
    }
    board->insert_cure(color);
    return *this;
}*/