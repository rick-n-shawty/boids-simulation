#include <vector>
#include "Boid.hpp"
#include "Boundary.hpp"
#include "Circle.hpp"
#ifndef QUADTREE_HPP 
#define QUADTREE_HPP 

class QuadTree{
    public: 
        QuadTree(Boundary* bounds, int capacity); 
        ~QuadTree();
        bool insert(Boid*& boid){
            if(!boundary->contains(boid)) return false; 

            if(entities.size() < capacity){
                entities.push_back(boid); 
                return true;
            }else{
                if(!isDivided){
                    subdivide(); 
                }
                if(NW->insert(boid))         return true; 
                else if(NE->insert(boid))    return true; 
                else if(SW->insert(boid))    return true; 
                else if (SE -> insert(boid)) return true; 

                return false; 
            }
        } 
        void subdivide(){
            isDivided = true; 
            float x = boundary->x; 
            float y = boundary->y;
            float w = boundary->w / 2; 
            float h = boundary->h / 2;
            isDivided = true;

            NE = new QuadTree(new Boundary(x + (w / 2), y - (h / 2), w, h), this->capacity);

            NW = new QuadTree(new Boundary(x - (w / 2), y - (h / 2), w, h), this->capacity);

            SE = new QuadTree(new Boundary(x + (w / 2), y + (h / 2), w, h), this->capacity);

            SW = new QuadTree(new Boundary(x - (w / 2), y + (h / 2), w, h), this->capacity);
        }
        void clearExceptRoot() {
            clearChildren(NW);
            clearChildren(NE);
            clearChildren(SW);
            clearChildren(SE);

            // Clear the points vector
            entities.clear();

            // Reset the isDivided flag
            isDivided = false;
        }
        std::vector<Boid*> query(Circle*& region, std::vector<Boid*>& foundBoids){
            if(!region->intersects(boundary)){
                return foundBoids; 
            }

            for(int i = 0; i < entities.size(); i++){
                if(region->contains(entities[i])){
                    foundBoids.push_back(entities[i]);
                }
            }
            if(isDivided){
                NW->query(region, foundBoids);
                NE->query(region, foundBoids); 
                SW->query(region, foundBoids); 
                SE->query(region, foundBoids);
            }
            return foundBoids;
        }
    private: 
        int capacity;
        bool isDivided = false;
        Boundary* boundary;
        std::vector<Boid*> entities;
        QuadTree* NW; 
        QuadTree* SW; 
        QuadTree* NE; 
        QuadTree* SE; 

        void clearChildren(QuadTree*& node){
            if (node != nullptr) {
                // Clear the child node recursively
                node->clearExceptRoot();
                // Delete the child node
                delete node;
                // Set the pointer to null
                node = nullptr;
            }
        }
};

#endif 