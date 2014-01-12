#include <iostream>
#include <string>
#include <cmath>
#include "cannonball.h"

using namespace std;

double startPosX = 0.0;
double startPosY = 0.0;
double acclX = 0.0, xVelocity = 50.0;

double acclY(){
	return -9.81;
}

double velY(double intitialSpeed, double timeInSeconds){
	return intitialSpeed + acclY()*timeInSeconds;
}

double velIntY(double initialSpeed, double timeInSeconds){
	double speedResult = initialSpeed;
	double accl = acclY(); //Compiler optimization.

	double timeDelta = 1.0;
	while ((timeInSeconds / timeDelta) > (1 / 1000000000000)){ //While the final timeDelta is bigger than 1*10^(-12) of a second, divide the time-delta by 10.
		timeDelta /= 10;
	}
	int timeSteps = trunc(timeInSeconds / timeDelta);

	for (int i = 0; i < timeSteps; i++){
		speedResult += accl*timeDelta;
	}

	/* //Alternate version without for-loop when acceleration is constant:
		speedResult += (accl*timeDelta)*timeSteps;
	*/

	return speedResult;
}

double posX(double initialSpeed, double timeInSeconds){
	return startPosX + (initialSpeed*timeInSeconds) + (0.5*acclX*timeInSeconds*timeInSeconds); 
}

double posIntX(double initialSpeed, double timeInSeconds){
	double coordResult = startPosX;

	double timeDelta = 1.0;
	while ((timeInSeconds / timeDelta) > (1 / 1000000000000)){ //While the final timeDelta is bigger than 1*10^(-12) of a second, divide the time-delta by 10.
		timeDelta /= 10;
	}
	int timeSteps = trunc(timeInSeconds / timeDelta);

	coordResult = (xVelocity*timeDelta)*timeSteps; //See bottom comment inside function velIntY(double initialSpeed, double timeInSeconds)...

	return coordResult;
}

double posY(double initialSpeed, double timeInSeconds){
	return startPosY + (initialSpeed*timeInSeconds) + (0.5*acclY()*timeInSeconds*timeInSeconds);
}

double posIntY(double initialSpeed, double timeInSeconds){
	double coordResult = startPosY;
	double yVelocityCurrent, yVelocityPrevious;

	double timeDelta = 1.0;
	while ((timeInSeconds / timeDelta) > (1 / 1000000000000)){ //While the final timeDelta is bigger than 1*10^(-12) of a second, divide the time-delta by 10.
		timeDelta /= 10;
	}
	int timeSteps = trunc(timeInSeconds / timeDelta);

	yVelocityPrevious = velIntY(initialSpeed, timeDelta);
	for (int i = 1; i < timeSteps; i++){
		yVelocityCurrent = velIntY(yVelocityPrevious, timeDelta);
		coordResult += yVelocityCurrent*timeDelta;
		yVelocityPrevious = yVelocityCurrent;
	}

	return coordResult;
}

void printTime(double timeInSeconds){
	int hours = 0, minutes = 0;
	bool functionEnd = false;
	string outpt = "";

	hours = trunc(timeInSeconds / 3600);
	if (hours > 0){
		timeInSeconds -= (hours * 3600);
		
		if (timeInSeconds == 0.0){
			functionEnd = true;
		}

		outpt += to_string(hours) + " hour";

		if (hours != 1){
			outpt += "s";
		}

		if (functionEnd){
			outpt += ".\n";
			cout << outpt << endl;
			return;
		} else{
			outpt += ", ";
		}
	}

	minutes = trunc(timeInSeconds / 60);
	if (minutes > 0){
		timeInSeconds -= (minutes * 60);

		if (timeInSeconds == 0.0){
			functionEnd = true;
			outpt += "and ";
		}

		outpt += to_string(minutes) + " minute";

		if (minutes != 1){
			outpt += "s";
		}

		if (functionEnd){
			outpt += ".\n";
			cout << outpt << endl;
			return;
		} else{
			outpt += ", ";
		}
	}

	outpt += "and " + to_string(timeInSeconds) + " second";

	if (timeInSeconds != 1.0){
		outpt += "s";
	}

	outpt += ".\n";
	cout << outpt << endl;

	return;
}

double flightTime(double yVelocity){
	double internalTimeDelta = 1 / (1000 * 1000 * 1000), 
		curVeloc = yVelocity, 
		totalTime = 0.0;

	if (yVelocity != 0.0){
		while (curVeloc != 0.0){
			curVeloc = velIntY(curVeloc, internalTimeDelta);
			totalTime += internalTimeDelta;
		} //When this loop is finished, the halfwaypoint is reached.

		while (curVeloc != yVelocity){
			curVeloc = velIntY(curVeloc, internalTimeDelta);
			totalTime += internalTimeDelta;
		} //When this loop is finished, it's reached groundlevel again. Could probably just have doubled totalTime after previous loop, but I'm not 100% sure that's correct.
		//This however I am very sure is correct. It would be an optimization though if I could just double totalTime after one while-loop instead of running through 2.

		/* //AKA this instead of the 2nd while-loop:
			totalTime *= 2;
		*/

	} else{
		totalTime = 0.0;
	}
	
	return totalTime;
}
