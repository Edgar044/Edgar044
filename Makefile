all: main
    
main: bin/main.o bin/menu.o bin/start.o bin/settings.o bin/records.o bin/user.o bin/input.o
	g++	bin/main.o bin/menu.o bin/start.o bin/settings.o bin/records.o bin/user.o bin/input.o -o main


bin/input.o: src/input.cpp include/input.hpp
	g++ -c src/input.cpp -o bin/input.o
	
bin/main.o: src/main.cpp 
	g++ -c src/main.cpp -o bin/main.o

bin/menu.o: src/menu.cpp 
	g++ -c src/menu.cpp -o bin/menu.o

bin/start.o: src/start.cpp
	g++ -c src/start.cpp -o bin/start.o

bin/settings.o: src/settings.cpp
	g++ -c src/settings.cpp -o bin/settings.o

bin/records.o: src/records.cpp 
	g++ -c src/records.cpp -o bin/records.o

bin/user.o: src/user.cpp
	g++ -c src/user.cpp -o bin/user.o
