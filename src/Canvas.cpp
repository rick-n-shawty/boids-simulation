#include <iostream>
#include "Canvas.hpp"
#include "Boid.hpp"
#include "Utils.hpp"
using std::cout; 


Canvas::Canvas(int width, int height){
    for(int i = 0; i < 20; i++){
        boids.push_back(new Boid(randomInt(0,width),randomInt(0,height),15, 30));
    }
    sf::ContextSettings settings; 
    settings.antialiasingLevel = 10;
    window.create(sf::VideoMode(width,height), "Boids", sf::Style::Titlebar | sf::Style::Close, settings);

}; 
Canvas::~Canvas(){
    // clean up dynamically allocated boids 
    for(int i = 0; i < boids.size(); i++){
        delete boids[i]; 
    }
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
    for(int i = 0; i < boids.size(); i++){
        cout << boids.size() << "\n";
        boids[i]->show(window);
    }
    window.display();
}


void Canvas::run(){
    while (window.isOpen()){
        handleEvents(); 
        update(1);
        render();
    }   
}