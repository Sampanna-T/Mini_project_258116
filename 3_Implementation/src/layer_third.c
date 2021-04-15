#include <stdio.h>
#include <string.h>
#include "solve_cube.h"
    
    void setCorner(){
        char* upColor=getUpMidColor();
        
        for(int value=1;value<=4;value++){
            while(!((strcmp(getUpColor(0,0,2),(upColor))==0)?true:false) )
                L(true,true,++count);
            upHorizontal(true,true,++count,' ');

        }
    }
    
    boolean layerThird(){
        
        printf("\nx--------x--------x--------x----------x-------x---------x----------x\n");
        setCorner();
        printf("__________________________________________________________________\n");
        
        return true;
    }