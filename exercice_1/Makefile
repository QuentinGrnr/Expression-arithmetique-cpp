output : caractere.o main pile.o
	./main1

main : main.cpp pile.o caractere.o
	g++ -o main1 pile.o caractere.o main.cpp

pile.o : pile.cpp pile.h
	g++ -c pile.cpp

caractere.o : caractere.cpp caractere.h
	g++ -c caractere.cpp
