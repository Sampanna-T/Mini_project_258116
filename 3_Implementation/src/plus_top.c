#include <stdio.h>
#include <string.h>
#include "solve_cube.h"
    
       
    boolean isTopPlus(){
        int j=0;
        char* upColor = getUpMidColor();
        char* frontUpColor = getUpColor(0, j, 1);
        char* leftUpColor = getUpColor(1, j, 0);
        char* backUpColor = getUpColor(2, j, 1);
        char* rightUpColor = getUpColor(1, j, 2);
        
        if(((strcmp(frontUpColor,(upColor))==0)?true:false) && ((strcmp(leftUpColor,(upColor))==0)?true:false) && ((strcmp(backUpColor,(upColor))==0)?true:false) && ((strcmp(rightUpColor,(upColor))==0)?true:false))
            return true;
        else
            return false;
    }
    
    boolean isTopDot(){
        int j=0;
        char* upColor = getUpMidColor();
        char* frontUpColor = getUpColor(0, j, 1);
        char* leftUpColor = getUpColor(1, j, 0);
        char* backUpColor = getUpColor(2, j, 1);
        char* rightUpColor = getUpColor(1, j, 2);
        
        if(!((strcmp(frontUpColor,(upColor))==0)?true:false) && !((strcmp(leftUpColor,(upColor))==0)?true:false) && !((strcmp(backUpColor,(upColor))==0)?true:false) && !((strcmp(rightUpColor,(upColor))==0)?true:false))
            return true;
        else
            return false;
    }
    
    boolean isTopLORMinus(){
        int j=0;
        char* upColor = getUpMidColor();
        char* frontUpColor = getUpColor(0, j, 1);
        char* leftUpColor = getUpColor(1, j, 0);
        char* backUpColor = getUpColor(2, j, 1);
        char* rightUpColor = getUpColor(1, j, 2);
        
        if( (((strcmp(leftUpColor,(upColor))==0)?true:false) && ((strcmp(rightUpColor,(upColor))==0)?true:false)) || (((strcmp(leftUpColor,(upColor))==0)?true:false) && ((strcmp(backUpColor,(upColor))==0)?true:false))  )
            return true;
        else 
            return false;
    }
    
    void solvePlus(){
        
        while(!isTopPlus()){//while
            if(isTopDot()){
               twistFront(true,true,++count);
            }
            else{
                while(true){
                    if(isTopLORMinus() || isTopDot())
                        break;
                    else
                        upHorizontal(true,true,++count,' ');
                }
                twistFront(true,true,++count);
            }
        }//while
    }
    
    void plusTop(){
        
        printf("\nx--------x--------x--------x----------x-------x---------x----------x\n");
        solvePlus();
        printf("____________________________________________________________________\n");

    }
    