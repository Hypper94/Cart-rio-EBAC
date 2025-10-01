#include <stdio.h> //biblioteca de comunicação do usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsavel por cuidar das strings

int registro() //função responsável por cadastrar usuários no sistema
{
	//início da criação de variáveis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variáveis/strings
	
	printf("DIGITE O CPF A SER CADASTRADO:\n"); //coleta de informações de usuários
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

int consulta() //função responsárvel por consultar inforações dos usuários
{
	setlocale(LC_ALL, "Portuguese");
	
	//criação das variáveis
	char cpf[40];
	char conteudo[200];
	//fim da criação das variáveis
	
	printf("DIGITE O CPF A SER CONSULTADO:\n"); //lê informçãoes a serem localizadas no banco de dados
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); //lê o arquivo
	
	if(file == NULL)
	{
		printf("O CPF DO DIGITADO NÃO FOI LOCALIZADO!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nINFORMAÇÕES DO USUÁRIO:\n ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
}

int deletar() //função responsável por deletar usuários do sistema
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40]; //criação de variáveis
	
	printf("DIGITE O CPF DO USUÁRIO A SER DELETADO:\n");
	scanf("%s",cpf);
	
	remove(cpf); //deleta o usuário
	printf("CPF DO USUÁRIO DELETADO COM SUCESSO!\n");
	system("pause");
	
	FILE* file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("CPF NÃO ENCONTRADO NO SISTEMA!\n");
		system("pause");
	}
	
}


int main()
    {
	int opcao=0; //definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
		system("cls"); //responsável por limpar a tela
		
		setlocale(LC_ALL, "Portuguese");
	
	
		printf("\tCARTÓRIO DA EBAC\n\n"); //nome do meu
		printf("ESCOLHA A DESEJÃO DESEJADA DO MENU:\n\n");
		printf("\t1. REGISTRAR NOMES\n");
		printf("\t2. CONSULTAR NOMES\n");
		printf("\t3. DELETAR NOMES\n\n"); //fim do menu
	
		scanf("%d", &opcao); //armazenando as escolhas do usuário
	
		system("cls");
		
		
		switch(opcao)
		{
			case 1:
			registro(); //chamada de funções
			break;
			
			case 2:
			consulta();
			break;
			
			
			case 3:
			deletar();
			break;
			
			
			default:
			printf("ESSA OPÇÃO NAO ESTÁ DISPINÍVEL!\n");
			system("pause");
			break;
			//fim da seleção
		}
		
	}
}
