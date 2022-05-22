//This will be our header file

#include <iostream>
#include <vector>
#include <list>
#include <thread>
#include <atomic>
#include <ncurses.h>


             //This will be the map itself,
class OurMap{
public:
 OurMap();
 OurMap(unsigned int w, unsigned int h);
 int d;
 void PrintMap();   //Prints entire map
 void PrintScreen(); //Prnts the Camera, a portion of the map we are at
 std::vector<std::vector<char>> EntireMap;  //matrix holding the map as chars
 
private:
 unsigned int WidthMap;
 unsigned int HeightMap;
};

                  //This will be a portion of our map, and we will print our character on it
class OurCamera{
    public:
    OurCamera();
    private:

};
             //This will be our Character
class Player{
public:
Player();
Player(char a);
void SetCords(unsigned int x, unsigned int y);
void PrintPlayer(OurMap Map1);

char Prev; //We get the previous tile and print it so the map returns to normal a.k.a, it wont leave a path of itself
unsigned int Xcord;
unsigned int Ycord;
unsigned int PrevXcord;
unsigned int PrevYcord;
char getAvatar();

private:
char Avatar; //The symbol that will be printed as our character
};

                     //Idea for game running, give it small amount of time, if nothing we proceed, if key pressed we moves
class GameInstance{
    public:
   
    GameInstance(OurMap level, Player player1);
    GameInstance(const GameInstance & other);
    OurMap Level;
    Player P1;
    void PlayRun();    //This function controls the movement of the character
    void RunGame();   //THIS will be the game running itself, pretty important 
    std::atomic<bool> isRunning;   //This bool will be used to tell if the game is still running
  
};

void StartGame(GameInstance OurInstance);