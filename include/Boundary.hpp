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
            return true;
        }


    private:
        sf::RectangleShape box; 
};

#endif