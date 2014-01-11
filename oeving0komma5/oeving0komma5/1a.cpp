#include <iostream>

using namespace std;

bool isFibonacciNumber(int n){
	int a = 0, b = 1;
	int temp = 0;

	while (b < n){
		temp = b;
		b += a;
		a = temp;
	}

	if (b == n){
		return true;
	} else{
		return false;
	}
}

int main(){
	int inpt = 0;

	cout << "What number do you want to know if is a Fibonacci number? Type it in here:" << endl;
	cin >> inpt;

	if (isFibonacciNumber(inpt)){
		cout << "The number you inputted ("<< inpt << ") is a fibonacci number!" << endl;
	} else{
		cout << "The number you inputted (" << inpt << ") is not a fibonacci number!" << endl;
	}

}
