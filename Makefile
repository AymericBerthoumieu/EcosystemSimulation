main : main.cpp Aquarium.o Pet.o Environment.o
	g++ -Wall -std=c++11 -o main main.cpp Aquarium.o Pet.o Environment.o -I . -lX11 -lpthread

Aquarium.o : Aquarium.h Aquarium.cpp
	g++ -Wall -std=c++11  -c Aquarium.cpp -I .

Pet.o : Pet.h Pet.cpp
	g++ -Wall -std=c++11  -c Pet.cpp -I .

Environment.o : Environment.h Environment.cpp
	g++ -Wall -std=c++11  -c Environment.cpp -I .
