#include<stdio.h>
#include<stdlib.h>
int main() {
	int matriz[10][10]; // matriz que ira receber os valores
	int linhas; // numero de linhas e colunas da matriz
	int soma; // soma dos elementos da matriz
	int referencia; // salva o valor para comparacao
	bool magico; // Indica se o quadrado eh magico ou nao
	printf("Digite um valor para numero de linhas e colunas: ");
	scanf_s("%i%*c", &linhas); // recebe a quantidade de linhas e colunas da matriz
	// entrada de dados da matriz
	for (int l = 0; l < linhas; l++)
	{
		for (int c = 0; c < linhas; c++) {
			printf("\nDigite um valor para linha[%i], coluna[%i]: ", l, c);
			scanf_s("%i%*c", &matriz[l][c]);
		}
	}
	printf("Matriz\n");
	// imprime os elementos da matriz
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++)
		{
			printf("%d\t", matriz[i][j]);
			
		}
		printf("\n");
	}
	printf("******************\n");
	magico = true;
	// Faz a soma de cada uma das linhas da matriz
	for (int i = 0; i < 3; i++)
	{
		soma = 0;
		for (int j = 0; j < 3; j++)
		{
			soma += matriz[i][j];
		}
		if (i == 0) // Salva o valor da primeira linha para comparar com as demais linhas, colunas e diagonais
		{
			referencia = soma;
		}
		if (referencia != soma) // verifica se os valores sao iguais
		{
			magico = false;
		}
	}
	// Faz a soma de cada uma das colunas da matriz
	for (int i = 0; i < 3; i++)
	{
		soma = 0;
		for (int j = 0; j < 3; j++)
		{
			soma += matriz[j][i];
		}
		if (referencia != soma) // verifica se os valores sao iguais
		{
			magico = false;
		}
	}
	// Faz a soma da diagonal principal da matriz
	soma = 0;
	for (int i = 0; i < 3; i++)
	{
		soma += matriz[i][i];
	}
	if (referencia != soma) // verifica se os valores sao iguais
	{
		magico = false;
	}
	// Faz a soma da diagonal secundaria da matriz
	soma = 0;
	for (int i = 0; i < 3; i++)
	{
		soma += matriz[2 - i][i];
	}
	if (referencia != soma) // verifica se os valores sao iguais
	{
		magico = false;
	}
	// Imprime o resultado
	if (magico == true) {
		printf("Sua matriz eh um quadrado magico\n");
	}
	else {
		printf("Sua matriz nao eh um quadrado magico\n");
	}
	system("pause");
}