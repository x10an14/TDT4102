#include <iostream>

using namespace std;

void fibonacci(int nthNumber, int *list){
	int a = 0, b = 1;
	int temp = 0;
	
	for (int i = 1; i < nthNumber; ++i){
		temp = b;
		b += a;
		a = temp;
		list[i] = b;
	}
}

int main(){
	int inpt = 0, n = 0;

	cout << "How long a Fibonacci-sequence do you want printed? Type it in below:" << endl;
	cin >> inpt;
	cout << "\n" << endl;

	//Declare and initialize array to contain sequence of fibonacci numbers.
	int *fibSeq = new int[inpt];
	//The fibonacci function given in the exercise does not print the first number, 0.
	fibSeq[0] = 0;

	//Iterate over and save said fibonacci sequence in the fibSeq-array.
	fibonacci(inpt, fibSeq);

	while (n < inpt){ //Print out each element in the fibonacci sequence.
		cout << "Number " << n+1 << ": " << fibSeq[n] << endl;
		n++;
	}

	cout << "\n" << endl;

	return 0;
}
