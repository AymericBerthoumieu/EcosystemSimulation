SRCDIR := src/

main : main.cpp Aquarium.o Pet.o Environment.o GregariousBehaviour.o
	g++ -Wall -std=c++11 -o main main.cpp Aquarium.o Pet.o Environment.o GregariousBehaviour.o -I $(SRCDIR) -lX11 -lpthread

Aquarium.o : src/Aquarium.h src/Aquarium.cpp
	g++ -Wall -std=c++11  -c $(SRCDIR)Aquarium.cpp -I $(SRCDIR) 

Pet.o : $(SRCDIR)Pet.h $(SRCDIR)Pet.cpp
	g++ -Wall -std=c++11  -c $(SRCDIR)Pet.cpp -I  $(SRCDIR)

Environment.o : $(SRCDIR)Environment.h $(SRCDIR)Environment.cpp
	g++ -Wall -std=c++11  -c $(SRCDIR)Environment.cpp -I $(SRCDIR)

GregariousBehaviour.o : $(SRCDIR)BehaviourStrategy.h $(SRCDIR)GregariousBehaviour.h $(SRCDIR)GregariousBehaviour.cpp
	g++ -Wall -std=c++11  -c $(SRCDIR)GregariousBehaviour.cpp -I $(SRCDIR)

 
