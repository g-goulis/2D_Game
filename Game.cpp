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

    //Relative to the screen
    //std::cout << "Mouse Position: " << sf::Mouse::getPosition().x << " " << sf::Mouse::getPosition().y << std::endl;

    //Relative to the window
    std::cout << "Mouse Position: " << sf::Mouse::getPosition(*this->window).x << " " << sf::Mouse::getPosition(*this->window).y << std::endl;
}

void Game::render(){
    this->window->clear();

    this->window->draw(this->enemy);

    this->window->display();
}

void Game::initVars() {
    this->window = nullptr;

}

void Game::initWindow() {
    this->videoMode.height = 600;
    this->videoMode.width = 800;

    this->window = new sf::RenderWindow(this->videoMode, "My First Game", sf::Style::Titlebar | sf::Style::Close);
    this->window->setFramerateLimit(144);
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
