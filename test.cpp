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
    std::cout << "Test 4: The resetted deck is shuffled: ";
    test4(e);
    std::cout << "Test 5: A hand value over 21 is bust: ";
    test5(e);
    std::cout << "Test 6: Given a hand of an Ace and a Queen is a Blackjack: ";
    test6(e);
    std::cout << "Test 7: ";
    test7(e);
    std::cout << "Test 8: ";
    test8(e);
    std::cout << "Test 9: ";
    test9(e);
    std::cout << "Test 10: ";
    test10(e);
    std::cout << "Test 11: ";
    test11(e);
    std::cout << "Test 12: ";
    test12(e);
    

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
    cout << temp.getHand(0) << temp.getHand(1) << temp.getHand(2) << temp.getHand(21) << temp.getHand(20) << temp.getHand(19) <<"test\n";
    cout << temp.handValue();
    cout << temp.getHandSize();
}
void test::test7(Executive e)
{

}
void test::test8(Executive e)
{

}
void test::test9(Executive e)
{

}
void test::test10(Executive e)
{

}
void test::test11(Executive e)
{

}
void test::test12(Executive e)
{

}