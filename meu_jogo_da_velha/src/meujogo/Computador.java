package meujogo;

import java.util.Random;

public abstract class Computador extends Jogador { // Classe Computador que herda da classe Jogador e será extendida as classes filhas ComputadorA,B e C.
	

	public Computador(int jogador) {  //Define o computador.
		super(jogador);
		this.numeroDoJogador = jogador;
		
	}

	Random rand = new Random(); //Faz jogadas Randomicas.

	@Override
	public void jogar(Tabuleiro tabuleiro) {
		Tentativa(tabuleiro);
		tabuleiro.setPosicao(tentativa, numeroDoJogador);
	}

	@Override
	public abstract void Tentativa(Tabuleiro tabuleiro);
}
