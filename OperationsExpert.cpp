#include "OperationsExpert.hpp"
using namespace std;
using namespace pandemic;

OperationsExpert::OperationsExpert(Board& board, City city) : Player(board, city){
    this->operationsexpert = 1;
}

/*Player& OperationsExpert::build(){
    if(!board->research_station(city)){
        board->build_research_station(city);
        return *this;
    }
    throw invalid_argument("The city already have Research station");
}*/