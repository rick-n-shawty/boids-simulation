#include <iostream>
#include <ctime>
#include <SFML/Graphics.hpp>
#include "Canvas.hpp"

int main (){
    srand(time(0));
    Canvas canvas(1000,750);
    canvas.run();
    return 0; 
}