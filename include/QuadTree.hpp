#ifndef QUADTREE_HPP 
#define QUADTREE_HPP 

class QuadTree{
    public: 
        QuadTree(); 
        ~QuadTree();
        bool insert(){
            return true; 
        } 
        void subdivide(){
            
        }
    private: 
        int capacity;
        bool isDivided = false;
        // boundary 
        // entities 
        QuadTree* NW; 
        QuadTree* SW; 
        QuadTree* NE; 
        QuadTree* SE; 


};

#endif 