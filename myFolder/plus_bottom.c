#include <stdio.h>
#include <string.h>
#include "solve_cube.h"

//checks whether the edge pieces in the UP layer contain color equal to downColor
boolean isColorUp(){
    int j=0;
    
    char* downColor = getDownMidColor();

    boolean isFrontEqualsDown = (strcmp(getFrontColor(0,j,1),downColor)==0)?true:false;    
    boolean isBackEqualsDown = (strcmp(getBackColor(2,j,1),downColor)==0)?true:false;    
    boolean isLeftEqualsDown = (strcmp(getLeftColor(1,j,0),downColor)==0)?true:false;    
    boolean isRightEqualsDown = (strcmp(getRightColor(1,j,2),downColor)==0)?true:false; 

    if(isFrontEqualsDown || isBackEqualsDown || isLeftEqualsDown || isRightEqualsDown)
        return true;
    else
        return false;
    

}
//checks whether the edge pieces in the MIDDLE layer contain color equal to downMidColor
boolean isColorMiddle(){
    int j=1;
    char* downColor=getDownMidColor();

    boolean isFrontLeftEqualsDown = ((strcmp(getFrontColor(0,j,0),downColor)==0)?true:false) || ((strcmp(getLeftColor(0,j,0),downColor)==0)?true:false);
    boolean isBackLeftEqualsDown = ((strcmp(getLeftColor(2,j,0),downColor)==0)?true:false) || ((strcmp(getBackColor(2,j,0),downColor)==0)?true:false);
    boolean isBackRightEqualsDown = ((strcmp(getBackColor(2,j,2),downColor)==0)?true:false) || ((strcmp(getRightColor(2,j,2),downColor)==0)?true:false);
    boolean isFrontRightEqualsDown = ((strcmp(getRightColor(0,j,2),downColor)==0)?true:false) || ((strcmp(getFrontColor(0,j,2),downColor)==0)?true:false);

    if(isFrontLeftEqualsDown || isBackLeftEqualsDown || isBackRightEqualsDown || isFrontRightEqualsDown)
        return true;
    else
        return false;
   
}

//checks whether the edge pieces in the DOWN layer contain color equal to the downMidColor
boolean isColorDown(){
    int j=2;
    char* downColor=getDownMidColor();

    boolean isFrontEqualsDown = ((strcmp(getFrontColor(0,j,1),downColor)==0)?true:false)|| ((strcmp(getDownColor(0,j,1),downColor)==0)?true:false);
    boolean isLeftEqualsDown = ((strcmp(getLeftColor(1,j,0),downColor)==0)?true:false)|| ((strcmp(getDownColor(1,j,0),downColor)==0)?true:false);
    boolean isBackEqualsDown = ((strcmp(getBackColor(2,j,1),downColor)==0)?true:false)|| ((strcmp(getDownColor(2,j,1),downColor)==0)?true:false);
    boolean isRightEqualsDown = ((strcmp(getRightColor(1,j,2),downColor)==0)?true:false)|| ((strcmp(getDownColor(1,j,2),downColor)==0)?true:false);

    if(isFrontEqualsDown || isLeftEqualsDown || isBackEqualsDown || isRightEqualsDown)
        return true;
    else
        return false;
    

}

//puts all the up layer edge pieces having downColor to the FRONT on the up layer 
void solveColorUp(char* downColor){
//if any color on the up layer edge piece equals downColor then loop continues

    while(isColorUp()){//while(isColorUp()
        //if up layer front edge color equals down color
        if(strcmp(getFrontColor(0,0,1),downColor)==0){//if
            rotateFront(true,true,++count,' ');
            /*performs rotation horizontally to the right for top layer
            until the Up color of (1,0,2) is not downColor*/
            while(strcmp(getUpColor(1,0,2),downColor)==0)
                upHorizontal(true,true,++count,' ');
                   
            rightVertical(true,true,++count,' ');

        }//if
        else if(isColorUp()){//else if
            upHorizontal(true,true,++count,' ');
        }//else if 
            
    }//while(isColorUp())
    
}


//puts all the middle layer edge pieces having downColor on the up layer
void solveColorMiddle(char* downColor){
    
//if any color in the middle layer edge piece equals downColor then loop continues    
    while(isColorMiddle()){
        //if middle layer FRONT of right edge color equals down color
        if(strcmp(getFrontColor(0,1,2),downColor)==0){//if
            //loop until the up right middle color is not equal to downColor
            while(strcmp(getUpColor(1,0,2),downColor)==0)
                upHorizontal(true,true,++count,' ');
                
                rightVertical(true,true,++count,' ');
        }//if
            
        //if middle layer RIGHT of right edge color equals bottom color
        else if(strcmp(getRightColor(0,1,2),downColor)==0){
            //loop until the up right middle color is not equal to downColor
            while(strcmp(getUpColor(0,0,1),downColor)==0)
                upHorizontal(true,true,++count,' ');
                
            rotateFront(false,true,++count,' ');
        }
        //if ther exits any edge color in the middle layer equals downColor
        else if(isColorMiddle()){
            middleHorizontal(true,true,++count,' ');
        }

    }//while(isColorMiddle()) 
    
}

//puts all the down layer edge pieces having downColor on the up layer
void solveColorDown(char* downColor){
    
//if any color in the down layer edge piece equals downColor then loop continues  
    while(isColorDown()){
        if(strcmp(getFrontColor(0,2,1),downColor)==0){
            while(strcmp(getUpColor(0,0,1),downColor)==0)
                upHorizontal(true,true,++count,' ');

            downHorizontal(false,true,++count,' ');
            middleVertical(false,true,++count,' ');
            downHorizontal(true,true,++count,' ');
            middleVertical(true,true,++count,' ');
        }
        else if(strcmp(getDownColor(0,2,1),downColor)==0){
            while(strcmp(getUpColor(0,0,1),downColor)==0)
                upHorizontal(true,true,++count,' ');
            
            rotateFront(true,true,++count,' ');
            rotateFront(true,true,++count,' ');
        }
        else if(isColorDown()){
            downHorizontal(true,true,++count,' ');
        }
    }//while(isColorDown)
    
               
}

//Performs rotation to completely shift required top edge pieces to the bottom
void finalStep1(char* downColor){
    
    for(int pos=0;pos<4;pos++){
        //performs UPHORIZONTAL until we get a piece that has to go down
        while(!(strcmp(getFrontColor(0,0,1),getFrontMidColor())==0 && strcmp(getUpColor(0,0,1),downColor)==0)){
            upHorizontal(true,true,++count,' ');
        }
        rotateFront(true,true,++count,' ');
        rotateFront(true,true,++count,' ');
        if(pos!=3)
        circleHorizontal(true,true,++count,' ');
    }
}


boolean plusBottom(){
    char* downColor=getDownMidColor();
        printf("________________________________________________\n\n");
        solveColorUp(downColor);
        printf("------------------------------------------------\n");
        
        solveColorMiddle(downColor);
        printf("------------------------------------------------\n");
        
        solveColorDown(downColor);
        printf("------------------------------------------------\n");
        
        finalStep1(downColor);
        printf("________________________________________________\n\n");

        circleVertical(false,true,++count,' ');
        circleVertical(false,true,++count,' ');
        
        printf("________________________________________________\n\n");

        return true;
}



