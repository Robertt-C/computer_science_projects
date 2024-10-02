#include <stdio.h>                                                                                                  

int main() {
  float num1, num2, num3, num4, num5, average;
  
  scanf("%f %f %f %f %f", &num1, &num2, &num3, &num4, &num5);
  
  average = (num1+num2+num3+num4+num5) / 5;
  printf("p1= %.1f p2= %.1f p3= %.1f p4= %.1f p5= %.1f media= %.2f\n", num1, num2, num3, num4, num5, average);
  
  return 0;
}