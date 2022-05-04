#include <iostream>

int main(int argc, char** argv)
{
	const int NUM_NUMBERS = 5;
	int numbers[NUM_NUMBERS] = { 10, 20, 30, 40, 50 };

	/* 
	TODO: Print each value of the array in order
	Expected:
		10, 20, 30, 40, 50,
	*/
	// Task1: Write your Code here
	// ------------------------------------------------------------------------

	
	std::cout << numbers[0] << ", " << numbers[1] << ", " << numbers[2] << ", " << numbers[3] << ", " << numbers[4] << ", " << std::endl;
	

	// ------------------------------------------------------------------------

	std::cout << "\n";

	/*
	TODO: Print each value of the array in reverse order
	Expected:
		50, 40, 30, 20, 10,
	*/

	// Task 2: Write your Code here
	// ------------------------------------------------------------------------

	std::cout << numbers[4] << ", " << numbers[3] << ", " << numbers[2] << ", " << numbers[1] << ", " << numbers[0] << ", " << std::endl;

	// ------------------------------------------------------------------------

	return 0;
}
