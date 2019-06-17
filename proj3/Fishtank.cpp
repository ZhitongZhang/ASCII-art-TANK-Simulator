//fishtank.cpp
//Zhitong Zhang
//4/11/19
//driver for the Fishtank class. 

#include <iostream>
#include "fishtank.h"
using namespace std; 



//Constructer w/ no parameter.
//sets width and height = 0 and initializes the tank.
FishTank::FishTank(){
    set_width(0);
    set_height(0);
    for (int i = 0; i < MAX_HGT; i++){
        for (int j = 0; j < MAX_WID; j++){
            screen[i][j] = ' ';
        }
    }
}
//Constructor w/ height and width parameter (int)
//sets width and height accordingly and initalizes the tank.
FishTank::FishTank(int hgt, int wid){
    set_width(wid);
    set_height(hgt);
    for (int i = 0; i < MAX_HGT; i++){
        for (int j = 0; j < MAX_WID; j++){
            screen[i][j] = ' ';
        }
    }
}
//parameter: int hgt
//return: true or false
//purpose: sets the height, and if the set height is inbound, return true, 
//else returns false.
bool FishTank::set_height(int hgt){
    if ((hgt >= 0) and (hgt < MAX_HGT)){
        height = hgt;
        return true;
    }
    return false;
}
//parameter: int wid
//return: true or false
//purpose: sets the width, and if the set width is inbound, return true, 
//else returns false.
bool FishTank::set_width(int wid){
    if ((wid >= 0) and (wid < MAX_WID)){
        width = wid;
        return true;
    }
    return false;
}
//parameter: none
//return: integer value
//purpose: returns the height data member.
int FishTank::get_height(){
    return height;
}
//parameter: none
//return: intger value
//purpose: returns the width data member.
int FishTank::get_width(){
    return width;
}
//parameter: none
//return:: none
//purpose:  clears the tank (sets the entire "screen" to ' ' empty character)
void FishTank::clear_tank(){
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            screen[i][j] = ' ';
        }
    }
}
//parameter: an int row, col; and char c
//return: none
//purpose: replaces the character corresponding to the row and col with c.
void FishTank::update_at(int row, int col, char c){
    screen[row][col] = c;
}
//parameter: none
//output: none
//purpose: prints the screen
void FishTank::show_tank(){
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            cout << screen[i][j];
        }
        cout << endl;
    }
}