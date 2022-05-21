
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
Player::Player(){
  Avatar='#';
}

Player::Player(char a){
  Avatar=a;
}

                                                       //Set cordinate, sets the player position, could be used for when
                                                       //game instance is initialized, doors to other maps
void Player::SetCords(unsigned int x, unsigned int y){
  Xcord=x;
  Ycord=y;
}

GameInstance:: GameInstance(const GameInstance & other){
  Level=other.Level;
  P1=other.P1;
  isRunning=ATOMIC_VAR_INIT(false);
}

GameInstance::GameInstance(OurMap levelx,Player player1){
  Level=levelx;
  P1=player1;
  isRunning=ATOMIC_VAR_INIT(false);
}

                                                     //This prints the screen each time, our actual
                                                     //game running pretty much
void GameInstance::RunGame(){

       using namespace std::literals::chrono_literals;

       while(!isRunning){
       Level.PrintMap();
       std::this_thread::sleep_for(1s);
       }

}

void StartGame(GameInstance OurInstance){

  std::thread GameThread(&GameInstance::RunGame,&OurInstance);
 

  std::cin.get();
  OurInstance.isRunning = ATOMIC_VAR_INIT(true); //maybe due the atomic initialization to true
  
  GameThread.join();
  std::cin.get();

}

