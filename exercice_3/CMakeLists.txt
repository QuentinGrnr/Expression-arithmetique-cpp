cmake_minimum_required(VERSION 3.23)
project(TD2S2_POO)

set(CMAKE_CXX_STANDARD 14)

include_directories(..)

add_executable(exercice_3
        main.cpp
        caractere.cpp
        caractere.h
        pile.cpp
        pile.h
        outputChain.h
        outputChain.cpp
        arbre.cpp
        arbre.h
        noeud.cpp
        noeud.h
        )
