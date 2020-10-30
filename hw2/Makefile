# Author: Lodewyk Jansen van Rensburg.
# Lab3: Practise with classes.
# Date: October 13, 2020.

# Variables.

exe_file = crazy_8
CC = g++
CCFLAGS = -std=c++11 -g 

# Targets.

$(exe_file): driver.o Card.o Deck.o Game.o Hand.o Player.o
	$(CC) $(CCFLAGS) driver.o Card.o Deck.o Game.o Hand.o Player.o -o $(exe_file)

driver.o: driver.cpp 
	$(CC) $(CCFLAGS) -c driver.cpp

Card.o: Card.cpp Card.h
	$(CC) $(CCFLAGS) -c Card.cpp

Deck.o: Deck.cpp Deck.h
	$(CC) $(CCFLAGS) -c Deck.cpp
	
Game.o: Game.cpp Game.h
	$(CC) $(CCFLAGS) -c Game.cpp

Hand.o: Hand.cpp Hand.h
	$(CC) $(CCFLAGS) -c Hand.cpp

Player.o: Player.cpp Player.h
	$(CC) $(CCFLAGS) -c Player.cpp
clean:
	rm -f *.o *.out $(exe_file)
