#include <iostream>
#include <iomanip> //Needed for convertNOKToEUR
#include <string> //Needed for printMultiplicationTable

using namespace std;

void getAndPrintInteger(){ //This function has the return value "void" for one reason in this context; nothing is returned, yet procedures are run.
	int inpt = 0;

	cout << "Type in a number you want printed to the command console: " << endl;
	cin >> inpt;

	cout << "The number you inputted was: " << inpt << "." << endl;
}

//The difference in the above and below return values, reflect what variables you can instantiate with values with the help of these functions.
//The above function you cannot instantiate anything with, its return value doesn't correspond to any type.
//The below function you can instantiate integers with, since its return value corresponds to ints.

int getAndReturnInteger(){ //This function has the return value "int", since it's of interest to return a value to whatever called this function.
	int inpt = 0;

	cout << "Type in a number: " << endl;
	cin >> inpt;

	return inpt;
}

void getAndPrintSum(){
	int inpt1 = 0, inpt2 = 0;

	inpt1 = getAndReturnInteger();
	inpt2 = getAndReturnInteger();

	cout << "The sum of the two numbers you inputted is: " << inpt1 + inpt2 << "." << endl;
}

//The function I chose to use within "getAndPrintSum" was "getAndReturnInteger", since the other choice would ask for numbers from the users (which PrintSum needed), 
//but it had no way of giving the values to PrintSum. "getAndReturnInteger" however does enable PrintSum to receive the values the user inputs.
//And therefore it is of use.... Have I written enough sentence now...?

void getAndPrintMoreSums(){
	int inpt = 0, sum = 0;

	cout << "Input the amount of numbers you want to input: " << endl;
	cin >> inpt;

	for (int i = 0; i < inpt; i++){
		sum += getAndReturnInteger();
	}

	cout << "The sum of the " << inpt << " numbers you inputted is: " << sum << "." << endl;
}

//The best type of loop if the user has given the amount of numbers beforehand, is a for-loop. This is mostly due to simplicity, a while loop with a counter would've been just as easy.
//If the user instead was to input any random amount of numbers, as long as said numbers are not "0". If the number "0" is given as input, then that's supposed to be the users way of saying 
//"No more numbers to be inputted". Below is an example of how the while-loop could look like:

/*
	inpt = getAndReturnInteger();
	while (inpt != 0){
		sum += inpt;
		inpt= getAndReturnInteger();
	}
*/

double getAndReturnDouble(){
	double inpt = 0.0;

	cout << "Type in the value of a double: " << endl;
	cin >> inpt;

	return inpt;
}

void convertNOKToEUR(){ //http://stackoverflow.com/questions/2335657/prevent-scientific-notation-in-ostream-when-using-with-double <-- Source used for this.
	double inpt = 0;

	cout << "Type in a decimal value (double) of NOK you want to convert to EUR." << endl;
	inpt = getAndReturnDouble(); //If getAndReturnInteger had been used here instead, it would've been a type-mismatch giving a compiler error. The below division would work with an int, but the result would be floored due to inpt not being a double, therefore neglecting data =P.

	while (inpt <= 0.0){
		cout << "\nThe double value needs to be POSITIVE!!! Greater than zero!!!\nTry again!\n" << endl;
		inpt = getAndReturnDouble();
	}

	inpt /= 7.84;
	//The below line first sets the precision of the output to two decimalpoints, then "fixed" forces it to show 0's if it's a number like "4.00", and then forces the decimalpoint (comma) to be shown with "showpoint".
	cout << setprecision(2) << fixed << showpoint;
	cout << "\n" << inpt << " is the result of the conversion to EUR.\n" << endl;
}

void printMultiplicationTable(){
	int height = 1, width = 1;
	string table = "";

	cout << "Input two integers (height and then width) for the size of the multiplication table that's going to be printed. " << endl;

	//Get the user input for height
	height = getAndReturnInteger();
	while (height <= 0){
		cout << "C'mon, be sensible and don't make me more misanthropic, give a proper value above 0..." << endl;
		height = getAndReturnInteger();
	}
	height++;

	//Get the user input for width
	width = getAndReturnInteger();
	while (width <= 0){
		cout << "C'mon, be sensible and don't make me more misanthropic, give a proper value above 0..." << endl;
		width = getAndReturnInteger();
	}
	width++;

	cout << "Here's the " << height-1 << "x" << width-1 << " multiplication table:" << endl;
	for (int i = 1; i < height; i++){
		for (int j = 1; j < width; j++){
			table += to_string(i*j);
			table += "\t";
		}
		table += "\n";
	}

	cout << table << endl;
}

int main(){
	int function = 0, intInpt = 0;
	double doubleInpt = 0.0;

	while (function != -1){
		cout << "You can choose to run one of the following functions: " <<
				"\n1) getAndPrintInteger()" <<
				"\n2) getAndReturnInteger()" <<
				"\n3) getAndPrintSum()" <<
				"\n4) getAndPrintMoreSums()" <<
				"\n5) getAndReturnDouble()" <<
				"\n6) convertNOKToEUR() //This function converts NOKs to EURs. " <<
				"\n7) printMultiplicationTable() //This function asks for height and width, and prints corresponding mult. table. "
				"\n8) Finish. (AKA close program)." << 
				"\n\nMake a choice, input an integer in the range of 1-8:" << endl;
		cin >> function;

			switch (function){
				case 1:
					cout << "\nYou chose option 1:" << endl;
					getAndPrintInteger();
					break;
				case 2:
					cout << "\nYou chose option 2:" << endl;
					intInpt = getAndReturnInteger();
					cout << "\nThe integer you inputted was: " << intInpt << "." << endl;
					break;
				case 3:
					cout << "\nYou chose option 3: " << endl;
					getAndPrintSum();
					break;
				case 4:
					cout << "\nYou chose option 4: " << endl;
					getAndPrintMoreSums();
					break;
				case 5:
					cout << "\nYou chose option 5: " << endl;
					doubleInpt = getAndReturnDouble();
					cout << "\nThe double you inputted was: " << doubleInpt << "." << endl;
					break;
				case 6:
					cout << "\nYou chose option 6: " << endl;
					convertNOKToEUR();
					break;
				case 7:
					cout << "\nYou chose option 7: " << endl;
					printMultiplicationTable();
					break;
				case 8:
					cout << "\nYou chose to finish up and close this program! Bye bye suckah!\n" << endl;
					function = -1;
					break;
				default:
					function = 0;
					cout << "\nYour input was invalid. Try again...\n" << endl;
			}
	}
	
	system("PAUSE");
	return 0;
}