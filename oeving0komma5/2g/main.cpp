#include <iostream>

using namespace std;

int findGreatestDivisor(int n){
	for (int i = (n-1); i > 0; i--){
		if (n%i == 0){
			return i;
		}
	}
	return -1;
}

int main(){
	int inpt = 0, result = 0;

	cout << "Input the number whose greatest divisor you want to naively find below: " << endl;
	cin >> inpt;
	cout << "\n" << endl;

	result = findGreatestDivisor(inpt);

	cout << result << " is the greatest common divisor to the inputted number " << inpt << "." << endl;

	return 0;
}