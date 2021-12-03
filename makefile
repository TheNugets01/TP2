main : Catalogue.o ListeChainee.o Maillon.o Trajet.o  TrajetSimple.o main.o 
		g++ -o main Catalogue.o ListeChainee.o Maillon.o Trajet.o TrajetSimple.o main.o -ansi -pedantic -Wall -std=c++11

Catalogue.o : Catalogue.cpp
		g++ -c -g -ansi -pedantic -Wall -std=c++11 Catalogue.cpp

ListeChainee.o : ListeChainee.cpp
		g++ -c -g -ansi -pedantic -Wall -std=c++11 ListeChainee.cpp

Maillon.o : Maillon.cpp
		g++ -c -g -ansi -pedantic -Wall -std=c++11 Maillon.cpp

Trajet.o : Trajet.cpp
		g++ -c -g -ansi -pedantic -Wall -std=c++11 Trajet.cpp

TrajetSimple.o : TrajetSimple.cpp
		g++ -c -g -ansi -pedantic -Wall -std=c++11 TrajetSimple.cpp

main.o : main.cpp
		g++ -c -g -ansi -pedantic -Wall -std=c++11 main.cpp
