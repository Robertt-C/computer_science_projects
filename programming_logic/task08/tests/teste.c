
#include <stdio.h>
#include <string.h>
 
void Receber_texto(char texto[100], char texto2[100])
{
    scanf("%s", texto);
    scanf("%s", texto2);
   
    return;
}
 
int Procura(char *texto, char *texto2, int ii)
{
    int i, n;
    
    for(i=ii, n=0; i <strlen(texto); i++)
    {
        if(texto[i]==texto2[n])
        {
            n++;
        }
        else
        {
            n=0;
        }
        if(n==strlen(texto2))
        {
            return i;//achou
        }
    }
    return -1;//nao achou
}
 
void Imprimir(int *cont)
{
    printf ("Número de ocorrência: %d\n", *cont);
    return;
}
 
int main()
{
    char texto[100];
    char texto2[100];
    int ii =0, i, cont=0, cont3=0;
   
    Receber_texto(texto, texto2);
 
    if(strlen(texto2) == 1)
    {
        for(i=0; i<strlen(texto); i++)
        {
            if(texto2[0]==texto[i])
            {
            cont3++;
            }
        }
        printf("Número de ocorrência: %d\n",cont3);
    }
    
    else{
    do{ // primeiro chamar função, dps testar
        ii = Procura(texto, texto2, ii);
            if(ii != -1)
            {
                cont++;
            }
        
    } while(ii != -1);
   
    
    Imprimir( &cont);
    
   }
 
   
    return 0;
}
