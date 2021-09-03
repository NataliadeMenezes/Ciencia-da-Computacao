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
