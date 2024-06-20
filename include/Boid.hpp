#include <SFML/Graphics.hpp>
#ifndef BOID_HPP 
#define BOID_HPP 

class Boid{
    public: 
        Boid(float x, float y); 
        ~Boid(); 
    private: 
        sf::ConvexShape triangle; 
        sf::Vector2f velocity;
};


#endif 