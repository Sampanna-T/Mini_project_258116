#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rubiks_cube.h"

void setRubixCube(){//void setRubixCube()
printf("********************************************************************************************\n");
printf("Enter the colours of rubix cube one at a time when asked\n");
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
 printf("********************************************************************************************\n\n");

}//void setRubixCube()

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

void display2(){//void display()

    for(int i = 0; i < DIMENSION; i++){
        for(int j = 0; j < DIMENSION; j++){
            for(int k = 0; k < DIMENSION; k++){
                int count=getSize(i,j,k);

                for(int index = 0;index < count; index++){//for index
                   /* printf("(%s)",getPosition(i,j,k,index));
                    printf("%d)%s",get_index(i,j,k,getPosition(i,j,k,index)),getColorAt(i,j,k,getPosition(i,j,k,index)));*/
                   printf("%s ",getColor(i,j,k,index));

                }//for index
            }//for k
        }//for j
    }//for i
    
}//void display()


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

