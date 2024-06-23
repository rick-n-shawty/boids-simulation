#include <cmath>
#include <iostream>
#include <random> 
#include <math.h>
#ifndef UTILS_HPP 
#define UTILS_HPP 

const int WINDOW_WIDTH = 1000;
const int WINDOW_HEIGHT = 750;

inline int randomInt(int min, int max){
    return (rand() % (max - min)) + min;    
}
inline float randomFloat(float min, float max){
    std::random_device rd; 
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> distribution(min, max);
    float randomFloat = distribution(gen);
    return randomFloat;
}
inline float vectorMagnitude(sf::Vector2f vect){
    return (sqrt( pow(vect.x, 2) + pow(vect.y, 2) ));
}
inline float vectorMagSquared(sf::Vector2f vect){
    return (pow(vect.x, 2) + pow(vect.y, 2)); 
}
inline float calcDistance(sf::Vector2f a, sf::Vector2f b){
    sf::Vector2f dist; 
    dist.x = pow(a.x - b.x, 2);
    dist.y = pow(a.y - b.y, 2); 
    return vectorMagnitude(dist);
}

inline sf::Vector2f normalize(sf::Vector2f vector){
    float mag = vectorMagnitude(vector);
    constexpr float epsilon = 1e-6f; // Small epsilon value
    if (mag > epsilon) {
        vector.x /= mag;
        vector.y /= mag;
    }
    return vector;
}

inline sf::Vector2f limitMag(sf::Vector2f vector, float maxMagnitude){
    float mag = vectorMagnitude(vector); 
    if(mag > maxMagnitude){
        vector *= maxMagnitude / mag;
    }
    return vector;
}

inline sf::Vector2f randomVelocity(float minMag, float maxMag){
    float angle = randomFloat(0.0f, 2.0f * M_PI); 
    sf::Vector2f direction(cos(angle), sin(angle));
    float magnitude = randomFloat(minMag, maxMag); 
    sf::Vector2f velocity = direction * magnitude;

    return velocity; 
}

#endif