#include <iostream>
#include "test.h"
#include <string>
#include <cstdlib>
#include "Executive.h"
#include "Blackjack.h"
#include <vector>
#include "algorithm"
#include <unistd.h>
using namespace std;
test::test(Executive e, Blackjack b)
{
    std::cout << "Test 1: Blackjack initializes with an empty hand: ";
    test1(b);
    std::cout << "Test 2: Blackjack dealer and player starts with 2 cards: ";
    test2(e);
    std::cout << "Test 3: Upon hit the player has a total of 3 cards: ";
    test3(e);
    std::cout << "Test 4: The resetted deck is shuffled(If 'FAILED' try program again): ";
    test4(e);
    std::cout << "Test 5: A hand value over 21 is bust: ";
    test5(e);
    std::cout << "Test 6: Given a hand of an Ace and a Queen is a Blackjack: ";
    test6(e);
    std::cout << "Test 7: Given a hand of two Aces and a Queen is a Blackjack: ";
    test7(e);
    std::cout << "Test 8: Player's hand value is bigger than Dealer's hand is true: ";
    test8(e);
    std::cout << "Test 9: Player's hand value is smaller than Dealer's hand is true: ";
    test9(e);
    std::cout << "Test 10: Player's hand and Dealer's hand value are the same is true: ";
    test10(e);
    std::cout << "Test 11: When a player surrender they get half their bet back: ";
    test11(e);
    std::cout << "Test 12: Doubling the bet is doubled: ";
    test12(e);
    std::cout << "Test 13: Player's starting balance is 150: ";
    test13();
    std::cout << "Test 14: Player's starting balance is 200 after winning 50: ";
    test14();
    std::cout << "Test 15: If Bet is lower than 5 it returns false: ";
    test15();
    std::cout << "Test 16: If Bet is higher than 50 it returns false: ";
    test16();
    std::cout << "Test 17: Betting higher than your balance returns false: ";
    test17();
    

}

test::~test(){

}
void test::test1(Blackjack b)
{
    if(b.getHandSize() == 0)
    {
        cout << "PASSED\n";
    }
    else{
        cout << "FAILED\n";
    }
}

void test::test2(Executive e)
{
    int phand = e.getDealer()->getHandSize();
    int dhand = e.getPlayer()->getHandSize();
    if(phand == 2 && dhand == 2)
    {
        cout << "PASSED\n";
    }
    else {
        cout << "FAILED\n";
    }
}

void test::test3(Executive e)
{
    vector<int> deck;
    for (int i = 0; i < 312; i++) {
        deck.push_back(i % 52);
    }
    e.getPlayer()->hit(deck);
    int phand = e.getPlayer()->getHandSize();
    if(phand == 3)
    {
        cout << "PASSED\n";
    }
    else {
        cout << "FAILED\n";
    }
}

void test::test4(Executive e)
{
    vector<int> deck;
    for (int i = 0; i < 312; i++) {
        deck.push_back(i % 52);
    }
    random_shuffle(deck.begin(), deck.end());
    Blackjack* p1 = new Blackjack();
    Blackjack* p2 = new Blackjack();
    p1->hit(deck);
    p2->hit(deck);
    deck.clear();
    for (int i = 0; i < 312; i++) {
        deck.push_back(i % 52);
    }
    random_shuffle(deck.begin(), deck.end());
    p1->hit(deck);
    p2->hit(deck);
    if(p2->handValue() != p1->handValue())
    {
        cout << "PASSED\n";
    }
    else {
        cout << "FAILED\n";
    }
    delete p1;
    delete p2;
}
void test::test5(Executive e)
{
    vector<int> deck;
    for (int i = 0; i < 312; i++) {
        deck.push_back(i % 52);
    }
    Blackjack* p1 = new Blackjack();
    for(int i = 0; i < 10; i++)
    {
        p1->hit(deck);
    }
    if(p1->isBust())
    {
        cout << "PASSED\n";
    }
    else {
        cout << "FAILED\n";
    }
    delete p1;
}
void test::test6(Executive e)
{
    Blackjack temp;
    temp.setHand(0, 13);
    temp.setHand(1,11);
    if(temp.handValue() == 21)
    {
        cout << "PASSED\n";
    }
    else {
        cout << "FAILED\n";
    }
}
void test::test7(Executive e)
{
    Blackjack temp;
    temp.setHand(0, 13);
    temp.setHand(1,11);
    temp.setHand(2,11);
    if(temp.handValue() == 21)
    {
        cout << "PASSED\n";
    }
    else {
        cout << "FAILED\n";
    }
}
void test::test8(Executive e)
{
    Blackjack* p1 = new Blackjack();
    Blackjack* p2 = new Blackjack();
    p1->setHand(0,13);
    p2->setHand(0,10);
    if(( (p1->handValue() > p2->handValue()) || (p2->isBust()) ) && (!(p1->isBust())))
    {
        cout << "PASSED\n";
    }
    else {
        cout << "FAILED\n";
    }
    delete p1;
    delete p2;
}
void test::test9(Executive e)
{
    Blackjack* p1 = new Blackjack();
    Blackjack* p2 = new Blackjack();
    p1->setHand(0,10);
    p2->setHand(0,13);
    if(( (p1->handValue() > p2->handValue()) || (p2->isBust()) ) && (!(p1->isBust())))
    {
        cout << "FAILED\n";
    }
    else {
        cout << "PASSED\n";
    }
    delete p1;
    delete p2;
}
void test::test10(Executive e)
{
    Blackjack* p1 = new Blackjack();
    Blackjack* p2 = new Blackjack();
    p1->setHand(0,10);
    p2->setHand(0,10);
    if( ((p1->handValue() == p2->handValue())) || ( (p2->isBust()) && (p1->isBust())))
    {
        cout << "PASSED\n";
    }
    else {
        cout << "FAILED\n";
    }
    delete p1;
    delete p2;
}
void test::test11(Executive e)
{
    Blackjack test;
    int store = test.surrender(100);
    if(store == 50)
    {
        cout << "PASSED\n";
    }
    else {
        cout << "FAILED\n";
    }
}
void test::test12(Executive e)
{
    Blackjack test;
    int store = test.doubleBet(100);
    if(store == 200)
    {
        cout << "PASSED\n";
    }
    else {
        cout << "FAILED\n";
    }
}
void test::test13()
{
    Blackjack test;
    if(test.getBankValue() == 150)
    {
        cout << "PASSED\n";
    }
    else {
        cout << "FAILED\n";
    }

}
void test::test14()
{
    Blackjack test;
    test.adjustBank(50);
    if(test.getBankValue() == 200)
    {
        cout << "PASSED\n";
    }
    else {
        cout << "FAILED\n";
    }
}
void test::test15()
{
    Blackjack test;
    if(test.checkBet(4) != true)
    {
        cout << "PASSED\n";
    }
    else {
        cout << "FAILED\n";
    }
}

void test::test16()
{
    Blackjack test;
    if(test.checkBet(51) != true)
    {
        cout << "PASSED\n";
    }
    else {
        cout << "FAILED\n";
    }
}
void test::test17()
{
    Blackjack test;
    test.adjustBank(-120);
    if(test.checkBet(40) != true)
    {
        cout << "PASSED\n";
    }
    else {
        cout << "FAILED\n";
    }
}