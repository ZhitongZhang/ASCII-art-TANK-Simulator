//testtank.cpp
//Zhitong Zhang
//4/16/19
//This .cpp file is for the purpose of testing the components of proj 3.
#include <iostream>
#include <fstream>
#include "fishtank.h"
//#include "fish.h"
using namespace std;


int main(){
	FishTank Tank(30, 100);

    //For the purpose of drawing some characters in tank (test)
    for (int i = 0; i < 15 ; i++){
        for (int j = 0; j < 50; j++){
            Tank.update_at(i,j, 'g');
        }
    }
    Tank.show_tank();
    cout << "this tank is " << Tank.get_height() << " by " << Tank.get_width()
         << endl;

//	ifstream file;
//	file.open("tank1.dat");
// string bro;
//    if (file.fail()){
//        cerr << "error opening" << endl;
//        return 1;
//    }
//    getline(file, bro);//Just to skip a line (the tank line)
//   Fish1.read_fish(file);
//    Fish1.print();


//    file.close();

	return 0;
}