#include <stdio.h>                                                                                                                                                                      


//=== Exchanging values without a third variable.
int main() {
  int num1, num2;
  scanf("%d %d", &num1, &num2);
  printf("Os valores digitados foram a: %d e b: %d.\n", num1, num2);
  num1 = num1 + num2;
  num2 = num1 - num2;
  num1 = num1 - num2;
  printf("Os valores atuais são a: %d e b: %d.\n", num1, num2);
  return 0;
}
/*
int main() {
  int num1, num2;
  scanf("%d %d", &num1, &num2);
  printf("Os valores digitados foram a: %d e b: %d.\nOs valores atuais são a: %d e b: %d.\n", num1, num2, (int)(((float)num2/(float)num1)*(float)num1), (int)(((float)num1/(float)num2)*(float)num2));
  return 0;
}*/

/*int main() {
  int num1, num2;
  scanf("%d %d", &num1, &num2);
  printf("Os valores digitados foram a: %d e b: %d.\nOs valores atuais são a: %d e b: %d.", num1, num2, num2, num1);
  return 0;
}*/

