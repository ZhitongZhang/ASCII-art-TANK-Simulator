//simulation.cpp
//Zhitong Zhang
//4/17/19
//driver for the simulation class

#include <iostream>
#include <fstream>
#include <unistd.h>
#include "simulation.h"
#include "termfuncs.h"
#include "fish.h"
#include "fishtank.h"
using namespace std; 
//This is the default constructor
Simulation::Simulation(){
	head = NULL;
}
// This is the destructor that will free memory in heap
Simulation::~Simulation(){
    while(head != NULL){
        Node *temp = head;
        head = head->next;
        delete temp;
    }
}
//Parameter: Fish f, and Node next pointer
//return: a Node pointer
//purpose: creates a new node that stores f into data and
//stores *next into next. 
Simulation::Node *Simulation::newNode(Fish f, Node *next)
{
        Node *result = new Node;
        result->data = f;
        result->next = next;

        return result;
}
//parameter: Fish f
//return: none
//purpose: turns the fish into a node with it as a data member,
//then have it be what head points to. (have head point to it)
void Simulation::addToFront(Fish f){
    head = newNode(f, head);

}
//parameter: the string filename
//return: true or false
//purpose: initializes tank dim, fish linked list data. Returns
// false if error occurs
bool Simulation::setup(string filename){
	string tank_checker;
	ifstream file;
	file.open(filename.c_str());
    if (file.fail()){
        return false;
    }
    file >> tank_checker;
    if (tank_checker != "tank"){
    	return false;
    }
    int tank_height, tank_width;
    file >> tank_height >> tank_width;
    the_tank.set_height(tank_height);
    the_tank.set_width(tank_width);
    getline(file, tank_checker); //only for the purpose of skipping tank line
    Fish curr_fish;
     while ((curr_fish.read_fish(file))){
        addToFront(curr_fish);
    }
    file.close();
    //print_linked_list();
    return true;
}
//parameter: bool single_step, and int fps
//return: none;
//purpose: runs the simulation in fps frames per second. Will only run once
//if single_step is true, otherwise will run as described (similar to 
//the example program provided)
//stops of all fish dies or user inputs 'q'
void Simulation::run(bool single_step, int fps){
    float increment = (float)(1000000 / fps); //1000000 is one second
    if (single_step){
        while (head != NULL){
            head->data.move(the_tank.get_height(),the_tank.get_width());
            head->data.draw(&the_tank);
            head = head->next;
        }
        the_tank.show_tank();
    }else{
         Node *temp = new Node;
         temp = head;
         bool quit = false;
         while (not quit){
             while (temp != NULL){
                temp->data.move(the_tank.get_height(),the_tank.get_width());
                temp->data.draw(&the_tank);
                temp = temp->next;
            }
            the_tank.show_tank();
            the_tank.clear_tank();
            cout << "\033[2J" << "\33[H"; //clear screen and home cursor
            usleep(increment);
            if (all_fish_dead(head) or (getacharnow(0) ==  'q')){
                delete temp;
                break; // quit if user input 'q' or all fish dead
            }
            temp = head;
        }
    }
}
//parameter: Node head pointer
//return: true or false
//purpose: checks of all fishes are dead, if yes, return true, else false
bool Simulation::all_fish_dead(Node *head){
    int counter = 0;
    int dead_fish = 0;
    while (head != NULL){
        counter++;
        if (head->data.lifetime() == -1)
            return false; //if there is an immortal fish, dont end
        if (head->data.lifetime() == 0)
            dead_fish++;
        head = head->next;
    }
    if (counter == dead_fish)
        return true;
    else 
        return false;

}

// void Simulation::print_linked_list(){
//     while (head != NULL){
//         cout << head->data.get_name() << endl;
//         head = head->next;
//     }
// }