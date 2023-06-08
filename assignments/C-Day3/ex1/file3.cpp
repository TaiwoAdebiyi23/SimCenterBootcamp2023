
// program to read values from a file, each file a csv list of int and two double
// written: fmk

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main(int argc, char **argv) {

  if (argc != 3) {
    cerr << "ERROR correct usage appName inputFile outputBinaryFile\n";
    return -1;
  }

  //
  // read from ascii file
  // 
  FILE *filePtr = fopen(argv[1],"r"); 

  int i = 0;
  float float1, float2;
  int maxVectorSize = 100;
  double *vector1 = new double[maxVectorSize];
  double *vector2 = new double[maxVectorSize];  
  int vectorSize = 0;
  
  while (fscanf(filePtr,"%d, %f, %f\n", &i, &float1, &float2) != EOF) {
    vector1[vectorSize] = float1;
    vector2[vectorSize] = float2;
    printf("%d, %f, %f\n",i, vector2[i], vector1[i]);
    vectorSize++;

    if (vectorSize == maxVectorSize) {
      
      // create new arrys & copy contents
      double *newVector1 = new double [2*vectorSize];
      double *newVector2 = new double [2*vectorSize];
      for (int i=0; i<vectorSize; i++) {
	newVector1[i]=vector1[i];
	newVector2[i]=vector2[i];
      }

      // release old memory, set vectors to point to new ones and update max vector size
      delete [] vector1;
      delete [] vector2;
      vector1 = newVector1;
      vector2 = newVector2;
      maxVectorSize *= 2;
    }
  }
  fclose(filePtr);

  //
  // write to binary file
  //
  
  FILE *filePtrB = fopen(argv[2],"wb");
  fwrite(vector1, sizeof(double), vectorSize, filePtrB);
  fwrite(vector2, sizeof(double), vectorSize, filePtrB);    
  fclose(filePtrB);  
}
