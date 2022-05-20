
#include "GameHeader.hpp"

// g++ Main.cpp Game.cpp -o Main.exe

int main(int argc, char** argv)
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

    return 1;
}