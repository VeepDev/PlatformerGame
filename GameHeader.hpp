//This will be our header file

#include <iostream>
#include <vector>
#include <list>

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
Player(char a);
void SetCords(unsigned int x, unsigned int y);
private:
char Avatar; //The symbol that will be printed as our character
unsigned int Xcord;
unsigned int Ycord;
};


class GameInstance{
    public:
    OurMap Level;
    Player P1;
};