package meujogo;

public class ComputadorA extends Computador {

	public ComputadorA(int jogador) { // ComputadorA definição de jogdas.
		super(jogador);
		this.numeroDoJogador = jogador;

	}

	@Override
	public void Tentativa(Tabuleiro tabuleiro) {//Implementaçao de como o ComputadorA joga
		do {
			tentativa[0] = rand.nextInt(3);
			tentativa[1] = rand.nextInt(3);
		} while (!checaTentativa(tentativa, tabuleiro));
	}

}
