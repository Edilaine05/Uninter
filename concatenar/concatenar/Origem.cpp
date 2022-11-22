#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char combinacao[40]; // variavel que recebera o resultado
// faz a junçao das duas strings
void juncao(char nome[20], int posicao, char sobrenome[20]) {
	strncpy_s(combinacao, nome, posicao);
	strcat_s(combinacao, sobrenome);
}
int main() {
	char nome[20];
	char sobrenome[20];
	int posicao;
	// entrada das variaveis
	printf("Digite seu nome:\n"); // primeira string
	gets_s(nome);
	printf("Digite seu sobrenome:\n"); // segunda string
	gets_s(sobrenome);
	printf("Digite o ultimo numero de seu RU:\n"); // posição
	scanf_s("%i", &posicao);
	juncao(nome, posicao, sobrenome);
	printf("O resultado eh: %s\n", combinacao); // imprime o resultado
	system("pause");
	return 0;
}