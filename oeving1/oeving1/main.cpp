#include <iostream>
#include <iomanip> //Needed for convertNOKToEUR
#include <string> //Needed for printMultiplicationTable
#include <cstdint> //Needed for printTime, 64-bit signed ints
#include <cmath> //Needed for internalSum

using namespace std;

void getAndPrintInteger(){ //This function has the return value "void" for one reason in this context; nothing is returned, yet procedures are run.
	int inpt = 0;

	cout << "Type in a integer you want printed to the command console: " << endl;
	cin >> inpt;

	cout << "The number you inputted was: " << inpt << "." << endl;
}

//The difference in the above and below return values, reflect what variables you can instantiate with values with the help of these functions.
//The above function you cannot instantiate anything with, its return value doesn't correspond to any type.
//The below function you can instantiate integers with, since its return value corresponds to ints.

int getAndReturnInteger(){ //This function has the return value "int", since it's of interest to return a value to whatever called this function.
	int inpt = 0;

	cout << "Type in an integer: " << endl;
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

	cout << "Input the amount of integers you want to input: " << endl;
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

void printTime(){
	int64_t seconds = 0, years = 0, weeks = 0, days = 0, hours = 0, minutes = 0;
	bool end = false;
	string outpt = "";

	cout << "Input the amount of seconds you want converted to years, days, hours, minutes, and seconds:\n" << endl;
	cin >> seconds;

	years = (seconds / (60 * 60 * 24 * 7 * 52)); //I'm assuming floor division here between two integers.
	if (years > 0){
		seconds -= (years * 60 * 60 * 24 * 7 * 52);

		if ((seconds % (60 * 60 * 24 * 7 * 52)) == 0){
			end = true;
		}

		outpt += to_string(years) + " year";

		if (years != 1){
			outpt += "s";
		}

		if (end){
			outpt += ".\n";
			cout << outpt << endl;
			return;
		} else{
			outpt += ", ";
		}
	}

	weeks = (seconds / (60 * 60 * 24 * 7));
	if (weeks > 0){
		seconds -= (weeks * 60 * 60 * 24 * 7);

		if ((seconds % (60 * 60 * 24 * 7)) == 0){
			end = true;
			outpt += "and ";
		}

		outpt += to_string(weeks) + " week";

		if (weeks != 1){
			outpt += "s";
		}

		if (end){
			outpt += ".\n";
			cout << outpt << endl;
			return;
		} else{
			outpt += ", ";
		}
	}

	days = seconds / (60 * 60 * 24);
	if (days > 0){
		seconds -= (days * 60 * 60 * 24);

		if ((seconds % (60 * 60 * 24)) == 0){
			end = true;
			outpt += "and ";
		}

		outpt += to_string(days) + " day";

		if (days != 1){
			outpt += "s";
		}

		if (end){
			outpt += ".\n";
			cout << outpt << endl;
			return;
		}
		else{
			outpt += ", ";
		}
	}

	hours = seconds / (60 * 60);
	if (hours > 0){
		seconds -= (hours * 60 * 60);

		if ((seconds % (60 * 60)) == 0){
			end = true;
			outpt += "and ";
		}

		outpt += to_string(hours) + " hour";

		if (hours != 1){
			outpt += "s";
		}

		if (end){
			outpt += ".\n";
			cout << outpt << endl;
			return;
		}
		else{
			outpt += ", ";
		}
	}

	minutes = seconds / 60;
	if (minutes > 0){
		seconds -= (minutes * 60);

		if ((seconds % 60) == 0){
			end = true;
			outpt += "and ";
		}

		outpt += to_string(minutes) + " minute";

		if (minutes != 1){
			outpt += "s";
		}

		if (end){
			outpt += ".\n";
			cout << outpt << endl;
			return;
		}
		else{
			outpt += ", ";
		}
	}

	outpt += "and " + to_string(seconds) + " second";

	if (seconds != 1){
		outpt += "s";
	}

	outpt += ".\n";
	cout << outpt << endl;
	return;
}

void printRestaurantBill(){
	double inpt = 0.0;

	cout << "Type in a double value representing the cost of the meal below: " << endl;
	inpt = getAndReturnDouble();

	while (inpt <= 0){
		cout << "C'mon... type in a proper positive value. Use '.' to separate the decimal values if you want to use them..." << endl;
		inpt = getAndReturnDouble();
	}

	cout << setprecision(2) << fixed << showpoint;

	cout << "The tax of this meal is: " << (inpt*0.0875) << "." << endl;
	cout << "The tip (including the tax) for this meal is: " << (inpt*0.18) << "." << endl;
	cout << "All of it together sums up to:" << (inpt*1.18) << "." << endl;

	return;
}

void printEvenOrOdd(){
	int inpt = 0;

	inpt = getAndReturnInteger();

	if (inpt % 2 == 0){
		cout << inpt << " is an even number." << endl;
	} else{
		cout << inpt << " is an odd (not even) number." << endl;
	}

	return;
}

void returnMaxDouble(){
	double inpt1 = 0.0, inpt2 = 0.0;

	inpt1 = getAndReturnDouble();
	inpt2 = getAndReturnDouble();

	if (inpt1 > inpt2){
		cout << inpt1 << " is the biggest number of the two previous inputted integers." << endl;
	} else if (inpt1 == inpt2){
		cout <<"Both the integers inputted have the same value." << endl;
	} else{
		cout << inpt2 << " is the biggest number of the two previous inputted integers." << endl;
	}

	return;
}

/*
If the exercise text had changed to what is suggested, the functions would've needed to receive inputs, AKA the values the function used were defined outside of the function itself.
Instead of the function instantiating those values themselves inside of the functions with the help of user-input.
*/

double internalSum(double a, double b, double c){
	return (b*b) - 4 * a*c;
}

double positiveSqrt(double x){
	if (x >= 0){
		return sqrt(x);
	} else{
		return -1;
	}
}

double polyRoot(double a, double b, double c){
	return positiveSqrt(internalSum(a, b, c));
}

void abcFormula(double a, double b, double c){
	double root = polyRoot(a, b, c);
	if (root == 0){
		cout << "One real result:\n" << ((-b) / (2 * a)) << "." << endl;
	} else if (root < 0){
		cout << "No real results for these values." << endl;
	} else{
		cout << "Two results:" << endl;
		cout << "Real result one: " <<  ((-b - root) / (2 * a)) << endl;
		cout << "Real result two: " << ((-b + root) / (2 * a)) << endl;
	}
	return;
}

void solveAndPrintRoots(){
	double a = 0.0, b = 0.0, c = 0.0;

	cout << "This function requires three doubles as input from the user, please input the double-values representing A, B, and C in your 2nd degree equation of the form:" <<
		"Ax^2 + Bx + C = 0\n" << endl;

	cout << "First A:" << endl;
	a = getAndReturnDouble();
	cout << "Then B:" << endl;
	b = getAndReturnDouble();
	cout << "And at last, C:" << endl;
	c = getAndReturnDouble();

	abcFormula(a, b, c);
}

void calculateLoanPayments(){
	double loanAmount = 0.0, interest = 0.0, curPayment = 0.0, totalLoan = 0.0;

	cout << "Skriv inn lånebeløp (som double):" << endl;
	loanAmount = getAndReturnDouble();
	totalLoan = loanAmount;

	cout << "Skriv inn rente (som double):" << endl;
	interest = getAndReturnDouble();

	cout << setprecision(0) << fixed;

	cout << "\n\nÅr\t\tInnbetaling\t\tGjenstående Lån" << endl;
	cout << "1\t\t" << ((totalLoan / 10) + ((interest / 100)*loanAmount)) << "\t\t" << loanAmount << endl;

	for (size_t i = 2; i < 11; i++){
		loanAmount -= totalLoan / 10;
		curPayment = ((totalLoan / 10) + ((interest / 100)*loanAmount));
		cout << i << "\t\t" << curPayment << "\t\t" << loanAmount << endl;
	}
}

int main(){
	int function = 0, intInpt = 0;
	double doubleInpt = 0.0;

	while (function != -1){
		cout << "\n\nYou can choose to run one of the following functions: " <<
				"\n1) getAndPrintInteger()" <<
				"\n2) getAndReturnInteger()" <<
				"\n3) getAndPrintSum()" <<
				"\n4) getAndPrintMoreSums()" <<
				"\n5) getAndReturnDouble()" <<
				"\n6) convertNOKToEUR() //This function converts NOKs to EURs. " <<
				"\n7) printMultiplicationTable() //This function asks for height and width, and prints corresponding mult. table. " <<
				"\n8) printTime() //This function takes in seconds, and prints out years, weeks, days, minutes, and seconds those seconds represent. " <<
				"\n9) printRestaurantBills() //This function needs a double value representing the cost of the meal, and returns info about tax and tips and total sum. " <<
				"\n10) printEvenOrOdd() //This function requires a double as input, and reports whether it is an even or odd number. " <<
				"\n11) returnMaxDouble() //This function requires two doubles as input, and returns the biggest number. " <<
				"\n12) solveAndPrintRoots() //This function requires three doubles as input, to solve a 2nd degree equation the doubles represent, and then returns the real values to the screen." <<
				"\n13) calculateLoanPayments() //Give loan amount and interest to this function, and it will tell you how much you have to pay per year if the loan is to be paid in 10 years." <<
				"\n14) Finish. (AKA close program)." <<
				"\n\nMake a choice, input an integer in the range of 1-14:" << endl;
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
					cout << "\nYou chose option 8: " << endl;
					printTime();
					break;
				case 9:
					cout << "\nYou chose option 9: " << endl;
					printRestaurantBill();
					break;
				case 10:
					cout << "\nYou chose option 10: " << endl;
					printMultiplicationTable();
					break;
				case 11:
					cout << "\nYou chose option 11: " << endl;
					printMultiplicationTable();
					break;
				case 12:
					cout << "\nYou chose option 12: " << endl;
					solveAndPrintRoots();
					break;
				case 13:
					cout << "\nYou chose option 13: " << endl;
					calculateLoanPayments();
					break;
				case 14:
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