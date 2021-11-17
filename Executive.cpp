#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include <unistd.h>
#include "Executive.h"
#include "Blackjack.h"
using namespace std;

Executive::Executive()
{
  player = new Blackjack();
  dealer = new Blackjack();
  resetDeck();
  currentPlayer = 0; //The player0 is user and player1 is Dealer(ai)
  for (int i = 0; i < 2; i++) {
    player->hit(deck);
    dealer->hit(deck);
  }
  balance = player->getBankValue();
}

void Executive::run()
{
  //setup
  wins=0;
  ties=0;
  losses=0;
  int choice;

  srand(time(NULL));

  //Turn phase
  do{
    continueGame = 0;
    player->clearHand();
    dealer->clearHand();
    resetDeck();
    bet=0;
    allUpdate();
    currentPlayer = 0; //The player0 is user and player1 is Dealer(ai)
    for (int i = 0; i < 2; i++) {
        player->hit(deck);
        dealer->hit(deck);
    }
  
  
    if(currentPlayer == 0) //user turn
    {
        changeLScreen(7);
	    clearScreen();
        screenRefresh();
	    cin >> bet;
	    allUpdate();
        bet = checkBet(bet,0);
        int surDoub = 0;
        changeLScreen(9);
        screenRefresh();
        cin >> surDoub;
        //Checks the users bet to make sure it is a valid bet
        int temp_bet =0;
        if(surDoub==2)
        {
            temp_bet = player->doubleBet(bet);
            bet = checkBet(temp_bet, surDoub);
            if(temp_bet != bet)
            {
                surDoub=0;
            }
            allUpdate();
            choice = 3;
        }
        else
        {
            changeLScreen(8);
            screenRefresh();
            cin >> surDoub;
            if(surDoub==2)
            {
                bet = player->surrender(bet);
                choice = 4;
            }
        }
        do {
            //Checks the users bet to make sure it is a valid bet
            if(surDoub!=2)
            {
                //Asks the user to hit or stay
                changeLScreen(1);
                allUpdate();
                screenRefresh();
                std::cin >> choice;
            }
            

            if(choice == 1)//hit
            {
            player->hit(deck);
            if(player->isBust()) {
                changeLScreen(2);
                allUpdate();
                screenRefresh();
                //input bust message
                cin>>choice;
                choice = 2;
            }
            } else if (choice == 3)//double
            {
                player->hit(deck);
                allUpdate();
                choice = 2;
                if(player->isBust()) {
                    //displaybust();
                    changeLScreen(2);
                    allUpdate();
                    screenRefresh();
                    //input bust message
                    cin>>choice;
                    choice = 2;
                }
            } else if (choice == 4)//surrender
            {
                player->clearHand();
                dealer->clearHand();
                turnChange();
                choice = 2;
            }
        } while(choice !=2);
      turnChange();
    }


    if(currentPlayer == 1) //ai turn
    {
      
      do {
    //displayend();
    changeLScreen(3);
	allUpdate();
	screenRefresh();
	usleep(500000);
        if(dealer->handValue() >= 17)
        {
	  //cout<<"stay";
	  usleep(500000);
	  
          choice = 5;
        }
        if(dealer->handValue() <= 16)
        {
          dealer->hit(deck);
	  //cout<<"hit";
	  usleep(500000);
          if(dealer->isBust()) {
            //dealer lost
            //player gets win fucntion
            choice = 5;
          }
        }
      } while(choice != 5);
      turnChange();
    }


    //the end of game//////////////////////////////
    usleep(2000000);
    winningCondition(dealer, player);
    if(endGame==1)
    {
        continueGame=0;
        changeLScreen(13);
        screenRefresh();
    }
    else
    {
        allUpdate();
        cin>>continueGame;
        if(continueGame == 2)
        {
            continueGame = 0;
        }
    }
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
  if (player->getHandSize() == 2) {
    cout << "\n\nhit(1) or stand(2) or double(3) or surrender(4)";
  } else {
    cout<<"\n\nhit(1) or stand(2): ";
  }
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
        changeLScreen(4);
	    allUpdate();
	    screenRefresh();
        player->adjustBank(bet);
        balance = player->getBankValue();
        wins++;
    }
  else if( (((player->handValue() == dealer->handValue())) || ( (dealer->isBust()) && (player->isBust()))) && dealer->handValue() != 0)
    {
        //push
        changeLScreen(5);
	    allUpdate();
	    screenRefresh();
        ties++;
    }
    else if (player->handValue() == 0 && dealer->handValue() == 0) {
        changeLScreen(5);
        allUpdate();
        screenRefresh();
        bet = bet - (2*bet);
        player->adjustBank(bet);
        balance = player->getBankValue();
        ties++;
    }
    else
    {
        changeLScreen(6);
	    allUpdate();
	    screenRefresh();
        bet = bet - (2*bet);
        player->adjustBank(bet);
        balance = player->getBankValue();
        losses++;
    }
    
    if(balance <= 0)
    {
        endGame=1;
    }
}

void Executive::resetDeck() {
  deck.clear();
  for (int i = 0; i < 312; i++) {
    deck.push_back(i % 52);
  }
  random_shuffle(deck.begin(), deck.end(), seed);
}








void Executive::printSomething(char inputSomething){
    if(inputSomething=='a'){
        cout<<"♣ ";
    }
    else if(inputSomething=='b'){
        cout<<"♦ ";
    }
    else if(inputSomething=='c'){
        cout<<"♥ ";
    }
    else if(inputSomething=='d'){
        cout<<"♠ ";
    }
    else if(inputSomething=='e'){
        cout<<"♔ ";
    }
    else if(inputSomething=='f'){
        cout<<"♕ ";
    }
    else if(inputSomething=='g'){
        cout<<"♗ ";
    }
    else if(inputSomething=='h'){
        cout<<"♚ ";
    }
    else if(inputSomething=='i'){
        cout<<"♛ ";
    }
    else if(inputSomething=='j'){
        cout<<"♝ ";
    }
    else if(inputSomething=='v'){
        cout<<"& ";
    }
    else{
    cout<<inputSomething<<" ";
    }
    return;
}


void Executive::screenRefresh() {
    cout<<"\x1B[2J\x1B[H";
    for(int i = 0; i < 29; i ++) {
        for(int j = 0; j < 60; j++) {
            printSomething(baseScreen[i][j]);
        }
        cout << '\n';
    }   
}

void Executive::changeLScreen(int mode){
    if(mode == 0){
        for(int i=0; i<19; i++){
            for(int j=1; j<19; j++){
                baseScreen[j][i]=' ';
            }
        }
    }
    if(mode == 1){
        for(int i=0; i<19; i++){
            for(int j=1; j<19; j++){
                baseScreen[j][i]=mode1[j][i];
            }
        }
    }
    if(mode == 2){
        for(int i=0; i<19; i++){
            for(int j=1; j<19; j++){
                baseScreen[j][i]=mode2[j][i];
            }
        }
    }
    if(mode == 3){
        for(int i=0; i<19; i++){
            for(int j=1; j<19; j++){
                baseScreen[j][i]=mode3[j][i];
            }
        }
    }
    if(mode == 4){
        for(int i=0; i<19; i++){
            for(int j=1; j<19; j++){
                baseScreen[j][i]=mode4[j][i];
            }
        }
    }
    if(mode == 5){
        for(int i=0; i<19; i++){
            for(int j=1; j<19; j++){
                baseScreen[j][i]=mode5[j][i];
            }
        }
    }
    if(mode == 6){
        for(int i=0; i<19; i++){
            for(int j=1; j<19; j++){
                baseScreen[j][i]=mode6[j][i];
            }
        }
    }
    if(mode == 7){
        for(int i=0; i<19; i++){
            for(int j=1; j<19; j++){
                baseScreen[j][i]=mode7[j][i];
            }
        }
    }
    if(mode == 8){
        for(int i=0; i<19; i++){
            for(int j=1; j<19; j++){
                baseScreen[j][i]=mode8[j][i];
            }
        }
    }
    if(mode == 9){
        for(int i=0; i<19; i++){
            for(int j=1; j<19; j++){
                baseScreen[j][i]=mode9[j][i];
            }
        }
    }
    if(mode == 10){
        for(int i=0; i<19; i++){
            for(int j=1; j<19; j++){
                baseScreen[j][i]=mode10[j][i];
            }
        }
    }
    if(mode == 11){
        for(int i=0; i<19; i++){
            for(int j=1; j<19; j++){
                baseScreen[j][i]=mode11[j][i];
            }
        }
    }
    if(mode == 12){
        for(int i=0; i<19; i++){
            for(int j=1; j<19; j++){
                baseScreen[j][i]=mode12[j][i];
            }
        }
    }
    if(mode == 13){
        for(int i=0; i<19; i++){
            for(int j=1; j<19; j++){
                baseScreen[j][i]=mode13[j][i];
            }
        }
    }
    if(mode == 14){
        for(int i=0; i<19; i++){
            for(int j=1; j<19; j++){
                baseScreen[j][i]=mode14[j][i];
            }
        }
    }
	
}

void Executive::insertCard(int x, int y, int card){
    for(int i=x; i<x+5; i++){
        for(int j=y; j<y+7; j++){
            baseScreen[j][i]=cards[j-y+(card*7)][i-x];
        }
    }
}

void Executive::clearScreen(){
    for(int i=20; i<40; i++){
        for(int j=1; j<13; j++){
            baseScreen[j][i]=' ';
        }
    }
    for(int i=20; i<40; i++){
        for(int j=15; j<27; j++){
            baseScreen[j][i]=' ';
        }
    }
}

void Executive::dealerValueUpdate(){
    string strVal= to_string(dealer->handValue());
    
    if(strVal.length()==2){
        baseScreen[13][35]=strVal[0];
        baseScreen[13][36]=strVal[1];
    }
    if(strVal.length()==1){
        baseScreen[13][35]=' ';
        baseScreen[13][36]=strVal[0];
    }
    if(strVal.length()==0){
        baseScreen[13][35]=' ';
        baseScreen[13][36]=' ';
    }
}

void Executive::playerValueUpdate(){
    string strVal= to_string(player->handValue());
    
    if(strVal.length()==2){
        baseScreen[27][35]=strVal[0];
        baseScreen[27][36]=strVal[1];
    }
    if(strVal.length()==1){
        baseScreen[27][35]=' ';
        baseScreen[27][36]=strVal[0];
    }
    if(strVal.length()==0){
        baseScreen[27][35]=' ';
        baseScreen[27][36]=' ';
    }
}

void Executive::balanceUpdate(){
    string strBal= to_string(balance);
    string error="HOW DID YOU DO IT";
    if(strBal.length() > 17){
        for(int i=1; i<18; i++){
            baseScreen[27][i]=error[i-1];
        }
    }
    else{
        int frontSpace= (17-strBal.length())/2;
        
        for(int i=1; i<frontSpace+1; i++){
            baseScreen[27][i]=' ';
        }
        
        for(int i=frontSpace+1; i<strBal.length()+frontSpace+1; i++){
            baseScreen[27][i]=strBal[i-frontSpace-1];
        }
        
        for(int i=strBal.length()+frontSpace+1; i<18; i++){
            baseScreen[27][i]=' ';
        }
    }
}

void Executive::betUpdate(){
    string strBal= to_string(bet);
    string error="HOW DID YOU DO IT";
    if(strBal.length() > 17){
        for(int i=42; i<58; i++){
            baseScreen[27][i]=error[i-41];
        }
    }
    else{
        int frontSpace= (17-strBal.length())/2;
        
        for(int i=42; i<frontSpace+42; i++){
            baseScreen[27][i]=' ';
        }
        
        for(int i=frontSpace+42; i<strBal.length()+frontSpace+42; i++){
            baseScreen[27][i]=strBal[i-frontSpace-42];
        }
        
        for(int i=strBal.length()+frontSpace+42; i<58; i++){
            baseScreen[27][i]=' ';
        }
    }
}

void Executive::cardsUpdate(){
    //cout<<dealer->getCard(0);
    insertCard(3, 33, dealer->getCard(0));
    for(int i=0; i<21; i++){
        if(dealer->getCard(i)>=0){
            if(i==0){
                insertCard(33, 3, dealer->getCard(i));
            }
            else if(i==1){
                insertCard(31, 4, dealer->getCard(i));
            }
            else if(i%9==2){
                insertCard(21, 2, dealer->getCard(i));
            }
            else if(i%9==3){
                insertCard(23, 2, dealer->getCard(i));
            }
            else if(i%9==4){
                insertCard(25, 2, dealer->getCard(i));
            }
            else if(i%9==5){
                insertCard(21, 5, dealer->getCard(i));
            }
            else if(i%9==6){
                insertCard(23, 5, dealer->getCard(i));
            }
            else if(i%9==7){
                insertCard(25, 5, dealer->getCard(i));
            }
            else if(i%9==8){
                insertCard(21, 8, dealer->getCard(i));
            }
            else if(i%9==0){
                insertCard(23, 8, dealer->getCard(i));
            }
            else if(i%9==1){
                insertCard(25, 8, dealer->getCard(i));
            }
        }
    }
    
    for(int i=0; i<21; i++){
        if(player->getCard(i)>=0){
            if(i==0){
                insertCard(24, 18, player->getCard(i));
            }
            else if(i==1){
                insertCard(22, 19, player->getCard(i));
            }
            else if(i%9==2){
                insertCard(30, 16, player->getCard(i));
            }
            else if(i%9==3){
                insertCard(32, 16, player->getCard(i));
            }
            else if(i%9==4){
                insertCard(34, 16, player->getCard(i));
            }
            else if(i%9==5){
                insertCard(30, 18, player->getCard(i));
            }
            else if(i%9==6){
                insertCard(32, 18, player->getCard(i));
            }
            else if(i%9==7){
                insertCard(34, 18, player->getCard(i));
            }
            else if(i%9==8){
                insertCard(30, 20, player->getCard(i));
            }
            else if(i%9==0){
                insertCard(32, 20, player->getCard(i));
            }
            else if(i%9==1){
                insertCard(34, 20, player->getCard(i));
            }
        }
    }
}

void Executive::allUpdate(){
    dealerValueUpdate();
    playerValueUpdate();
    balanceUpdate();
    betUpdate();
    cardsUpdate();
}

Blackjack* Executive::getPlayer()
{
    return(player);
}

Blackjack* Executive::getDealer()
{
    return(dealer);
}
vector<int> Executive::getDeck()
{
    return(deck);
}

int Executive::seed(int n) {
  return (rand() % n);
}

int Executive::checkBet(int bet, int surDoub)
{   
    if(surDoub == 2)
    {
        int tempVal = player->checkBet(bet);
        int dummy = 0;
        if(tempVal == 1)
        {
            changeLScreen(10);
            screenRefresh();
            cin>>dummy;
            return bet/2;
        }
        else if(tempVal == 4)
        {
            changeLScreen(14);
            screenRefresh();
            cin>>dummy;
            return bet/2;
        }
        else
        {
            return bet;
        }
    }
    else
    {
        while(player->checkBet(bet) != 0)
        {
            int tempVal = player->checkBet(bet);
            int dummy = 0;
            if(tempVal == 1)
            {
                changeLScreen(10);
                screenRefresh();
                cin>>dummy;
            }
            else if(tempVal == 2)
            {
                changeLScreen(11);
                screenRefresh();
                cin>>dummy;
            }
            else if(tempVal == 3)
            {
                changeLScreen(12);
                screenRefresh();
                cin>>dummy;
            }
            else if(tempVal == 4)
            {
                changeLScreen(14);
                screenRefresh();
                cin>>dummy;
            }
            changeLScreen(7);
            screenRefresh();
            cin>>bet;
        }
        return bet;
    }
}
