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
        void run();
	void display();
	void displayend();
	void displaybust();
        void turnChange();
        void winningCondition(Blackjack* dealer, Blackjack* player);
	bool contGame();
};

#endif
