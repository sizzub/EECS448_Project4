#include <iostream>
#include <cstdlib>
#include "Executive.h"
#include "Blackjack.h"
#include "test.h"

int main()
{
  int input;
  std::cout<<"hello2\n";
  std::cout << "\nOptions:\n1. Blackjack\n2. Test\nEnter here: ";
  std::cin >> input;
  if(input == 1)
  {
    Executive exec;
    exec.run();
  }
  else if(input ==2)
  {
    Executive q;
    Blackjack p;
    test t(q, p);
  }
  else {
    std::cout << "Wrong input try again.\n";
  }
  

  return(0);
}
