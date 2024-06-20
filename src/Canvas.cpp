#include <iostream>
#include "Canvas.hpp"
using std::cout; 
Canvas::Canvas(int width, int height){
    sf::ContextSettings settings; 
    settings.antialiasingLevel = 10;
    window.create(sf::VideoMode(width,height), "Boids", sf::Style::Titlebar | sf::Style::Close, settings);

}; 
Canvas::~Canvas(){

};
void Canvas::handleEvents(){
    sf::Event event; 
    while (window.pollEvent(event)){
        if(event.type == sf::Event::Closed){
            window.close();
        }
    }
    
}
void Canvas::update(float dt){

}
void Canvas::render(){
    window.clear(sf::Color::Black); 
    window.display();
}


void Canvas::run(){
    while (window.isOpen()){
        handleEvents(); 
        update(1);
        render();
    }   
}