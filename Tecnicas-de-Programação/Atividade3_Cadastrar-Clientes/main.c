#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
	
typedef struct {    
	char nome[30];    
	char ano[5];    
	int gastos;
}cliente;
	
cliente cadastro[10];
	
unsigned int TAMANHO_CADASTRO = 10;
unsigned int CLIENTES_CADASTRADOS = 0;
	
int menu(){    
	int opcao = 0;    
	while (opcao == 0){        
		printf("\n\n\n\t\t\t| **** SISTEMA DE CADASTRO DE CLIENTES**** |");        
		printf("\n\t\t\t|------------------------------------------|");        
		printf("\n\t\t\t|                    MENU                  |");        
		printf("\n\t\t\t|------------------------------------------|");        
		printf("\n\t\t\t|1-Incluir novo cliente                    |");        
		printf("\n\t\t\t|2-Remover cliente                         |");        
		printf("\n\t\t\t|3-Zerar montantes - virada de m�s         |");        
		printf("\n\t\t\t|4-Listar o melhor cliente comprador       |");        
		printf("\n\t\t\t|5-Exibir cliente espec�fico               |");        
		printf("\n\t\t\t|6-Sair                                    |");        
		printf("\n\n\t\t\t| INFORME A SUA OP��O:  "); scanf("%d", &opcao);        
		printf("\n\n");                    
	}    
	
	if (opcao > 6 || opcao < 0){        
		printf("\n\t\t\t|Op��o %d inv�lida!!", opcao);        
		opcao = 0;    
	}    
	return opcao;
}
	
void salvarCadastro(){  
	FILE *arquivo;  arquivo = fopen("CADASTRO.txt", "w+");
	for (int i = 0; i < CLIENTES_CADASTRADOS; i++)  {    
		fprintf(arquivo, "\n\t\t\t|Nome do Cliente: %s", cadastro[i].nome);    
		fprintf(arquivo, "\n\t\t\t|Ano de Nascimento: %s", cadastro[i].ano);    
		fprintf(arquivo, "\n\t\t\t|Gastos do m�s: %d", cadastro[i].gastos);  
	}  
	fclose(arquivo);
}
	
void aumentaCadastro() {  
		printf("\n\t\t\t|Tamanho m�ximo de cadastros atingido!");  
		printf("\n\t\t\t| Digite  1 para aumentar o limite  |");  
		printf("\n\t\t\t| Digite  0 para retornar ao menu   |\n");  
	int number;  
		printf("\n\t\t\t|"); scanf("%d", &number);  
		if(number == 1)  {    
		int limit;    
		printf("\n\t\t\t|O limite pode ser aumentado de 10 em 10. \n\t\t\t|Digite quantas vezes de 10 voc� deseja ampliar o cadastro: ");    
		printf("\n\t\t\t|"); scanf("%d", &limit);    
		TAMANHO_CADASTRO = limit * 10;    
		printf("\t\t\t|Cadastro aumentado com sucesso, o novo tamanho �: %d", TAMANHO_CADASTRO);
	} 
	else {    
	menu();  
}}
	
void cadastrarCliente(){  
	if (TAMANHO_CADASTRO > CLIENTES_CADASTRADOS)  {    
		puts("\n\t\t\t|Informe o nome do cliente: ");    
		printf("\n\t\t\t|"); scanf("%30s", cadastro[CLIENTES_CADASTRADOS].nome);
		puts("\n\t\t\t|Informe o ano de Nascimento: ");    
		printf("\n\t\t\t|"); scanf("%5s", cadastro[CLIENTES_CADASTRADOS].ano);        
		puts("\n\t\t\t|Informe o montante gasto no m�s: ");    
		printf("\n\t\t\t|"); scanf("%d", &cadastro[CLIENTES_CADASTRADOS].gastos);        
		printf("\n\t\t\t|Nome do Cliente: %s", cadastro[CLIENTES_CADASTRADOS].nome);    
		printf("\n\t\t\t|Ano de Nascimento: %s", cadastro[CLIENTES_CADASTRADOS].ano);    
		printf("\n\t\t\t|Gastos do m�s: %d", cadastro[CLIENTES_CADASTRADOS].gastos);        
		CLIENTES_CADASTRADOS++;    
		salvarCadastro();    
		printf("\n\t\t\t|Cadastro realizado com sucesso!");  
	}  
	else  {    
		aumentaCadastro();  
}}
	
void removeCadastro(){  
		printf("\n\t\t\t|Insira o nome do cliente que deseja remover: ");  
		int opcao;  char nomeCadastrado[30];  
		printf("\n\t\t\t|"); scanf("%19s", nomeCadastrado);  
	for (int i = 0; i < TAMANHO_CADASTRO; i++)  {    
		if (strcmp(cadastro[i].nome, nomeCadastrado) == 0)    {      
			printf("\n\t\t\t|O cadastro a ser removido � de: %s", cadastro[i].nome);      
			printf("\n\t\t\t|Digite 1 para continuar e 0 para retornar ao menu");      
			printf("\n\t\t\t|"); scanf("%d", &opcao);      
			if (opcao == 1)      {        
				memset(cadastro[i].nome, ' ', 30);        
				memset(cadastro[i].ano, ' ', 10);        
				cadastro[i].gastos = 0;        
				CLIENTES_CADASTRADOS = CLIENTES_CADASTRADOS - 1;      
			}      
			else   {        
				menu();      
			}    
		}  
}}
	
void zerarMontantes(){  
	for (int i = 0; i < TAMANHO_CADASTRO; i++)  {    
		cadastro[i].gastos = 0;  
}}
	
void melhorCliente(){  
	int montante = 0;  char *cliente[30];   
	for (int i = 0; i < TAMANHO_CADASTRO; i++)  {    
		if (cadastro[i].gastos > montante)    {      
			montante = cadastro[i].gastos;      
			*cliente = cadastro[i].nome;    
		}  
	}  
	printf("\n\t\t\t|O melhor cliente �: %s \n\t\t\t|E teve um gasto de: %d", *cliente, montante);  
}
	
void pesquisarCliente(){  
		printf("\n\t\t\t|Insira o nome do cliente que deseja pesquisar: ");  
		char nomeCadastrado[30];  
		printf("\n\t\t\t|"); scanf("%19s", nomeCadastrado);  
	for (int i = 0; i < TAMANHO_CADASTRO; i++)  {    
		if (strcmp(cadastro[i].nome, nomeCadastrado) == 0) {      
			printf("\n\t\t\t|***Informa��es do Cliente Pesquisado***");      
			printf("\n\t\t\t|Nome completo: %s", cadastro[i].nome);      
			printf("\n\t\t\t|Ano de Nascimento: %s", cadastro[i].ano);      
			printf("\n\t\t\t|Gastos do m�s: %d", cadastro[i].gastos);          
		}    
		else {      
			printf("\n\t\t\t|Cliente n�o encontrado!\n\t\t\t|Escolha uma nova op��o no menu: ");    
		}  
}}
	
int main(int argc, char **argv) {    
	setlocale(LC_ALL, "Portuguese");        
	int opcao = 0;  do  {    
		opcao = menu();    
		switch (opcao)    
		{    
			case 1:      
			cadastrarCliente();      
			break;    
			case 2:      
			removeCadastro();      
			break;    
			case 3:      
			zerarMontantes();      
			break;    
			case 4:      
			melhorCliente();      
			break;    
			case 5:      
			pesquisarCliente();      
			break;    
			default:      
			break;    
		}  
	} 
	while (opcao != 6);  
	printf("\n\t\t\tAgradecemos por utilizar nosso sistema!\n\t\t\tAperte 0 para encerrar o programa.");    
	return 0;
}	