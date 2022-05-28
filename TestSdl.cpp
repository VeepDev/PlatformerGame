//g++ -I src/include -L src/lib -o Main.exe  TestSdl.cpp -lSDL2main -lSDL2  -lpthread -std=c++14
#define SDL_MAIN_HANDLED
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

  window = SDL_CreateWindow("Test Window",500,200,640,480,SDL_WINDOW_SHOWN);
  SDL_Delay(6000);
  SDL_DestroyWindow(window);
  SDL_Quit();
 

  return 1;
}