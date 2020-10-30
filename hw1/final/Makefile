# Filename: Makefile
# Author: Lodewyk Petrus Jansen van Rensburg.
# Student ID: 934 309 717.
# Description: This is the Makfile that is used for
# 		program 1: The Wizard Spellbook Catalog.
# Date: October 11, 2020.

# =========
# Variables
# =========

gcc = g++
gccflags = -std=c++11 -g #-Wall

exe_file = catalog_app

# ========
# Targets
# =======

$(exe_file): driver.o spellbook.o wizard.o login_user1.o build_library2.o user_selection3.o
	$(gcc) $(gccflags) driver.o spellbook.o wizard.o login_user1.o build_library2.o user_selection3.o -o $(exe_file)

driver.o: driver.cpp spellbook.cpp wizard.cpp login_user1.cpp build_library2.cpp user_selection3.cpp
	$(gcc) $(gccflags) -c driver.cpp 

spellbook.o: spellbook.cpp
	$(gcc) $(gccflags) -c spellbook.cpp 

wizard.o: wizard.cpp
	$(gcc) $(gccflags) -c wizard.cpp 

login_user1.o: login_user1.cpp
	$(gcc) $(gccflags) -c login_user1.cpp 

build_library2.o: build_library2.cpp
	$(gcc) $(gccflags) -c build_library2.cpp 

user_selection3.o: user_selection3.cpp
	$(gcc) $(gccflags) -c user_selection3.cpp 

clean: 
	rm -f *.o *.out $(exe_file)
