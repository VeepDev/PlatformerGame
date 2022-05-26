all:
	g++ -Isrc/Include -Lsrc/lib -o Main.exe Game.cpp Main.cpp -lSDL2 -lSDL2main -lpthread -std=c++14 -pedantic -Wall -Wextra