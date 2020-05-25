# Makefile
CXX_FLAG = --std=c++11 -g

all: runMovies

runMovies: main.o movie.o
	g++ $(CXX_FLAG) -o runMovies main.o movie.o

tests: tests.o movies.o
	g++ $(CXX_FLAG) -o tests tests.o movies.o

main.o: main.cpp
	g++ -c $(CXX_FLAG) main.cpp

movie.o: movie.cpp
	g++ -c $(CXX_FLAG) movie.cpp

tests.o: tests.cpp
	g++ -c $(CXX_FLAG) tests.cpp

clean:
	rm -f tests runMovies *.o

