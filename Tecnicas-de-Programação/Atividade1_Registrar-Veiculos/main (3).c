
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct {
    char marca[20];
    char modelo[20];
    int ano;
    char placa[10];
}Veiculo;

void printVeics(Veiculo * veics, int qtt, int * filterYear, int * filterMinYear, char * filterModel){
    if (qtt < 1) {
        printf("Sem veiculos registrados.\n");
        return;
    }
    printf("Marca, Modelo, Ano, Placa\n");
    int i;
    for(i = 0; i < qtt; i++){
        if(filterYear != NULL && veics[i].ano != *filterYear){
            continue;
        }
        if(filterMinYear != NULL && veics[i].ano < *filterMinYear){
            continue;
        }
        if(filterModel != NULL && strstr(veics[i].modelo, filterModel) == NULL){
            continue;    
        }
        printf("%s, %s, %d, %s\n", veics[i].marca, veics[i].modelo, veics[i].ano, veics[i].placa);
    }
}

int readVeic(Veiculo * veics, int qtt){
    if(qtt >= 10){
        printf("Excedeu o limite de veiculos.\n");
        return qtt;
    }
    
    Veiculo creating;
    printf("Digite a marca, modelo, ano e placa separados por espaço:\n");
    char marca[20];
    char modelo[20];
    int ano;
    char placa[10];
    scanf("%s %s %d %s", &creating.marca, &creating.modelo, &creating.ano, &creating.placa);
    fflush(stdin);
    veics[qtt] = creating;
    printf("Veiculo Registrado!\n");
    return ++qtt;
}

int main()
{
	setlocale(LC_ALL, "Portuguese");
    Veiculo veics[10];
    int qtt = 0;

    while(1){
        printf("\n	Menu\n 1- Listar os veiculos cadastrados\n 2- Cadastrar novo veiculo\n 3- Filtrar por ano de fabricação\n 4- Filtrar por ano minimo\n 5- Filtrar pelo modelo\n Digite o numero da sua opção: \n");
        int opcao;
        scanf("%d", &opcao);
        fflush(stdin);

        if (opcao == 1){
            printVeics(veics, qtt, NULL, NULL, NULL);
        }
        else if(opcao == 2){
            qtt = readVeic(veics, qtt);
        }
        else if(opcao == 3){
            printf("Digite o ano: ");
                int ano;
                scanf("%d", &ano);
                printVeics(veics, qtt, &ano, NULL, NULL);
        }
        else if(opcao == 4){
            printf("Digite o ano: ");
                int ano;
                scanf("%d", &ano);
                printVeics(veics, qtt, NULL, &ano, NULL);
        }
        else if(opcao == 5){
            printf("Digite o modelo: ");
                char modelo[10];
                scanf("%s", &modelo);
                printVeics(veics, qtt, NULL, NULL, modelo);
        }
        else if((opcao >= 6) || (opcao <= 0)){
            printf("\nOpção invalida! Tente novamente.\n");
            break;
        }
    }
    
    return 0;
}

