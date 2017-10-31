
import java.awt.Dimension;
import javax.media.opengl.GLCanvas;
import javax.media.opengl.GLCapabilities;
import javax.swing.JFrame;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Maicon
 */
public class Janela extends JFrame {

    public Janela(Mundo mundo) {
        super("Xadrez 3D");
        
        /*  Configução da tela */
        GLCapabilities caps = new GLCapabilities();
        caps.setRedBits(8);
        caps.setGreenBits(8);
        caps.setBlueBits(8);
        caps.setAlphaBits(8);
        
        GLCanvas canvas = new GLCanvas(caps);
        canvas.addGLEventListener(mundo);
        canvas.addKeyListener(mundo);
        canvas.setPreferredSize(new Dimension(800,600));
        add(canvas);
        
        pack();
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setLocationRelativeTo(null);
        setVisible(true);
    }
    
    
}
