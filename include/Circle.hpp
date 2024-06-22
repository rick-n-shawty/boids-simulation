#include "Boundary.hpp"
#ifndef CIRCLE_HPP 
#define CIRCLE_HPP 

class Circle{
    public: 
        float x, y, r; 

        Circle(float x1, float y1, float r1){
            x = x1;
            y = y1; 
            r = r1; 
        };
        ~Circle(){

        }
        bool intersects(Boundary* boundary){
            return !(
                x + r <  boundary->x  -  (boundary->w / 2) || 
                x - r >  boundary->x  +  (boundary->w / 2) || 
                y - r >  boundary->y  +  (boundary->h / 2) ||
                y + r <  boundary->y  -  (boundary->h / 2) 
            );
        }
    private: 
};

#endif 