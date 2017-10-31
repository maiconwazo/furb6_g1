/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Objetos;

/**
 *
 * @author Maicon
 */
enum TipoPlayer  {
    PlayerUm, PlayerDois;
}

public class ObjetoPadrao {
    private final TipoPlayer tipoPlayer;
    
    /**
     *
     * @param tipoPlayer
     */
    public ObjetoPadrao(TipoPlayer tipoPlayer) {
        this.tipoPlayer = tipoPlayer;
    } 

    public TipoPlayer getTipoPlayer() {
        return this.tipoPlayer;
    }
}
