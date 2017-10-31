/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Objetos;

import java.util.ArrayList;

/**
 *
 * @author Maicon
 */
public class Jogo {
    private final ArrayList<ObjetoPadrao> listaDePecas;

    public Jogo() {
        this.listaDePecas = new ArrayList<>();
        
        for (int i = 0; i < 8; i++) {
            this.listaDePecas.add(new Peao(TipoPlayer.PlayerUm));
            this.listaDePecas.add(new Peao(TipoPlayer.PlayerDois));
        }
    }     
}
