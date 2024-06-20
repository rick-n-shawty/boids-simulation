#include <SFML/Graphics.hpp>
#include <vector> 
#include "Boid.hpp"
#ifndef CANVAS_HPP 
#define CANVAS_HPP

class Canvas{
    public: 
        Canvas(int width = 1000, int height=750); 
        ~Canvas();
        void run(); 
    private: 
        sf::RenderWindow window; 
        void handleEvents(); 
        void update(float dt);
        void render();

        std::vector<Boid*> boids;
};
#endif