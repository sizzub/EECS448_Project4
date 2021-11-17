#ifndef TEST_H
#define TEST_H

#include <iostream>
#include <cstdlib>
#include <string>
#include "Executive.h"
#include "Blackjack.h"

class test {
public:
test(Executive e, Blackjack b);
~test();
/*
* @pre Executive initialized
* @post checks if the player wants to quit
* @param none
* @return 1 if the player wants to continue, 0 if the player wants to quit
*/	
void test1(Blackjack b);
void test2(Executive e);
void test3(Executive e);
void test4(Executive e);
void test5(Executive e);
void test6(Executive e);
void test7(Executive e);
void test8(Executive e);
void test9(Executive e);
void test10(Executive e);
void test11(Executive e);
void test12(Executive e);
};
#endif