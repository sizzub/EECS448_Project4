#ifndef BLACKJACK_H
#define BLACKJACK_H
#include <string>
using namespace std;

class Blackjack {
  
private: 
	int hand[22];
	int handSize;
	
public: 
	
	Blackjack(); //initialize hand and handSize
	
	int getHandSize();
	
	int getCard(int index); //returns the card at the given index (0 to 21) in the hand
	
	int handValue(); //returns the optimal hand value for the player (counts aces as 1 if they would cause a bust, 11 otherwise)
	
	bool isBust();
	
	void hit();
	
	int randomCard();
	
	string parseCard(int card);
	
	int cardValue(int card);
	
};
#endif
