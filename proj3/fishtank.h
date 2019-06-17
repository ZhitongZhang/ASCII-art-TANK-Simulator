//fishtank.h
//Zhitong Zhang
//4/11/19
//The headerfile for the fishtank class
#ifndef FISHTANK_H
#define FISHTANK_H
//This FishTank class contains the tools needed for
//printing, updating, and retrieving the dim 
//of the FishTank.
class FishTank{
public:
    FishTank();
    FishTank(int hgt, int wid);
    bool set_height(int hgt);  
    bool set_width(int wid);
    int get_height();
    int get_width();
    void clear_tank();
    void update_at(int row, int col, char c);
    void show_tank();
private:
    static const int MAX_HGT = 50;
    static const int MAX_WID = 200;
    int width, height;
    char screen[MAX_HGT][MAX_WID];
};

#endif
