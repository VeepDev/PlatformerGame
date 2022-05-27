//g++ -I src/include -L src/lib -o Main.exe  TestSdl.cpp -lmingw32 -lSDL2main -lSDL2  -lpthread -std=c++14
#include <SDL2/SDL.h>
#include <iostream>

int main(int argc, char *argv[]){
  
 
   SDL_Window* window=nullptr;
   std::cout<<"Poaper"<<std::endl;
  
   SDL_Init(SDL_INIT_VIDEO);
   
    std::cout<<"horsepucky";

    if(SDL_Init(SDL_INIT_VIDEO)!=0){
    std::cout<<"SDL could not be initialized:";
    }
    
    std::cout<<"FUCKEA";

  window = SDL_CreateWindow("Test Window",0,000,640,480,SDL_WINDOW_SHOWN);
  SDL_Delay(3000);
  SDL_DestroyWindow(window);
  SDL_Quit();
 

  return 1;
}