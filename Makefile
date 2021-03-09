SRCDIR := src/

main2 : main_test.cpp
	g++ -Wall -std=c++11 -o main2 main_test.cpp

main : main.cpp Aquarium.o Pet.o Environment.o
	g++ -Wall -std=c++11 -o main main.cpp Aquarium.o Pet.o Environment.o -I $(SRCDIR) -lX11 -lpthread

Aquarium.o : src/Aquarium.h src/Aquarium.cpp
	g++ -Wall -std=c++11  -c $(SRCDIR)Aquarium.cpp -I $(SRCDIR) 

Pet.o : $(SRCDIR)Pet.h $(SRCDIR)Pet.cpp
	g++ -Wall -std=c++11  -c $(SRCDIR)Pet.cpp -I  $(SRCDIR)

Environment.o : $(SRCDIR)Environment.h $(SRCDIR)Environment.cpp
	g++ -Wall -std=c++11  -c $(SRCDIR)Environment.cpp -I $(SRCDIR)


 
