#include "Boid.hpp"
#include <SFML/Graphics.hpp>
#ifndef BOUNDARY_HPP 
#define BOUNDARY_HPP 

class Boundary{
    public:
        float x, y, w, h; 
        Boundary(float x, float y, float w, float h); 
        ~Boundary();  

        bool contains(Boid* boid){
            return (
                boid->getPos().x >= x - (w / 2) && 
                boid->getPos().x <= x + (w / 2) && 
                boid->getPos().y >= y - (h / 2) &&
                boid->getPos().y <= y + (h / 2)
            ); 
        }

        sf::RectangleShape getShape(){
            return box; 
        }

    private:
        sf::RectangleShape box; 
};

#endif