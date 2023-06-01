output : noeud.o main pile.o outputChain.o arbre.o
	./main

main : main.cpp pile.o noeud.o outputChain.o arbre.o
	g++ -o main pile.o noeud.o outputChain.o arbre.o main.cpp

arbre.o : arbre.cpp arbre.h
	g++ -c arbre.cpp

outputChain.o : outputChain.cpp outputChain.h
	g++ -c outputChain.cpp

pile.o : pile.cpp pile.h
	g++ -c pile.cpp

noeud.o : noeud.cpp noeud.h
	g++ -c noeud.cpp
