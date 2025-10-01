#include <stdio.h> //biblioteca de comunica��o do usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca responsavel por cuidar das strings

int registro() //fun��o respons�vel por cadastrar usu�rios no sistema
{
	//in�cio da cria��o de vari�veis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de vari�veis/strings
	
	printf("DIGITE O CPF A SER CADASTRADO:\n"); //coleta de informa��es de usu�rios
	scanf("%s", cpf); //%s se refere a string
	
	strcpy(arquivo, cpf); //responsavel por copiar os valores das strings
	
	FILE *file;
	file = fopen(arquivo, "w"); //cria o arquivo
	fprintf(file,cpf);  //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("DIGITE O NOME A SER CADASTRADO:\n");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("DIGITE O SOBRENOME A SER CADASTRADO:\n");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("DIGITE O CARGO A SER CADASTRADO:\n");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
}

int consulta() //fun��o respons�rvel por consultar infora��es dos usu�rios
{
	setlocale(LC_ALL, "Portuguese");
	
	//cria��o das vari�veis
	char cpf[40];
	char conteudo[200];
	//fim da cria��o das vari�veis
	
	printf("DIGITE O CPF A SER CONSULTADO:\n"); //l� inform��oes a serem localizadas no banco de dados
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); //l� o arquivo
	
	if(file == NULL)
	{
		printf("O CPF DO DIGITADO N�O FOI LOCALIZADO!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nINFORMA��ES DO USU�RIO:\n ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
}

int deletar() //fun��o respons�vel por deletar usu�rios do sistema
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40]; //cria��o de vari�veis
	
	printf("DIGITE O CPF DO USU�RIO A SER DELETADO:\n");
	scanf("%s",cpf);
	
	remove(cpf); //deleta o usu�rio
	printf("CPF DO USU�RIO DELETADO COM SUCESSO!\n");
	system("pause");
	
	FILE* file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("CPF N�O ENCONTRADO NO SISTEMA!\n");
		system("pause");
	}
	
}


int main()
    {
	int opcao=0; //definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
		system("cls"); //respons�vel por limpar a tela
		
		setlocale(LC_ALL, "Portuguese");
	
	
		printf("\tCART�RIO DA EBAC\n\n"); //nome do meu
		printf("ESCOLHA A DESEJ�O DESEJADA DO MENU:\n\n");
		printf("\t1. REGISTRAR NOMES\n");
		printf("\t2. CONSULTAR NOMES\n");
		printf("\t3. DELETAR NOMES\n\n"); //fim do menu
	
		scanf("%d", &opcao); //armazenando as escolhas do usu�rio
	
		system("cls");
		
		
		switch(opcao)
		{
			case 1:
			registro(); //chamada de fun��es
			break;
			
			case 2:
			consulta();
			break;
			
			
			case 3:
			deletar();
			break;
			
			
			default:
			printf("ESSA OP��O NAO EST� DISPIN�VEL!\n");
			system("pause");
			break;
			//fim da sele��o
		}
		
	}
}
