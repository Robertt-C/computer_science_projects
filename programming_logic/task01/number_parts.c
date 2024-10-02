#include <stdio.h>
 
int main(){
  float num;
  scanf("%f", &num);
  printf("A parte inteira: %d\n",(int)num);
  printf("A parte decimal: %0.0f\n", (num - (int)num)*100);
}