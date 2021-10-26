#ifndef EXECUTIVE_H
#define EXECUTIVE_H
#include "Blackjack.h"
#include <string>

class Executive {
    private:
        Blackjack* dealer;
        Blackjack* player;
        std::string winner;


    public:
        void winningCondition(Blackjack* dealer, Blackjack* player);
};

#endif
