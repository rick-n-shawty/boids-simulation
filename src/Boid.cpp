#include "Boid.hpp"
#include "Utils.hpp"

Boid::Boid(float x, float y, float width, float height){
    // triangle.setPointCount(3); 
    // sf::Vector2f point0(x,y); // top point  
    // sf::Vector2f point1(x - width / 2, y + height / 2); // bottom left point 
    // sf::Vector2f point2(x + width / 2, y + height / 2); // bottom right point

    // triangle.setPoint(0, point0); 
    // triangle.setPoint(1, point1); 
    // triangle.setPoint(2, point2);  

    // calculate the centroid 
    // sf::Vector2f centroid((point0.x + point1.x + point2.x) / 3.0f, (point0.y + point1.y + point2.y) / 3.0f);

    // triangle.setOrigin(centroid); 
    // triangle.setPosition(sf::Vector2f(x,y));
    // triangle.setFillColor(sf::Color::Red);

    circle.setPosition(sf::Vector2f(x, y)); 
    circle.setRadius(height); 
    circle.setFillColor(sf::Color::Red); 


    // set up initial velocity 
    velocity = randomVelocity(minSpeed, maxSpeed);
}                                            

Boid::~Boid(){
    // DESTRUCTOR
}