//This will be our header file

#include <iostream>
#include <vector>
#include <list>
#include <thread>
#include <atomic>
#include <SDL2/SDL.h>
//#include <windows.h>
//#include <ncurses.h>




             //This will be the map itself,
class OurMap{
public:
 OurMap();
 OurMap(unsigned int w, unsigned int h);
 int d;
 void PrintMap();   //Prints entire map
 void PrintScreen(); //Prnts the Camera, a portion of the map we are at
 void UpdateMap(unsigned int x, unsigned int y, char c); //Updates the map, and will do bound checking
 std::vector<std::vector<char>> EntireMap;  //matrix holding the map as chars
 unsigned int WidthMap;
 unsigned int HeightMap;
};

                  //This will be a portion of our map, and we will print our character on it
class OurCamera{
    public:
    OurCamera();
    void UpdateCamera();
    std::vector<std::vector<char>> Camera;
    unsigned int WidthCamera;
    unsigned int HeightCamera;

};
             //This will be our Character
class Player{
public:
Player();
Player(char a);
bool CanCollide(unsigned int a, unsigned int b,OurMap m); //This is used to check the block we will be interfering with and tell if we can collide or not
void SetCords(unsigned int x, unsigned int y);
void SetCords(unsigned int x, unsigned int y,OurMap m); //Not used for now
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
 
    void SetGravity(bool flag, int speed);  //
    bool isGravity;        //This tell us whether Gravity has been set on or off in options
    int  speedGravity;     //This is the intensity of Gravity
    void GravityOn(int &counter); //This actually controls/makes the gravity happen

    void PlayRun();    //This function controls the movement of the character
    void RunGame();   //THIS will be the game running itself, pretty important 
    std::atomic<bool> isRunning;   //This bool will be used to tell if the game is still running
  
};

void StartGame(GameInstance OurInstance);