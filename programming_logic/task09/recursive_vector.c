#include <stdio.h>

//=== Recebedor de número genérico.
int Input() {
  int num;
  scanf("%d", &num);
  return num;
}

//=== Checando o maior entre os números que serão pedidos posteriormente.
int CheckingBiggerOne(int numbers[100]) {
  int i, bigger, smaller;
  
  smaller = 0;
  bigger = 0;
  for (i = 0; i < 100; i++) {
    if (bigger <= numbers[i]) {
      bigger = numbers[i];
    } else {
      smaller = numbers[i];
    }
    
    if (bigger >= smaller) {
      ; 
    } else {
      bigger = smaller;
    }
  }
  
  return bigger;
}

//=== Passando números para o vetor.
int GetNumber(int numbers[100], int count) {
  
  scanf("%d", &numbers[count]);
  
  if (numbers[count] != 0) {
    return GetNumber(numbers, count + 1);
  } else if (numbers[count] == 0) {
    printf("%d\n", CheckingBiggerOne(numbers));
  }
  
  return 0;
}


//=== Exibidor do resultado final (maior número).
void Printer() {
  int numbers[100] = {0};
  int count = 0;
  
  GetNumber(numbers, count);
  
  return;
}


int main() {
  
  Printer();
  
  return 0;
}