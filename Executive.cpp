#include "Executive.h"

void Executive::winningCondition(Blackjack* dealer, Blackjack* player)
{
    //summing players hand
    if(player->handValue() > dealer->handValue())
    {
        //playyer wins
        winner = "Player";
    }
    else if(player->handValue() == dealer->handValue())
    {
        //push
        winner = "Push";
    }
    else
    {
        //HOUSE WINS
        winner = "Dealer"
    }
}
