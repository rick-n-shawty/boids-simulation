# Flocking Simulation 

## Demo
![](https://github.com/rick-n-shawty/boids-simulation/blob/main/BoidVid.gif)


## Background 
Flocking simulation algorithm (also known as boids algorithm) was developed by Craig Reynolds in 1986.
The primary goal of the algorithm is to simulate behaviour of birds in a group motion.

## Algorithm Description 
The algorithm adheres to THREE rules: 
- Allignment 
- Cohesion 
- Separation 
### Allignment 
Essentialy, an individual boids tries to adjust its velocity towards the average direction of the nearby 
flockmates. By "nearby", I mean the perception range of each boid. 

### Cohesion 
In cohesion, a boid always steers towards the center of mass of the nearby boids. 

### Separation 
This rule produces introveted boids... If boid B is withing a protected range of boid A, boid A tries to steer away from boid B. 

Combining these rules yields a beautiful emergent behaviour. If you are curious,
More details can be found [here](https://en.wikipedia.org/wiki/Boids). 


## Getting started on macOS