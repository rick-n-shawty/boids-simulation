#include <iostream>
#include <ctime> 
#ifndef UTILS_HPP 
#define UTILS_HPP 

int randomInt(int min, int max){
    return (rand() % (max - min)) + min;    
}

#endif