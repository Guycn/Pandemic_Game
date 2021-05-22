#include <fstream>
#include "Board.hpp"

using namespace pandemic;
using namespace std;

Board::Board(){
    ifstream my_file{"cities_map.txt"};
    map<string, Color> _Color{
    {"Blue", Color::Blue},
    {"Black", Color::Black},
    {"Red", Color::Red},
    {"Yellow", Color::Yellow}
    };

    while(!my_file.eof()){
        string city;
        string color;
        string neighbor;
        my_file >> city >> color;
        cities_color[city_name.find(city)->second] = _Color.find(color)->second;  //add city color
        disease_level[city_name.find(city)->second] = 0;              //disease level start with 0
        while(my_file.peek()!='\n' && !my_file.eof()){          //connected city map
            my_file >> neighbor;
            city_connections[city_name.find(city)->second].insert(city_name.find(neighbor)->second);  //add city neighbors
        }
    }
    my_file.close();
}


int& Board::operator[](City c){
    return disease_level[c];
}

ostream& pandemic::operator<<(ostream& out, const Board& board){
    out <<"Disease level board\n" << endl;
    for(const auto& var : city_name){
        string city = var.first;
        int level = board.disease_level.find(var.second)->second;
        out << city <<"\t" << level <<"\n" << endl;
    }
    return out;
}

bool Board::is_clean()const{
    for(const auto& var : disease_level){
        if(var.second > 0){
            return false;
        }
    }
    return true;
}

bool Board::research_station(City c) const{
    return(existing_research_station.contains(c));
}

void Board::build_research_station(City c){
    existing_research_station.insert(c);
}

bool Board::is_connected(City& c1, City& c2){
    return(city_connections.at(c1).contains(c2));
}

Color Board::get_city_color(City c) const{
    return cities_color.at(c);
}

bool Board::cure_exist(Color color) const{
    return(color_cure.contains(color));
}

void Board::insert_cure(Color color){
    color_cure.insert(color);
}

void Board::remove_cures(){
    color_cure.clear();
}

void Board::remove_stations(){
    existing_research_station.clear();
}



