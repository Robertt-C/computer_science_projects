#include <math.h>
#include <stdio.h>

//=== Receber cada coeficiente da equação. ===//
float NumReceiver() {
  float num;
  
  scanf("%f", &num);
  
  return num;
}

//=== Calculando delta da fórmula quadrática. ===//
float Delta(float a, float b, float c) {
  float delta;
  
  delta = pow(b, 2) - 4 * a * c;
  
  return delta;
}

//=== Fórmulas quadráticas positiva e negativa. ===//
float PositiveEquation(float a, float b, float c) {
  float positiveEquation;
  
  positiveEquation = (-b + sqrt(Delta(a, b, c))) / (2 * a);
  
  return positiveEquation;
}


float NegativeEquation(float a, float b, float c) {
  float negativeEquation;
  
  negativeEquation = (-b - sqrt(Delta(a, b, c))) / (2 * a);
  
  return negativeEquation;
}

//=== Em caso do coeficiente a = 0, então haverá uma equação de primeiro grau. ===//
float FirstDegreeEquation(float b, float c) {
  float firstDegreeEquation;
  
  firstDegreeEquation = -c / b;
  
  return firstDegreeEquation;
}

//=== Mostrador das raízes ou da não existência delas.
void Printer(float a, float b, float c) {
  
  if (a == 0) {
    printf("Raiz: %.2f\n", FirstDegreeEquation(b, c));
  } else if (Delta(a, b, c) > 0) {
    printf("Raiz 1: %.2f\n", PositiveEquation(a, b, c));
    printf("Raiz 2: %.2f\n", NegativeEquation(a, b, c));
  } else if (Delta(a, b, c) == 0) {
    printf("Raiz: %.2f\n", PositiveEquation(a, b, c));
  } else {
    printf("Não existem raízes reais\n");
  }
}


//=== Passando todos os valores e mostrando os resultados. ===//
int main() {
  float a, b, c;
  
  a = NumReceiver();
  b = NumReceiver();
  c = NumReceiver();
  
  Printer(a, b, c);
  return 0;
}