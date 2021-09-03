/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int main()
{
    float A1, A2, A3, A4, Prova, media;
    
    printf("Primeira nota: "); scanf("%f", &A1);
    printf("Segunda nota: "); scanf("%f", &A2);
    printf("Terceira nota: "); scanf("%f", &A3);
    printf("Quarta nota: "); scanf("%f", &A4);
    printf("Nota da prova: "); scanf("%f", &Prova);
    
    media = ((A1 + A2 + A3 + A4)/4) * 0.4 + (Prova) * 0.6;
    
    if (media >= 6)
    {
        printf("Aluno Aprovado!!\nNota %.2f", media);
    }
    else
    {
        printf("Aluno Reprovado! ");
    }
     return 0;
}
