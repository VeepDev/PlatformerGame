#include "GameHeader.hpp"
////g++ -I src/include -L src/lib -o PlatTest.exe Game.cpp PlatTest.cpp -lmingw32 -lSDL2main -lSDL2  -lpthread -std=c++14 

// g++ -I src/include -I SDL_image/include  -L SDL_image/lib -L src/lib  -o PlatTest.exe Game.cpp PlatTest.cpp -lmingw32 -lSDL2 -lSDL2main -lSDL2_image  -lpthread -std=c++14
GameEngineSDL *game = nullptr;

int main(int argrc, char *argv[]){
    game = new GameEngineSDL();

    game->GameInit("PlatformerGame", false);

    while(game->running()){
        game->handleEvents();
        game->update();
        game->render();
    }

    game->clean();
    return 0;
}