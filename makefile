main : Catalogue.o ListeChainee.o Maillon.o Trajet.o TrajetCompose.o TrajetSimple.o main.o 
		g++ -o main Catalogue.o ListeChainee.o Maillon.o Trajet.o TrajetCompose.o TrajetSimple.o main.o  -ansi -pedantic -Wall -std = c++11

Catalogue.o : Catalogue.cpp
		g++ -c Catalogue.cpp -ansi -pedantic -Wall -std = c++11

ListeChainee.o : ListeChainee.cpp
		g++ -c ListeChainee.cpp -ansi -pedantic -Wall -std = c++11

Maillon.o : Maillon.cpp
		g++ -c Maillon.cpp -ansi -pedantic -Wall -std = c++11

Trajet.o : Trajet.cpp
		g++ -c Trajet.cpp -ansi -pedantic -Wall -std = c++11

TrajetCompose.o : TrajetCompose.cpp -ansi -pedantic -Wall -std = c++11
		g++ -c TrajetCompose.cpp -ansi -pedantic -Wall -std = c++11

TrajetSimple.o : TrajetSimple.cpp -ansi -pedantic -Wall -std = c++11
		g++ -c TrajetSimple.cpp

main.o : main.cpp
		g++ -c main.cpp -ansi -pedantic -Wall -std = c++11
