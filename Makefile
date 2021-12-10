all: main
    
main: objekt_files/main.o objekt_files/menu.o objekt_files/start.o objekt_files/settings.o objekt_files/records.o objekt_files/user.o objekt_files/input.o
	g++	objekt_files/main.o objekt_files/menu.o objekt_files/start.o objekt_files/settings.o objekt_files/records.o objekt_files/user.o objekt_files/input.o -o main


objekt_files/input.o: src/input.cpp Headers/input.hpp
	g++ -c src/input.cpp -o objekt_files/input.o
	
objekt_files/main.o: src/main.cpp 
	g++ -c src/main.cpp -o objekt_files/main.o

objekt_files/menu.o: src/menu.cpp 
	g++ -c src/menu.cpp -o objekt_files/menu.o

objekt_files/start.o: src/start.cpp
	g++ -c src/start.cpp -o objekt_files/start.o

objekt_files/settings.o: src/settings.cpp
	g++ -c src/settings.cpp -o objekt_files/settings.o

objekt_files/records.o: src/records.cpp 
	g++ -c src/records.cpp -o objekt_files/records.o

objekt_files/user.o: src/user.cpp
	g++ -c src/user.cpp -o objekt_files/user.o
