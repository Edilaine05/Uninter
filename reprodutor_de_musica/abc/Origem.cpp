#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct playerdemusica {
	float duracao;
	char musica[100];
	char artista[100];
	struct playerdemusica* proximo;
} head;

int opcao;
void cadastro();
void pesquisa();
void lista();

int main() {
	int c;
	
	
	do {
		system("cls");//menu de principal
		printf("************************************\n");
		printf("*          PLAYER DE MUSICA        *\n");
		printf("*                                  *\n");
		printf("*       @ Escolha uma Opcao @      *\n");
		printf("*                                  *\n");
		printf("* (1). Cadastrar uma nova musica.  *\n");
		printf("* (2). Pesquisar uma musica.       *\n");
		printf("* (3). Exibir lista de musicas.    *\n");
		printf("* (4). Sair.                       *\n");
		printf("*                                  *\n");
		printf("************************************\n");
		scanf_s("%d", &opcao);
		while ((c = getchar()) != '\n' && c != EOF) {}
		switch (opcao) {
		case 1:
			cadastro(); //caso a opcao 1 seja seleciona vai para parte decadastro

			break;

		case 2:
			pesquisa(); //caso a opcao 2 seja seleciona vai para parte pesquisa		
			break;
		
		case 3:
			lista();   //caso a opcao 3 seja seleciona vai para parte listagem	
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

void cadastro() { // implementa a funcao cadastro

	int cont, c;
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
		printf("Digite o nome da musica:\n");
		scanf_s("%s", &cad_atual->musica, 100); //musica tem no máximo 100 caracteres
		while ((c = getchar()) != '\n' && c != EOF) {}
		printf("Digite o nome do artista ou banda:\n");
		scanf_s("%s", &cad_atual->artista, 100); //artista tem no máximo 100 caracteres
		while ((c = getchar()) != '\n' && c != EOF) {}
		printf("Digite o duracao:\n"); 
		scanf_s("%f", &cad_atual->duracao); //recebe a duracao da musica
		printf("__________________________\n");

		ultimo_cad = cad_atual;
		ultimo_cad->proximo = NULL;

		while ((c = getchar()) != '\n' && c != EOF) {}
		printf("Deseja continuar??? \n(1)SIM e (0)NAO\n");// opcao de continuar cadrastro ou nao
		scanf_s("\n %d", &cont); 
		while ((c = getchar()) != '\n' && c != EOF) {}

		if (cont != 1) {
			break;
		}

	}
	printf("\n");
}
void pesquisa() // implementa a funcao pesquisa
{
	char artista_aux[100];
	char musica_aux[100];
	head* prox_cad;
	int op, c;

	do {
		printf("__________________________\n");
		printf("\n Digite parametro da pesquisa: \n(1) Artista ou Banda: \n(2) Nome da musica:\n(0) Para sair\n"); // faz a pesquisa por nome da banda ou artista
		scanf_s("%d", &opcao);
		printf("__________________________\n");
		while ((c = getchar()) != '\n' && c != EOF) {}
		if (opcao == 0) break;
		prox_cad = inicio_cad;
		bool achou = false;
		switch (opcao) {
		case 1:
			printf("\n Digite o nome do Artista ou Banda:\n");
			scanf_s("%s", &artista_aux, 100);
			while ((c = getchar()) != '\n' && c != EOF) {}
			
			while (prox_cad != NULL) {
				if (strcmp(prox_cad->artista, artista_aux) == NULL)
				{
					achou = true;
					printf("__________________________\n"); // exibe a musica que foi pesquisado pelo nome da banda/artista junto com seus dados
					printf("Musica encontrada :\n Musica:%s\n Artista:%s\n Duracao:%.2f\n", prox_cad->musica, prox_cad->artista, prox_cad->duracao); 
					printf("Deseja continuar a busca??? \n(1)SIM e (0)NAO\n");  //exibe na tela a opcao de continuar ou nao
					scanf_s("\n %d", &op); 
					while ((c = getchar()) != '\n' && c != EOF) {} 
					if (op == 0)return;
					break;
				}

				prox_cad = prox_cad->proximo;
				
			}
			
			if (achou == false) {
				printf("\nArtista ou banda nao cadastrada.\n");
			}

	
			break;
		case 2:
			
			// faz a pesquisa por nome da musica
			printf("\n Digite o nome da musica:\n");
			scanf_s("%s", musica_aux, 100);//não precisa de & para string
			while ((c = getchar()) != '\n' && c != EOF) {}
			while (prox_cad != NULL) {
				if (strcmp(prox_cad->musica, musica_aux) == NULL)
				{
					achou = true;
					printf("__________________________\n");// exibe a musica que foi pesquisado junto com seus dados
					printf("Musica encontrada :\n Musica:%s\n Artista:%s\n Duracao:%.2f\n", prox_cad->musica, prox_cad->artista, prox_cad->duracao);
					printf("Deseja continuar a busca??? \n(1)SIM e (0)NAO\n"); //exibe na tela a opcao de continuar ou nao
					scanf_s("\n %d", &op);
					while ((c = getchar()) != '\n' && c != EOF) {}
					if (op == 0)return;
					break;
				}
				
				prox_cad = prox_cad->proximo;
			}
			if (achou == false) {
				printf("\nMusica nao cadastrada.\n");
			}
			break;

		default:
		
			printf("\n****Opcao Invalida*****"); // caso seja escolhido uma opcao diferente exibe essa frase
			break;
		}		
		
	} while (1);

}
void lista()   //implementa a funcao lista
{
	playerdemusica* exibelista;
	head* prox_cad;
	exibelista = inicio_cad;
	int c, op;

	if (exibelista == NULL)
	{
		printf("\n Lista Vazia.\n"); //caso nao haja nada na lista ira exibir essa mensagem
		system("pause");
	}
	else
	{
		while (exibelista != NULL)
		{							// exibe os itens da lista com seus dados
			printf("\nMusica:%s\n", exibelista->musica);
			printf("Artista ou Banda:%s\n", exibelista->artista);
			printf("Duracao: %.2f\n\n",exibelista->duracao);
			exibelista = exibelista->proximo;
			
	}
		printf("Deseja retornar ao menu principal ??? \n(1)SIM e (0)NAO\n"); // da opcao de retornar o menu inicial ou encerrar 
		scanf_s("\n %d", &op);
		while ((c = getchar()) != '\n' && c != EOF) {}
		if (op == 0) exit(0);
		else
		{
			return;
		}
	}
}
