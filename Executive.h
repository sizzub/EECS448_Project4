#ifndef EXECUTIVE_H
#define EXECUTIVE_H
#include <string>
#include <vector>
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include "Blackjack.h"

class Executive {
    private:
        Blackjack* dealer;
        Blackjack* player;
	vector<int> deck;
        std::string winner;
        int currentPlayer;
	int wins;
	int ties;
	int losses;
	
	char baseScreen[29][60]={{'_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','|','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','|','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_'},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ','D','E','A','L','E','R',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ','H','A','N','D',' ','V','A','L','U','E',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ','P','L','A','Y','E','R',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{'_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_'},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ','+','+','+',' ',' ',' ','O','O','O',' ',' ',' ','Z','Z','Z',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ','+','+','+',' ',' ',' ','O','O','O',' ',' ',' ','Z','Z','Z',' ',' '},{' ','+','a','b','c','+',' ','O','a','b','c','O',' ','N','a','b','c','N',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ','+','a','b','c','+',' ','O','a','b','c','O',' ','N','a','b','c','N',' '},{' ','+','d','C','d','+',' ','O','d','D','d','O',' ','N','d','M','d','N',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ','+','d','C','d','+',' ','O','d','D','d','O',' ','N','d','M','d','N',' '},{' ','+','c','b','a','+',' ','O','c','b','a','O',' ','N','c','b','a','N',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ','+','c','b','a','+',' ','O','c','b','a','O',' ','N','c','b','a','N',' '},{' ',' ','+','+','+',' ',' ',' ','O','O','O',' ',' ',' ','Z','Z','Z',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ','+','+','+',' ',' ',' ','O','O','O',' ',' ',' ','Z','Z','Z',' ',' '},{' ',' ',' ',' ',' ',' ','B','A','L','E','N','C','E',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ','B','E','T',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ','H','A','N','D',' ','V','A','L','U','E',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{'_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','|','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','|','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_'}};
    char cards[364][5]={{' ','v','v','v',' '},{'v','A',' ',' ','v'},{'v','a','|',' ','v'},{'v','-','+','-','v'},{'v',' ','|','a','v'},{'v',' ',' ','A','v'},{' ','v','v','v',' '},{' ','v','v','v',' '},{'v','2',' ',' ','v'},{'v','a',' ',' ','v'},{'v',' ',' ',' ','v'},{'v',' ',' ','a','v'},{'v',' ',' ','2','v'},{' ','v','v','v',' '},{' ','v','v','v',' '},{'v','3',' ',' ','v'},{'v','a',' ',' ','v'},{'v',' ','a',' ','v'},{'v',' ',' ','a','v'},{'v',' ',' ','3','v'},{' ','v','v','v',' '},{' ','v','v','v',' '},{'v','4',' ',' ','v'},{'v','a',' ','a','v'},{'v',' ',' ',' ','v'},{'v','a',' ','a','v'},{'v',' ',' ','4','v'},{' ','v','v','v',' '},{' ','v','v','v',' '},{'v','5',' ',' ','v'},{'v','a',' ','a','v'},{'v',' ','a',' ','v'},{'v','a',' ','a','v'},{'v',' ',' ','5','v'},{' ','v','v','v',' '},{' ','v','v','v',' '},{'v','6',' ',' ','v'},{'v',' ','a','a','v'},{'v','a',' ','a','v'},{'v','a','a',' ','v'},{'v',' ',' ','6','v'},{' ','v','v','v',' '},{' ','v','v','v',' '},{'v','7',' ',' ','v'},{'v',' ','a','a','v'},{'v','a','a','a','v'},{'v','a','a',' ','v'},{'v',' ',' ','7','v'},{' ','v','v','v',' '},{' ','v','v','v',' '},{'v','8',' ',' ','v'},{'v','a','a','a','v'},{'v','a',' ','a','v'},{'v','a','a','a','v'},{'v',' ',' ','8','v'},{' ','v','v','v',' '},{' ','v','v','v',' '},{'v','9',' ',' ','v'},{'v','a','a','a','v'},{'v','a','a','a','v'},{'v','a','a','a','v'},{'v',' ',' ','9','v'},{' ','v','v','v',' '},{' ','v','v','v',' '},{'v','X',' ','a','v'},{'v','a','a','a','v'},{'v','a',' ','a','v'},{'v','a','a','a','v'},{'v','a',' ','X','v'},{' ','v','v','v',' '},{' ','v','v','v',' '},{'v','J',' ',' ','v'},{'v','a','+',' ','v'},{'v','+','j','+','v'},{'v',' ','+','a','v'},{'v',' ',' ','J','v'},{' ','v','v','v',' '},{' ','v','v','v',' '},{'v','Q',' ',' ','v'},{'v','a','O',' ','v'},{'v','O','i','O','v'},{'v',' ','O','a','v'},{'v',' ',' ','Q','v'},{' ','v','v','v',' '},{' ','v','v','v',' '},{'v','K',' ',' ','v'},{'v','a','Z',' ','v'},{'v','N','h','N','v'},{'v',' ','Z','a','v'},{'v',' ',' ','K','v'},{' ','v','v','v',' '},{' ','v','v','v',' '},{'v','A',' ',' ','v'},{'v','b','|',' ','v'},{'v','-','+','-','v'},{'v',' ','|','b','v'},{'v',' ',' ','A','v'},{' ','v','v','v',' '},{' ','v','v','v',' '},{'v','2',' ',' ','v'},{'v','b',' ',' ','v'},{'v',' ',' ',' ','v'},{'v',' ',' ','b','v'},{'v',' ',' ','2','v'},{' ','v','v','v',' '},{' ','v','v','v',' '},{'v','3',' ',' ','v'},{'v','b',' ',' ','v'},{'v',' ','b',' ','v'},{'v',' ',' ','b','v'},{'v',' ',' ','3','v'},{' ','v','v','v',' '},{' ','v','v','v',' '},{'v','4',' ',' ','v'},{'v','b',' ','b','v'},{'v',' ',' ',' ','v'},{'v','b',' ','b','v'},{'v',' ',' ','4','v'},{' ','v','v','v',' '},{' ','v','v','v',' '},{'v','5',' ',' ','v'},{'v','b',' ','b','v'},{'v',' ','b',' ','v'},{'v','b',' ','b','v'},{'v',' ',' ','5','v'},{' ','v','v','v',' '},{' ','v','v','v',' '},{'v','6',' ',' ','v'},{'v',' ','b','b','v'},{'v','b',' ','b','v'},{'v','b','b',' ','v'},{'v',' ',' ','6','v'},{' ','v','v','v',' '},{' ','v','v','v',' '},{'v','7',' ',' ','v'},{'v',' ','b','b','v'},{'v','b','b','b','v'},{'v','b','b',' ','v'},{'v',' ',' ','7','v'},{' ','v','v','v',' '},{' ','v','v','v',' '},{'v','8',' ',' ','v'},{'v','b','b','b','v'},{'v','b',' ','b','v'},{'v','b','b','b','v'},{'v',' ',' ','8','v'},{' ','v','v','v',' '},{' ','v','v','v',' '},{'v','9',' ',' ','v'},{'v','b','b','b','v'},{'v','b','b','b','v'},{'v','b','b','b','v'},{'v',' ',' ','9','v'},{' ','v','v','v',' '},{' ','v','v','v',' '},{'v','X',' ','b','v'},{'v','b','b','b','v'},{'v','b',' ','b','v'},{'v','b','b','b','v'},{'v','b',' ','X','v'},{' ','v','v','v',' '},{' ','v','v','v',' '},{'v','J',' ',' ','v'},{'v','b','+',' ','v'},{'v','+','g','+','v'},{'v',' ','+','b','v'},{'v',' ',' ','J','v'},{' ','v','v','v',' '},{' ','v','v','v',' '},{'v','Q',' ',' ','v'},{'v','b','O',' ','v'},{'v','O','f','O','v'},{'v',' ','O','b','v'},{'v',' ',' ','Q','v'},{' ','v','v','v',' '},{' ','v','v','v',' '},{'v','K',' ',' ','v'},{'v','b','Z',' ','v'},{'v','N','e','N','v'},{'v',' ','Z','b','v'},{'v',' ',' ','K','v'},{' ','v','v','v',' '},{' ','v','v','v',' '},{'v','A',' ',' ','v'},{'v','c','|',' ','v'},{'v','-','+','-','v'},{'v',' ','|','c','v'},{'v',' ',' ','A','v'},{' ','v','v','v',' '},{' ','v','v','v',' '},{'v','2',' ',' ','v'},{'v','c',' ',' ','v'},{'v',' ',' ',' ','v'},{'v',' ',' ','c','v'},{'v',' ',' ','2','v'},{' ','v','v','v',' '},{' ','v','v','v',' '},{'v','3',' ',' ','v'},{'v','c',' ',' ','v'},{'v',' ','c',' ','v'},{'v',' ',' ','c','v'},{'v',' ',' ','3','v'},{' ','v','v','v',' '},{' ','v','v','v',' '},{'v','4',' ',' ','v'},{'v','c',' ','c','v'},{'v',' ',' ',' ','v'},{'v','c',' ','c','v'},{'v',' ',' ','4','v'},{' ','v','v','v',' '},{' ','v','v','v',' '},{'v','5',' ',' ','v'},{'v','c',' ','c','v'},{'v',' ','c',' ','v'},{'v','c',' ','c','v'},{'v',' ',' ','5','v'},{' ','v','v','v',' '},{' ','v','v','v',' '},{'v','6',' ',' ','v'},{'v',' ','c','c','v'},{'v','c',' ','c','v'},{'v','c','c',' ','v'},{'v',' ',' ','6','v'},{' ','v','v','v',' '},{' ','v','v','v',' '},{'v','7',' ',' ','v'},{'v',' ','c','c','v'},{'v','c','c','c','v'},{'v','c','c',' ','v'},{'v',' ',' ','7','v'},{' ','v','v','v',' '},{' ','v','v','v',' '},{'v','8',' ',' ','v'},{'v','c','c','c','v'},{'v','c',' ','c','v'},{'v','c','c','c','v'},{'v',' ',' ','8','v'},{' ','v','v','v',' '},{' ','v','v','v',' '},{'v','9',' ',' ','v'},{'v','c','c','c','v'},{'v','c','c','c','v'},{'v','c','c','c','v'},{'v',' ',' ','9','v'},{' ','v','v','v',' '},{' ','v','v','v',' '},{'v','X',' ','c','v'},{'v','c','c','c','v'},{'v','c',' ','c','v'},{'v','c','c','c','v'},{'v','c',' ','X','v'},{' ','v','v','v',' '},{' ','v','v','v',' '},{'v','J',' ',' ','v'},{'v','c','+',' ','v'},{'v','+','g','+','v'},{'v',' ','+','c','v'},{'v',' ',' ','J','v'},{' ','v','v','v',' '},{' ','v','v','v',' '},{'v','Q',' ',' ','v'},{'v','c','O',' ','v'},{'v','O','f','O','v'},{'v',' ','O','c','v'},{'v',' ',' ','Q','v'},{' ','v','v','v',' '},{' ','v','v','v',' '},{'v','K',' ',' ','v'},{'v','c','Z',' ','v'},{'v','N','e','N','v'},{'v',' ','Z','c','v'},{'v',' ',' ','K','v'},{' ','v','v','v',' '},{' ','v','v','v',' '},{'v','A',' ',' ','v'},{'v','d','|',' ','v'},{'v','-','+','-','v'},{'v',' ','|','d','v'},{'v',' ',' ','A','v'},{' ','v','v','v',' '},{' ','v','v','v',' '},{'v','2',' ',' ','v'},{'v','d',' ',' ','v'},{'v',' ',' ',' ','v'},{'v',' ',' ','d','v'},{'v',' ',' ','2','v'},{' ','v','v','v',' '},{' ','v','v','v',' '},{'v','3',' ',' ','v'},{'v','d',' ',' ','v'},{'v',' ','d',' ','v'},{'v',' ',' ','d','v'},{'v',' ',' ','3','v'},{' ','v','v','v',' '},{' ','v','v','v',' '},{'v','4',' ',' ','v'},{'v','d',' ','d','v'},{'v',' ',' ',' ','v'},{'v','d',' ','d','v'},{'v',' ',' ','4','v'},{' ','v','v','v',' '},{' ','v','v','v',' '},{'v','5',' ',' ','v'},{'v','d',' ','d','v'},{'v',' ','d',' ','v'},{'v','d',' ','d','v'},{'v',' ',' ','5','v'},{' ','v','v','v',' '},{' ','v','v','v',' '},{'v','6',' ',' ','v'},{'v',' ','d','d','v'},{'v','d',' ','d','v'},{'v','d','d',' ','v'},{'v',' ',' ','6','v'},{' ','v','v','v',' '},{' ','v','v','v',' '},{'v','7',' ',' ','v'},{'v',' ','d','d','v'},{'v','d','d','d','v'},{'v','d','d',' ','v'},{'v',' ',' ','7','v'},{' ','v','v','v',' '},{' ','v','v','v',' '},{'v','8',' ',' ','v'},{'v','d','d','d','v'},{'v','d',' ','d','v'},{'v','d','d','d','v'},{'v',' ',' ','8','v'},{' ','v','v','v',' '},{' ','v','v','v',' '},{'v','9',' ',' ','v'},{'v','d','d','d','v'},{'v','d','d','d','v'},{'v','d','d','d','v'},{'v',' ',' ','9','v'},{' ','v','v','v',' '},{' ','v','v','v',' '},{'v','X',' ','d','v'},{'v','d','d','d','v'},{'v','d',' ','d','v'},{'v','d','d','d','v'},{'v','d',' ','X','v'},{' ','v','v','v',' '},{' ','v','v','v',' '},{'v','J',' ',' ','v'},{'v','d','+',' ','v'},{'v','+','j','+','v'},{'v',' ','+','d','v'},{'v',' ',' ','J','v'},{' ','v','v','v',' '},{' ','v','v','v',' '},{'v','Q',' ',' ','v'},{'v','d','O',' ','v'},{'v','O','i','O','v'},{'v',' ','O','d','v'},{'v',' ',' ','Q','v'},{' ','v','v','v',' '},{' ','v','v','v',' '},{'v','K',' ',' ','v'},{'v','d','Z',' ','v'},{'v','N','h','N','v'},{'v',' ','Z','d','v'},{'v',' ',' ','K','v'},{' ','v','v','v',' '}};
    char mode1[20][19]={{'_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_'},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ','D','O',' ','Y','O','U',' ','W','A','N','T',' ','T','O',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ','H','I','T',' ','(','1',')',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ','O','R',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ','S','T','A','Y',' ','(','2',')',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{'_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_'}};
    char mode2[20][19]={{'_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_'},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ','Y','O','U',' ','B','U','S','T',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ','P','R','E','S','S',' ','(','1',')',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{'_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_'}};
    char mode3[20][19]={{'_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_'},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ','D','E','A','L','E','R',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ','T','U','R','N',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{'_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_'}};
    char mode4[20][19]={{'_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_'},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ','Y','O','U',' ','W','I','N',' ','!','!','!','!','!',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ','C','O','N','T','I','N','U','E',' ','(','1',')',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ','O','R',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ','Q','U','I','T',' ','(','2',')',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{'_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_'}};
    
    char mode5[20][19]={{'_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_'},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ','P','U','S','H',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ','B','E','T','S',' ','R','E','T','U','R','N','E','D',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ','C','O','N','T','I','N','U','E',' ','(','1',')',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ','O','R',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ','Q','U','I','T',' ','(','2',')',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{'_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_'}};
    
    char mode6[20][19]={{'_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_'},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ','D','E','A','L','E','R',' ','W','I','N','S',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ','C','O','N','T','I','N','U','E',' ','(','1',')',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ','O','R',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ','Q','U','I','T',' ','(','2',')',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{'_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_'}};
    char mode7[20][19]={{'_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_'},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ','H','O','W',' ','M','U','C','H',' ','D','O',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ','Y','O','U',' ','W','A','N','T',' ','T','O',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ','B','E','T','?',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{'_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_'}};
    
	char mode8[20][19]={{'_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_'},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ','D','O',' ','W','A','N','T',' ','T','O',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ','S','U','R','R','E','N','D','E','R',' ','(','2',')',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ','A','N','D',' ','F','O','R','F','E','I','T',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ','H','A','L','F',' ','Y','O','U','R',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ','B','E','T',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ','O','R',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ','C','O','N','T','I','N','U','E',' ','(','1',')',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{'_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_'}};
	
	char mode9[20][19]={{'_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_'},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ','D','O',' ','W','A','N','T',' ','T','O',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ','D','O','U','B','L','E','?',' ','(','2',')',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ','A','N','D',' ','D','O','U','B','L','E',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ','Y','O','U','R',' ','B','E','T',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ','O','R',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ','C','O','N','T','I','N','U','E',' ','(','1',')',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{'_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_'}};
	
	char mode10[20][19]={{'_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_'},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ','Y','O','U',' ','C','A','N','N','O','T',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ','B','E','T',' ','M','O','R','E',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ','T','H','A','N',' ','5','0',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ','C','O','N','T','I','N','U','E',' ','(','1',')',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{'_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_'}};
	
	char mode11[20][19]={{'_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_'},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ','Y','O','U',' ','M','U','S','T',' ','B','E','T',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ','A','T','L','E','A','S','T',' ','5',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ','C','O','N','T','I','N','U','E',' ','(','1',')',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{'_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_'}};
	
	char mode12[20][19]={{'_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_'},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ','Y','O','U',' ','M','U','S','T',' ','B','E','T',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ','A',' ','M','U','L','T','I','P','L','E',' ','O','F',' ','5',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ','C','O','N','T','I','N','U','E',' ','(','1',')',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{'_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_'}};
	
	char mode13[20][19]={{'_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_'},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ','Y','O','U','R',' ','B','A','N','K',' ','I','S',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ','E','M','P','T','Y',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ','Y','O','U',' ','L','O','O','S','E',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ','C','O','N','T','I','N','U','E',' ','(','1',')',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{'_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_'}};
	
	
	
	
	
	
	
	
    int balance=0;
    int bet=0;


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
	
	/*
	* @pre none
	* @post clears deck, fills with 312 cards (=6 decks of 52), shuffles the deck
	* @param none
	* @return none
	*/
	void resetDeck();
	
	
	
    
    void changeLScreen(int mode);
    void dealerValueUpdate();
    void playerValueUpdate();
    void balanceUpdate();// edits [27] [1-18]
    void betUpdate();// edits [27] [42-58]
    void cardsUpdate();
    void allUpdate();
    
    void clearScreen();//removes cards
	
	void insertCard(int x, int y, int card);// edits baseScreen to input a card
	
	
    void printSomething(char inputSomething);
	void screenRefresh();//prints the screen
		/*
	* @pre none
	* @post none
	* @param none
	* @return Player
	*/
	Blackjack* getPlayer();
	/*
	* @pre none
	* @post none
	* @param none
	* @return Dealer
	*/
    Blackjack* getDealer();
	/*
	* @pre none
	* @post none
	* @param none
	* @return Deck
	*/
	vector<int> getDeck();
};

#endif
