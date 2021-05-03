#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"

#include "Researcher.hpp"
#include "Scientist.hpp"
#include "FieldDoctor.hpp"
#include "GeneSplicer.hpp"
#include "OperationsExpert.hpp"
#include "Dispatcher.hpp"
#include "Medic.hpp"
#include "Virologist.hpp"
#include "doctest.h"

using namespace pandemic;

#include <iostream>
#include <stdexcept>
using namespace std;

TEST_CASE("Researcher"){
    Board board;  // Initialize an empty board (with 0 disease cubes in any city).
	board[City::NewYork] = 1;      // put 1 blue disease cubes in NewYork.
	board[City::Kinshasa] = 2;      // put 2 Yellow disease cubes in Kinshasa
	board[City::MexicoCity] = 3;    // put 3 yellow disease cubes in MexicoCity
	board[City::HoChiMinhCity] = 1; // put 1 red disease cube in HoChiMinhCity
	board[City::Chicago] = 1;       // put 1 blue disease cube in Chicago
    Researcher player {board, City::NewYork};
    //player.build();                  //build research station in new york
    CHECK_EQ(board[City::NewYork],1);
    CHECK_EQ(board[City::Kinshasa],2);
    CHECK_EQ(board[City::MexicoCity],3);
    CHECK_EQ(board[City::HoChiMinhCity],1);
    CHECK_EQ(board[City::Chicago],1);
    CHECK_THROWS(player.treat(City::Bogota)); //The Player in New york not in bogota
    player.take_card(City::Paris)
	 .take_card(City::Atlanta)
	 .take_card(City::Chicago)
	 .take_card(City::NewYork)
	 .take_card(City::Washington)
     .take_card(City::SanFrancisco);
    player.discover_cure(Color::Blue);   //Researcher can discover cure without research station
    player.treat(City::NewYork);
    CHECK_EQ(board[City::NewYork],0);   //The cure discoverd --> disease level = 0
    player.take_card(City::Madrid)
	 .take_card(City::Miami)
	 .take_card(City::Bogota)
	 .take_card(City::MexicoCity)
	 .take_card(City::Lima)
     .take_card(City::SaoPaulo);
     CHECK_THROWS(player.fly_direct(City::Lagos));            //Lagos card not exist
     CHECK_THROWS(player.fly_shuttle(City::Lagos));           //New york card not exist

    board[City::Miami] = 1;          // put 1 Yellow disease cubes in Miami.
	board[City::Bogota] = 2;         // put 2 Yellow disease cubes in Bogota
	board[City::MexicoCity] = 2;     // change the number of 3 yellow disease to 2 Yellow disease cubes in MexicoCity
	board[City::Lima] = 1;           // put 1 red disease cube in Lima
	board[City::SaoPaulo] = 1;       // put 1 blue disease cube in SaoPaulo
    CHECK_EQ(board[City::Miami],1);
    CHECK_EQ(board[City::Bogota],2);
    CHECK_EQ(board[City::MexicoCity],2);
    CHECK_EQ(board[City::Lima],1);
    CHECK_EQ(board[City::SaoPaulo],1);
    player.fly_direct(City::Bogota);  //fly from new york to bogota
    CHECK_THROWS(player.discover_cure(Color::Yellow));      //Not enough cards
    CHECK_THROWS(player.treat(City::NewYork));    //new york cubes = 0
    CHECK_THROWS(player.drive(City::NewYork));   //New york and Bogota not neighb
    player.treat(City::Bogota);
    CHECK_EQ(board[City::Bogota],1);
    player.treat(City::Bogota);
    CHECK_EQ(board[City::Bogota],0);
    CHECK_THROWS(player.treat(City::Bogota));       //disease level is 0
    

}