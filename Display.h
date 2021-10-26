#ifndef DISPLAY_H
#define DISPLAY_H
#include <string>
using namespace std;

class Display {
  
	private: 
		int[22] player;
		int[22] dealer;
		int playerWins=0;
		int dealerWins=0;
		int tiesWins=0;
		
	public: 
		Display();
		void displayStart();
		void displayScreen();
		void update(int playerHand[22], int dealerHand[22]);
		void displayWin(std::string winner);
	

	
};
#endif
