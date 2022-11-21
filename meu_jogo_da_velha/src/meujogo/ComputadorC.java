package meujogo;

public class ComputadorC extends Computador {

	public ComputadorC(int jogador) { //ComputadorC definição de jogdas.         
		super(jogador);
		this.numeroDoJogador = jogador;
		
	}
	
	@Override
	public void Tentativa(Tabuleiro tabuleiro) { //Implementaçao de como o ComputadorC joga
		for (int linha = 0; linha < 3; linha ++) {
			for (int coluna = 0; coluna < 3; coluna++) {
				tentativa[0] = linha;
				tentativa[1] = coluna;
				if (checaTentativa(tentativa, tabuleiro)) {
					return;
				}
			}
		}
	}

}
