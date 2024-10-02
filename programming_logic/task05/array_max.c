#include <stdio.h>

int main() {
  int nums[5];
  int i, j, k, max;
  
// Construindo o vetor.
  i = 0;
  while (i <= 4) {
    scanf("%d", &nums[i]);
    i++;
  }
  
/* 
  Fazendo comparações entre cada ítem dentro do vetor
  e checando o maior.
*/
  for (j = 0; j <= 4; j++) {
    for (k = 0; k <= 4; k++) {
      if (nums[j] >= nums[k]) {
        max = nums[j];
      } else if (nums[k] >= nums[j]) {
        max = nums[k];
        nums[j] = nums[k];
      }
    }
  }
  
  printf("%d\n", max);
  
}