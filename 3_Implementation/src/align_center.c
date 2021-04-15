#include <stdio.h>
#include <string.h>
#include "solve_cube.h"
    
    boolean isCenterAligned(){
        int j=0;
        char* frontColor=getFrontMidColor();
        char* leftColor=getLeftMidColor();
        char* backColor=getBackMidColor();
        char* rightColor=getRightMidColor();
        
        char* frontFUMColor=getFrontColor(0, j, 1);
        char* leftMULColor=getLeftColor(1, j, 0);
        char* backBUMColor=getBackColor(2, j, 1);
        char* rightMURColor=getRightColor(1, j, 2);
        
        if(((strcmp(frontFUMColor,(frontColor))==0)?true:false)  && ((strcmp(leftMULColor,(leftColor))==0)?true:false) && ((strcmp(backBUMColor,(backColor))==0)?true:false) && ((strcmp(rightMURColor,(rightColor))==0)?true:false))
            return true;
        else
            return false;  
    }
    
    boolean isAdjacentColorsEqual(){
        int j=0;
        char* frontColor=getFrontMidColor();
        char* leftColor=getLeftMidColor();
        char* backColor=getBackMidColor();
        char* rightColor=getRightMidColor();
        
        char* frontFUMColor=getFrontColor(0, j, 1);
        char* leftMULColor=getLeftColor(1, j, 0);
        char* backBUMColor=getBackColor(2, j, 1);
        char* rightMURColor=getRightColor(1, j, 2);
        
        boolean adj1 = ((strcmp(frontFUMColor,(frontColor))==0)?true:false) && ((strcmp(leftMULColor,(leftColor))==0)?true:false);
        boolean adj2 = ((strcmp(leftMULColor,(leftColor))==0)?true:false) && ((strcmp(backBUMColor,(backColor))==0)?true:false);
        boolean adj3 = ((strcmp(backBUMColor,(backColor))==0)?true:false) && ((strcmp(rightMURColor,(rightColor))==0)?true:false);
        boolean adj4 = ((strcmp(rightMURColor,(rightColor))==0)?true:false) && ((strcmp(frontFUMColor,(frontColor))==0)?true:false);
        
        if(adj1 || adj2 || adj3 || adj4)
            return true;
        else
            return false;
    }
    
    boolean isOppositeColorsEqual(){
        int j=0;
        char* frontColor=getFrontMidColor();
        char* leftColor=getLeftMidColor();
        char* backColor=getBackMidColor();
        char* rightColor=getRightMidColor();
        
        char* frontFUMColor=getFrontColor(0, j, 1);
        char* leftMULColor=getLeftColor(1, j, 0);
        char* backBUMColor=getBackColor(2, j, 1);
        char* rightMURColor=getRightColor(1, j, 2);
        
        boolean opp1 = ((strcmp(frontFUMColor,(frontColor))==0)?true:false) && ((strcmp(backBUMColor,(backColor))==0)?true:false);
        boolean opp2 = ((strcmp(leftMULColor,(leftColor))==0)?true:false) && ((strcmp(rightMURColor,(rightColor))==0)?true:false);
        
        if(opp1 || opp2)
            return true;
        else
            return false;
    }
    
    void align(){
        char* upColor=getUpMidColor();
        char* backColor=getBackMidColor();
        char* rightColor=getRightMidColor();
        
        //loops until UP layer center gets aligned
        while(!isCenterAligned()){//whileMain
            if(isOppositeColorsEqual()){
                while(!((strcmp(getUpColor(0,0,1),(upColor))==0)?true:false))
                    circleHorizontal(true,true,++count,' ');
                upTwist(true,true,++count);
                upHorizontal(true,true,++count,' ');
                upTwist(true,true,++count);
                while(!isCenterAligned())
                    upHorizontal(false,true,++count,' ');
            }
            else if(isAdjacentColorsEqual()){
		
                while(!(((strcmp(getBackColor(2,0,1),(backColor))==0)?true:false) && ((strcmp(getRightColor(1,0,2),(rightColor))==0)?true:false)))
                    circleHorizontal(true,true,++count,' ');
            
                upTwist(true,true,++count);
                while(!isCenterAligned())
                    upHorizontal(false,true,++count,' ');
            }
            else {//if(!isCenterAligned()){//else if(!isCenterAligned)
                int value=0;
                while(!(isAdjacentColorsEqual() || isOppositeColorsEqual())){//while
			
                    if(value==4)
                        upTwist(true,true,++count);
                    
                    upHorizontal(false,true,++count,' ');
                    value++;
                }//while
            }//else if(!isCenterAligned())
        }//whileMain
    }
    
    boolean alignCenter(){
        
        printf("\nx--------x--------x--------x----------x-------x---------x----------x\n");
        align();
        printf("____________________________________________________________________\n");
        return true;
    }