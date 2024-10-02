#include "ticket_generator.h"


int main() {
  typeQueue queue;
  typeItem item;
  int i, option;
  
  
  initializeQueue(&queue);
  
  do {
    printf("\nPegar uma senha, digite 1.\nPegar uma senha preferencial, digite 2\nVer estado atual das filas, digite 3.\nSer atendido, digite 4.\nSair, digite 5.\n");
    
    printf("\nOpção: \n");
    scanf("%d", &option);
    
    switch (option) {
      case 1:
        getItem(&regularQueue, &item);
        
        if (insertNode(&regularQueue, item)) {
          printItem(item);
        } else {
          printf("ERRO!");
        }
        
        break;
      case 2:
        getItem(&priorityQueue, &item);
        
        if (insertNode(&priorityQueue, item)) {
          printItem(item);
        } else {
          printf("ERRO!");
        }
        
        break;
      case 3:
        printf("+-------------------+-------------------+-------------------+\n");
        printf("Fila Comum:\n");
        printQueue(&regularQueue);
        printf("+-------------------+-------------------+-------------------+\n");
        printf("\n\n");
        printf("+-------------------+-------------------+-------------------+\n");
        printf("Fila Prioritária:\n");
        printQueue(&priorityQueue);
        printf("+-------------------+-------------------+-------------------+\n");
        
        break;
      case 4:
        if (!isQueueEmpty(&regularQueue)) {
          removeNode(&regularQueue, &item);
          printf("\nFila Comum...\nAtendido(a/e): \n");
          printAttended(item);
        }
        
        if (!isQueueEmpty(&priorityQueue)) {
          for (i = 0; i < toAttend; i++) {
            removeNode(&priorityQueue, &item);
            
            if (i == 0) {
              printf("\nFila Prioritária...\nAtendidos(as/es):\n");
            }
            
            printAttended(item);
          }
        }
        
        break;
      case 5:
        if (!(isQueueEmpty(&regularQueue)) || !(isQueueEmpty(&priorityQueue))) {
          printf("\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
          printf("\nHá senhas a serem atendidas!\n\n");
          printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n\n");
          option = 0;
        } else {
          printf("Até mais!\n");
        }
        
        break;
      default:
        break;
    }
  } while (option != 5);
  
  return 0;
}