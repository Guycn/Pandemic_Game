#include "FieldDoctor.hpp"
using namespace std;
using namespace pandemic;

 FieldDoctor::FieldDoctor(Board& board, City city): Player(board, city){
     this->Field_Doctor = 1;
 }

 /*Player& FieldDoctor::treat(City c){
     if(!board->is_connected(city,c)){
         throw invalid_argument("Non-neighboring cities");
     }
     if(board->disease_level[c]==0){
         throw invalid_argument("The disease level in the city is 0");
     }
     if(board->cure_exist(board->cities_color[c])){
         board->disease_level[c] = 0;
         return *this;
     }
     board->disease_level[c] -=1;
     return *this;

 }*/