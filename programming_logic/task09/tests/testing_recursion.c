#include <stdio.h>
#include <string.h>

#define PI 3.14159265358979323846264338327950288419716939937510

int Divider(float a, float divider) {
  
  divider = a / PI;
  
  if (a <= 1000) {
    printf("%.6f\n", divider);
    a++;
    Divider(a, divider);
  } else if (a > 1000) {
    return 0;
  }
  return 0;
}


int main() {
  float a, divider;
  
  divider = 0;
  
  scanf("%f", &a);
  
  Divider(a, divider);
  
  return 0;
}