output : caractere.o main pile.o outputChain.o
	./main

main : main.cpp pile.o caractere.o outputChain.o
	g++ -o main pile.o caractere.o outputChain.o main.cpp

outputChain.o : outputChain.cpp outputChain.h
	g++ -c outputChain.cpp

pile.o : pile.cpp pile.h
	g++ -c pile.cpp

caractere.o : caractere.cpp caractere.h
	g++ -c caractere.cpp
