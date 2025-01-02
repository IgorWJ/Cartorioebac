#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das string
		
int registro() //Função responsável por cadastar os usuários no sistema
{
	//início da criação de variáveis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variáveis/strings

	printf("Digite o CPF a ser cadastrado: "); //coletando informações do usuário
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); // salvo o valor da variavel
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
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);	
	
    printf("\nRegistro concluído com sucesso! Pressione ENTER para retornar ao menu...\n");

   
    while (getchar() != '\n');
    getchar();

    return 0;
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem

	//início da criação de variáveis/strings
    char cpf[40];
    char conteudo[200];
	//Fim da criação de variáveis/strings

	printf("Digite o CPF a ser consultado: "); //coletando informações do usuário
    scanf("%s", cpf); //%s refere-se a string

    FILE *file; // cria o arquivo

    file = fopen(cpf, "r");

    if(file == NULL){
	printf("Não foi possivel abrir o arquivo, não localizado!.\n\n");
    printf("Digite ENTER para continuar...\n");
    while (getchar() != '\n'); 
        getchar(); // Aguarda ENTER
        return 0; // Sai da função
    
}
    
    while(fgets(conteudo, 200, file) != NULL){
        printf("\nEssas são as informações do usuário: ");
        printf("%s", conteudo);
        printf("\n\n");
        printf("Digite ENTER para continuar...");
    }

    getchar();
    getchar();
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s", cpf);

	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");

	if (file == NULL){
		printf("O usuário não se encontra no sistema.\n");
		getchar();
		getchar();
	}

}


	
int main()
	{
	int opcao=0; //Definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{

		system("clear");

		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
			
		printf("### Cartório da EBAC ###\n\n"); //inicio do menu
		printf("Escolha a opção desejada do menu\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("\t4 - Sair do sistema\n\n");
		printf("Opção: ");//fim do menu
				
		scanf("%d", &opcao); //armazenando a escolha do usuário
		
		system("clear"); //responsável por limpar a tela
	
		switch(opcao) //inicio da seleção
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

			case 4:
			printf("Obrigado por utilizar o sistema!\n");
			return 0;
			break;
		
			default:
			printf("Essa opção não está disponivel!\n");
			getchar();
            getchar();
			break;
		} //fim da seleção
			
	}	
}