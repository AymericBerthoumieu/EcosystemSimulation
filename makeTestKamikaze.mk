SRCDIR := src/
TESTSDIR := tests/

testKamikaze : $(TESTSDIR)testKamikaze.cpp KamAqua.o Pet.o Environment.o Kamikaze.o KamikazeBehaviour.o 
	g++ -Wall -std=c++11 -o testKamikaze $(TESTSDIR)testKamikaze.cpp KamAqua.o Pet.o Environment.o Kamikaze.o KamikazeBehaviour.o -I $(SRCDIR) -lX11 -lpthread

KamAqua.o : $(SRCDIR)Aquarium.h $(TESTSDIR)KamAqua.cpp
	g++ -Wall -std=c++11  -c $(TESTSDIR)KamAqua.cpp -I $(SRCDIR) 

Pet.o : $(SRCDIR)Pet.h $(SRCDIR)Pet.cpp
	g++ -Wall -std=c++11  -c $(SRCDIR)Pet.cpp -I  $(SRCDIR)

Kamikaze.o : $(SRCDIR)Animal.h $(TESTSDIR)Kamikaze.cpp
	g++ -Wall -std=c++11 -c $(TESTSDIR)Kamikaze.cpp -I $(SRCDIR)

Environment.o : $(SRCDIR)Environment.h $(SRCDIR)Environment.cpp
	g++ -Wall -std=c++11  -c $(SRCDIR)Environment.cpp -I $(SRCDIR)

KamikazeBehaviour.o : $(SRCDIR)BehaviourStrategy.h $(SRCDIR)KamikazeBehaviour.h $(SRCDIR)KamikazeBehaviour.cpp
	g++ -Wall -std=c++11  -c $(SRCDIR)KamikazeBehaviour.cpp -I $(SRCDIR)


