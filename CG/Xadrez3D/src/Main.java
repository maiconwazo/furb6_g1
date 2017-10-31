
import Objetos.Jogo;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Maicon
 */
public class Main {
    
    public static void main(String[] args) {
        Jogo jogo = new Jogo();
        new Janela(new Mundo(jogo));
    }    
}
