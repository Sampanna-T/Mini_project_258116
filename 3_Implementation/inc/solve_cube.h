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
 void plusBottom();

 
 /**
  * @brief 
  * completes the first layer
  */   
 void layerFirst();
    
 /**
  * @brief 
  * completes the second layer if first layer is complete
  */   
 void layerSecond();

 /**
  * @brief 
  * cretes a plus mark at the top after solving first and second layer
  */
 void plusTop();
    
 /**
  * @brief 
  * aligns all the centers of the top layer
  */
 void alignCenter();
    
 /**
  * @brief 
  * positions the corner pieces(at the top) at the right location
  */
 void cornerAlign();

 /**
  * @brief 
  * solves the corner pieces which are aligned using corner() function
  */
 void layerThird();
    
 /**
  * @brief 
  * performs all the operations specified above
  */
 void solveAll();
    
#endif