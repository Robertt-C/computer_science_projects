#include <stdio.h>

#define PI 3.14159265358979323846

void calc_esfera(float R, float *area, float *volume) {
  *area = 4 * PI * R * R;
  *volume = (4 * PI * R * R * R) / 3;
  
  return;
}


void imprimirArea() {
  float raio, area, volume;
  
  printf("Dê-me o raio:\n");
  scanf("%f", &raio);
  
  calc_esfera(raio, &area, &volume);
  
  printf("Área da superfície é: %.2f\nVolume é: %.2f\n", area, volume);
  
  return;
}




int main() {
  
  imprimirArea();
  
  return 0;
}
