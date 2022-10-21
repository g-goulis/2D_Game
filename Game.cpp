//
// Created by ninja on 10/14/2022.
//

#include "headers/Game.h"

Game::Game(){
    this->initVars();
    this->initWindow();
    this->initEnemy();

}

Game::~Game(){
    delete this->window;
    this->window = nullptr;
}

void Game::update(){
    this->pollEvents();

    this->updateMousePos();

    this->updateEnemies();
}

void Game::render(){
    this->window->clear();

    this->renderEnemeies();

    text.setString("Points: " + std::to_string(this->points));

    this->window->draw(text);

    this->window->display();
}

void Game::initVars() {
    this->window = nullptr;
    this->enemySpawnTimer = 0.f;
    this->enemySpawnTimerMax = 100.f;
    this->maxEnemies = 5;
    this->points = 0;
    this->font.loadFromFile("C:\\Users\\ninja\\CLionProjects\\2D_Game\\assets\\arial_narrow_7.ttf");
    this->text.setFont(this->font);
    this->text.setCharacterSize(50);

}

void Game::initWindow() {
    this->videoMode.height = 600;
    this->videoMode.width = 800;

    this->window = new sf::RenderWindow(this->videoMode, "My First Game", sf::Style::Titlebar | sf::Style::Close);
    this->window->setFramerateLimit(60);
}

const bool Game::getWindowRunning() const {
    return this->window->isOpen();
}

void Game::pollEvents() {
    while(this->window->pollEvent(this->event)){
        switch(this->event.type){
            case sf::Event::Closed:
                this->window->close();
                break;
            case sf::Event::KeyPressed:
                if(this->event.key.code == sf::Keyboard::Escape){
                    this->window->close();
                }
                break;
        }
    }
}

void Game::initEnemy() {

    this->enemy.setPosition(10.f, 10.f);
    this->enemy.setSize(sf::Vector2f(50.f, 50.f));
    this->enemy.setFillColor(sf::Color::Red);
    this->enemy.setOutlineColor(sf::Color::White);
    this->enemy.setOutlineThickness(2.f);

}

void Game::updateMousePos() {
    this->mousePosWindow = sf::Mouse::getPosition(*this->window);
    this->mousePosView = this->window->mapPixelToCoords(this->mousePosWindow);
}

void Game::spawnEnemy() {
    this->enemy.setPosition(rand()%static_cast<int>(this->window->getSize().x - this->enemy.getSize().x), 0.f);

    this->enemy.setFillColor(sf::Color::Red);

    this->enemies.push_back(this->enemy);
}

void Game::updateEnemies() {


    if(this->enemySpawnTimer >= this->enemySpawnTimerMax){
        this->enemySpawnTimer = 0.f;
        if(this->enemies.size() < this->maxEnemies){
            this->spawnEnemy();
        }
    } else {
        this->enemySpawnTimer += 1.f;
    }

    //Move the enemies
    bool deleted;
    for(int i = 0; i < this->enemies.size(); i++){
        deleted = false;
        this->enemies[i].move(0.f, 1.f);

        //Check if clicked upon?
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            if(this->enemies[i].getGlobalBounds().contains(this->mousePosView)){
                deleted = true;
                this->points += 10.f;
            }
        }

        //If enemy passes bottom of screen
        if(this->enemies[i].getPosition().y > this->window->getSize().y){
            deleted = true;
        }

        if(deleted){
            this->enemies.erase(this->enemies.begin() + i);

        }
    }
}

void Game::renderEnemeies() {
    for(auto &i : this->enemies){
        this->window->draw(i);
    }
}
