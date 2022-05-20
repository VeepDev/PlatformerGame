
#include "GameHeader.hpp"

OurMap::OurMap(){
    WidthMap=10;
    HeightMap=10;
    EntireMap.resize(WidthMap,std::vector<char>(HeightMap,'.'));
}

OurMap::OurMap(unsigned int w, unsigned int h){
    WidthMap=w;
    HeightMap=h;
    EntireMap.resize(WidthMap,std::vector<char>(HeightMap,'.'));
}


