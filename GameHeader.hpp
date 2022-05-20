//This will be our header file

#include <iostream>
#include <vector>
#include <list>

class OurMap{
public:
 OurMap();
 OurMap(unsigned int w, unsigned int h);
 int d;
 void PrintMap();
 void RunGame();
 
private:
 unsigned int WidthMap;
 unsigned int HeightMap;
 std::vector<std::vector<char>> EntireMap;
 int l;
};