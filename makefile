CXX = g++
CPPFLAGS = -std=c++14 -O2 -Wall -pedantic
DEPS = Hangman.hpp

%.o: %.c $(DEPS)
	$(CXX) -c -o $@ $< $(CPPFLAGS)

hangman: Hangman.o
	$(CXX) -o hangman Hangman.o
clean:
	rm -f *.o
