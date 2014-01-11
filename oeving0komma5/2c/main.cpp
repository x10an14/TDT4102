#include <iostream>

using namespace std;

void squareNumberSum(int n, int *list){
	int totalsum = 0, temp = 0;

	for (int i = 1; i < n; i++){
		temp = i*i;
		totalsum += temp;
		list[i] = temp;
	}

	list[0] = totalsum;
}

int main(){
	int inpt = 0, n = 1;

	cout << "Input a number whose sum of all its predecessors squared you want outputted: " << endl;
	cin >> inpt;
	cout << "\n" << endl;

	int *intSeq = new int[inpt];

	squareNumberSum(inpt, intSeq);

	while (n < inpt){
		cout << n << "^2 =  " << intSeq[n] << "." << endl;
		n++;
	}

	cout << "\nThe sum of all the above squared numbers are: " << intSeq[0] << "\n" << endl;

	return 0;
}
