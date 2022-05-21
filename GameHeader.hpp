//This will be our header file

#include <iostream>
#include <vector>
#include <list>
#include <thread>
#include <atomic>

             //This will be the map itself,
class OurMap{
public:
 OurMap();
 OurMap(unsigned int w, unsigned int h);
 int d;
 void PrintMap();   //Prints entire map
 void PrintScreen(); //Prnts the Camera, a portion of the map we are at
 
 
private:
 unsigned int WidthMap;
 unsigned int HeightMap;
 std::vector<std::vector<char>> EntireMap;  //matrix holding the map as chars
};


             //This will be our Character
class Player{
public:
Player();
Player(char a);
void SetCords(unsigned int x, unsigned int y);
private:
char Avatar; //The symbol that will be printed as our character
unsigned int Xcord;
unsigned int Ycord;
};

                     //Idea for game running, give it small amount of time, if nothing we proceed, if key pressed we moves
class GameInstance{
    public:
   
    GameInstance(OurMap level, Player player1);
    GameInstance(const GameInstance & other);
    OurMap Level;
    Player P1;
    void RunGame();   //THIS will be the game running itself, pretty important 
    std::atomic<bool> isRunning;   //This bool will be used to tell if the game is still running
  
};

void StartGame(GameInstance OurInstance);