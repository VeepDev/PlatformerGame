
#include "GameHeader.hpp"

// g++ Main.cpp Game.cpp -o Main.exe -std=c++14 -pedantic -Wall -Wextra -lpthread
// g++ -Isrc/Include -Lsrc/lib -o Main.exe Game.cpp Main.cpp -lSDL2 -lSDL2main -lpthread -std=c++14 -pedantic -Wall -Wextra 
//The second one is what's located in the make file,


//Explained a little bit, the first two files are what we are using to make the executable
// the -o lets us entere the name for our executable "Main.exe", the next few are just 
// recommended for debugging, and then -lpthread is used because we utilize threads while
// running our game
//-lncurses is for the getch, not sure if we will kepp this

int main()
{
    
    OurMap Pib;
    Pib.d=3;

    std::cout<<Pib.d;
    std::cout<<std::endl; 
    Pib.PrintMap();

    unsigned int A=8;
    unsigned int B=130; 
    OurMap Pib2(A,B);

    std::vector<char> dafloor(B,'#');
    Pib2.EntireMap[7]=dafloor;

    for(unsigned int i=0;i<B;i+=6){
    Pib2.EntireMap[6][i]='#';}

     for(unsigned int i=0;i<B;i++){
    if(i>5 && i<25){     
    Pib2.EntireMap[3][i]='#';}}

     for(unsigned int i=0;i<A;i++){
    if(i>1 && i<A){     
    Pib2.EntireMap[i][15]='#';}}

    Pib2.PrintMap();

    Player PlayerMeep('@');
    PlayerMeep.SetCords(1,5);

    GameInstance Instance1(Pib2,PlayerMeep);
    
    bool gravityon=true;
    unsigned int gravityspd=10;
    Instance1.SetGravity(gravityon,gravityspd);
    
    StartGame(Instance1);

    return 1;
}