
#include "GameHeader.hpp"

// g++ Main.cpp Game.cpp -o Main.exe -std=c++14 -pedantic -Wall -Wextra -lpthread

//Explained a little bit, the first two files are what we are using to make the executable
// the -o lets us entere the name for our executable "Main.exe", the next few are just 
// recommended for debugging, and then -lpthread is used because we utilize threads while
// running our game

int main()
{
    
    OurMap Pib;
    Pib.d=3;

    std::cout<<Pib.d;
    std::cout<<std::endl; 
    Pib.PrintMap();

    unsigned int A=8;
    unsigned int B=30; 
    OurMap Pib2(A,B);
    Pib2.PrintMap();

    Player PlayerMeep('@');
    PlayerMeep.SetCords(1,2);

    GameInstance Instance1(Pib2,PlayerMeep);
    StartGame(Instance1);

    return 1;
}