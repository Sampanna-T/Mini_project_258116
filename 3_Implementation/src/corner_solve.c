#include <stdio.h>
#include <string.h>
#include "solve_cube.h"
    
    boolean isFrontLeftCornerValid(){
        int i=0,j=0,k=0;
        char* frontColor = getFrontMidColor();
        char* upColor = getUpMidColor();
        char* leftColor = getLeftMidColor();
        boolean isValid=false;
        
        char colors[3][10];
        
        for(int index = 0; index < getSize(i,j,k); index++){
            strcpy(colors[index],getColor(i,j,k,index));
        }
        for(int index = 0; index < 3; index++){
            if(((strcmp(colors[index],(frontColor))==0)?true:false) || ((strcmp(colors[index],(leftColor))==0)?true:false) || ((strcmp(colors[index],(upColor))==0)?true:false)){
                isValid=true;
            }
            else{
                isValid=false;
                break;
            }
        }
        return isValid;   
    }
    
    boolean isBackLeftCornerValid(){
        int i=2,j=0,k=0;
        char* backColor = getBackMidColor();
        char* upColor = getUpMidColor();
        char* leftColor = getLeftMidColor();
        boolean isValid=false;
        
         
        char colors[3][10];
        
        for(int index = 0; index < getSize(i,j,k); index++){
            strcpy(colors[index],getColor(i,j,k,index));
        }
        
        for(int index = 0; index < 3; index++){
            if(((strcmp(colors[index],(backColor))==0)?true:false) || ((strcmp(colors[index],(leftColor))==0)?true:false) || ((strcmp(colors[index],(upColor))==0)?true:false)){
                isValid=true;
            }
            else{
                isValid=false;
                break;
            }
        }
        return isValid;   
    }
    
    boolean isBackRightCornerValid(){
        int i=2,j=0,k=2;
        char* backColor = getBackMidColor();
        char* upColor = getUpMidColor();
        char* rightColor = getRightMidColor();
        boolean isValid=false;
        
        char colors[3][10];
        
        for(int index = 0; index < getSize(i,j,k); index++){
            strcpy(colors[index],getColor(i,j,k,index));
        }

        for(int index = 0; index < 3; index++){
            if(((strcmp(colors[index],(backColor))==0)?true:false) || ((strcmp(colors[index],(rightColor))==0)?true:false) || ((strcmp(colors[index],(upColor))==0)?true:false)){
                isValid=true;
            }
            else{
                isValid=false;
                break;
            }
        }
        return isValid;   
    }
    
    boolean isFrontRightCornerValid(){
        int i=0,j=0,k=2;
        char* frontColor = getFrontMidColor();
        char* upColor = getUpMidColor();
        char* rightColor = getRightMidColor();
        boolean isValid=false;
        
        char colors[3][10];
        
        for(int index = 0; index < getSize(i,j,k); index++){
            strcpy(colors[index],getColor(i,j,k,index));
        }
        
        for(int index = 0; index < 3; index++){
            if(((strcmp(colors[index],(frontColor))==0)?true:false) || ((strcmp(colors[index],(rightColor))==0)?true:false) || ((strcmp(colors[index],(upColor))==0)?true:false)){
                isValid=true;
            }
            else{
                isValid=false;
                break;
            }
        }
        return isValid;   
    }
    
    boolean isAllCornerAligned(){
        if(isFrontLeftCornerValid() && isBackLeftCornerValid() && isBackRightCornerValid() && isFrontRightCornerValid() )
            return true;
        else
            return false;
    }
    
    boolean isAnyCornerAligned(){
      
        if(isFrontLeftCornerValid() || isBackLeftCornerValid() || isBackRightCornerValid() || isFrontRightCornerValid() )
            return true;
        else
            return false;
    }
    
    void solveCorner(){
        while(!(isAllCornerAligned())){

            if(isAnyCornerAligned()){
               while(!isFrontRightCornerValid()){
                    circleHorizontal(true,true,++count,' ');
               }
               while(!(isAllCornerAligned())){
                    corner(true,true,++count);
               }
            }
            else{
                corner(true,true,++count);
            }
        }

    }
    
    void cornerAlign(){
        
        printf("\nx--------x--------x--------x----------x-------x---------x----------x\n");
        solveCorner();
        printf("___________________________________________________________________\n");
    
    }