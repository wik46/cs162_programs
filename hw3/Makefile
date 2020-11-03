# #######################################################################################
# Filename: Makefile.
# Program 3: Zoo Tycoon.
# Author: Lodewyk Jansen van Rensburg.
# Student ID: 934 309 717.
# Date: November 8, 2020.
# Description: This file is used to make the compilation process easier for development.
# ########################################################################################

# Variables.

EXE_FILE = Zoo_Tycoon

GXX = g++
GXXFLAGS = -std=c++11 -g 

# Targets.

$(EXE_FILE): driver.o Animal.o Bear.o Sea_lion.o Tiger.o Date.o Probability.o Zoo.o
	$(GXX) $(GXXFLAGS) driver.o Animal.o Bear.o Sea_lion.o Tiger.o Date.o Probability.o Zoo.o -o $(EXE_FILE)

driver.o: driver.cpp
	$(GXX) $(GXXFLAGS) -c driver.cpp

Animal.o: Animal.cpp Animal.h
	$(GXX) $(GXXFLAGS) -c Animal.cpp

Bear.o: Bear.cpp Bear.h
	$(GXX) $(GXXFLAGS) -c Bear.cpp

Sea_lion.o: Sea_lion.cpp Sea_lion.h
	$(GXX) $(GXXFLAGS) -c Sea_lion.cpp

Tiger.o: Tiger.cpp Tiger.h
	$(GXX) $(GXXFLAGS) -c Tiger.cpp


Date.o: Date.cpp Date.h
	$(GXX) $(GXXFLAGS) -c Date.cpp

Probability.o: Probability.cpp Probability.h
	$(GXX) $(GXXFLAGS) -c Probability.cpp

Zoo.o: Zoo.cpp Zoo.h
	$(GXX) $(GXXFLAGS) -c Zoo.cpp	
clean: 
	rm -f *.out *.o $(EXE_FILE)
	 

