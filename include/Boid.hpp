#include <cmath> 
#include <iostream>
#include <SFML/Graphics.hpp>
#ifndef BOID_HPP 
#define BOID_HPP 

class Boid{
    public: 
        Boid(float x, float y, float width, float height); 
        ~Boid(); 
        void show(sf::RenderWindow& window){
            window.draw(triangle);
        }
        sf::Vector2f getPos(){
            return triangle.getPosition(); 
        }
        sf::Vector2f getVelocity(){
            return velocity; 
        }
        sf::Vector2f getNormalVel(){
            float mag = sqrt((velocity.x * velocity.x) + (velocity.y * velocity.y));
            sf::Vector2f newVel(0,0);
            if(mag == 0){
                return newVel;
            } 
            newVel.x = (velocity.x) / mag; 
            newVel.y = (velocity.y) / mag; 
            return newVel;
        }
        void setVelocity(sf::Vector2f newVel){
            velocity = newVel; 
        }
        void move(){
            triangle.move(velocity);
        }
        bool isClose(Boid*& boid){
            float x1 = getPos().x;
            float y1 = getPos().y; 
            float x2 = boid->getPos().x; 
            float y2 = boid->getPos().y; 

            float dist = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1); 
            return dist < 50;
        }
    private: 
        sf::ConvexShape triangle; 
        sf::Vector2f velocity;
};


#endif 