//simft.cpp
//Zhitong Zhang
//4/17/19
//This file will contain the main to run project 3.


#include <iostream>
#include "fishtank.h"
#include "fish.h"
#include "simulation.h"
using namespace std;

int main(int argc, char *argv[]){
    // FishTank THETAN(30,30);
    // THETAN.update_at(12,4,'c');
    // THETAN.show_tank();
    if (argc > 0){
        cout << "File given: " << argv[1] << endl;
        
        Simulation trial;
        if (trial.setup(argv[1]))
            cout << "setup is good\n";
        else
            cout << "setup failed\n";
        trial.run(false, 100);
    }
    else
        cout << "no argument given";
    return 0; 
}
