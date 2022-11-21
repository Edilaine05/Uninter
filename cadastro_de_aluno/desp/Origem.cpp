#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct aluno {
	int alunos;
	int ru;
	char nome[60];
	char email[100];
	struct aluno* proximo ;
} head;

int opcao;
void cadastro();
void pesquisa();
void lista();
void alunoprecad();

int main() {
	int c;
	do {
		system("cls");
		printf("**********************************\n");
		printf("*   CADASTRO DE ALUNOS           *\n");
		printf("*                                *\n");
		printf("* @ Escolha uma Opcao @          *\n");
		printf("*                                *\n");
		printf("* (1). Cadastrar Aluno.          *\n");
		printf("* (2). Pesquisar Aluno.          *\n");
		printf("* (3). Exibir lista de Alunos    *\n");
		printf("* (4). Sair.                     *\n");
		printf("*                                *\n");
		printf("**********************************\n");
		scanf_s("%d", &opcao);
		while ((c = getchar()) != '\n' && c != EOF) {}
		switch (opcao) {
		case 1:
			cadastro(); //caso a opcao 1 seja seleciona vai para parte de cadastro

			break;

		case 2:
			pesquisa(); //caso a opcao 2 seja seleciona vai para parte pesquisa
	
			break;
		case 3:
			lista(); //caso a opcao 3 seja seleciona vai para parte listagem

			break;
		case 4:
			system("exit"); //caso a opcao 4 seja seleciona o progama encerra

			break;
		default:
			printf("Opcao Invalida...\n"); //caso a opcao selecionada seja deferende de 1,2,3 ou 4 exibe essa mensagem
			system("pause");
			
			break;
		}

	} while (opcao != 4);


	return true;
}

head* inicio_cad = NULL; // Declara essa variavel global que ira armazenar o inicio da lista encadeada
head* ultimo_cad = NULL; // Declara essa variavel global que ira armazenar o ultimo da lista encadeada

void cadastro() // implementa a funcao cadastro
{

	int cont,c;
	head* cad_atual;

	while (1) {
		cad_atual = (head*)malloc(sizeof(head));
		cad_atual->proximo = NULL;

		if (inicio_cad == NULL) {
			inicio_cad = cad_atual;
			if (inicio_cad == NULL) exit(1);
		}

		if (ultimo_cad != NULL) {
			ultimo_cad->proximo = cad_atual;
		}

		printf("__________________________\n");
		printf("INICIANDO CADASTRO:\n\n");
		printf("Digite o RU:"); //Recebe RU do aluno
		scanf_s("%d", &cad_atual->ru);
		while ((c = getchar()) != '\n' && c != EOF) {}
		printf("Digite o Nome:");
		scanf_s("%s", &cad_atual->nome, 60); //Nome tem no máximo 60 caracteres
		while ((c = getchar()) != '\n' && c != EOF) {}
		printf("Digite o email:");
		scanf_s("%s", &cad_atual->email, 100); //Email tem no máximo 100 caracteres
		
		ultimo_cad = cad_atual; //Salva os itens cadastrados antes de sair
		ultimo_cad->proximo = NULL;

		while ((c = getchar()) != '\n' && c != EOF) {}
		printf("Deseja continuar??? \n(1)SIM e (0)NAO\n"); //opcao de continuar cadrastro ou nao
		scanf_s("\n %d", &cont);
		while ((c = getchar()) != '\n' && c != EOF) {}
		
		if (cont == 0) {
			break;
		}
	
	}
	printf("\n");
}
void pesquisa() // implementa a funcao pesquisa
{
	int ru_aux, c;
	char nome_aux[60];
	head* prox_cad;
	int op;
	
	do {
		printf("__________________________\n");
		printf("\n Digite parametro da pesquisa: \n(1) RU: \n(2) Nome:\n(0) para sair\n");
		scanf_s("%d", &opcao);
		printf("__________________________\n");
		while ((c = getchar()) != '\n' && c != EOF) {}
		if (opcao == 0) break;
		prox_cad = inicio_cad;
		bool achou = false;
		switch (opcao) {
		case 1:
			// faz a pesquisa por RU do aluno
			printf("\n Digite o RU do Aluno:\n");
			scanf_s("%d", &ru_aux);
			while ((c = getchar()) != '\n' && c != EOF) {}
			while (prox_cad != NULL) {
				if (prox_cad->ru == ru_aux)
				{
					achou = true;
					printf("__________________________\n"); //exibe o aluno que foi pesquisado pelo RU junto com seus dados
					printf("Aluno encontrado :\n RU: %d\n Nome:%s\n Email:%s\n", prox_cad->ru, prox_cad->nome, prox_cad->email);
					printf("Deseja continuar a busca??? \n(1)SIM e (0)NAO\n");
					scanf_s("\n %d", &op);
					while ((c = getchar()) != '\n' && c != EOF) {}
					if (op == 0)return;
					break;
				}
				
				prox_cad = prox_cad->proximo;

			}
			if (achou == false) {
				printf("\nAluno nao cadastrado.\n");

			}
			break;
		case 2:
			// faz a pesquisa por nome do aluno
			printf("\n Digite o nome do Aluno:");
			scanf_s("%s", nome_aux, 60);//não precisa de & para string
			while ((c = getchar()) != '\n' && c != EOF) {}
			while (prox_cad != NULL) {
				if (strcmp(prox_cad->nome, nome_aux) == NULL)
				{ 
					achou = true;
					printf("__________________________\n"); //exibe o aluno que foi pesquisado pelo nome junto com seus dados
					printf("Aluno encontrado : \n RU : %d\n Nome : % s\n Email : % s\n", prox_cad->ru, prox_cad->nome, prox_cad->email);
					printf("Deseja continuar a busca??? \n(1)SIM e (0)NAO\n");
					scanf_s("\n %d", &op);
					while ((c = getchar()) != '\n' && c != EOF) {}
					if (op == 0)return;

					break;
				}
				
				prox_cad = prox_cad->proximo;	
				
				
			}
			if (achou == false) {
				printf("\nAluno nao cadastrado.\n");

			}
			break;

		default:
			printf("\n****Opcao Invalida*****"); // caso seja escolhido uma opcao diferente exibe essa frase
			break;
		}
	} while (1);

}void lista() //implementa a funcao lista
{
	aluno* exibelista;
	head* prox_cad;
	exibelista = inicio_cad;
	int c, op;

	if (exibelista == NULL)
	{
		printf("\n Lista Vazia.\n"); //caso nao haja nada na lista ira exibir essa mensagem
		printf("Deseja retornar ao menu??? \n(1)SIM e (0)NAO\n");
		scanf_s("\n %d", &op);
		while ((c = getchar()) != '\n' && c != EOF) {}
		if (op == 0) exit(0);
		else
		{
			return;
		}
	}
	
	else
	{
		while (exibelista != NULL)
		{ // exibe os itens da lista com seus dados
			printf("\nRu:%d\n", exibelista->ru);
			printf("Nome:%s\n", exibelista->nome);
			printf("Email:%s\n\n", exibelista->email);
			
			exibelista = exibelista->proximo;

		}
		printf("Deseja retornar ao menu??? \n(1)SIM e (0)NAO\n"); // da opcao de retornar o menu inicial ou encerrar 
		scanf_s("\n %d", &op);
		while ((c = getchar()) != '\n' && c != EOF) {}
		if (op == 0) exit(0);
		else
		{
			return;
		}
	}
}
