/*
  This exercise is taken from the class Parallel Programming Workshop (MPI,
  OpenMP and Advanced Topics) at HLRS given by Rolf Rabenseifner
 */

#include <cstdio>
#include <cmath>
#include <mpi.h>

inline int digit(double x, int n) {
  return std::trunc(x * std::pow(10., n)) - std::trunc(x * std::pow(10., n - 1)) *10.;
}

inline double f(double a) { return (4. / (1. + a * a)); }


int main(int argc, char *argv[]) {
  int i;
  double dx, x, sum, pi;
  int size,rank;

  MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &size);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);

  const int n = 1000000;
  const int sub_n = n/size;

  /* calculate pi = integral [0..1] 4 / (1 + x**2) dx */
  dx = 1. / n;
  sum = 0.0;
  for (i = rank*sub_n; i < (rank+1)*sub_n; i++) {
    x = 1. * i * dx;
    sum += f(x);
  }
  pi = dx * sum;
 
  double add1(pi), add2(pi);
  MPI_Status status;
  MPI_Request request;
  for(int ir=1;ir<size;ir++){
    MPI_Sendrecv(&add1, 1, MPI_DOUBLE, (rank+1)%size     , 0,
                 &add2, 1, MPI_DOUBLE, (rank-1+size)%size, 0, MPI_COMM_WORLD, &status);
    add1 = add2;
    pi += add1;
  }

  std::printf("computed pi (thread %d )        = %.16g\n", rank,  pi);

//  for(int d = 1; d <= 15; ++d) {
//    std::printf("%d", digit(pi, d));
//  }

  MPI_Finalize();
}
