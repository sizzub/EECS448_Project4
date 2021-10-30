prog: main.o Blackjack.o Executive.o Display.o
	g++ -std=c++11 -g -Wall main.o Executive.o Board.o Display.o -o prog

main.o: main.cpp
	g++ -std=c++11 -g -Wall -c main.cpp

Executive.o: Executive.h Executive.cpp
	g++ -std=c++11 -g -Wall -c Executive.cpp Executive.h

Blackjack.o: Blackjack.h Blackjack.cpp
	g++ -std=c++11 -g -Wall -c Blackjack.cpp Blackjack.h
  
Display.o: Display.h Display.cpp
	g++ -std=c++11 -g -Wall -c Display.cpp Display.h

clean: 
	rm -fr *.o prog prog.* Blackjack.h.gch Executive.h.gch Display.h.gch
