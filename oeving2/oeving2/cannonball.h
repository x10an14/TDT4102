#ifndef CANNONBALL_H
#define CANNONBALL_H

double acclY();

double velY(double intitialSpeed, double timeInSeconds);
double velIntY(double initialSpeed, double timeInSeconds);

double posX(double initialSpeed, double timeInSeconds);
double posIntX(double initialSpeed, double timeInSeconds);

double posY(double initialSpeed, double timeInSeconds);
double posIntY(double initialSpeed, double timeInSeconds);

void printTime(double timeInSeconds);

double flightTime(double yVelocity);

#endif
