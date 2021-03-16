SRCDIR := src/
TESTSDIR := tests/

testFearful : $(TESTSDIR)testFearful.cpp Aquarium.o Pet.o Environment.o Fearful.o FearfulBehaviour.o 
	g++ -Wall -std=c++11 -o testFearful $(TESTSDIR)testFearful.cpp Aquarium.o Pet.o Environment.o Fearful.o FearfulBehaviour.o -I $(SRCDIR) -lX11 -lpthread

Aquarium.o : $(SRCDIR)Aquarium.h $(SRCDIR)Aquarium.cpp
	g++ -Wall -std=c++11  -c $(SRCDIR)Aquarium.cpp -I $(SRCDIR) 

Pet.o : $(SRCDIR)Pet.h $(SRCDIR)Pet.cpp
	g++ -Wall -std=c++11  -c $(SRCDIR)Pet.cpp -I  $(SRCDIR)

Fearful.o : $(SRCDIR)Animal.h $(TESTSDIR)Fearful.cpp
	g++ -Wall -std=c++11 -c $(TESTSDIR)Fearful.cpp -I $(SRCDIR)

Environment.o : $(SRCDIR)Environment.h $(SRCDIR)Environment.cpp
	g++ -Wall -std=c++11  -c $(SRCDIR)Environment.cpp -I $(SRCDIR)

FearfulBehaviour.o : $(SRCDIR)BehaviourStrategy.h $(SRCDIR)FearfulBehaviour.h $(SRCDIR)FearfulBehaviour.cpp
	g++ -Wall -std=c++11  -c $(SRCDIR)FearfulBehaviour.cpp -I $(SRCDIR)


