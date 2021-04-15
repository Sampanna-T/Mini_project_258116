#include <stdio.h>
#include <string.h>
#include "solve_cube.h"

boolean topFlag = false;
  //checks whether corner piece is valid or not
    boolean isCornerValid(int i, int j, int k){
        char* frontColor = getFrontMidColor();
        char* upColor = getUpMidColor();
        char* rightColor = getRightMidColor();
        boolean isValid=false;
        
        char colors[3][10];
        //
        for(int index = 0; index < getSize(i,j,k); index++){
            strcpy(colors[index],getColor(i,j,k,index));
        }
         
        
        for(int index = 0; index < 3; index++){
            if(((strcmp(colors[index],frontColor)==0)?true:false) || ((strcmp(colors[index],rightColor)==0)?true:false) || ((strcmp(colors[index],upColor)==0)?true:false)){
                isValid=true;
            }
            else{
                isValid=false;
                break;
            }
        }
        return isValid;
    }
    
    //checks whether the corner piece is in the right position or not
    boolean isCornerSet(){
        char* frontColor = getFrontMidColor();
        char* upColor = getUpMidColor();
        char* rightColor = getRightMidColor();
        
        if(((strcmp(getFrontColor(0,0,2),(frontColor))==0)?true:false) && ((strcmp(getUpColor(0,0,2),(upColor))==0)?true:false) && ((strcmp(getRightColor(0,0,2),(rightColor))==0)?true:false))
            return true;
        else 
            return false;
    }
    
    //Places the corner piece to be inserted on Top in positions 0,0,2 or 0,2,2
    void placeThePiece(){
    /*
    if topFlag=true implies corner piece is at 0,0,2
    else if topFlag=false implies corner piece is at 0,2,2
    */
        if(isCornerValid(0,0,2)||isCornerValid(0,2,2)){  
            if(isCornerValid(0,0,2)) 
                topFlag=true;//Only case where piece ends up at position 0,0,2
        }
        else if(isCornerValid(0,0,0)){//else if 
            leftVertical(false,true,++count,' ');
            downHorizontal(true,true,++count,' ');
            leftVertical(true,true,++count,' ');
        }
        else if(isCornerValid(0,2,0)){//else if
            downHorizontal(true,true,++count,' ');
        }//else if
        else if(isCornerValid(2,0,0)){//else if
            rotateBack(false,true,++count,' ');
            downHorizontal(true,true,++count,' ');
            downHorizontal(true,true,++count,' ');
            rotateBack(true,true,++count,' ');
        }//else if
        else if(isCornerValid(2,2,0)){//else if
            downHorizontal(true,true,++count,' ');
            downHorizontal(true,true,++count,' ');
        }//else if
        else if(isCornerValid(2,0,2)){//else if
            rotateBack(true,true,++count,' ');
            downHorizontal(false,true,++count,' ');
            rotateBack(false,true,++count,' ');
        }//else if
        else if(isCornerValid(2,2,2)){//else if
            downHorizontal(false,true,++count,' ');
        }//else if
    }

    //to set the corner piece At the proper location
    void finalStep2(char* upColor){
        for(int itr = 0; itr < 4; itr++){
            placeThePiece();
            if(!isCornerSet()){//if(!isCornerSet)
                if(topFlag){
                    if(((strcmp(getFrontColor(0,0,2),(upColor))==0)?true:false)){
                        rotateFront(true,true,++count,' ');
                        downHorizontal(true,true,++count,' ');
                        rotateFront(false,true,++count,' ');
                        downHorizontal(false,true,++count,' ');
                        downHorizontal(false,true,++count,' ');
                        rightVertical(false,true,++count,' ');
                        downHorizontal(true,true,++count,' ');
                        rightVertical(true,true,++count,' ');
                    }
                    else if(((strcmp(getRightColor(0,0,2),(upColor))==0)?true:false)){
                        L(true,true,++count);//firstuse
                        rightVertical(false,true,++count,' ');
                        downHorizontal(false,true,++count,' ');
                        rightVertical(true,true,++count,' ');
                    }
                }//if(topFlag)
                else{
                    if(((strcmp(getFrontColor(0,2,2),(upColor))==0)?true:false)){
                        downHorizontal(false,true,++count,' ');
                        rightVertical(false,true,++count,' ');
                        downHorizontal(true,true,++count,' ');
                        rightVertical(true,true,++count,' ');
                    }
                    else if(((strcmp(getRightColor(0,2,2),(upColor))==0)?true:false)){
                        rightVertical(false,true,++count,' ');
                        downHorizontal(false,true,++count,' ');
                        rightVertical(true,true,++count,' ');
                    }
                    else if(((strcmp(getDownColor(0,2,2),(upColor))==0)?true:false)){
                        rightVertical(false,true,++count,' ');
                        downHorizontal(false,true,++count,' ');
                        downHorizontal(false,true,++count,' ');
                        rightVertical(true,true,++count,' ');
                        downHorizontal(true,true,++count,' ');
                        rightVertical(false,true,++count,' ');
                        downHorizontal(false,true,++count,' ');
                        rightVertical(true,true,++count,' ');

                    }
                }//else
            }//if(!isCornerSet())
        topFlag = false;

        if(itr != 3)
            circleHorizontal(true,true,++count,' ');

        } //for
    }
    
    boolean layerFirst(){
        printf("\nx--------x--------x--------x----------x-------x---------x----------x\n");
        finalStep2(getUpMidColor());
        printf("________________________________________________\n\n");
        circleVertical(false,true,++count,' ');
        circleVertical(false,true,++count,' '); 
        printf("________________________________________________\n\n");
        return true;
    }