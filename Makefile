
sudoku: main.o Sboard.o Catalog.o
	g++ src/main.cpp build/Sboard.o build/Catalog.o -std=c++17 -o bin/sudoku

main.o: src/main.cpp
	g++ src/main.cpp -c -std=c++17 -o build/main.o

Sboard.o: src/Sboard.cpp src/Sboard.hpp 
	g++ src/Sboard.cpp -c -std=c++17 -o build/Sboard.o

Catalog.o: src/Catalog.hpp src/Catalog.cpp
	g++ src/Catalog.cpp -c -std=c++17 -o build/Catalog.o