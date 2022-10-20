#include <iostream>
#include "Game.cpp"

//using namespace std;

int main() {

    //Init random
    srand(static_cast<unsigned>(time(NULL)));

    //Init game object
    Game game;

    //Game loop
    while(game.getWindowRunning()){
        //Update
        game.update();

        //Render
        game.render();
    }

    //End of application
    return 0;
}
