#include <stdio.h>
#include <omp.h>
#include <time.h>  // Added for clock()

#define N 1000000000

int main(int argc, char *argv[]){
  double x, final;
  int i;

  final = 1;
  x = 1 + 1.0/N;

  clock_t start_time = clock();  // Record start CPU time

#pragma omp parallel default(none) private(i) shared(x) reduction(*:final)
  {
#pragma omp for
    for(i=0; i<N; i++) {
      final = final*x;
    }
  }
  
  clock_t end_time = clock();  // Record end CPU time
  double time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC;  // Calculate CPU time in seconds

  printf("Resultado=%lf\n",final);
  printf("Tempo: %.6f segundos\n", time_taken);  // Print with microsecond precision
  return 0;
}
