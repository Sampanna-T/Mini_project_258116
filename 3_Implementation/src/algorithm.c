#include <stdio.h>
#include <string.h>
#include "algorithm.h"

boolean L(boolean direction, boolean print, int count){
    if(direction){
        rightVertical(false,print,count,'a');
        downHorizontal(false,print,count,'b');
        rightVertical(true,print,count,'c');
        downHorizontal(true,print,count,'d');
    }
    else{    
        leftVertical(false,print,count,'a');
        downHorizontal(true,print,count,'b');
        leftVertical(true,print,count,'c');
        downHorizontal(false,print,count,'d');
    }
    return true;
}

boolean layer2(boolean direction, boolean print, int count){

    if(direction){
        upHorizontal(false,print,count,'a');
        rightVertical(true,print,count,'b');
        upHorizontal(true,print,count,'c');
        rightVertical(false,print,count,'d');
        upHorizontal(true,print,count,'e');
        rotateFront(false,print,count,'f');
        upHorizontal(false,print,count,'g');
        rotateFront(true,print,count,'h');
    }
    else{
        upHorizontal(true,print,count,'a');
        leftVertical(true,print,count,'b');
        upHorizontal(false,print,count,'c');
        leftVertical(false,print,count,'d');
        upHorizontal(false,print,count,'e');
        rotateFront(true,print,count,'f');
        upHorizontal(true,print,count,'g');
        rotateFront(false,print,count,'h');
    }
    return true;
}

boolean twistFront(boolean direction, boolean print, int count){

    if(direction){
        rotateFront(true,print,count,'a');
        rightVertical(true,print,count,'b');
        upHorizontal(false,print,count,'c');
        rightVertical(false,print,count,'d');
        upHorizontal(true,print,count,'e');
        rotateFront(false,print,count,'f');
    }
    else{
        rotateFront(false,print,count,'a');
        leftVertical(true,print,count,'b');
        upHorizontal(true,print,count,'c');
        leftVertical(false,print,count,'d');
        upHorizontal(false,print,count,'e');
        rotateFront(true,print,count,'f');
    }

    return true;
}

boolean upTwist(boolean direction, boolean print, int count){
    
    if(direction){
        rightVertical(true,print,count,'a');
        upHorizontal(false,print,count,'b');
        rightVertical(false,print,count,'c');
        upHorizontal(false,print,count,'d');
        rightVertical(true,print,count,'e');
        upHorizontal(false,print,count,'f');
        upHorizontal(false,print,count,'g');
        rightVertical(false,print,count,'h');
    }
    else{
        leftVertical(true,print,count,'a');
        upHorizontal(true,print,count,'b');
        leftVertical(false,print,count,'c');
        upHorizontal(true,print,count,'d');
        leftVertical(true,print,count,'e');
        upHorizontal(true,print,count,'f');
        upHorizontal(true,print,count,'g');
        leftVertical(false,print,count,'h');
    }
    
    return true;
}

boolean corner(boolean direction, boolean print, int count){

    if(direction){
        upHorizontal(false,print,count,'a');
        rightVertical(true,print,count,'b');
        upHorizontal(true,print,count,'c');
        leftVertical(true,print,count,'d');
        upHorizontal(false,print,count,'e');
        rightVertical(false,print,count,'f');
        upHorizontal(true,print,count,'g');
        leftVertical(false,print,count,'h');
    }
    else{
        upHorizontal(true,print,count,'a');
        leftVertical(true,print,count,'b');
        upHorizontal(false,print,count,'c');
        rightVertical(true,print,count,'d');
        upHorizontal(true,print,count,'e');
        leftVertical(false,print,count,'f');
        upHorizontal(false,print,count,'g');
        rightVertical(false,print,count,'h');
    }
    return true;
}
