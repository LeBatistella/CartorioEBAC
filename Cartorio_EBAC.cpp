#include <stdio.h> //biblioteca de comunicação com usuário
#include <stdlib.h> //biblioteca de alocação de espaço de memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável por cuidar de string

int registro()// Responsavel por cadastrar usuários
{
	//inicio criação de variáveis/strings
    char arquivo[40];//cria o arquivo com nome cpf
	char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    
    printf("Digite o CPF a ser cadastrado: ");
    scanf("%s", cpf);
    
    strcpy(arquivo, cpf); //Responsável por copiar os valores das string arquivo=cpf
    
    FILE *file; // Cria o arquivo função do sistema
    file = fopen(arquivo, "w"); //Escrever um arquivo novo
    fprintf(file,cpf); // salva o valor da variável
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
   		printf("Não foi localizado este cadastro!\n");	
	}
	
	while(fgets(conteudo, 200,file) != NULL) // Busca do usuário até 200 e no arquivo file
	{
			printf("\nEssas são as informações do usuário: ");
			printf("%s",conteudo);
			printf("\n\n");
	}
   	
    system("pause");
}

int deletar()
{
    char cpf[40];
    
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf);

	remove(cpf);

	FILE *file;
  	file = fopen(cpf,"r"); // Tenta abrir o arquivo para leitura

	if (file == NULL) 
  	{
    printf("O usuário não se encontra no sistema!\n");
    system("pause");
    }
	 
}

int main()
{
	int opcao=0; //Definindo váriaveis
	int laco=1;
	char senhadigitada[10]="a";
	int comparacao;
	
	printf("### Cartório da EBAC ###\n\n");
	printf("Login de administrador!\n\nDigite a sua senha: ");
	scanf("%s",senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");
		
	if(comparacao == 0)
	{
		for(laco=1;laco=1;)
		{
		
			system("cls");
		
			setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
		
		
			printf("Escolha a opção desejada no menu:\n\n"); //Inicio do menu
			printf("\t1 - Adicionar nomes\n");
			printf("\t2 - Consultar nomes\n");
			printf("\t3 - Deletar nomes\n");
			printf("\t4 - Sair do sistema\n\n");
			printf("Opção: "); //fim do menu
		
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
				printf("Essa opção não está disponóvel!\n");
				system("pause");
				break;
			}
		}
	
	}
	else
	printf("Senha incorreta!");
	
}
	


