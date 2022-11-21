package meujogo;

import java.util.Scanner;

public class Humano extends Jogador { //Classe Humano que herda da classe Jogador
	public Scanner entrada = new Scanner(System.in);

	public Humano(int jogador) {
		super(jogador);
		this.numeroDoJogador = jogador;

	}

	@Override
	public void jogar(Tabuleiro tabuleiro) {
		
		Tentativa(tabuleiro);
		tabuleiro.setPosicao(tentativa, numeroDoJogador);
	}

	@Override
	public void Tentativa(Tabuleiro tabuleiro) {
		
		do {
			do {
				try { //impede que exception aconteça
					System.out.print("Linha: ");
					tentativa[0] = entrada.nextInt();
					if (tentativa[0] > 3 || tentativa[0] < 1) //Checa se foi digitado uma opçao valida para linha.
						System.out.println("Linha inválida. É 1, 2 ou 3"); //exibe na tela quando a opçao digitada não é valida.
				} catch (Exception e) { //impede que exception aconteça
					try { //impede que exception aconteça
						entrada.next();
					} catch (Exception e1) { //impede que exception aconteça
						
					}
					System.out.println("Linha inválida. É 1, 2 ou 3");
				}
			} while (tentativa[0] > 3 || tentativa[0] < 1);
			do {
				try {
					System.out.print("Coluna: ");
					tentativa[1] = entrada.nextInt();
					if (tentativa[1] > 3 || tentativa[1] < 1) //Checa se foi digitado uma opçao valida para coluna.
						System.out.println("Coluna inválida. É 1, 2 ou 3"); //exibe na tela quando a opçao digitada não é valida.
				} catch (Exception e) {
					try {
						entrada.next();
					} catch (Exception e1) {
						
					}
					System.out.println("Coluna inválida. É 1, 2 ou 3");
				}
			} while (tentativa[1] > 3 || tentativa[1] < 1);
			tentativa[0]--;
			tentativa[1]--;
			if (!checaTentativa(tentativa, tabuleiro)) // para checar se o local onde será feita a jogada esta livre.
				System.out.println("Esse local já foi marcado. Tente  outro.");
		} while (!checaTentativa(tentativa, tabuleiro));
	}
}
