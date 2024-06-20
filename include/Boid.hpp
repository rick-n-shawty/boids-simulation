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

        
    private: 
        sf::ConvexShape triangle; 
        sf::Vector2f velocity;
};


#endif 