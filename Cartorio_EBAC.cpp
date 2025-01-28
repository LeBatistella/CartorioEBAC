#include <stdio.h> //biblioteca de comunica��o com usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o de mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar de string

int registro()// Responsavel por cadastrar usu�rios
{
	//inicio cria��o de vari�veis/strings
    char arquivo[40];//cria o arquivo com nome cpf
	char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    
    printf("Digite o CPF a ser cadastrado: ");
    scanf("%s", cpf);
    
    strcpy(arquivo, cpf); //Respons�vel por copiar os valores das string arquivo=cpf
    
    FILE *file; // Cria o arquivo fun��o do sistema
    file = fopen(arquivo, "w"); //Escrever um arquivo novo
    fprintf(file,cpf); // salva o valor da vari�vel
    fclose(file); // fecha o arquivo
    
    file = fopen(arquivo, "a");
    fprintf(file,",");
    fclose(file);
    
    printf("Digite o nome a ser cadastrado: ");
    scanf("%s",nome);
    
    file = fopen(arquivo, "a");
    fprintf(file,nome);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file,",");
    fclose(file);
    
    printf("Digite o sobrenome a ser cadastrado: ");
    scanf("%s",sobrenome);
    
    file = fopen(arquivo, "a");
    fprintf(file, sobrenome);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file,",");
    fclose(file);
    
    printf("Digite o cargo a ser cadastrado: ");
    scanf("%s", cargo);
    
    file = fopen(arquivo, "a");
    fprintf(file,cargo);
    fclose(file);
    
    system("pause");
    
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
   	char cpf[40];
   	char conteudo[200];
   	
   	printf("Digite o CPF a ser consultado: ");
   	scanf("%s",cpf);
   	
   	FILE *file;
   	file = fopen(cpf,"r");
   	
   	if(file == NULL)
	{
   		printf("N�o foi localizado este cadastro!\n");	
	}
	
	while(fgets(conteudo, 200,file) != NULL) // Busca do usu�rio at� 200 e no arquivo file
	{
			printf("\nEssas s�o as informa��es do usu�rio: ");
			printf("%s",conteudo);
			printf("\n\n");
	}
   	
    system("pause");
}

int deletar()
{
    char cpf[40];
    
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s",cpf);

	remove(cpf);

	FILE *file;
  	file = fopen(cpf,"r"); // Tenta abrir o arquivo para leitura

	if (file == NULL) 
  	{
    printf("O usu�rio n�o se encontra no sistema!\n");
    system("pause");
    }
	 
}

int main()
{
	int opcao=0; //Definindo v�riaveis
	int laco=1;
	char senhadigitada[10]="a";
	int comparacao;
	
	printf("### Cart�rio da EBAC ###\n\n");
	printf("Login de administrador!\n\nDigite a sua senha: ");
	scanf("%s",senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");
		
	if(comparacao == 0)
	{
		for(laco=1;laco=1;)
		{
		
			system("cls");
		
			setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
		
		
			printf("Escolha a op��o desejada no menu:\n\n"); //Inicio do menu
			printf("\t1 - Adicionar nomes\n");
			printf("\t2 - Consultar nomes\n");
			printf("\t3 - Deletar nomes\n");
			printf("\t4 - Sair do sistema\n\n");
			printf("Op��o: "); //fim do menu
		
			scanf("%d", &opcao);//Armazenando escolha
		
			system("cls");
			
			switch(opcao)
			{
				case 1:
				registro();
				break;
				
				case 2:
				consulta();
				break;
				
				case 3:
				deletar();
				break;
				
				case 4:
				printf("Obrigado por utilizar nosso sistema.");
				return 0;
				break;
				
				default:
				printf("Essa op��o n�o est� dispon�vel!\n");
				system("pause");
				break;
			}
		}
	
	}
	else
	printf("Senha incorreta!");
	
}
	


