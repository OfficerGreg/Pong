#include "Game.h"

#define SCREENWIDTH 1080
#define SCREENHEIGHT 720

int main(){
    Game game(SCREENWIDTH, SCREENHEIGHT);
    while (!game.GameshouldClose()){
        game.Tick();
    }
    
    return 0;
}