SRCDIR := src/
TESTSDIR := tests/

testPetFactory : $(TESTSDIR)testPetFactory.cpp Aquarium.o Pet.o Environment.o Animal.o PetFactory.o Fin.o Eyes.o KamikazeBehaviour.o FearfulBehaviour.o GregariousBehaviour.o BehaviourStrategy.o Statistics.o
	g++ -Wall -std=c++11 -o testPetFactory $(TESTSDIR)testPetFactory.cpp Aquarium.o Pet.o Environment.o Animal.o PetFactory.o Fin.o Eyes.o FearfulBehaviour.o GregariousBehaviour.o BehaviourStrategy.o Statistics.o KamikazeBehaviour.o -I $(SRCDIR) -lX11 -lpthread

Aquarium.o : src/Aquarium.h src/Aquarium.cpp
	g++ -Wall -std=c++11 -c $(SRCDIR)Aquarium.cpp -I $(SRCDIR) 

Pet.o : $(SRCDIR)Pet.h $(SRCDIR)Pet.cpp
	g++ -Wall -std=c++11 -c $(SRCDIR)Pet.cpp -I  $(SRCDIR)

Animal.o : $(SRCDIR)Animal.h $(SRCDIR)Animal.cpp
	g++ -Wall -std=c++11 -c $(SRCDIR)Animal.cpp -I $(SRCDIR)

Environment.o : $(SRCDIR)Environment.h $(SRCDIR)Environment.cpp
	g++ -Wall -std=c++11 -c $(SRCDIR)Environment.cpp -I $(SRCDIR)

PetFactory.o : $(SRCDIR)PetFactory.h $(SRCDIR)PetFactory.cpp
	g++ -Wall -std=c++11 -c $(SRCDIR)PetFactory.cpp -I $(SRCDIR)

Fin.o : $(SRCDIR)Fin.h $(SRCDIR)Fin.cpp
	g++ -Wall -std=c++11 -c $(SRCDIR)Fin.cpp -I $(SRCDIR)

Eyes.o : $(SRCDIR)Eyes.h $(SRCDIR)Eyes.cpp
	g++ -Wall -std=c++11 -c $(SRCDIR)Eyes.cpp -I $(SRCDIR)

BehaviourStrategy.o : $(SRCDIR)BehaviourStrategy.h $(SRCDIR)BehaviourStrategy.cpp
	g++ -Wall -std=c++11 -c $(SRCDIR)BehaviourStrategy.cpp -I $(SRCDIR)

GregariousBehaviour.o : $(SRCDIR)GregariousBehaviour.h $(SRCDIR)GregariousBehaviour.cpp
	g++ -Wall -std=c++11 -c $(SRCDIR)GregariousBehaviour.cpp -I $(SRCDIR)

FearfulBehaviour.o : $(SRCDIR)FearfulBehaviour.h $(SRCDIR)FearfulBehaviour.cpp
	g++ -Wall -std=c++11 -c $(SRCDIR)FearfulBehaviour.cpp -I $(SRCDIR)

KamikazeBehaviour.o : $(SRCDIR)KamikazeBehaviour.h $(SRCDIR)KamikazeBehaviour.cpp
	g++ -Wall -std=c++11 -c $(SRCDIR)KamikazeBehaviour.cpp -I $(SRCDIR)

Statistics.o : $(SRCDIR)Statistics.h $(SRCDIR)Statistics.cpp
	g++ -Wall -std=c++11 -c $(SRCDIR)Statistics.cpp -I $(SRCDIR)
