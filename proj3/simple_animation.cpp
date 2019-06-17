/*
 * Demonstrate a simple animation.
 *
 * Shows a couple of escape sequences to clear the 
 * terminal screen and put the cursor in the home position
 * (upper left).
 *
 * Also demonstrates use of usleep() to suspend a program
 * for a given amount of time (in microseconds).
 */
#include <iostream>
#include <unistd.h>

using namespace std;

/*
 * Microseconds in 1 / 4 of a second
 */
const int QUARTER_SECOND_us = 250000;

/*
 * Clears the terminal screen using special escape code
 */
void clear_screen()
{
	cout << "\033[2J";
}

/*
 * Moves the curser to the home position (upper left) 
 * in the terminal screen using special escape code
 */
void home_cursor()
{
	cout << "\33[H";
}

int main()
{
	int	pos = 0;

	clear_screen();
	for (pos = 0; pos < 30; pos++) {
		home_cursor();
		for (int i = 0; i < pos; i++)
			cout << " ";
		cout << "><>";
		home_cursor();
		cout.flush();               // force string to print
                                            //      without new line
		usleep(QUARTER_SECOND_us);  // sleep for 1 / 4 second
	}
        return 0;
}
