main : Catalogue.o ListeChainee.o Maillon.o Trajet.o TrajetCompose.o TrajetSimple.o main.o 
		g++ -o main Catalogue.o ListeChainee.o Maillon.o Trajet.o TrajetCompose.o TrajetSimple.o main.o 

Catalogue.o : Catalogue.cpp
		g++ -c Catalogue.cpp

ListeChainee.o : ListeChainee.cpp
		g++ -c ListeChainee.cpp

Maillon.o : Maillon.cpp
		g++ -c Maillon.cpp

Trajet.o : Trajet.cpp
		g++ -c Trajet.cpp

TrajetCompose.o : TrajetCompose.cpp
		g++ -c TrajetCompose.cpp

TrajetSimple.o : TrajetSimple.cpp
		g++ -c TrajetSimple.cpp

main.o : main.cpp
		g++ -c main.cpp
