#include <stdio.h>

int main() {
  int day0, day1, month0, month1, year0, year1;
  
  scanf("%d/%d/%d", &day0, &month0, &year0);
  
  scanf("%d/%d/%d", &day1, &month1, &year1);
  
  if (year0 < year1) {
    printf("A primeira data ocorreu antes da segunda.\n");
  } else if (year0 > year1) {
    printf("A segunda data ocorreu antes da primeira.\n");
  } else if (month0 < month1) {
    printf("A primeira data ocorreu antes da segunda.\n");
  } else if (month0 > month1) {
    printf("A segunda data ocorreu antes da primeira.\n");
  } else if (day0 < day1) {
    printf("A primeira data ocorreu antes da segunda.\n");
  } else if (day0 > day1) {
    printf("A segunda data ocorreu antes da primeira.\n");
  }
  
  return 0;
}