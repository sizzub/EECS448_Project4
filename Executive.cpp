#include "Executive.h"
Executive::Executive()
{
  //initialize the hand here??
  int currentPlayer = 0; //The player0 is user and player1 is Dealer(ai)
  run();
}
void Executive::run()
{
  int choice;
  bool continueGame = true;
  
  //Turn phase
  do{
    if(currentPlayer == 0) //user turn
    {
      do {
        cout << "It's your turn."
        //Some display menu function with choices hit and stand
        cin >> choice;
        if(choice == 1)//hit
        {
          player.hit();
          if(player.isBust()) {
            //player lost
            //dealer gets win function
            choice == 4;
          }
          //Display hand function
        }
        if(choice == 2)//stand
        {
          choice = 4;
        }
        if(choice == 3)//Show hands (Both dealer and players)
        {
          //Display hands function
        }
        else {
          cout << "Invalid input\n";
        }
      } while(choice !=4);
      turnChange();
    }
    if(currentPlayer == 1) //ai turn
    {
      do {
        if(dealer.handValue() > 17)
        {
          cout << "Dealer stays\n";
          choice = 4;
        }
        if(dealer.handValue() <= 16)
        {
          cout << "Dealer hits\n";
          dealer.hit();
          if(dealer.isBust()) {
            //dealer lost
            //player gets win fucntion
            choice == 4;
          }
          //displays dealer's hand??
        }
      } while(choice != 4);
      turnChange();
    }

    //the end of game//////////////////////////////
    winningCondition(dealer, player);
    while(1)
    {
      cout << "==================\n\nDo you want to continue playing?\n\n==================";
      cin >> continueGame;
      if(continueGame == true || continueGame ==false) {
        cout << "Thanks for playing!\n";
        break;
      }
      else
      {
        cout << "Invalid input. Try again.\n";
      }
    }

  } while(continueGame == true)


}

void Executive::turnChange()
{
  if(currentPLayer == 0) {
    currentPlayer = 1;
  }
  else{
    currentPlayer = 0;
  }
}
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
