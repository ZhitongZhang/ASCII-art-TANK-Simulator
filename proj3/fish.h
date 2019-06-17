//fish.h
//Zhitong Zhang
//4/11/19
//the header file for the fish class

#ifndef FISH_H
#define FISH_H
#include "fishtank.h"

//The Fish class interface 
class Fish{
public:
    Fish();
    bool read_fish(std::istream &input);
    std::string get_name();
    void set_name(std::string name);
    void set_pos(int row, int col);
    int get_height();
    int get_width();
    int lifetime();
    void move(int tank_hgt, int tank_wid);
    void draw(FishTank *tank);
    


private:
    static const int MAX_HGT = 30;
    static const int MAX_WID = 60;
    float start_row, start_col, ver_spe, hor_spe;
    int height, width, lifetime_i;
    std::string fish_name;
    char fish_pic[MAX_HGT][MAX_WID];
    void print();



};

#endif 