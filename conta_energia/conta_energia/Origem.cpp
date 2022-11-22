#include <stdio.h>;
#include <stdlib.h>;
#include <math.h>;
// variaveis globais
int totalDeCadastrados = 0; // total de pessoas cadastradas
int numeroConsumidoresAcima170; // numero de consumidores que excederam 170kw
int maiorConsumo = 0; // consumidor com maior consumo
int menorConsumo = 0; // consumidor com menor consumo
int numeroDaConta[100]; // numero da conta do consumidor
float kw[100]; // kw consumidos pelo consumidor
float valorKW = 1.75; // valor fixo do kw
int main() {
	// variaveis locais
	int conta; // variavel auxiliar para entrada de um numero de conta
	int opcao; // opcao de selecao do menu
	float soma; // Valor da soma de energia da cidade
	float media; // media de energia da cidade
	while (true)
	{
		// menu de opcoes
		printf("\nMenu:\n");
		printf("[1]-Cadastrar um novo consumidor\n");
		printf("[2]-Listagem geral de valores a pagar\n");
		printf("[3]-Listagem de valor a pagar por consumidor\n");
		printf("[4]-Maior consumo\n");
		printf("[5]-Menor consumo\n");
		printf("[6]-Media da cidade\n");
		printf("[7]-Numero de consumidores que excederam 170KW\n");
		printf("[0]-Sair\n");
		printf("escolha uma opcao: ");
		scanf_s("%i", &opcao);
		switch (opcao) {
		case 1: // cadastrar novo consumidor
			printf("\nDigite o numero da conta: ");
			scanf_s("%i", &numeroDaConta[totalDeCadastrados]);
			printf("\nDigite o numero de KW consumidos: ");
			scanf_s("%f", &kw[totalDeCadastrados]);
			if (kw[totalDeCadastrados] > 170) // verifica se o consumidor consumiu mais de 170kw
			{
				numeroConsumidoresAcima170++;
			}
			if (kw[totalDeCadastrados] > kw[maiorConsumo]) // verifica se o consumido possui o maior consumo
			{
				maiorConsumo = totalDeCadastrados;
			}
			if (kw[totalDeCadastrados] < kw[menorConsumo] || totalDeCadastrados == 0) // verifica se o consumido possui omenor consumo
			{
			menorConsumo = totalDeCadastrados;
			}
			totalDeCadastrados++;
			break;
		case 2: // lista de consumidores cadastrados, kw e valores a pagar
			for (int i = 0; i < totalDeCadastrados; i++)
			{
				printf("\nConta: %i, KW consumido: %.2f, Valor a pagar R$: %.2f", numeroDaConta[i], kw[i], kw[i] * valorKW);
			}
			break;
		case 3: // kw e valor a pagar por consumidor especifico
			printf("\nDigite o numero da conta a consultar: ");
			scanf_s("%i", &conta);
			for (int i = 0; i < totalDeCadastrados; i++) // procura pelo numero da conta
			{
				if (conta == numeroDaConta[i])
				{
					printf("\nConta: %i, KW consumido: %.2f, Valor a pagar R$: %.2f", numeroDaConta[i], kw[i], kw[i] *
						valorKW);
					break;
				}
			}
			break;
		case 4: // conta com maior consumo
			printf("\nMaior consumo:");
			printf("\nConta: %i, KW consumido: %.2f, Valor a pagar R$: %.2f", numeroDaConta[maiorConsumo], kw[maiorConsumo],
				kw[maiorConsumo] * valorKW);
			break;
		case 5: // conta com menor consumo
			printf("\nMenor consumo:");
			printf("\nConta: %i, KW consumido: %.2f, Valor a pagar R$: %.2f", numeroDaConta[menorConsumo], kw[menorConsumo],
				kw[menorConsumo] * valorKW);
			break;
		case 6: // media de consumo da cidade
			soma = 0;
			for (int i = 0; i < totalDeCadastrados; i++) // calcula a soma da energia da cidade
			{
				soma = soma + kw[i];
			}
			media = soma / totalDeCadastrados; // calcula a media
			printf("\nA media de consumo foi: %.2f", media);
			break;
		case 7: // numero de consumidores que consumiram acima de 170kw
			printf("\nNumero de consumidores que excederam 170KW: %i", numeroConsumidoresAcima170);
			break;
		case 0: // encerar programa
			exit(0);
			break;
		default:
			printf("\nOpcao invalida.");
		}
		printf("\n");
		system("pause");
	}
}