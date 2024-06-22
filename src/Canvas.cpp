#include <iostream>
#include "Canvas.hpp"
#include "Boid.hpp"
#include "Utils.hpp"

using std::cout; 


Canvas::Canvas(int width, int height){
    mainBounds = new Boundary(width / 2.0f, height / 2.0f, width, height);
    qtree = new QuadTree(mainBounds, 4);
    for(int i = 0; i < 20; i++){
        boids.push_back(new Boid(randomInt(300,400),randomInt(200,300),15, 30));
        qtree->insert(boids[i]);
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
    if(qtree != nullptr){
        delete qtree; 
        qtree = nullptr;
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
    if(qtree != nullptr) qtree->clearExceptRoot();
    foundBoids.clear();

    totalTime += dt; 
    for(int i = 0; i < boids.size(); i++){
        sf::Vector2f avgVel;
        int count = 0;
        for(int j = 0; j < boids.size(); j++){
            if(boids[i]->isClose(boids[j]) && boids[i] != boids[j]){
                avgVel = avgVel + boids[j]->getNormalVel();
                count++; 
            }
        }
        if(count != 0 && totalTime > 1.5){ // allignment 
            avgVel.x = (avgVel.x / count);
            avgVel.y = (avgVel.y / count);
            boids[i]->setVelocity(avgVel);
        };
        boids[i]->move();
        qtree->insert(boids[i]);
    }
}
void Canvas::render(){
    window.clear(sf::Color::Black); 
    for(int i = 0; i < boids.size(); i++){
        boids[i]->show(window);
    }
    qtree->show(window);
    window.display();
}


void Canvas::run(){
    while (window.isOpen()){
        float dt = clock.restart().asSeconds();
        handleEvents(); 
        update(dt);
        render();
    }   
}