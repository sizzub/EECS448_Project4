prog: main.o Blackjack.o Executive.o
	g++ -std=c++11 -g -Wall main.o Executive.o Blackjack.o -o prog

main.o: main.cpp Executive.h
	g++ -std=c++11 -g -Wall -c main.cpp

Executive.o: Executive.h Executive.cpp
	g++ -std=c++11 -g -Wall -c Executive.cpp

Blackjack.o: Blackjack.h Blackjack.cpp
	g++ -std=c++11 -g -Wall -c Blackjack.cpp
  
clean: 
	rm *.o prog
