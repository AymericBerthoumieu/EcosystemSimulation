SRCDIR := ../src/


testStatistics.o : testStatistics.cpp Statistics.o
	g++ -Wall -std=c++11 -o testStatistics testStatistics.cpp Statistics.o -I $(SRCDIR)

Statistics.o : $(SRCDIR)Statistics.h $(SRCDIR)Statistics.cpp
	g++ -Wall -std=c++11  -c $(SRCDIR)Statistics.cpp -I $(SRCDIR)


