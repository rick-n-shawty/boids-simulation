#include <iostream>
#include <random> 
#ifndef UTILS_HPP 
#define UTILS_HPP 

inline int randomInt(int min, int max){
    return (rand() % (max - min)) + min;    
}
inline float randomFloat(float min, float max){
    std::random_device rd; 
    std::mt19937 gen(rd());
    std::normal_distribution<float> distribution(min, max);
    float randomFloat = distribution(gen);
    return randomFloat;
}

#endif