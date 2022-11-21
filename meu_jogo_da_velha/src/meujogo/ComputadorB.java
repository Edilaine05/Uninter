package meujogo;

public class ComputadorB extends Computador {

	public ComputadorB(int jogador) { //ComputadorB definição de jogdas.      
		super(jogador);
		this.numeroDoJogador = jogador;
		
	}
	
	@Override
	public void Tentativa(Tabuleiro tabuleiro) { //Implementaçao de como o ComputadorB joga
		do {
			tentativa[1] = rand.nextInt(3);
            tentativa[0] = rand.nextInt(3);
		} while (!checaTentativa(tentativa, tabuleiro));
	}

}
