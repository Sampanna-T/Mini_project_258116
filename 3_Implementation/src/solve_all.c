#include <stdio.h>
#include <string.h>
#include "solve_cube.h"
    
boolean solveAll(){

    printf("\n************************************PLUS_BOTTOM****************************************S\n");
    plusBottom();
    printf("\nPLUSBOTTOM RESULT\n");
    display();
    
    printf("\n************************************LAYER_FIRST*****************************************S\n");
    layerFirst();
    printf("\nLAYER FIRST RESULT\n");
    display();
    
    printf("\n*************************************LAYER_SECOND****************************************S\n");
    layerSecond();
    printf("\nLAYER SECOND RESULT\n");
    display();
    
    printf("\n********************************PLUS_TOP*********************************************S\n");
    plusTop();
    printf("\nPLUS TOP RESULT\n");
    display();
    
    printf("\n**********************************ALIGN_CENTER*******************************************S\n");
    alignCenter();
    printf("\nALIGN CENTER RESULT\n");
    display();
    
    printf("\n************************************CORNER_ALIGN*****************************************S\n");
    cornerAlign();
    printf("\nALIGN CORNER RESULT\n");
    display();


    printf("\n**********************************LAYERTHIRD*******************************************S\n");
    layerThird();
    printf("\nLAYER THIRD RESULT\n");
    display();

    freeSpace();

    return true;
}