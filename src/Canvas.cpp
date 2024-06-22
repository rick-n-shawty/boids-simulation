#include <iostream>
#include "Canvas.hpp"
#include "Boid.hpp"
#include "Utils.hpp"

using std::cout; 


Canvas::Canvas(int width, int height){
    for(int i = 0; i < 20; i++){
        boids.push_back(new Boid(randomInt(300,400),randomInt(200,300),15, 30));
    }
    sf::ContextSettings settings; 
    settings.antialiasingLevel = 10;
    window.create(sf::VideoMode(width,height), "Boids", sf::Style::Titlebar | sf::Style::Close, settings);
    window.setFramerateLimit(90);
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
    for(int i = 0; i < boids.size(); i++){
        // cout << "velX: " << boids[i]->getNormalVel().x << " velY: " << boids[i]->getNormalVel().y << '\n';
        sf::Vector2f avgVel;
        int count = 0;
        for(int j = 0; j < boids.size(); j++){
            if(boids[i]->isClose(boids[j]) && boids[i] != boids[j]){
                avgVel = avgVel + boids[j]->getNormalVel();
                count++; 
            }
        }
        if(count != 0){
            float mag = vectorMag(boids[i]->getVelocity()); 
            // cout << "Magnitude: " << mag << "\n";
            avgVel.x = (avgVel.x / count) ;
            avgVel.y = (avgVel.y / count) ;
            // cout << "X: " << avgVel.x << " Y: " << avgVel.y << "\n";
        //     boids[i]->setVelocity(avgVel);
        };
        boids[i]->move();
    }
    // cout << boids[0]->getPos().x << "\n";
}
void Canvas::render(){
    window.clear(sf::Color::Black); 
    for(int i = 0; i < boids.size(); i++){
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