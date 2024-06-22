#include "Boundary.hpp"


Boundary::Boundary(float x, float y, float w, float h){
    this->x = x; 
    this->y = y; 
    this->w = w;
    this->h = h;
    box.setSize(sf::Vector2f(w, h));
    box.setOrigin(sf::Vector2f(w / 2, h / 2));
    box.setPosition(sf::Vector2f(x,y));

    box.setOutlineColor(sf::Color::White); 
    box.setOutlineThickness(0.3);
    box.setFillColor(sf::Color::Transparent);
}
Boundary::~Boundary(){

};