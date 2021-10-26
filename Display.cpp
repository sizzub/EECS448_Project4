#include "Display.h"
#include <string>
#include <iostream>
using namespace std;

Display::Display() {

}

Display::displayStart(){
	cout<<"\x1B[2J\x1B[H";
    cout<<"This is the start display for the blackjack game";
}

Display::displayScreen(){
	cout<<"\x1B[2J\x1B[H";
	cout<<playerWins<<" "<<tiesWins<<" "<<dealerWins;
	cout<<"\nPlayer Hand:";
    for(int i=0; i<22; i++){
        cout<<player[i]<<" ";
    }
	cout<<"\nDealer Hand:";
    for(int i=0; i<22; i++){
        cout<<dealer[i]<<" ";
    }
}

Display::update(int playerHand[22], int dealerHand[22]){
	player=playerHand;
	dealer=dealerHand;
}

Display::displayWin(std::string winner){
	if(winner == "Player"){
		playerWins++
	}
	if(winner == "Push"){
		tiesWins++;
	}
	if(winner == "Dealer"){
		dealerWins++;
	}

	cout<<"\x1B[2J\x1B[H";
	cout<<winner;	
}