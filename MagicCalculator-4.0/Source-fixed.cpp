#include <cmath>
#include <iomanip>
#include <iostream>
#include <random>
#include <vector>
using namespace std;

/*
The Magic Calculator
	A user will pick a number between 1 and 100.
	The computer will display a set of numbers called a page and ask the user if they can see their number with a yes or no question.
	This process is repeated with 7 different pages.
	Then the computer will tell the user what it thinks the selected number was.

How this works
	* Each page corresponds to a binary digit and contains the numbers from the guess range that have a 1 in that binary digit.
	  Page Zero represents the one's place or 2^0. Page 1 is the two's place or 2^1. Page 2 is the four's place or 2^2.

	* So if a number is in a page that means in the equivalent binary number that place is 1. For example, the number 4 will only appear on page 2 (four's
	  place) because that is the only binary digit that has a 1 in the equivalent binary number. Another example is 67, 67 will appear on page 0, 1 and 6,
	  because the binary equivalent has a 1 in the 64's place, the two's place, and the one's place.

	* When a user says yes or no, that data is used to construct the binary number equal to the user's number. If page 2 is displayed and the user
	  responds yes, the four's place (corresponding digit to page 2) is given a 1.

	* Once all the pages are displayed the program now has a binary number equivalent to the user's number. If the user responds yes for page 0
	  page 1, page 6 and no for the other pages, the number is 1 0 0 0 0 1 1, which equals 64 + 2 + 1 = 67. Then 67 will be printed to the user.
*/

//Funtion to create vector that represents one of the 7 pages
vector<int> createPage(int pageNumber, int maxGuess = 100) {
	vector<int> page;

	for (int guess = 1; guess <= maxGuess; guess++) {
		if (guess & static_cast<int>(pow(2, pageNumber))) {
			page.push_back(guess);
		}
	}

	return page;
}

//Shuffle a page
void shufflePage(vector<int>& page) {
	int randomIndex;
	int originalValue;
	
	//initialize random seed
	srand(time(NULL));

	//generate secret number between 0 and size of vector:
	randomIndex = rand() % page.size();

	for (unsigned int i = 0; i < page.size(); i++) {
		originalValue = page.at(i);
		page.at(i) = page.at(randomIndex);
		page.at(randomIndex) = originalValue;
		randomIndex = rand() % page.size();
	}
}


//Function to Display page in a gride with cell width of 4
void displayPage(vector<int> page) {
	const int CELL_WIDTH = 4;
	const int MAX_COL = 8;
	const int MAX_ROW = ceil(static_cast<double>(page.size()) / static_cast<double>(MAX_COL));

	unsigned int i = 0;
	for (unsigned int row = 0; row < MAX_ROW; row++) {
		for (unsigned int col = 0; col < MAX_COL; col++) {
			if (i < page.size()) {
				cout << setw(CELL_WIDTH) << page.at(i);
				i++;
			}
		}
		cout << endl;
	}
}

//Function to Ask User if they see the number
bool askUser(vector<int> page) {
	char numCheckResponse;

	displayPage(page);

	do {
		cin.clear();
		cout << endl << "Do you see your number, (y or n): ";
		cin >> numCheckResponse;
	} while ((numCheckResponse != 'y' && numCheckResponse != 'n') || cin.fail());

	if (numCheckResponse == 'y') {
		return true;
	}
	else {
		return false;
	}
}

//Function to welcome the user and explain
bool welcomeAndStart(int maxGuess = 100) {
	string ready;
	//Display welcome to user
	cout << "Welcome to the Magic Calculator!" << endl;
	cout << "Please think of a number between 1 and " << maxGuess << endl;
	cout << "Once you have number I'm going to show some pages of numbers." << endl;
	cout << "Let me know if you see your number." << endl;
	cout << "Afterward, I'll use some magic and then I'll know your number too!" << endl << endl;
	cout << "Enter 'go' when you have a number: ";
	cin >> ready;
	while (ready != "go") {
		cout << "Enter 'go' to begin the magic trick: ";
		cin >> ready;
	}

	return true;
}

int main() {
	const int MAXIMUM_GUESS = 100;
	const int TOTAL_PAGES = 7;
	bool sawNum = false;
	//int computerGuess = 0; Found the bug :)
	char again;

	welcomeAndStart(MAXIMUM_GUESS);

	while (true) {
        int computerGuess = 0;

		for (int i = 0; i < TOTAL_PAGES; i++) {
			vector<int> page = createPage(i, MAXIMUM_GUESS); //Create a page
			cout << endl;

			shufflePage(page);
			sawNum = askUser(page);

			if (sawNum) {
				computerGuess |= static_cast<int>(pow(2, i)); // 0001 + 0010 = 0011
			}
		}

		cout << endl << "You number was " << computerGuess << endl << endl;

		cout << "Would you like to play again (y or n): ";
		cin >> again;

		if (again != 'y') {
			break;
		}
	}

	cout << endl << "Thank you for playing the Magic Calculator!" << endl;

	return 0;
}
