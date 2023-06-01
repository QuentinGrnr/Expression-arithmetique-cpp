Projet de fin de séquence UE Programmation Orientée Objet C++ 2023 - Garnier Quentin

Afin de pouvoir conserver chaque réponses aux questions du sujet, je placé chaques fonctionnalitées demandées dans chaque exercices dans plusieurs dossiers différents portant le nom de l'exercice en question.
Chacun de ces dossiers contient un fichier main.cpp qui permet de tester les fonctionnalitées demandées.

Comment compiler et exécuter les programmes :
Executer la commande make dans le dossier de l'exercice en question (en effet, chaque dossier contient son propre Makefile).
exemple : - cd exercice1
          - make

## Exercice 1
### Evaluation d'expression suffixées :
au lancement du programme il vous sera demander d'entrer une expression suffixée, puis le programme affichera le résultat de l'expression.
ATTENTION : Il est nécessaire de mettre un espace après chaque opérande afin de permettre au programme de les différencier. ce ce n'est pas le cas le programme ne fonctionnera pas.
exemple d'entrée : 2 3 4 +*5 6 *-

## Exercice 2
### transformation d'une expression infixe en expression suffixée :
au lancement du programme il vous sera demander d'entrer une expression infixe, puis le programme affichera l'expression suffixée correspondante.
exemple d'entrée : 2*X*7^5/(9*X^2-5+3)

## Exercice 3
### construction d'un arbre binaire à partir d'une expression suffixée :
Au lancement du programme il vous sera demander d'entrer une expression infixé, puis le programme affichera l'arbre binaire correspondant.
l'expression infixé correspondante est dans un premier temps affichée en notation suffixée, puis l'arbre correspondant est affiché, suivit du resultat. Enfin, l'arbre est lu et traduit en expression infixé avec les parenthéses necessaires.
exemple d'entrée : 2*X*7^5/(9*X^2-5+3)

## Exercice 4
### Dérivation d'une expression infixé et affichage de l'arbre binaire correspondant et de l'expression infixé dérivée :
Au lancement du programme il vous sera demander d'entrer une expression infixé. Dans un premier temps, le programme effectura les même taches qu'a l'exercice 3, puis l'arbre de l'expression dérivée sera affiché, et enfin, l'expression infixé dérivée sera affichée.
exemple d'entrée : 2*X*7^5/(9*X^2-5+3)