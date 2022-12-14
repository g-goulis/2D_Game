/*
 * ClassName: Game
 * Description: Class for all functions/functionality of game engine
 */

#ifndef INC_2D_GAME_GAME_H
#define INC_2D_GAME_GAME_H

#include <iostream>
#include <vector>
#include <ctime>

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
    sf::Font font;
    sf::Text text;

    //Mouse positions
    sf::Vector2i mousePosWindow;
    sf::Vector2f mousePosView;

    sf::RectangleShape enemy;
    std::vector<sf::RectangleShape> enemies;

    //Game Logic
    float enemySpawnTimer;
    float enemySpawnTimerMax;
    int maxEnemies;
    int points;

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
    void updateMousePos();
    void spawnEnemy();
    void updateEnemies();
    void renderEnemeies();
};


#endif //INC_2D_GAME_GAME_H
