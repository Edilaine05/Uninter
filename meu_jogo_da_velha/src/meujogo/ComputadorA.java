package meujogo;

public class ComputadorA extends Computador {

	public ComputadorA(int jogador) { // ComputadorA defini��o de jogdas.
		super(jogador);
		this.numeroDoJogador = jogador;

	}

	@Override
	public void Tentativa(Tabuleiro tabuleiro) {//Implementa�ao de como o ComputadorA joga
		do {
			tentativa[0] = rand.nextInt(3);
			tentativa[1] = rand.nextInt(3);
		} while (!checaTentativa(tentativa, tabuleiro));
	}

}
