# Author: Lodewyk Jansen van Rensburg.
# Student ID: 934 309 717.
# Date: December 6, 2020. 
# Program 5: Linked list.

# Variables
EXE_FILE = run_prog
GCC = g++ 
GCCFLAGS = -std=c++11 -g -Wall

# Targets
$(EXE_FILE): main.o Functions.o LinkedList.hpp Node.hpp
	$(GCC) $(GCCFLAGS) main.o Functions.o -o $(EXE_FILE)

main.o: main.cpp LinkedList.hpp Node.hpp
	$(GCC) $(GCCFLAGS) -c main.cpp

Functions.o: Functions.cpp Functions.h
	$(GCC) $(GCCFLAGS) -c Functions.cpp
clean: 
	rm -f *.out *.o $(EXE_FILE)
author:
	echo "Program author: Lodewyk Jansen van Rensburg"

