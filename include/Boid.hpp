#include <cmath> 
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Utils.hpp"
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
        float velocityMagnitude(){
            return sqrt(pow(velocity.x, 2) + pow(velocity.y, 2));
        }
        sf::Vector2f velocityNormal(){
            float mag = (velocity.x * velocity.x) + (velocity.y * velocity.y);
            sf::Vector2f newVel(0,0);
            if(mag == 0){
                return newVel;
            } 
            newVel.x = pow(velocity.x, 2) / mag; 
            newVel.y = pow(velocity.y, 2) / mag; 
            return newVel;
        }
        void setVelocity(sf::Vector2f newVel){
            velocity = newVel; 
        }
        void move(){
            sf::Vector2f position = triangle.getPosition();
            float x = position.x;
            float y = position.y;

            // Update position based on velocity
            position += velocity;

            // Wrap around screen edges
            if (position.x < 0) position.x += WINDOW_WIDTH;
            else if (position.x >= WINDOW_WIDTH) position.x -= WINDOW_WIDTH;

            if (position.y < 0) position.y += WINDOW_HEIGHT;
            else if (position.y >= WINDOW_HEIGHT) position.y -= WINDOW_HEIGHT;

            // Set new position
            triangle.setPosition(position);
  
        }
        void ASC(std::vector<Boid*>& neighbors){


            for(int i = 0; i < neighbors.size(); i++){

            }

        }
        bool isClose(Boid*& boid){
            float x1 = getPos().x;
            float y1 = getPos().y; 
            float x2 = boid->getPos().x; 
            float y2 = boid->getPos().y; 

            float dist = pow(x2 - x1, 2) + pow(y2 - y1, 2); 
            return (dist < pow(perception, 2));
        }

        int getPerception(){
            return perception;
        }
        void setPerception(int& newPerception){
            perception = newPerception;
        }
    private: 
        sf::ConvexShape triangle; 
        sf::Vector2f velocity;
        int perception = 100;
        float maxSpeed = 2;
        float minSpeed = 0.1;
};


#endif 