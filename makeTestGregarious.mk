SRCDIR := src/
TESTSDIR := tests/

testGregarious : $(TESTSDIR)testGregarious.cpp Aquarium.o Pet.o Environment.o Gregarious.o GregariousBehaviour.o 
	g++ -Wall -std=c++11 -o testGregarious $(TESTSDIR)testGregarious.cpp Aquarium.o Pet.o Environment.o Gregarious.o GregariousBehaviour.o -I $(SRCDIR) -lX11 -lpthread

Aquarium.o : $(SRCDIR)Aquarium.h $(SRCDIR)Aquarium.cpp
	g++ -Wall -std=c++11  -c $(SRCDIR)Aquarium.cpp -I $(SRCDIR) 

Pet.o : $(SRCDIR)Pet.h $(SRCDIR)Pet.cpp
	g++ -Wall -std=c++11  -c $(SRCDIR)Pet.cpp -I  $(SRCDIR)

Gregarious.o : $(SRCDIR)Animal.h $(TESTSDIR)Gregarious.cpp
	g++ -Wall -std=c++11 -c $(TESTSDIR)Gregarious.cpp -I $(SRCDIR)

Environment.o : $(SRCDIR)Environment.h $(SRCDIR)Environment.cpp
	g++ -Wall -std=c++11  -c $(SRCDIR)Environment.cpp -I $(SRCDIR)

GregariousBehaviour.o : $(SRCDIR)BehaviourStrategy.h $(SRCDIR)GregariousBehaviour.h $(SRCDIR)GregariousBehaviour.cpp
	g++ -Wall -std=c++11  -c $(SRCDIR)GregariousBehaviour.cpp -I $(SRCDIR)


