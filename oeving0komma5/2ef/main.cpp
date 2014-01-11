#include <iostream>

using namespace std;

bool isPrime(int n){
	for (int i = 2; i < n; i++){
		if (n%i == 0){
			return false;
			//break; //Not needed due to above line in C++ =).
		}
	}
	return true;
}

void naivePrimeSearch(int n){
	for (int i = 2; i < n; i++){
		if (isPrime(i)){
			cout << i << " is a prime." << endl;
		}
	}
}

int main(){
	int inpt = 0, function = 0;

	cout << "First, which function do you want to test?\n\nType in the digit '1' to test the function 'isPrime' which will tell you whether the inputted number you give it is a prime or not.\n\nType in the digit '2' to test the function 'naivePrimeSearch' which will naively search for all primes up to the number you give it as input and output those.\n\n\nType in the digit corresponding to the function you want to test below:" << endl;
	cin >> function;
	cout << "\nType in the number you want to give as input now below: " << endl;
	cin >> inpt;
	cout << "\n" << endl;

	if (function == 1){
		if (isPrime(inpt)){
			cout << inpt << " is a prime number." << endl;
		} else{
			cout << inpt << " is not a prime number." << endl;
		}
	} else{
		cout << "Your input number was " << inpt << ". Below are all primes naively found from 1 to (but not including) " << inpt << "." << endl;
		naivePrimeSearch(inpt);
	}

	return 0;
}