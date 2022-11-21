package meujogo;

public class JogoDaVelha {
	private static Jogo jogo;

	public static void main(String[] args) {
		
		setjogo1(new Jogo());
	}

	public static Jogo getjogo1() {
		return jogo;
	}

	public static void setjogo1(Jogo jogo1) {
		JogoDaVelha.jogo = jogo1;
	}
}
