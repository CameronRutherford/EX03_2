#include "readint.h"
#include <iostream> 
#include <stdexcept> 
#include <limits> 
#include <ios>

using namespace std;

int main()
{
	cin.exceptions(ios_base::failbit);
	try
	{
		int low, high;
		cout << "Enter the range of values to read.\n";
		cout << "high: ";
		cin >> high;
		cout << "low: ";
		cin >> low;
		int number = read_int("Please enter a number within the range: ", low, high);
		cout << "You entered " << number << endl;
		return 0;
	}
	catch (ios_base::failure &ex) {
		cerr << "Bad numeric string -- try again\n";
		// Reset the error flag
		cin.clear();
		// Skip current input line
		cin.ignore(numeric_limits<int>::max(), '\n');
	}
	catch (invalid_argument &ex) {
		cerr << "invalid_argument:\n" << ex.what();
	}
}