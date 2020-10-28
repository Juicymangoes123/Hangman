CXX=g++
CFLAGS=-std=c++14 -O2 -Wall
DEPS= Hangman.hpp

%.o: %.c $(DEPS)
	$(CXX) -c -o $@ $< $(CFLAGS)

hangman: Hangman.o
	$(CXX) -o hangman hangman.o
