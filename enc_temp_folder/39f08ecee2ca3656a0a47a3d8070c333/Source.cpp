#include <cmath>
#include <iomanip>
#include <iostream>
#include <random>
#include <vector>
using namespace std;

/*
The Magic Calculator
	A user will pick a number between 1 and 100.
	The computer wil display a set of numbers called a page and ask the user if they can see their number with a yes or no question.
	This process is repeated with 7 different pages.
	Then the computer will tell the user what it thinks the selected number was.
*/

/*
How this works
	* Each page corresponds to a binary digit and contains the numbers from the guess range that have a 1 in that binary digit. 
	  Page Zero is represents the one's place or 2^0. Page 1 is the two's place or 2^1. Page 2 is the four's place or 2^2.

	* So if a number is in a page that means in the equivalent binary number that place is 1. For example the number 4 will only apear on page 2 (four's
	  place), because that is the only binary digit that has a 1 in the equivlant binary number. Another example is 67, 67 will appear on page 0, 1 and 6, 
	  because the binary equivalent has a 1 in the 64's place, the two's place, and the one's place.

	* When a user says yes or no, that data is used to construct the binary number equal to the user's number. If page 2 is displayed and the user 
	  responds yes, the four's place (corrsponding digit to page 2) is given a 1.

	* Once all the pages are displayed the program now has a binary number equivlent to the user's number. If the user reponds yes for page 0
	  page 1, page 6 and no for the other pages, the number is 1 0 0 0 0 1 1, which equals 64 + 2 + 1 = 67. Then 67 will be printed to the user.
*/

const int TOTAL_PAGES = 7;

//Function to create a vector that represents one of the 7 pages.
vector<vector<int>> createPage(int pageNumber, int maxGuess = 100, unsigned int maxCol = 8) {

	vector<vector<int>> page;
	vector<int> temp; //temp allows program to make set a 2D vector where each row has a finite number of columns, 
					  //but has a flexible num of rows

	for (int guess = 1; guess <= maxGuess; guess++) {

		//If guess number's binary number has a one in the current set then add the guess to the set
		if (guess & static_cast<int>(pow(2, pageNumber))) {

			if (temp.size() < maxCol) { //If the temporary vector size is < maxCol length keep adding guess to it.
				temp.push_back(guess);
			}
			else if (temp.size() == maxCol) { //If temp vecotor size = maxCol add temp to set, erase temp and start adding guess again.
				page.push_back(temp);
				temp = {};
				temp.push_back(guess);
			}

		}
	}
	if (temp.size() != 0) {
		page.push_back(temp); //In case the last temp vector was never equal to max col
	}

	return page;
}

//Funtion to create vector that represents one of the 7 pages
vector<int> createPage1(int pageNumber, int maxGuess = 100) {
	vector<int> page;

	for (int guess = 1; guess <= maxGuess; guess++) {
		if (guess & static_cast<int>(pow(2, pageNumber))) {
			page.push_back(guess);
		}
	}

	return page;
}

//Function to Display page in a gride with cell width of 4
void displayPage1(vector<int> page) {
	const int CELL_WIDTH = 4;
	const int MAX_COL = 8;
	const int MAX_ROW = ceil(static_cast<double>(page.size()) / static_cast<double>(MAX_COL));

	unsigned int i = 0;
	for (unsigned int row = 0; row < MAX_ROW; row++) {
		for (unsigned int col = 0; col < MAX_COL; col++) {
			cout << setw(CELL_WIDTH) << page.at(i);
			i++;
		}
		cout << endl;
	}
}


//Function to Output the page in a nice grid with cell width of 4
int displayPage(vector<vector<int>> page) {
	const int CELL_WIDTH = 4;
	const int MAX_COL = 8;
	const int MAX_ROW = ceil(static_cast<double>(page.size()) / static_cast<double>(MAX_COL));

	//vector<int> page2;

	for (unsigned int row = 0; row < page.size(); row++) {
		for (unsigned int col = 0; col < page[row].size(); col++) {
			cout << setw(CELL_WIDTH) << page[row][col];
		}
		cout << endl;
	}
	
	return 0;
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


//Function to Ask user if they see the number
bool askUser(vector<vector<int>> page) {
	string numCheckResponse;

	displayPage(page);

	do {
		cin.clear();
		cout << endl << "Do you see your number, yes or no: ";
		cin >> numCheckResponse;
	} while ((numCheckResponse != "yes" && numCheckResponse != "no") || cin.fail());
	
	if (numCheckResponse == "yes") {
		return true;
	}
	else {
		return false;
	}
}

//Function to Ask User if they see the number
bool askUser1(vector<int> page) {
	string numCheckResponse;

	displayPage1(page);

	do {
		cin.clear();
		cout << endl << "Do you see your number, yes or no: ";
		cin >> numCheckResponse;
	} while ((numCheckResponse != "yes" && numCheckResponse != "no") || cin.fail());

	if (numCheckResponse == "yes") {
		return true;
	}
	else {
		return false;
	}
}

//Shuffle a page
/*
vector<int> shufflePage(vector<vector<int>> page) {
	//initialize random seed
	srand(time(NULL));

	generate secret number between 1 and size of vector:
	iSecret = rand() % 10 + 1;




}
*/

/*
int main() {
	const int MAXIMUM_GUESS = 100;
	const int TOTAL_PAGES = 7;
	bool sawNum = false;
	int computerGuess = 0;

	welcomeAndStart(MAXIMUM_GUESS);

	for (int i = 0; i < TOTAL_PAGES; i++) {
		vector<vector<int>> page = createPage(i, MAXIMUM_GUESS); //Create a page
		cout << endl;
		sawNum = askUser(page);

		if (sawNum) {
			computerGuess |= static_cast<int>(pow(2, i));
		}
	}

	cout << endl;
	cout << "You number was " << computerGuess;

	return 0;
}
*/

int main() {
	const int MAXIMUM_GUESS = 100;
	const int TOTAL_PAGES = 7;
	bool sawNum = false;
	int computerGuess = 0;

	welcomeAndStart(MAXIMUM_GUESS);

	for (int i = 0; i < TOTAL_PAGES; i++) {
		vector<int> page = createPage1(i, MAXIMUM_GUESS); //Create a page
		cout << endl;
		sawNum = askUser1(page);

		if (sawNum) {
			computerGuess |= static_cast<int>(pow(2, i));
		}
	}

	cout << endl;
	cout << "You number was " << computerGuess;

	return 0;
}