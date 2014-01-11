#include <iostream>

using namespace std;

void triangleNumbersBelow(int nthNumber, int *list){
	int acc = 1, num = 2;

	while (acc + num < nthNumber){
		acc += num;
		num += 1;
		list[num - 2] = acc;
	}
}

bool isTriangleNumber(int n){
	int acc = 1;

	while (n > 0){
		n -= acc;
		acc += 1;
	}

	if (n == 0){
		return true;
	} else{
		return false;
	}
}

int main(){
	int inpt = 0, function = 0, n = 1;

	cout << "First, which function do you want to test?\n\nType in the digit '1' to test the function 'triangleNumbersBelow' which will return all triangle numbers below your input digit.\n\nType in the digit '2' to test the function 'isTriangleNumber' which will test your input digit.\n\n\nType in the digit corresponding to the function you want to test below:" << endl;
	cin >> function;
	cout << "\n" << endl;

	if (function == 1){
		cout << "Input a number representing the uppermost triangle number you want the function to iterate from, and list all lower triangle numbers." << endl;
		cin >> inpt;
		cout << "\n" << endl;

		//Declare and initialize array to contain sequence of ints.
		int *intSeq = new int[inpt];

		//The below for-loop is mainly for pretty-printing
		for (size_t i = 0; i < inpt; i++){
			intSeq[i] = 0;
		}

		triangleNumbersBelow(inpt, intSeq);

		while (n < inpt && intSeq[n] != 0){ //There is no zeroth triangle number, and there's no point printing 0 where there are no triangle numbers.
			cout << "Triangle number " << n << ": " << intSeq[n] << endl;
			n++;
		}		
	} else if (function == 2) {
		cout << "Input a number you want to know if is a triangle number: " << endl;
		cin >> inpt;
		cout << "\n" << endl;

		if (isTriangleNumber(inpt)){
			cout << "The number you inputted (" << inpt << ") is a triangle number!!" << endl;
		} else{
			cout << "The number you inputted (" << inpt << ") is not a triangle number..." << endl;
		}
	} else{
		cout << "Your input was invalid. Try again..." << endl;
		main();
	}

	cout << "\n" << endl;

	return 0;
}
