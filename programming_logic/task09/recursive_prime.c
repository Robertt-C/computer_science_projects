#include <stdio.h>

int Input() {
  int num;
  scanf("%d", &num);
  return num;
}

int Text(int num, int base, int count) {
  
  if (num == 2) {
    printf("O número %d é primo!\n", num);
    return 1;
  } else if (num == 0 || num == 1 || num < 0) {
    printf("O número %d não é primo!\n", num);
    return 0;
  } else if (count != 0) {
    printf("O número %d não é primo!\n", num);
    return 0;
  } else {
    printf("O número %d é primo!\n", num);
    return 0;
  }
  
  return 0;
}



int Prime(int num, int base, int count) {
  
  while (base <= num / 2) {
    if (num % base == 0) {
      count++;
      break;
    }
    
    return Prime(num, base + 1, count);
  }
  
  Text(num, base, count);
  
  return 0;
}


void Printer() {
  int num, base, count;
  
  base = 2;
  num = Input();
  Prime(num, base, count);
  
  return;
}

int main() {
  
  Printer();
  
  return 0;
}