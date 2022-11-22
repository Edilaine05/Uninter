#include <stdio.h>
#include <stdlib.h>
void limpaBuffer();
int main()
{
	//declaração de variaveis
	int homens;// numero de homens entrevistados
	int mulheres;// numero de mulheres entrevistadas
	int resposta_sim;// numero de pessoas que responderam sim
	int resposta_nao;// numero de pessoas que responderam não
	char resposta;// resposta sim(S) ou não(N)
	char sexo;// sexo dos entrevistados mulher(M) ou homem(H)
	int resposta_sim_mulher;//quantidade de mulheres que responderam sim
	int resposta_nao_homem;//quantidade de homens que responderam não
	int numeros_de_pessoas;//quantidade de pessoas entrevistadas
	float porc_mulheres_sim;// porcentagem de resposta sim de mulheres
	float porc_homens_nao;//porcentagem de resposta não de homens
	int entrevistados;
	//acumuladores gerais
	numeros_de_pessoas = 0;// ate 150 pessoas
	homens = 0;
	mulheres = 0;
	resposta_sim = 0;
	resposta_nao = 0;
	resposta_sim_mulher = 0;
	resposta_nao_homem = 0;
	entrevistados = 150;
	do {
		printf("Digite o seu sexo (M/H): ");
		scanf_s("%c", &sexo);
		limpaBuffer();
		printf("Gostou do produto(S/N)? ");
		scanf_s("%c", &resposta);
		limpaBuffer();
		//destinção de sexo
		if (sexo == 'H' || sexo == 'h')
		{
			homens = homens + 1;
			if (resposta == 'N' || resposta == 'n')
			{
				resposta_nao_homem = resposta_nao_homem + 1;
			}
		}
		else
		{
			if (sexo == 'M' || sexo == 'm')
			{
				mulheres = mulheres + 1;
				if (resposta == 'S' | resposta == 's') {
					resposta_sim_mulher = resposta_sim_mulher + 1;
				}
			}
		}
		//verificar resposta
		if (resposta == 's' || resposta == 'S')
		{
			resposta_sim = resposta_sim + 1;
		}
		else
		{
			if (resposta == 'n' || resposta == 'N')
			{
				resposta_nao = resposta_nao + 1;
			}
		}
		numeros_de_pessoas = numeros_de_pessoas + 1;
	} while (numeros_de_pessoas < entrevistados);
	//Calculo das porcentagens
	porc_mulheres_sim = 100 * resposta_sim_mulher / entrevistados;
	porc_homens_nao = 100 * resposta_nao_homem / entrevistados;
	//resolução
	printf("Quantidade de pessoas que responderam sim: %d \n", resposta_sim);
	printf("Quantidade de pessoas que responderam nao: %d \n", resposta_nao);
	printf("Percentual de mulheres que responderarm sim: %.2f \n", porc_mulheres_sim);
	printf("Percentual de homens que responderam nao: %.2f \n", porc_homens_nao);
	system("pause");
	return(0);
}
void limpaBuffer() {
	char c;
	while ((c = getchar()) != '\n' && c != EOF) {}
}