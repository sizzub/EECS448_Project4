#include "Executive.h"
Executive::Executive()
{
  player = new Blackjack();
  dealer = new Blackjack();
  currentPlayer = 0; //The player0 is user and player1 is Dealer(ai)
  for (int i = 0; i < 2; i++) {
    player->hit();
    dealer->hit();
  }
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
        std::cout << "It's your turn.";
        //Some display menu function with choices hit and stand
        std::cin >> choice;
        if(choice == 1)//hit
        {
          player->hit();
          if(player->isBust()) {
            //player lost
            //dealer gets win function
            choice = 4;
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
        if(dealer->handValue() > 17)
        {
          std::cout << "Dealer stays\n";
          choice = 4;
        }
        if(dealer->handValue() <= 16)
        {
          std::cout << "Dealer hits\n";
          dealer->hit();
          if(dealer->isBust()) {
            //dealer lost
            //player gets win fucntion
            choice = 4;
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
      std::cout << "==================\n\nDo you want to continue playing?\n\n==================";
      std::cin >> continueGame;
      if(continueGame == true || continueGame ==false) {
        std::cout << "Thanks for playing!\n";
        break;
      }
      else
      {
        std::cout << "Invalid input. Try again.\n";
      }
    }

  } while(continueGame == true);


}

void Executive::turnChange()
{
  if(currentPlayer == 0) {
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
        winner = "Dealer";
    }
}
