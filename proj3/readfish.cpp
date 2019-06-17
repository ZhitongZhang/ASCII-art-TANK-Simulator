/* readfish.cpp
 *   show how to pass a file stream to a function
 *   also:  how to get filename from command line
 *   demo:  compile this, then type  ./a.out 2fish.simpledat
 *   where 2fish.simpledat is a file with:
 *
 *              charlie tuna 10
 *                   __
 *                 <====>
 *              nemo    clownfish 1
 *                  /o---\/
 *                  \____/\
 *
 * Note:  This test file is NOT in the same format as the data files
 * your program uses.
 */

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;


/*
 * Not the real Fish class.  Just an example to illustrate how 
 * to read data in a similar format.
 */
class Fish
{
public:
        Fish();
        bool readfish(istream &f);
        void showfish();
private:
        string  name;
        string  type;
        int     length;
        string  lines[2];
};

int main(int argc, char *argv[])
{
        Fish     f1, f2;
        ifstream input;

        if (argc > 1) {
                input.open(argv[1]);
                if (not input.is_open()) {
                        cout << "Cannot open " << argv[1] << endl;
                        exit(1);
                }
                f1.readfish(input);
                f2.readfish(input);
                input.close();
                f1.showfish();
                f2.showfish();
        } else {
                cerr << "Usage:  " << argv[0] << " 2fish.simpledat" << endl;
        }
        return 0;
}

/*
 * Default constructor for fish
 * name and type are unknown, and there is no picture, so 0 lines
 */
Fish::Fish()
{
        name = "unknown";
        type = "unknown";
        length = 0;
}

/*
 * Read on fish from the given input file stream.
 * Return true if successfully read a fish and false otherwise.
 */
bool Fish::readfish(istream &input)
{
        string  junk;

        if (input >> name >> type >> length) {
                getline(input, junk);               // eat rest of line
                getline(input, lines[0]);
                getline(input, lines[1]);

                return true;
        } else {
                return false;
        }
}

void Fish::showfish()
{
        cout << "Name: " << name << endl;
        cout << "Type: " << type << endl;
        cout << " Len: " << length << endl;
        cout << " Pic: " << endl;
        cout << lines[0] << endl;
        cout << lines[1] << endl;
        cout << endl;
}
