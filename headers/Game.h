/*
 * ClassName: Game
 * Description: Class for all functions/functionality of game engine
 */

#ifndef INC_2D_GAME_GAME_H
#define INC_2D_GAME_GAME_H

#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class Game {
private:
    //Variables
    sf::RenderWindow* window;
    sf::VideoMode videoMode;
    sf::Event event;

    sf::RectangleShape enemy;

    //Functions
    void initVars();
    void initWindow();
    void initEnemy();

public:
    //Constructors and Destructors
    Game();
    virtual ~Game();

    //Getters and Setters
    const bool getWindowRunning() const;

    //Functions
    void update();
    void render();
    void pollEvents();
};


#endif //INC_2D_GAME_GAME_H
