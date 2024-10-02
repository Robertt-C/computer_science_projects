#include <stdio.h>

void receiver() {
  int a, b, c;
  
  scanf("%d%d%d", &a, &b, &c);
}

int main() {
  int a, b, c;
  
  receiver();
  
  printf("%d%d%d", a, b, c);
  
  return 0;
}


/*
int test() {
  int a;
  a = 10;
  
  return a;
}

int main() {
  if (test() == 9) {
    printf("eeee");
  } else if (test() == 10) {
    printf("aaaa");
  }
}
*/