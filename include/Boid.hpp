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
        sf::Vector2f getVelocityDir(){
            float mag = velocity.x * velocity.x + velocity.y * velocity.y;
            if(mag != 0){
                return (velocity / mag);
            }else{
                return velocity;
            }
        }
        void setVelocity(sf::Vector2f& newVel){
            velocity = newVel; 
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