/**
 * @file rubiks_cube.h
 * 
 * @author Sampanna T (kashi16sadan@gmail.com)
 * 
 * @brief 
 * 1) Responsible for the creation of rubik's cube by taking user input.
 * 2) Checking if the input provided by the user is valid or not.
 * 3) Also performs all the operations that a rubik's cube can do like,
 *    (a) horizontal
 *    (b) vertical
 *    (c) rotational
 *
 * @date 2021-04-12
 * 
 */
#ifndef RUBIKS_CUBE_H
#define RUBIKS_CUBE_H

#include <stdio.h>
#include <stdlib.h>

#define DIMENSION 3
#define FRONT "FRONT"
#define MIDDLE "MIDDLE"
#define BACK "BACK"
#define UP "UP"
#define DOWN "DOWN"
#define RIGHT "RIGHT"
#define LEFT "LEFT"

#define ROTATE "ROTATE"
#define VERTICAL "VERTICAL"
#define HORIZONTAL "HORIZONTAL"

/**
 * @brief 
 * to use boolean values(i.e false=0, true=1 as compiler automatically sets it).
 */
typedef enum{
false,
true
}boolean;

/**
 * @brief 
 * 1)Node represents the smallest unit in the rubik's cube which might have 
 *   3 colors or 2 colors or 1 color or none.
 * 2)size field gives how many colors can the Node hold.
 * 3)color array has 3 char*s (literally char pointers) which holds the colors
 *   for the given Node.
 * 4)position array has 3 char*s (literally char pointers) which holds the
 *   positions(ex:UP,LEFT) for the given Node.
 */
typedef struct{
int size;
char *(color[3]);
}Node;

/**
 * @brief 
 *  move variable represents what action(ex:up_horizontal) is performed on 
 *  rubik's cube at present.
 */
char move[30];
 

/**
 * @brief 
 * piece variable holds all the 27 Nodes in the form of 3-D array.
 */
Node piece[DIMENSION][DIMENSION][DIMENSION];


/**
 * @brief 
 * returns the no of colors available in a given Node
 */
int getSize(int i, int j, int k);

/**
 * @brief 
 * returns the position for a given index of a given Node
 */
char* getPosition(int i, int j, int k, int index);

/**
 * @brief
 *   returns a String(char *) that specifies the location of Node i,j,k
 *   in 3-D array
 */
char* getLocation(int i, int j, int k);

/**
 * @brief
 * returns the color at a particular index(0 or 1 or 2) in a given Node
 */
char* getColor(int i, int j, int k, int index);

/**
 * @brief Get the index object
 * returns index for a given position
 */
int get_index(int i, int j, int k, char* position);

/**
 * @brief
 * returns the color at a particular position(ex: RIGHT,UP etc.) in a given Node
 */
char* getColorAt(int i, int j, int k, char* position);

/**
 * @brief 
 * returns the color at the center of the front layer 
 */
char* getFrontMidColor();

/**
 * @brief 
 * returns the color at the center of the back layer 
 */
char* getBackMidColor();

/**
 * @brief 
 * returns the color at the center of the upper layer 
 */
char* getUpMidColor();

/**
 * @brief 
 * returns the color at the center of the bottom layer 
 */
char* getDownMidColor();

/**
 * @brief 
 * returns the color at the center of the left layer 
 */
char* getLeftMidColor();

/**
 * @brief 
 * returns the color at the center of the right layer 
 */
char* getRightMidColor();

/**
 * @brief 
 * returns the front color for a given Node 
 */
char* getFrontColor(int i, int j, int k);

/**
 * @brief 
 * returns the back color for a given Node
 */
char* getBackColor(int i, int j, int k);

/**
 * @brief 
 * returns the color at the top for a given Node
 */
char* getUpColor(int i, int j, int k);

/**
 * @brief 
 * returns the color at the bottom for a given Node
 */
char* getDownColor(int i, int j, int k);

/**
 * @brief 
 * returns the left color for a given Node
 */
char* getLeftColor(int i, int j, int k);

/**
 * @brief 
 * returns the right color for a given Node
 */
char* getRightColor(int i, int j, int k);

/**
 * @brief 
 * sets @param color at a particular index specified by @param index
 */
void setColor(int i, int j, int k, int index, char* color);

/**
 * @brief 
 * sets @param color at a particular position specified by @param position
 */
void setColorAt(int i, int j, int k, char* position, char* color);

/**
 * @brief 
 *  initializes the rubik's cube by setting the colors for the respective
 *  Node based on user input.
 */

//

/**
 * @brief performs rotate operation of the front layer
 * @param direction
 * (a)if direction=true rotation takes place in clockwise direction
 * (b)if direction=false rotation takes place in anti-clockwise direction
 */
boolean rotateFront(boolean direction, boolean print, int count, int subcount);

/**
 * @brief performs rotate operation of the middle layer
 */
boolean rotateMiddle(boolean direction, boolean print, int count, int subcount);

/**
 * @brief performs rotate operation of the back layer
 */
boolean rotateBack(boolean direction, boolean print, int count, int subcount);

/**
 * @brief performs horizontal operation on upper layer
 * @param direction 
 * (a)if direction=true, horizontal operation takes place in the right direction
 * (b)if direction=false, horizontal operation takes place in the left direction
 */
boolean upHorizontal(boolean direction, boolean print, int count, int subcount);

/**
 * @brief performs horizontal operation on middle layer
 */
boolean middleHorizontal(boolean direction, boolean print, int count, int subcount);

/**
 * @brief performs horizontal operation on bottom layer
 */
boolean downHorizontal(boolean direction, boolean print, int count, int subcount);

/**
 * @brief performs vertical operation on left layer
 * @param direction 
 * (a)if direction=true, vertical operation takes place in the upward direction
 * (b)if direction=false, vertical operation takes place in the downward direction
 */
boolean leftVertical(boolean direction, boolean print, int count, int subcount);

/**
 * @brief performs vertical operation on middle layer
 */
boolean middleVertical(boolean direction, boolean print, int count, int subcount);

/**
 * @brief performs vertical operation on right layer
 */
boolean rightVertical(boolean direction, boolean print, int count, int subcount);

/**
 * @brief performs horizontal movement on the entire body of rubik's cube
 * @param direction 
 * (a)if direction=true, vertical operation takes place in the right direction
 * (b)if direction=false, vertical operation takes place in the left direction
 */
boolean circleHorizontal(boolean direction, boolean print, int count, int subcount);

/**
 * @brief performs vertical movement on the entire body of rubik's cube
 * @param direction 
 * (a)if direction=true, vertical operation takes place in the downward direction
 * (b)if direction=false, vertical operation takes place in the upward direction
 */
boolean circleVertical(boolean direction, boolean print, int count, int subcount);

//

void setRubixCube();

/**
 * @brief
 *   initializes the rubik's cube by taking String (i.e. char *) values 
 *   separated by space.(i.e. all the colors received via input initializes
 *   the rubik's cube)
 * @param input 
 *   space separated colors are given as input.
 */
void setRubixCubeAtOnce(char input[600]);

/**
 * @brief 
 *   returns true if the colors can be displayed and displays the colors
 *   returns false if the colors can't be displayed and doesn't display the colors
 * @return boolean 
 */
void display();

/**
 * @brief 
 *   deallocating memory to avoid memory leaks
 */
void freeSpace();

#endif