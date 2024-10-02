#include "hanoi.h"

int main() {
  typeStack tower1, tower2, tower3;
  int i, disksNumber, movementsNumber, fromTower, toTower;
  
  startStack(&tower1);
  startStack(&tower2);
  startStack(&tower3);
  
  printf("Quantos discos deseja? (0~10): ");
  scanf("%d", &disksNumber);
  
  printf("Quantos movimentos irá fazer? (0~2000): ");
  scanf("%d", &movementsNumber);
  
  fillStack(&tower1, disksNumber);
  
  printf("\ndigite 0 0 para parar\n");
  
  for (i = 0; i < movementsNumber; i++) {
    printf("Dê-me o movimento a ser realizado (origem e chegada): ");
    scanf("%d %d", &fromTower, &toTower);
    
    if (fromTower == 0 && toTower == 0) {
      break;
    }
    
    if (doTheMove(&tower1, &tower2, &tower3, fromTower, toTower)) {
      if (checkStackSequence(&tower1) == 0 || checkStackSequence(&tower2) == 0 || checkStackSequence(&tower3) == 0) {
        printf("Wrong Movement\n");
        return 0;
      }
      
    } else {
      break;
    }
    
  }
  
  if (checkStackSequence(&tower3) && towerTop(&tower3)){
    printf("Solved.\n");
  } else {
    printf("Unsolved.\n");
  }
  
  destroyStack(&tower1);
  destroyStack(&tower2);
  destroyStack(&tower3);
  
  return 0;
}