SRCDIR := src/
TESTSDIR := tests/

testFin : $(TESTSDIR)testFin.cpp Aquarium.o Pet.o Environment.o Animal.o BaseDecorator.o Fin.o
	g++ -Wall -std=c++11 -o testFin $(TESTSDIR)testFin.cpp Aquarium.o Pet.o Environment.o Animal.o BaseDecorator.o Fin.o -I $(SRCDIR) -lX11 -lpthread

Aquarium.o : $(SRCDIR)Aquarium.h $(SRCDIR)Aquarium.cpp
	g++ -Wall -std=c++11  -c $(SRCDIR)Aquarium.cpp -I $(SRCDIR)

Pet.o : $(SRCDIR)Pet.h $(SRCDIR)Pet.cpp
	g++ -Wall -std=c++11  -c $(SRCDIR)Pet.cpp -I  $(SRCDIR)

Environment.o : $(SRCDIR)Environment.h $(SRCDIR)Environment.cpp
	g++ -Wall -std=c++11  -c $(SRCDIR)Environment.cpp -I $(SRCDIR)

Fin.o : $(SRCDIR)Fin.h $(SRCDIR)Fin.cpp
	g++ -Wall -std=c++11  -c $(SRCDIR)Fin.cpp -I $(SRCDIR)

BaseDecorator.o : $(SRCDIR)BaseDecorator.h $(SRCDIR)BaseDecorator.cpp
	g++ -Wall -std=c++11  -c $(SRCDIR)BaseDecorator.cpp -I $(SRCDIR)