//Zhitong Zhang
//4/15/19
//The header file for the simulation class

#ifndef SIM_H
#define SIM_H
#include "fishtank.h"
#include "fish.h"
//This class coordinates the activity.
class Simulation{
public:
    //no parameter
    //Constructor will initalize linkedlist and set # of fish = 0; 
    Simulation();
    ~Simulation();
    bool setup(std::string filename);



    void run(bool single_step, int fps);
    
private:
    FishTank the_tank;
    struct Node{
        Fish data;
        Node *next;
    };
    Node *newNode(Fish f, Node *next); //helper func
    void addToFront(Fish f); //helper func
    void print_linked_list(); //helper func
    bool all_fish_dead(Node *head); //helper func



    Node *head; //pointer to the first node

};
#endif
