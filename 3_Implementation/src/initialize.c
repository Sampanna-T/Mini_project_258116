#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rubiks_cube.h"

/**
 * @brief cheacks whether all the Nodes entered by the user is valid or not
 * 
 * @return boolean 
 */
boolean isNodeValid(){
    for(int i = 0; i < DIMENSION; i++){
        for(int j = 0; j < DIMENSION; j++){
            for(int k = 0; k < DIMENSION; k++){
                int count=getSize(i,j,k);
                char colors[3][10];
        
                for(int index = 0; index < count; index++)
                   strcpy(colors[index],getColor(i,j,k,index));
            

                if(count==0 || count==1){
                    continue;
                }
                else if(count==2){
                    if(!((strcmp(colors[0],colors[1])==0)?true:false))
                        continue;
                    else
                        return false;
                }
                else if(count==3){
                    if( !((strcmp(colors[0],colors[1])==0)?true:false) && !((strcmp(colors[1],colors[2])==0)?true:false) && !((strcmp(colors[2],colors[0])==0)?true:false))
                        continue;  
                    else
                        return false;
                }
                
            }//for k
        }//for j
    }//for i
    return true;
}

//checks if the entered colors of rubiks cube have 6 colors where 9 are of same suit
boolean isRubiksCubeValid(){

    char* f = getFrontMidColor();
    char* l = getLeftMidColor();
    char* b= getBackMidColor();
    char* r = getRightMidColor();
    char* u = getUpMidColor();
    char* d = getDownMidColor();
    
    //returns false if any of the mid colors are equal
    if( ((strcmp(f,l)==0)?true:false) || ((strcmp(f,b)==0)?true:false)  || ((strcmp(f,r)==0)?true:false) || ((strcmp(f,u)==0)?true:false) || ((strcmp(f,d)==0)?true:false))
    return false;
    else if(((strcmp(l,b)==0)?true:false)  || ((strcmp(l,r)==0)?true:false) || ((strcmp(l,u)==0)?true:false) || ((strcmp(l,d)==0)?true:false))
    return false;
    else if(((strcmp(b,r)==0)?true:false) || ((strcmp(b,u)==0)?true:false) || ((strcmp(b,d)==0)?true:false))
    return false;
    else if(((strcmp(r,u)==0)?true:false) || ((strcmp(r,d)==0)?true:false))
    return false;
    else if(((strcmp(u,d)==0)?true:false))
    return false;
    
    printf("REACHED");
   
    //increments the respective index if the color received is similar to the one mentioned above
    int check[6]={0,0,0,0,0,0};

    for(int i = 0; i < DIMENSION; i++){
        for(int j = 0; j < DIMENSION; j++){
            for(int k = 0; k < DIMENSION; k++){
                int count=getSize(i,j,k);
                for(int index = 0; index < count; index++){
                   if(strcmp(f,getColor(i,j,k,index))==0)check[0]++;
                   else if(strcmp(l,getColor(i,j,k,index))==0)check[1]++;
                   else if(strcmp(b,getColor(i,j,k,index))==0)check[2]++;
                   else if(strcmp(r,getColor(i,j,k,index))==0)check[3]++;
                   else if(strcmp(u,getColor(i,j,k,index))==0)check[4]++;
                   else if(strcmp(d,getColor(i,j,k,index))==0)check[5]++;
            
                } 
            }//for k
        }//for j
    }//for i

    for(int i = 0; i < 6; i++){
       // printf("\nvalue[%d]=%d\n",i,check[i]);
        if(check[i]!=9)return false;
    }
    return true;

}

void setRubixCube(){//void setRubixCube()
printf("********************************************************************************************\n");
printf("Enter the colours of rubix cube one at a time when asked(MAX CHARACTERS=9)\n");
    for(int i = 0; i < DIMENSION; i++){
        for(int j = 0; j < DIMENSION; j++){
            for(int k = 0; k < DIMENSION; k++){
                int count=getSize(i,j,k);
                
                printf("set the colours of Node at ");
                printf("%s\n",getLocation(i,j,k));

                Node newNode;
                newNode.size = count;

                for(int index = 0;index < count; index++){
                    printf("enter %s color : ",getPosition(i,j,k,index));
                    newNode.color[index] = (char *)malloc(10*sizeof(char));
                    scanf("%s",newNode.color[index]);
                }
                piece[i][j][k]=newNode;      
            }//for k
        }//for j
    }//for i

    if(isNodeValid && isRubiksCubeValid){
        printf("\nALL COLORS ENTERED ARE VALID\n");
    }
    else{
        printf("\nALL NODES ENTERED ARE NOT VALID\n");
        printf("Enter colors again");
        setRubixCube();
    }

 printf("********************************************************************************************\n\n");

}//void setRubixCube()

//for the purpose of testing this function is used so that space separated inputs can be given at once
void setRubixCubeAtOnce(char input[600]){//void setRubixCubeAtOnce(char *input)
  
char input_temp[600];
strcpy(input_temp,input);
    char* token = strtok(input_temp," ");
  
    for(int i = 0; i < DIMENSION; i++){
        for(int j = 0; j < DIMENSION; j++){
            for(int k = 0; k < DIMENSION; k++){
                int count=getSize(i,j,k);
                Node newNode;
                newNode.size = count;

                for(int index = 0;index < count; index++){
                    newNode.color[index] = (char *)malloc(10*sizeof(char));
                    strcpy(newNode.color[index],token);
                    token = strtok(NULL," ");
                }
                piece[i][j][k]=newNode;      
            }//for k
        }//for j
    }//for i
}//void setRubixCubeAtOnce(char *input)

//displays the colors in the rubix cube along with the position
void display(){//void display()
    printf("********************************************************************************************\n");
    for(int i = 0; i < DIMENSION; i++){
        for(int j = 0; j < DIMENSION; j++){
            for(int k = 0; k < DIMENSION; k++){
                int count=getSize(i,j,k);

                for(int index = 0;index < count; index++){//for index
                    printf("(%s)",getPosition(i,j,k,index));
                    printf("%s",piece[i][j][k].color[index]);

                }//for index
                printf("\t");
            }//for k
                printf("\n");
        }//for j
        printf("____________________________________________________________________________________\n");
    }//for i
    
    printf("********************************************************************************************");
}//void display()

//function used for testing as it gives only space separated colors as output
void displayTest(){//void display()

    for(int i = 0; i < DIMENSION; i++){
        for(int j = 0; j < DIMENSION; j++){
            for(int k = 0; k < DIMENSION; k++){
                int count=getSize(i,j,k);

                for(int index = 0;index < count; index++){//for index
                    printf("%s ",getColor(i,j,k,index));
                }//for index
            }//for k
        }//for j
    }//for i
    
}//void display()

//freeing the space to avoid memory leak
void freeSpace(){//void freeSpace()
        for(int i = 0; i < DIMENSION; i++){
        for(int j = 0; j < DIMENSION; j++){
            for(int k = 0; k < DIMENSION; k++){
                int count=getSize(i,j,k);

                for(int index = 0;index < count; index++){//for index
                    free(piece[i][j][k].color[index]);
                }//for index
            }//for k
        }//for j
    }//for i
}//void freeSpace()

