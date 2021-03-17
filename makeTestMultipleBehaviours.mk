SRCDIR := src/
TESTSDIR := tests/

testMultipleBehaviours : $(TESTSDIR)testMultipleBehaviours.cpp Aquarium.o Pet.o Environment.o MultipleBehaviours.o GregariousBehaviour.o FearfulBehaviour.o KamikazeBehaviour.o 
	g++ -Wall -std=c++11 -o testMultipleBehaviours $(TESTSDIR)testMultipleBehaviours.cpp Aquarium.o Pet.o Environment.o MultipleBehaviours.o GregariousBehaviour.o FearfulBehaviour.o KamikazeBehaviour.o -I $(SRCDIR) -lX11 -lpthread

Aquarium.o : $(SRCDIR)Aquarium.h $(SRCDIR)Aquarium.cpp
	g++ -Wall -std=c++11  -c $(SRCDIR)Aquarium.cpp -I $(SRCDIR) 

Pet.o : $(SRCDIR)Pet.h $(SRCDIR)Pet.cpp
	g++ -Wall -std=c++11  -c $(SRCDIR)Pet.cpp -I  $(SRCDIR)

MultipleBehaviours.o : $(SRCDIR)Animal.h $(TESTSDIR)MultipleBehaviours.cpp
	g++ -Wall -std=c++11 -c $(TESTSDIR)MultipleBehaviours.cpp -I $(SRCDIR)

Environment.o : $(SRCDIR)Environment.h $(SRCDIR)Environment.cpp
	g++ -Wall -std=c++11  -c $(SRCDIR)Environment.cpp -I $(SRCDIR)

GregariousBehaviour.o : $(SRCDIR)BehaviourStrategy.h $(SRCDIR)GregariousBehaviour.h $(SRCDIR)GregariousBehaviour.cpp
	g++ -Wall -std=c++11  -c $(SRCDIR)GregariousBehaviour.cpp -I $(SRCDIR)

FearfulBehaviour.o : $(SRCDIR)BehaviourStrategy.h $(SRCDIR)FearfulBehaviour.h $(SRCDIR)FearfulBehaviour.cpp
	g++ -Wall -std=c++11  -c $(SRCDIR)FearfulBehaviour.cpp -I $(SRCDIR)

KamikazeBehaviour.o : $(SRCDIR)BehaviourStrategy.h $(SRCDIR)KamikazeBehaviour.h $(SRCDIR)KamikazeBehaviour.cpp
	g++ -Wall -std=c++11  -c $(SRCDIR)KamikazeBehaviour.cpp -I $(SRCDIR)

