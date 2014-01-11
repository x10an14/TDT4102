#include <iostream>

using namespace std;

int max(int a, int b){
	if (a > b){
		cout << "A is greater than B.\nA = " << a << endl;
		return a;
	} else if (b > a){
		cout << "B is greater than A.\nB = " << b << endl;
		return b;
	}
}

int main(){
	int  a = 0, b = 0;

	cout << "Input a number for A below: " << "\n" << endl;
	cin >> a;
	cout << "\nInput a number for B below: " << "\n" << endl;
	cin >> b;
	cout << "\n" << endl;

	max(a, b);

	return 0;
}
