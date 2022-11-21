package meujogo;

import java.util.Scanner;

public class Jogo {
	private Tabuleiro tabuleiro;
	private int rodada;
	private int vez;
	private Jogador jogador1;
	private Jogador jogador2;
	public Scanner entrada = new Scanner(System.in);
	private int opcao;
	

	public Jogo() { // inicia o jogo
		while (true) {
			rodada = 1;
			vez = 1;
			tabuleiro = new Tabuleiro(); // Inicia o tabuleiro.
			iniciarJogadores(); // Inicia os jogadores.
			while (Jogar())
				;

			System.out.println("Se deseja jogar novamente aperte uma tecla para sim ou (N) para não."); // Exibe na tela a pergunta de reiniciar o jogo.
			String resposta = entrada.next(); // Recebe a respota da pergunta
			if (resposta.equalsIgnoreCase("n")) {
				System.out.println("Jogo encerrado.");
				break;
			}
		}

	}

	public void iniciarJogadores() { // mensagem de inicio para esolher o jogador
		jogador1 = new Humano(1);
		int opcao = escolherJogador();
		if (opcao == 1) {
			jogador2 = new Humano(2);
		}

		else if (opcao == 2) {
			System.out.println("Jogador VS Computador");

			int computador = escolherComputador();
			switch (computador) {
			case 1:
				jogador2 = new ComputadorA(2);
				break;
			case 2:
				jogador2 = new ComputadorB(2);
				break;
			case 3:
				jogador2 = new ComputadorC(2);
				break;
			}
		}

	}

	public int escolherJogador() { // opção para escolher qual o tipo de jogador 2
		int opcao = 0;
		do {
			try {
				System.out.println("Escolha com quem quer jogar:");
				System.out.println("1. Humano");
				System.out.println("2. Computador\n");
				opcao = entrada.nextInt();
				System.out.println();
				if (opcao != 1 && opcao != 2) {
					System.out.println("Opção invalida, escolha denovo.");
					if (opcao == 2) {

					}
				}
			} catch (Exception e) {
				entrada.next();
				System.out.println("Opção invalida, escolha denovo.");
			}
		} while (opcao != 1 && opcao != 2);
		return opcao;
	}

	public int escolherComputador() { // opção para escolher o computador
		int opcao = 0;
		do {
			try {
				System.out.println("Escolha o Computador (1, 2  ou 3):");
				opcao = entrada.nextInt();
				System.out.println();
				if (opcao != 1 && opcao != 2 && opcao != 3) {
					System.out.println("Opção invalida, escolha denovo.");
				}
			} catch (Exception e) {
				entrada.next();
				System.out.println("Opção invalida, escolha denovo.");
			}
		} while (opcao != 1 && opcao != 2 && opcao != 3);
		return opcao;
	}

	public boolean Jogar() {
		if (ganhou() == 0) {
			if (tabuleiro.tabuleiroCompleto()) { // Exibe a mensagem se o tabuleiro estiver completo
				System.out.println("Tabuleiro Completo. Jogo empatado");
				return false;
			}
			Jogador jogadorAtual; // exibe na tela qual jogador esta jogando no momento e qual tem a vez .
			String nomeDoJogador;
			if (vez() == 1) {
				jogadorAtual = jogador1;
				nomeDoJogador = "Jogador 1";
			} else {
				jogadorAtual = jogador2;
				if (jogadorAtual instanceof Computador) {
					nomeDoJogador = "Computador"; // exibe na tela com quem esta jogando
				} else {
					nomeDoJogador = "Jogador 2"; // exibe na tela com quem esta jogando
				}
			}
			System.out.println("");
			System.out.println("Rodada " + ((rodada + 1) / 2) + ", " + nomeDoJogador); // exibe na tela com quem esta
																						// jogando e em que rodada está
			jogadorAtual.jogar(tabuleiro);
			vez++;
			rodada++;
			return true;
		} else {
			if (vez() == 2) {
				System.out.println("Jogador 1 ganhou!"); // exibe na tela o ganhador
			} else {
				if (jogador2 instanceof Computador) {
					System.out.println("Computador ganhou!");
				} else {
					System.out.println("Jogador 2 ganhou!");
				}
			}
			return false;
		}
	}

	public int vez() { // evita o jogo ficar em loop separando a vez de cada um
		if (vez % 2 == 1)
			return 1;
		else
			return 2;
	}

	public int ganhou() { // checa quem ganhou
		if (tabuleiro.checaLinhas() == 1)
			return 1;
		if (tabuleiro.checaColunas() == 1)
			return 1;
		if (tabuleiro.checaDiagonais() == 1)
			return 1;
		if (tabuleiro.checaLinhas() == -1)
			return -1;
		if (tabuleiro.checaColunas() == -1)
			return -1;
		if (tabuleiro.checaDiagonais() == -1)
			return -1;
		return 0;
	}

	public int getOpcao() {
		return opcao;

	}

	public void setOpcao(int opcao) {
		this.opcao = opcao;
	}
}
