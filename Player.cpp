#include "Player.hpp"



using namespace std;
using namespace pandemic;
static const int NUM_5 = 5;


Player::Player(Board& board, City c){
    this->board = &board;
    this->city = c;
    this->num = NUM_5;
    this->Res = 0;
    this->Field_Doctor = 0;
    this->dispatcher = 0;
    this->genesplicer = 0;
    this->operationsexpert = 0;
    this->virologist = 0;
}

Player& Player::drive(City c){
    if(board->is_connected(this->city,c)){
        this->city = c;
        return *this;
    }
    throw invalid_argument(city_to_string.find(city)->second + " and " + city_to_string.find(c)->second + " Non-neighboring cities");
}

Player& Player::fly_direct(City c){
    if(dispatcher == 1){
        this->city = c;
    }
    if(!this->player_cards.contains(c)){               //non-exist card
        throw invalid_argument("illegal action: you do not have the city card");
    }
    this->city = c;
    this->player_cards.erase(c);                    //remove the card
    return *this;
}
Player& Player::fly_charter(City c){
    if(!this->player_cards.contains(this->city)){
        throw invalid_argument("illegal action: you do not have " + city_to_string.find(city)->second + " city card");
    }
    this->city = c;
    player_cards.erase(this->city);
    return *this;
}

Player& Player::fly_shuttle(City c){
    if(this->board->research_station(c) && this->board->research_station(this->city)){
        this->city = c;
    }
    else{
        throw invalid_argument(city_to_string.find(c)->second + " + " + city_to_string.find(city)->second + " One of the cities do not have research station");
    }
    return *this;
}

Player& Player::build(){
    if(operationsexpert == 1){    //Player --> operationsexpert
        if(this->board->research_station(this->city)){
            throw invalid_argument("The city already have Research station");
        }
        this->board->build_research_station(this->city);
        return *this;
    }
//-------------Player --> Not operationexpert -------------------
    if(this->board->research_station(this->city)){
        throw invalid_argument("The city already have Research station");
    }
    if(!this->player_cards.contains(this->city)){
        throw invalid_argument("illegal action: you do not have the city card");
    }
    this->board->build_research_station(this->city);
    this->player_cards.erase(this->city);
    return *this;
}

Player& Player::discover_cure(Color color){
    if(genesplicer == 1){            //Player -->genesplicer
        if(this->board->cure_exist(color)){
            return *this;
        }
        if(this->player_cards.size()<num){
            throw invalid_argument("Not enough cards");
        }
        int tmp=0;
        for(const auto& var : player_cards){
            player_cards.erase(var);
            tmp++;
            if(tmp==num){
                break;
            }
        }
        board->insert_cure(color);
        return *this;
    }
//------------------ Player --> not genesplicer --------------------
    if(!this->board->research_station(this->city) && Res == 0){
        throw invalid_argument("There is no research station in the city");
    }
    if(this->board->cure_exist(color)){
        return *this;
    }
    if(this->player_cards.size()<this->num){
    throw invalid_argument("Not enough cards");
    }
    for(const auto& var : player_cards){
        Color co = board->get_city_color(var);
        if(color == co && this->temp.size()<num){
            this->temp.insert(var);
            //this->player_cards.erase(var);
        }
    }
    if(this->temp.size() == num){
        this->board->insert_cure(color);
        for(const auto& k : temp){
            player_cards.erase(k);
        }
        this->temp.clear();
        return *this;
    }
    for(const auto& var : temp){
        this->player_cards.insert(var);
    }
    this->temp.clear();
    throw invalid_argument("Not enough cards");
}

Player& Player::treat(City c){
    if(Field_Doctor!=0){                   //Player -->FieldDoctor
        if((*board)[c]==0){
            throw invalid_argument("The disease level in the city is 0");
        }
        if(board->is_connected(city,c) || city==c){
            if(this->board->cure_exist(this->board->cities_color[this->city])){
                this->board->disease_level[city] = 0;
                return *this;
            }
            this->board->disease_level[city]--;
            return *this;
        }
    }
//--------------Player--> Not FieldDoctor -------------------------
    if(virologist == 1){                //Player-->Virologist
        if(board->disease_level[c]==0){
            throw invalid_argument("The disease level in the city is 0");
        }
        if(!player_cards.contains(c)){
            throw invalid_argument("illegal action: you do not have the city card");
        }
        player_cards.erase(c);
        if(board->cure_exist(board->cities_color[c])){
            board->disease_level[c] = 0;
            return *this;
        }
        board->disease_level[c] -=1;
        return *this;
    }

    if(this->city != c){
        throw invalid_argument("To lower the level of illness in the city you must be in the city");
    }
    if((*board)[c]==0){
        throw invalid_argument("The disease level in the city is 0");
    }
    if(this->board->cure_exist(this->board->cities_color[this->city])){
        this->board->disease_level[city] = 0;
        return *this;
    }
    this->board->disease_level[city]--;
    return *this;
}

Player& Player::take_card(City c){
    player_cards.insert(c);
    return *this;
}