#include <iostream>
#include "Canvas.hpp"
#include "Boid.hpp"
#include "Utils.hpp"

using std::cout; 


Canvas::Canvas(int width, int height){
    queryRegion = new Circle(0,0,1);
    mainBounds = new Boundary(width / 2.0f, height / 2.0f, width, height);
    qtree = new QuadTree(mainBounds, 4);
    for(int i = 0; i < 400; i++){
        boids.push_back(new Boid(randomInt(0,width),randomInt(0,height), 30, 5));
        qtree->insert(boids[i]);
    }
    sf::ContextSettings settings; 
    settings.antialiasingLevel = 10;
    window.create(sf::VideoMode(width,height), "Boids", sf::Style::Titlebar | sf::Style::Close, settings);
    window.setFramerateLimit(60);
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
    if(queryRegion != nullptr){
        delete queryRegion; 
        queryRegion = nullptr; 
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
    totalTime += dt; 

    for(int i = 0; i < boids.size(); i++){
        qtree->insert(boids[i]);
    }

    for(int i = 0; i < boids.size(); i++){
        foundBoids.clear();

        queryRegion->x = boids[i]->getPos().x;
        queryRegion->y = boids[i]->getPos().y; 
        queryRegion->r = boids[i]->getPerception(); 
        qtree->query(queryRegion,foundBoids); 

        boids[i]->ASC(foundBoids); // allignment, separation, cohesion 
        boids[i]->move();
        boids[i]->show(window); 
    }
}
void Canvas::render(){
    // qtree->show(window);
    window.display();
}


void Canvas::run(){
    while (window.isOpen()){
        window.clear(sf::Color(137, 207, 240));
        float dt = clock.restart().asSeconds();
        handleEvents(); 
        update(dt);
        render();
    }   
}