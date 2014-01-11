#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

void compareListOfNumbers(int *inptList, int inptListLength, int *outptList){
	for (int i = 0; i < inptListLength; i++){
		if (inptList[i] < 0){
			outptList[0] += 1;
		} else if (inptList[i] > 0){
			outptList[2] += 1;
		} else{
			outptList[1] += 1;
		}
	}
}

int main(){
	srand(time(NULL)); //Needed to change the seed so that you don't get the same random numbers each time you run the program.
	int randNr = 0;
	int *list = new int[10];
	int *resList = new int[3];

	//Initialization of lists
	for (size_t i = 0; i < 3; i++){
		resList[i] = 0;
	}
	for (size_t i = 0; i < 10; i++){
		randNr = (rand() % 200) - 100;
		list[i] = randNr;
	}

	cout << "Following are all the elements of the 10-elements int array with values decided at compile-time: " << endl;

	for (size_t i = 0; i < 10; i++){
		cout << "Value of element " << i << ": " << list[i] << endl;
	}

	compareListOfNumbers(list, 10, resList);

	cout << "\nThe 10-elements list had:\n\n" << resList[0] << " values below 0 (negative),\n" << resList[1] << " values equal to 0,\n" << resList[2] << "values above 0 (positive).\n"  << endl;

	return 0;
}