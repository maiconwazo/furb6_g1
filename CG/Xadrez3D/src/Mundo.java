
import Objetos.Jogo;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import javax.media.opengl.DebugGL;
import javax.media.opengl.GL;
import javax.media.opengl.GLAutoDrawable;
import javax.media.opengl.GLEventListener;
import javax.media.opengl.glu.GLU;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Maicon
 */
public class Mundo implements GLEventListener, KeyListener {
    private GL gl;
    private GLU glu;
    private GLAutoDrawable glDrawable;
    
    private Jogo jogo;

    public Mundo(Jogo jogo) {
        this.jogo = jogo;
    }      

    @Override
    public void init(GLAutoDrawable glad) {
        glDrawable = glad;
        gl = glad.getGL();
        glu = new GLU();
        glDrawable.setGL(new DebugGL(gl));
        gl.glClearColor(0f, 0f, 0f, 0f);
    }

    @Override
    public void display(GLAutoDrawable glad) {
        
    }

    @Override
    public void reshape(GLAutoDrawable glad, int i, int i1, int i2, int i3) {
        
    }

    @Override
    public void displayChanged(GLAutoDrawable glad, boolean bln, boolean bln1) {
        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }

    @Override
    public void keyTyped(KeyEvent e) {
        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }

    @Override
    public void keyPressed(KeyEvent e) {
        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }

    @Override
    public void keyReleased(KeyEvent e) {
        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }
    
}