#include <iostream>
#include <cstdlib>
#include <string>
#include <unistd.h>
#include "Executive.h"
#include "Blackjack.h"
Executive::Executive()
{
  cout<<"hello";
  player = new Blackjack();
  dealer = new Blackjack();
  resetDeck();
  currentPlayer = 0; //The player0 is user and player1 is Dealer(ai)
  for (int i = 0; i < 2; i++) {
    player->hit(deck);
    dealer->hit(deck);
  }
  run();
}

void Executive::run()
{
  //setup
  wins=0;
  ties=0;
  losses=0;
  int choice;
  bool continueGame;

  display();
  srand(time(NULL));

  //Turn phase
  do{
  continueGame = false;
  player = new Blackjack();
  dealer = new Blackjack();
  resetDeck();
  currentPlayer = 0; //The player0 is user and player1 is Dealer(ai)
  for (int i = 0; i < 2; i++) {
    player->hit(deck);
    dealer->hit(deck);
  }
  
  
    if(currentPlayer == 0) //user turn
    {
      do {
	display();
        std::cin >> choice;
        if(choice == 1)//hit
        {
          player->hit(deck);
          if(player->isBust()) {
            displaybust();
	    cin>>choice;
            choice = 2;
          }
        }
      } while(choice !=2);
      turnChange();
    }


    if(currentPlayer == 1) //ai turn
    {
      
      do {
	displayend();
	usleep(500000);
        if(dealer->handValue() >= 17)
        {
	  cout<<"stay";
	  usleep(500000);
	  
          choice = 4;
        }
        if(dealer->handValue() <= 16)
        {
          dealer->hit(deck);
	  cout<<"hit";
	  usleep(500000);
          if(dealer->isBust()) {
            //dealer lost
            //player gets win fucntion
            choice = 4;
          }
        }
      } while(choice != 4);
      turnChange();
    }


    //the end of game//////////////////////////////
    usleep(2000000);
    winningCondition(dealer, player);
    usleep(2000000);
	  
	continueGame=contGame();

  } while(continueGame == 1);


}

void Executive::display()
{
  cout<<"\x1B[2J\x1B[H";
  //cout<<"display\n";
  cout<<"Wins: "<<wins<<"\nTies: "<<ties<<"\nLosses: "<<losses<<"\n\nDealer hand: ";

  cout<<"\n"<<dealer->parseCard(dealer->getCard(0))<<" ";
  
  cout<<"\n\nPlayer hand: ";
  for(int i=0; i<21; i++){
    if(player->getCard(i)>=0){
      cout<<"\n"<<player->parseCard(player->getCard(i));

    }
  }
  cout<<"\n\nhit(1) or stand(2): ";
  
}

void Executive::displayend()
{
  cout<<"\x1B[2J\x1B[H";
  //cout<<"displayend\n";
  cout<<"Wins: "<<wins<<"\nTies: "<<ties<<"\nLosses: "<<losses<<"\n\nDealer hand: ";

  for(int i=0; i<21; i++){
    if(dealer->getCard(i)>=0){
      cout<<"\n"<<dealer->parseCard(dealer->getCard(i))<<" ";
    }
  }
  cout<<"\n\nPlayer hand: ";
  for(int i=0; i<21; i++){
    if(player->getCard(i)>=0){
      cout<<"\n"<<player->parseCard(player->getCard(i));

    }
  }
  cout<<"\n\nhit(1) or stand(2): ";
  
}

void Executive::displaybust()
{
  cout<<"\x1B[2J\x1B[H";
  //cout<<"displaybust\n";
  cout<<"Wins: "<<wins<<"\nTies: "<<ties<<"\nLosses: "<<losses;


  cout<<"\n\nPlayer hand: ";
  for(int i=0; i<21; i++){
    if(player->getCard(i)>=0){
      cout<<"\n"<<player->parseCard(player->getCard(i));

    }
  }
  cout<<"\n\nPlayer Bust(1): ";
  
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

bool Executive::contGame()
{
  int choice;
  //cout<<"contGame\n";
  cout<<"\x1B[2J\x1B[H";
  cout<<"Wins: "<<wins<<"\nTies: "<<ties<<"\nLosses: "<<losses;

  cout<<"\n\n\nDo you want to play annother round?\nyes(1) no(2): ";
  cin>>choice;
  if(choice == 1){
    return 1;
  }
  else{
    return 0;
  }
}



void Executive::winningCondition(Blackjack* dealer, Blackjack* player)
{
  
    //summing players hand
  if( ( (player->handValue() > dealer->handValue()) || (dealer->isBust()) ) && (!(player->isBust())) )
    {
        //playyer wins
      winner="Player wins";
      wins++;
    }
  else if( ((player->handValue() == dealer->handValue())) || ( (dealer->isBust()) && (player->isBust())  ) )
    {
        //push
      winner="Tie";
      ties++;
    }
    else
    {
        //HOUSE WINS
      winner="Dealer wins";
      losses++;
    }
  cout<<"\x1B[2J\x1B[H";
  //cout<<"WinningCondition\n";
  cout<<"Wins: "<<wins<<"\nTies: "<<ties<<"\nLosses: "<<losses<<"\n\n"<<winner<<"\n\n";
}

void Executive::resetDeck() {
  deck.clear();
  for (int i = 0; i < 312; i++) {
    deck.push_back(i % 52);
  }
  random_shuffle(deck.begin(), deck.end());
}
