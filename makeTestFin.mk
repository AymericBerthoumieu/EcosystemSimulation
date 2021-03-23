SRCDIR := src/
TESTSDIR := tests/

testFin : $(TESTSDIR)testFin.cpp Aquarium.o Pet.o Environment.o Animal.o BaseDecorator.o Sensor.o Ears.o Shell.o Eyes.o Fin.o GregariousBehaviour.o FearfulBehaviour.o KamikazeBehaviour.o PetFactory.o Statistics.o MoveUtils.o
	g++ -Wall -std=c++11 -o testFin $(TESTSDIR)testFin.cpp Aquarium.o Pet.o Environment.o Animal.o BaseDecorator.o Sensor.o Ears.o Shell.o Eyes.o Fin.o GregariousBehaviour.o FearfulBehaviour.o KamikazeBehaviour.o PetFactory.o Statistics.o MoveUtils.o -I $(SRCDIR) -lX11 -lpthread

Aquarium.o : $(SRCDIR)Aquarium.h $(SRCDIR)Aquarium.cpp
	g++ -Wall -std=c++11  -c $(SRCDIR)Aquarium.cpp -I $(SRCDIR)

Animal.o : $(SRCDIR)Animal.h $(SRCDIR)Animal.cpp
	g++ -Wall -std=c++11 -c $(SRCDIR)Animal.cpp -I $(SRCDIR)

Pet.o : $(SRCDIR)Pet.h $(SRCDIR)Pet.cpp
	g++ -Wall -std=c++11  -c $(SRCDIR)Pet.cpp -I  $(SRCDIR)

Environment.o : $(SRCDIR)Environment.h $(SRCDIR)Environment.cpp
	g++ -Wall -std=c++11  -c $(SRCDIR)Environment.cpp -I $(SRCDIR)

Fin.o : $(SRCDIR)Fin.h $(SRCDIR)Fin.cpp
	g++ -Wall -std=c++11  -c $(SRCDIR)Fin.cpp -I $(SRCDIR)

Eyes.o : $(SRCDIR)Eyes.h $(SRCDIR)Eyes.cpp
	g++ -Wall -std=c++11  -c $(SRCDIR)Eyes.cpp -I $(SRCDIR)

Ears.o : $(SRCDIR)Ears.h $(SRCDIR)Ears.cpp
	g++ -Wall -std=c++11  -c $(SRCDIR)Ears.cpp -I $(SRCDIR)

Shell.o : $(SRCDIR)Shell.h $(SRCDIR)Shell.cpp
	g++ -Wall -std=c++11  -c $(SRCDIR)Shell.cpp -I $(SRCDIR)

BaseDecorator.o : $(SRCDIR)BaseDecorator.h $(SRCDIR)BaseDecorator.cpp
	g++ -Wall -std=c++11  -c $(SRCDIR)BaseDecorator.cpp -I $(SRCDIR)

GregariousBehaviour.o : $(SRCDIR)BehaviourStrategy.h $(SRCDIR)GregariousBehaviour.h $(SRCDIR)GregariousBehaviour.cpp
	g++ -Wall -std=c++11  -c $(SRCDIR)GregariousBehaviour.cpp -I $(SRCDIR)

FearfulBehaviour.o : $(SRCDIR)BehaviourStrategy.h $(SRCDIR)FearfulBehaviour.h $(SRCDIR)FearfulBehaviour.cpp
	g++ -Wall -std=c++11  -c $(SRCDIR)FearfulBehaviour.cpp -I $(SRCDIR)

KamikazeBehaviour.o : $(SRCDIR)BehaviourStrategy.h $(SRCDIR)KamikazeBehaviour.h $(SRCDIR)KamikazeBehaviour.cpp
	g++ -Wall -std=c++11  -c $(SRCDIR)KamikazeBehaviour.cpp -I $(SRCDIR)

PetFactory.o : $(SRCDIR)PetFactory.h $(SRCDIR)PetFactory.cpp
	g++ -Wall -std=c++11 -c $(SRCDIR)PetFactory.cpp -I $(SRCDIR)

Statistics.o : $(SRCDIR)Statistics.h $(SRCDIR)Statistics.cpp
	g++ -Wall -std=c++11 -c $(SRCDIR)Statistics.cpp -I $(SRCDIR)

MoveUtils.o : $(SRCDIR)MoveUtils.h $(SRCDIR)MoveUtils.cpp
	g++ -Wall -std=c++11  -c $(SRCDIR)MoveUtils.cpp -I $(SRCDIR)