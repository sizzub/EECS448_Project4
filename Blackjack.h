#ifndef BLACKJACK_H
#define BLACKJACK_H
#include <string>
#include <vector>
using namespace std;

class Blackjack {
  
private: 
	int hand[22];
	int handSize;
	
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
	
};
#endif
