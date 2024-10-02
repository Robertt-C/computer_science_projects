#include <stdio.h>
#include <math.h>

void Receber_Coeficientes(int * a, int * b, int * c){
    scanf("%f%f%f", a, b, c);
    return;
}

float Calcular_Delta(int a, int b, int c){
    int delta = 0;
    delta = pow(b, 2) - 4 * a * c;
    
    return delta;
}

int Verifica_Num_Raizes(int delta){
    if(delta > 0){
        return 2;
    }else if(delta == 0){
        return 1;
    }
    return 0;
}

void Calcula_Raizes(int a, int b, int c, int delta, float * raiz1, float * raiz2){
    *raiz1 = (-b + sqrt(delta)) / 2*a;
    *raiz2 = (-b - sqrt(delta)) / 2*a;
    return;
}

void Imprime_Resultado(float raiz1, float raiz2, int numRaizes){
    if(numRaizes == 2){
        printf("Raiz 1: %.2f\nRaiz 2: %.2f", raiz1, raiz2);
    }else if(numRaizes == 1){
        printf("Raiz: %.2f", raiz1);
    }else{
        printf("Não existem raízes reais");
    }
    return;
}

int main() {
    int numRaizes = 0;
    float a, b, c, delta, raiz1, raiz2;
    Receber_Coeficientes(&a, &b, &c);
    delta = Calcular_Delta(a, b, c);
    numRaizes = Verifica_Num_Raizes(delta);
    Calcula_Raizes(a, b, c, delta, &raiz1, &raiz2);
    Imprime_Resultado(raiz1, raiz2, numRaizes);
    
    return 0;
}