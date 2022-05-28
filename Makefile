all:
	g++ -I src/include -L src/lib -o Main.exe Game.cpp Main.cpp -lmingw32 -lSDL2main -lSDL2  -lpthread -std=c++14