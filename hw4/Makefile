## Author: Lodewyk Jansen van Rensburg
## Date: November 22, 2020.
## Program 4: Hunt the Wumpus.

## Variables:

EXE_FILE = wumpus
GCC = g++
GCCFLAGS = -std=c++11 -g

## Targets
$(EXE_FILE): main.o Game.o Event.o Bat.o Gold.o Pit.o Wumpus.o Player.o Room.o Grid.o Keyboard.o Vec2d.o 
	$(GCC) $(GCCFLAGS) main.o Game.o Event.o Bat.o Gold.o Pit.o Wumpus.o Player.o Room.o Grid.o Keyboard.o Vec2d.o -o $(EXE_FILE)

main.o: main.cpp  
	$(GCC) $(GCCFLAGS) -c main.cpp 

Game.o: Game.cpp Game.h 
	$(GCC) $(GCCFLAGS) -c Game.cpp 

Event.o: Event.cpp Event.h 
	$(GCC) $(GCCFLAGS) -c Event.cpp 

Bat.o: Bat.cpp Bat.h 
	$(GCC) $(GCCFLAGS) -c Bat.cpp 

Gold.o: Gold.cpp Gold.h 
	$(GCC) $(GCCFLAGS) -c Gold.cpp 

Pit.o: Pit.cpp Pit.h 
	$(GCC) $(GCCFLAGS) -c Pit.cpp 

Wumpus.o: Wumpus.cpp Wumpus.h 
	$(GCC) $(GCCFLAGS) -c Wumpus.cpp 

Player.o: Player.cpp Player.h 
	$(GCC) $(GCCFLAGS) -c Player.cpp 

Room.o: Room.cpp Room.h 
	$(GCC) $(GCCFLAGS) -c Room.cpp 

Grid.o: Grid.cpp Grid.h 
	$(GCC) $(GCCFLAGS) -c Grid.cpp 

Keyboard.o: Keyboard.cpp Keyboard.h 
	$(GCC) $(GCCFLAGS) -c Keyboard.cpp 

Vec2d.o: Vec2d.cpp Vec2d.h 
	$(GCC) $(GCCFLAGS) -c Vec2d.cpp 

clean: 
	rm -f *.out *.o $(EXE_FILE)
