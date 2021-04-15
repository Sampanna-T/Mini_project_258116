#ifndef SOLVECUBE_H
#define SOLVECUBE_H
#include "rubiks_cube.h"
#include "algorithm.h"

/**
  * @brief 
  * count variable specifies how many operations / algorithms were performed on the rubiks cube
  */
 static int count=0;

 /**
  * @brief 
  * cretes a plus mark at the bottom
  */
 boolean plusBottom();

 
 /**
  * @brief 
  * completes the first layer
  */   
 boolean layerFirst();
    
 /**
  * @brief 
  * completes the second layer if first layer is complete
  */   
 boolean layerSecond();

 /**
  * @brief 
  * cretes a plus mark at the top after solving first and second layer
  */
 boolean plusTop();
    
 /**
  * @brief 
  * aligns all the centers of the top layer
  */
 boolean alignCenter();
    
 /**
  * @brief 
  * positions the corner pieces(at the top) at the right location
  */
 boolean cornerAlign();

 /**
  * @brief 
  * solves the corner pieces which are aligned using corner() function
  */
 boolean layerThird();
    
 /**
  * @brief 
  * performs all the operations specified above
  */
 boolean solveAll();
    
#endif