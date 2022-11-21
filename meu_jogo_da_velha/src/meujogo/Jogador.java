package meujogo;

public abstract class Jogador { // classe jogador
	protected int[] tentativa = new int[2];
	protected int numeroDoJogador;
	protected int computador;

	public Jogador(int numeroDoJogador) {
		this.numeroDoJogador = numeroDoJogador;
	}
	
	public int getNumeroDoJogador() {
		return numeroDoJogador;
	}

	public abstract void jogar(Tabuleiro tabuleiro);

	public abstract void Tentativa(Tabuleiro tabuleiro);

	public boolean checaTentativa(int[] tentativa, Tabuleiro tabuleiro) {
		if (tabuleiro.getPosicao(tentativa) == 0)
			return true;
		else
			return false;
	}
}