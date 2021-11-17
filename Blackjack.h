#ifndef BLACKJACK_H
#define BLACKJACK_H
#include <string>
#include <vector>
using namespace std;

class Blackjack {
  
private: 
	int hand[22];
	int handSize;
	int bank;
	
public: 
	
	Blackjack(); //initialize hand and handSize
	
	/*
	* @pre hand initialized
	* @post none
	* @param none
	* @return handSize
	*/
	int getHandSize();
	
	/*
	* @pre hand initialized
	* @post none
	* @param index in the hand to check 
	* @return handSize
	*/
	int getCard(int index);
	
	/*
	* @pre hand initialized
	* @post none
	* @param none
	* @return optimal hand value for the player (counts aces as 1 if they would cause a bust, 11 otherwise)
	*/
	int handValue();
	
	/*
	* @pre hand initialized
	* @post none
	* @param none
	* @return true if hand value is over 21, false otherwise
	*/
	bool isBust();
	
	/*
	* @pre hand initialized
	* @post if hand size is less than 22 and the deck has cards in it it adds last card from deck to hand, 
		removes that card from deck, and increments hand sizes
	* @param the deck to draw from
	* @return none
	*/
	void hit(vector<int> &deck);
	
	/*
	* @pre none
	* @post none
	* @param none
	* @return pseudorandom int between 0 and 51
	*/
	int randomCard();
	
	/*
	* @pre none
	* @post none
	* @param int between 0 and 51 representing a card
	* @return string name of the card including face and suit
	*/
	string parseCard(int card);
	
	/*
	* @pre none
	* @post none
	* @param int between 0 and 51 representing a card
	* @return int point value of the card (aces counted as 11)
	*/
	int cardValue(int card);

	/*
	* @pre none
	* @post none
	* @param int value, the value of either how much the user lost or won
	* @return none
	*/
	void adjustBank(int value);

	/*
	* @pre none
	* @post none
	* @param int value, the amount the user is betting
	* @return returns true if the amount the user is betting is correct, false if not
	*/
	bool checkBet(int value);

	/*
	* @pre none
	* @post none
	* @param none
	* @return returns the bank total 
	*/
	int getBankValue();

	/*
	* @pre none
	* @post none
	* @param int value, the value of the users current bet
	* @return returns the users current bet doubled
	*/
	int doubleBet(int value);

	/*
	* @pre none
	* @post none
	* @param int value, the value of the users current bet
	* @return returns the users current bet halved
	*/
	int surrender(int value);
	
	
	/*
	* @pre none
	* @post resets all values in hand to -1 and sets handSize to 0
	* @param none
	* @return none
	*/
	void clearHand();

	/*
	* @pre none
	* @post resets all values for the player in order to continue on with the game
	* @param none
	* @return none
	*/
	void resetPlayer();
	
};
#endif
