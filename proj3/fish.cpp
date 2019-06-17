//fish.cpp
//Zhitong Zhang
//4/11/19
//driver for the Fish class.

#include <iostream>
#include <string>
#include "fish.h"
#include "fishtank.h"

using namespace std; 
// This is the default constructor the for Fish class. 
Fish::Fish(){
    for (int i = 0; i < MAX_HGT; i++){
        for (int j = 0; j < MAX_WID; j++){
            fish_pic[i][j] = ' ';
        }
    }
    set_name("");
    height = 0;
    width= 0;
    ver_spe = 0;
    hor_spe = 0;
    lifetime_i = -1;
}
//parameter: the istream input
//return: trur or false
//purpose: intialize the data member of each fish from a file,
//return true if successful, else return false.
bool Fish::read_fish(istream &input){
    string CheckFish;
    string curr_layer_fish;
    input >> CheckFish;
    //cout << CheckFish << endl;
    if (CheckFish == "fish"){
        input >> height >> width >> start_row >> start_col >> ver_spe 
              >> hor_spe >> lifetime_i >> fish_name;
        getline(input, CheckFish); //Just to skip a line
        for (int i = 0; i < height; i++){
            getline(input, curr_layer_fish); //Go to the next row
            for (int j = 0; j < width; j++){
                fish_pic[(int) (i)][(int) (j)] = curr_layer_fish.at(j);
                if (j  == curr_layer_fish.length() - 1) //sign compare warning
                    break;                              // can be ignored here
            }
        }
        return true;
    }
    return false;
}
//parameter: none
//return: the string fish_name
//purpose: return the name of the fish.
string Fish::get_name(){
    return fish_name;
}
//parameter: string name
//return: none
//purpose: set the fish_name data member to the input.
void Fish::set_name(string name){
    fish_name = name;
}
//parameter: int row, int col
//return: none
//purpose: set the start_row and start_col data member
// to the inputs. 
void Fish::set_pos(int row, int col){
    start_row = row;
    start_col = col;
}
//parameter: none
//return: height integer
//purpose: simply returns the height data member
int Fish::get_height(){
    return height;
}
//parameter: none
//return: width integer
//purpose: simply returns the width data member
int Fish::get_width(){
    return width;
}
//parameter: none
//return: limetime_i integer
//purpose: simply returns the lifetime_i data member
int Fish::lifetime(){
    return lifetime_i;
}
//parameter: tank_hgt integer, tank_wid integer
//return: none
//purpose: moves the fish by adding start pos w/ speed,
// subtracts 1 on lifetime_i on move (unless immortal or dead),
// if start position is greater than tank boundary, will wrap around on 
//opposite side.
void Fish::move(int tank_hgt, int tank_wid){
    start_row = start_row + ver_spe;
    start_col = start_col + hor_spe;
    if ((lifetime_i != -1) and (lifetime_i != 0))
        lifetime_i--;
    if (start_col > tank_wid){
        start_col = start_col - tank_wid;
        //if ((lifetime_i != -1) and (lifetime_i != 0))
        //  lifetime_i--;
    }
    else if (start_col < 0){
        start_col = tank_wid + start_col;
    //  if ((lifetime_i != -1) and (lifetime_i != 0))
    //      lifetime_i--;
    }
    if (start_row > tank_hgt){
        start_row = start_row - tank_hgt;
    //  if ((lifetime_i != -1) and (lifetime_i != 0))
    //      lifetime_i--;
    }
    else if (start_row < 0){
        start_row = tank_hgt + start_row;
    //  if ((lifetime_i != -1) and (lifetime_i != 0))
    //      lifetime_i--;
    }
}
//parameter: FishTank tank pointer 
//return: none
//purpose: prints the fish onto the tank, will wrap around on opposite side
//if fish character is outside tank boundary.
void Fish::draw(FishTank *tank){
    if (lifetime_i == 0)
        return;
    if (ver_spe  == 0){
        for (int j = 0; j < width; j++){ 
            for (int i = 0; i < height ; i++){
                if (fish_pic[i][j] != ' '){ //transparency.
                    if (i + start_row > tank->get_height())
                        start_row = start_row - tank->get_height();
                    if (j + start_col > tank->get_width())
                        start_col = start_col - tank->get_width();
                    tank->update_at((int)(i + start_row),(int)(j + start_col),
                    fish_pic[i][j]);
                }
            }
         }
    }else{
        for (int i = 0; i < height; i++){
            for (int j = 0; j < width; j++){
                if (fish_pic[i][j] != ' '){ //transparency.
                    if (i + start_row > tank->get_height())
                        start_row = start_row - tank->get_height();
                    if (j + start_col > tank->get_width())
                        start_col = start_col - tank->get_width();
                    tank->update_at((int)(i + start_row),(int)(j + start_col),
                    fish_pic[i][j]);
                }
            }
         }
    }
}
//parameter: none
//return: none
//purpose: prints the fish
void Fish::print(){
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            cout << fish_pic[(int)(i)][(int)(j)]; 
        }
        cout << endl;
    }
}