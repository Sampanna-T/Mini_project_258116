#include <string.h>
#include <stdlib.h>
#include "rubiks_cube.h"

int getSize(int i, int j, int k){
    int count=0;
            switch(i){
                case 0:count++;break;
                case 1:break;
                case 2:count++;break;
            }
            switch(j){
                case 0:count++;break;
                case 1:break;
                case 2:count++;break;
            }
            switch(k){
                case 0:count++;break;
                case 1:break;
                case 2:count++;break;
            }
    return count;
}

char* getPosition(int i, int j, int k, int index){
    static char str[25];
    strcpy(str,"");
    
    if(i==1)return getPosition(0,j,k,index+1);

switch(i){
    case 0:strcat(str,FRONT);break;
    case 1:strcat(str,MIDDLE);break;
    case 2:strcat(str,BACK);break;
    }

    if(index==0 && strcmp(str,MIDDLE)!=0){return str;}
    else if(index==0 && strcmp(str,MIDDLE)==0)index++;
    strcpy(str,"");

switch(j){
    case 0:strcat(str,UP);break;
    case 1:strcat(str,MIDDLE);break;
    case 2:strcat(str,DOWN);break;
    }
    if(index==1 && strcmp(str,MIDDLE)!=0)return str;
    else if(index==1 && strcmp(str,MIDDLE)==0)index++;
    strcpy(str,"");

switch(k){
    case 0:strcat(str,LEFT);break;
    case 1:strcat(str,MIDDLE);break;
    case 2:strcat(str,RIGHT);break;
    }

    if(index==2 && strcmp(str,MIDDLE)!=0)return str;
    else if(index==2 && strcmp(str,MIDDLE)==0)index++;
    strcpy(str,"");

    return str;
}

char* getLocation(int i, int j, int k){
    static char str[25];
    strcpy(str,"");

    switch(i){
        case 0:strcat(str,FRONT);break;
        case 1:strcat(str,MIDDLE);break;
        case 2:strcat(str,BACK);break;
    }

                strcat(str,"_");

    switch(j){
        case 0:strcat(str,UP);break;
        case 1:strcat(str,MIDDLE);break;
        case 2:strcat(str,DOWN);break;
    }

    strcat(str,"_");

    switch(k){
        case 0:strcat(str,LEFT);break;
        case 1:strcat(str,MIDDLE);break;
        case 2:strcat(str,RIGHT);break;
    }

}

char* getColor(int i, int j, int k, int index){
return piece[i][j][k].color[index];
}

int get_index(int i, int j, int k, char* position){
    if(strcmp(position,LEFT)==0 || strcmp(position,RIGHT)==0){
        return (getSize(i,j,k)-1);
    }
    else if(strcmp(position,UP)==0 || strcmp(position,DOWN)==0){
        if(i==1)return 0;
        else if(i==0 || i==2)return 1;
    }
    else if(strcmp(position,FRONT)==0 || strcmp(position,BACK)==0){
        if(i==0 || i==2){
            return 0;
        }
    }
    return -1;
}

char* getColorAt(int i, int j, int k, char* position){
return getColor(i,j,k,get_index(i,j,k,position));
}

char* getFrontMidColor(){
    return getColorAt(0,1,1,FRONT);
}

char* getBackMidColor(){
    return getColorAt(2,1,1,BACK);
}

char* getUpMidColor(){
    return getColorAt(1,0,1,UP);
}

char* getDownMidColor(){
    return getColorAt(1,2,1,DOWN);
}

char* getLeftMidColor(){
    return getColorAt(1,1,0,LEFT);
}

char* getRightMidColor(){
    return getColorAt(1,1,2,RIGHT);
}

char* getFrontColor(int i, int j, int k){
    return getColorAt(i,j,k,FRONT);
}

char* getBackColor(int i, int j, int k){
    return getColorAt(i,j,k,BACK);
}

char* getUpColor(int i, int j, int k){
    return getColorAt(i,j,k,UP);
}

char* getDownColor(int i, int j, int k){
    return getColorAt(i,j,k,DOWN);
}

char* getLeftColor(int i, int j, int k){
    return getColorAt(i,j,k,LEFT);
}

char* getRightColor(int i, int j, int k){
    return getColorAt(i,j,k,RIGHT);
}


void setColor(int i, int j, int k, int index, char* color){
    strcpy(piece[i][j][k].color[index],color);
}

void setColorAt(int i, int j, int k, char* position, char* color){
    strcpy(piece[i][j][k].color[get_index(i,j,k,position)],color);
}



