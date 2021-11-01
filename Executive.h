#ifndef EXECUTIVE_H
#define EXECUTIVE_H
#include <string>
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include "Blackjack.h"

class Executive {
    private:
        Blackjack* dealer;
        Blackjack* player;
        std::string winner;
        int currentPlayer;
	int wins;
	int ties;
	int losses;


    public:
        Executive();
	
	/*
	* @pre Executive initialized
	* @post runs through the game
	* @param none
	* @return none
	*/
        void run();
	
	/*
	* @pre Executive initialized
	* @post displays the game information including upto all of the player hand and one card of the dealer hand
	* @param none
	* @return none
	*/
	void display();
	
	/*
	* @pre Executive initialized
	* @post displays the game information including upto all of the player hand and all of the dealer hand
	* @param none
	* @return none
	*/	
	void displayend();
	
	/*
	* @pre Executive initialized
	* @post displays the game information and informs the player that they bust
	* @param none
	* @return none
	*/	
	void displaybust();
        
	/*
	* @pre Executive initialized
	* @post changes the internal variable currentPlayer to the next player in line 
	* @param none
	* @return none
	*/	
	void turnChange();
        
	/*
	* @pre Executive initialized
	* @post calculates the most recent winner and displays and saves the winner
	* @param the two blackjacks that are checked
	* @return none
	*/	
	void winningCondition(Blackjack* dealer, Blackjack* player);
	
	/*
	* @pre Executive initialized
	* @post checks if the player wants to quit
	* @param none
	* @return 1 if the player wants to continue, 0 if the player wants to quit
	*/	
	bool contGame();
};

#endif
