all: Source.exe
Source.exe : Source.o fractions.o util.o
	g++ -std=c++17 Source.o fractions.o util.o -o Source.exe
Source.o: Source.cpp RPN.h
	g++ -std=c++17 -c Source.cpp
fractions.o: fractions.cpp fractions.h util.h
	g++ -std=c++17 -c fractions.cpp
util.o: util.cpp util.h
	g++ -std=c++17 -c util.cpp
clean:
	rm -f Source.exe Source.o fractions.o util.o
