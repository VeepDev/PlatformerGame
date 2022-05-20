
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

void OurMap::PrintMap(){
  for(unsigned int i=0;i<EntireMap.size();i++){
      for(unsigned int j=0;j<EntireMap[i].size();j++){
          std::cout<<EntireMap[i][j];
      }
      std::cout<<std::endl;
  }
}

                         //Chooses Symbol for player
Player::Player(char a){
  Avatar=a;
}

                                                       //Set cordinate, sets the player position, could be used for when
                                                       //game instance is initialized, doors to other maps
void Player::SetCords(unsigned int x, unsigned int y){
  Xcord=x;
  Ycord=y;
}

