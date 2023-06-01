exercice1 : caractere1.o main1 pile1.o
	./main1

main1 : exercice_1/main.cpp pile1.o caractere1.o
	g++ -o main1 pile1.o caractere1.o exercice_1/main.cpp

pile1.o : exercice_1/pile.cpp exercice_1/pile.h
	g++ -c exercice_1/pile.cpp

caractere1.o : exercice_1/caractere.cpp exercice_1/caractere.h
	g++ -c exercice_1/caractere.cpp



exercice2 : caractere2.o main2 pile2.o output2.o
	./main2

main2 : exercice_2/main.cpp pile2.o caractere2.o output2.o
	g++ -o main2 pile2.o caractere2.o output2.o exercice_2/main.cpp

output2.o : exercice_2/outputChain.cpp exercice_2/outputChain.h
	g++ -c exercice_2/outputChain.cpp

pile2.o : exercice_2/pile.cpp exercice_2/pile.h
	g++ -c exercice_2/pile.cpp

caractere2.o : exercice_2/caractere.cpp exercice_2/caractere.h
	g++ -c exercice_2/caractere.cpp