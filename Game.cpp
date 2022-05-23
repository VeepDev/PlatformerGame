
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

void OurMap::UpdateMap(unsigned int x, unsigned int y, char c){
                        //The if statements are bound checking
         unsigned int a;
         unsigned int b;
         if(x<1){a=1;}
         else{if(x==WidthMap){a=WidthMap-1;}
         else{a=x;}}
         
         if(y<1){b=1;}
         else{if(y>HeightMap-2){b=HeightMap-1;}
         else{b=y;}}

         EntireMap[a][b]=c;
         return;
}

                         //Chooses Symbol for player
Player::Player(){
  Avatar='#';
  Prev='.';
  PrevXcord=0;
  PrevYcord=0;
}

Player::Player(char a){
  Avatar=a;
  Prev='.';
}

                                                                  //This is used to check the block we will be interfering with and tell if we can collide or not
bool Player::CanCollide(unsigned int a, unsigned int b, OurMap m){
  return m.EntireMap[a][b]=='.';
}



                                                       //Set cordinate, sets the player position, could be used for when
                                                       //game instance is initialized, doors to other maps
void Player::SetCords(unsigned int x, unsigned int y){
  Xcord=x;
  Ycord=y;
}

void Player::SetCords(unsigned int x, unsigned int y,OurMap m){
  if(x>m.WidthMap-1){x=m.WidthMap-1;}
  else{Xcord=x;}
  
  if(y>m.HeightMap-1){y=m.HeightMap-1;}
  else{Ycord=y;}
  
  
}

char Player::getAvatar(){
  return Avatar;
}

                                         //This will print our player each time
//void Player::PrintPlayer(OurMap Map1){                                
//    return;
//}

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

void GameInstance::PlayRun(){

  bool movementFlag=0;  //We will use this to determine when to stop moving, such as reaching destination
  char x;
  bool NoPrev=false;
  //We need to reference cordinates each time to print character in right spot, this will hold x,y

  while(!movementFlag){
    if(NoPrev==true){
    P1.Prev=Level.EntireMap[P1.PrevXcord][P1.PrevYcord];}
    
    NoPrev=true;
    
    P1.PrevXcord=P1.Xcord;
    P1.PrevYcord=P1.Ycord;
    //Level.EntireMap[P1.Xcord][P1.Ycord]=P1.Prev;
    x=' ';
    

    std::cin >> x;                          //HEYYYYYYYYYYYY, we need to do bound checking, prinrtr previous, chang cin to getch() so we need not press enters
    //initscr();
	  //cbreak();                                  //Might wanna check the gameegine one lone coder video
    //timeout(1);
    
    //endwin();
    //x=getch();
    //endwin();
    //GetAsnycKey();
    
    
    
    switch (x)
    {
    case 'k':
      if(!P1.CanCollide(P1.Xcord+1,P1.Ycord,Level)){break;}
      P1.SetCords(P1.Xcord+1,P1.Ycord);
      Level.EntireMap[P1.Xcord][P1.Ycord]=P1.getAvatar();

    if(NoPrev==true){
    Level.EntireMap[P1.PrevXcord][P1.PrevYcord]=P1.Prev;}
      break;

    case 'i':
      /* code */
      if(!P1.CanCollide(P1.Xcord-1,P1.Ycord,Level)){break;}
      P1.SetCords(P1.Xcord-1,P1.Ycord);
      Level.EntireMap[P1.Xcord][P1.Ycord]=P1.getAvatar();

    if(NoPrev==true){
    Level.EntireMap[P1.PrevXcord][P1.PrevYcord]=P1.Prev;}
      break; 

    case 'l':
      /* code */
      if(!P1.CanCollide(P1.Xcord,P1.Ycord+1,Level)){break;}
      P1.SetCords(P1.Xcord,P1.Ycord+1);
      Level.EntireMap[P1.Xcord][P1.Ycord]=P1.getAvatar();
     

    if(NoPrev==true){
    Level.EntireMap[P1.PrevXcord][P1.PrevYcord]=P1.Prev;}
      break; 
      
    case 'j':
      /* code */
      if(!P1.CanCollide(P1.Xcord,P1.Ycord-1,Level)){break;}
      P1.SetCords(P1.Xcord,P1.Ycord-1);
      Level.EntireMap[P1.Xcord][P1.Ycord]=P1.getAvatar();

    if(NoPrev==true){
    Level.EntireMap[P1.PrevXcord][P1.PrevYcord]=P1.Prev;}
      break;
    
    case 'e':
      movementFlag=1;
      break;

    default:
      break;
    }
    

  }

}
                                                       //This function contains the thread, which will print the map each time, and run the game
void StartGame(GameInstance OurInstance){

  std::thread GameThread(&GameInstance::RunGame,&OurInstance);
 
  OurInstance.PlayRun();
  //std::cin.get();
  OurInstance.isRunning = ATOMIC_VAR_INIT(true); //maybe due the atomic initialization to true
  
  GameThread.join();
  std::cin.get();

}

