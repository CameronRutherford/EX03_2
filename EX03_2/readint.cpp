#include "readint.h"

#include <string> 
#include <iostream> 
#include <stdexcept> 
#include <limits> 
#include <ios>

using namespace std;

/** Function to return an integer data value in response
	to a prompt. If a non-number is entered (as when 
	the first character is not a digit) the function will 
	prompt for another input after discarding the 
	erroneous input.
	@param prompt Message to be displayed 
	@return The first valid data value
*/

int read_int(const std::string &prompt, int low, int high) {
	cin.exceptions(ios_base::failbit);
	int num = 0;
	if (high - low <= 1) {
		throw invalid_argument("Exception: Range specified is empty.\n");
	}
	while (1) {
		try {
			cout << prompt;
			cin >> num;
			if (!(num >= low && num <= high)) {
				throw out_of_range("Number entered is out of range.\n");
			}
			return num;
		}
		catch (ios_base::failure &ex) {
			cerr << "Bad numeric string -- try again\n";
			// Reset the error flag
			cin.clear();
			// Skip current input line
			cin.ignore(numeric_limits<int>::max(), '\n');
		}
		catch (out_of_range &ex) {
			cerr << "out_of_range:\n" << ex.what();
		}
	}
}