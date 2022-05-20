//This will be our header file

#include <iostream>
#include <vector>
#include <list>

class OurMap{
public:
 OurMap();
 OurMap(unsigned int w, unsigned int h);
 int d;
 void PrintMap();   //Prints entire map
 void PrintScreen(); //Prnts the Camera, a portion of the map we are at
 void RunGame(); //To be determined
 
private:
 unsigned int WidthMap;
 unsigned int HeightMap;
 std::vector<std::vector<char>> EntireMap;  //matrix holding the map as chars
};