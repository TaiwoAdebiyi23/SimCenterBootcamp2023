// program to transform stress:
//
// sigmaX' = sigmaX * cos^2(theta) + sigmaY * sin^2(theta) + 2 * tauXY Sin(theta)Cos(theta)
// sigmaY' = sigmaX * sin^2(theta) + sigmaY * cos^2(theta) - 2 * tauXY Sin(theta)Cos(theta)
// tauXY' = (sigmaY-sigmaX) * sin(theta)cos(theta) + tauXY(cos^2(theta) - sin^2(theta))
//
// write a program to take:
// 1: 4 inputs: sigmaX, sigmaY, tauXY, theta and output transformed stresses: sigmaX', sigmaY', tauXY'
// 2: 3  inputs: sigmaX, sigmaY, tauXY and output transformed stresses: sigmaX', sigmaY', tauXY' for every 10 degrees
//
// NOTE: perform the transformation inside a function that cannot be named main
//
// Extend to possibly include all outputs for a Mohr circle, were the theta now provided is a deltaTheta

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void transformStress(float *stressIN, float theta, float *stressTransformed);

int main(int argc, char **argv) {
  float stressIN[3], stressTransformed[3]; // create initialized array for input and output stresses//
    // Now put the arguments into the stressIN array //
    stressIN[0] = atof(argv[1]); 
  stressIN[1] = atof(argv[2]);
  stressIN[2] = atof(argv[3]);
  float theta = 0; // initialized theta

  if (argc == 5) 
    theta = atof(argv[4]);
    if(argc == 5) {
      transformStress(stressIN, theta, stressTransformed);
  printf("%.4f, %.4f, %.4f\n", stressTransformed[0], stressTransformed[1], stressTransformed[2]);
    } else {
      float theta_i = theta;
      while (theta_i < 360.) {
	transformStress(stressIN, theta_i, stressTransformed);
	printf("%.4f, %.4f, %.4f, %.4f\n", theta_i, stressTransformed[0], stressTransformed[1], stressTransformed[2]);
	theta_i += 10.;
      }
    }
  return 0;
}



void transformStress(float *stressIN, float theta, float *stressTransformed) {

  float sigmaX = stressIN[0];
  float sigmaY = stressIN[1];
  float tauXY = stressIN[2];

  float thetaRadians = theta*M_PI/180.;
  float cosX = cos(thetaRadians);
  float sinX = sin(thetaRadians);

  stressTransformed[0] = sigmaX*cosX*cosX + sigmaY*sinX*sinX + 2*tauXY * sinX*cosX;
  stressTransformed[1] = sigmaX*sinX*sinX + sigmaY*cosX*cosX - 2*tauXY * sinX*cosX;
  stressTransformed[2] = (sigmaY-sigmaX)*sinX*cosX + tauXY * (cosX*cosX - sinX*sinX);

}

