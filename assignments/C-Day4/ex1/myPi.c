#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char **argv) {
  
  int numP, procID;

  // ---------the usual mpi initialization-------------
  MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &numP);
  MPI_Comm_rank(MPI_COMM_WORLD, &procID);

  double *globalData=NULL;
  double localData[1];

  int numSteps = atol(argv[1]);

  // process 0 is only 1 that needs global data
  if (procID == 0) {
    globalData = (double *)malloc(1 * numP * sizeof(double) );
    for (int i=0; i<1*numP; i++)
      globalData[i] = 0;
  }

  double myPart = 0;
  double dx = 1./numSteps; 
  double x = dx*0.50;

  for (int i=procID; i<numSteps; i+=numP) {
    x = (i+.5)*dx;
    myPart += 4./(1.+x*x);
  }

  myPart *= dx;

  // localData[0] = myPart;

  
  MPI_Gather(&myPart, 1, MPI_DOUBLE, globalData, 1, MPI_DOUBLE, 0, MPI_COMM_WORLD);

  double pi = 0;
  if (procID == 0) {
    for (int i=0; i<numP; i++)
      pi += globalData[i];
    printf("PI = %16.14f Difference from math.h definition %16.14f \n", pi, pi-M_PI);
  }

  if (procID == 0)
    free(globalData);

  MPI_Finalize();
}
