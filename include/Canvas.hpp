#include <SFML/Graphics.hpp>
#include <vector> 
#include "Boid.hpp"
#include "QuadTree.hpp"
#ifndef CANVAS_HPP 
#define CANVAS_HPP

class Canvas{
    public: 
        Canvas(int width = 1000, int height=750); 
        ~Canvas();
        void run(); 
    private: 
        sf::RenderWindow window; 
        sf::Clock clock;

        void handleEvents(); 
        void update(float dt);
        void render();

        float totalTime = 0;

        QuadTree* qtree;
        Boundary* mainBounds;
        Circle* queryRegion; 
        std::vector<Boid*> boids;
        std::vector<Boid*> foundBoids; 
};
#endif