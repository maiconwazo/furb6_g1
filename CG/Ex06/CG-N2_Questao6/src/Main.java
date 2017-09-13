/// \file Exemplo_N2_Jogl_Eclipse.java
/// \brief Exemplo_N2_Jogl_Eclipse: desenha uma linha na diagonal.
/// \version $Revision: 1.0 $
/// \author Dalton Reis.
/// \date 03/05/13.
/// Obs.: variaveis globais foram usadas por questoes didaticas mas nao sao recomendas para aplicacoes reais.

import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;

import javax.media.opengl.DebugGL;
import javax.media.opengl.GL;
import javax.media.opengl.GLAutoDrawable;
import javax.media.opengl.GLEventListener;
import javax.media.opengl.glu.GLU;
import javax.swing.JOptionPane;

import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.event.MouseMotionListener;

public class Main implements GLEventListener, KeyListener, MouseListener, MouseMotionListener  {
	private float ortho2D_minX = -400.0f, ortho2D_maxX =  400.0f, ortho2D_minY = -400.0f, ortho2D_maxY =  400.0f;
	private GL gl;
	private GLU glu;
	private GLAutoDrawable glDrawable;
	private double valorX = -100, valorY = -100;
	private int antigoX, antigoY;
	private double aX = -100.0, aY = -100.00;
	private double bX = -100.0, bY = 100.00;
	private double cX = 100.0, cY = 100.00;
	private double dX = 100.0, dY = -100.00;
	private int button = 0;
	private double t;

	public void init(GLAutoDrawable drawable) {
		System.out.println(" --- init ---");
		glDrawable = drawable;
		gl = drawable.getGL();
		glu = new GLU();
		glDrawable.setGL(new DebugGL(gl));
		System.out.println("Espaco de desenho com tamanho: " + drawable.getWidth() + " x " + drawable.getHeight());
		gl.glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
		
	}
	
	//exibicaoPrincipal
	public void display(GLAutoDrawable arg0) {
		gl.glClear(GL.GL_COLOR_BUFFER_BIT);
		glu.gluOrtho2D(ortho2D_minX, ortho2D_maxX, ortho2D_minY, ortho2D_maxY);

		gl.glMatrixMode(GL.GL_MODELVIEW);
		gl.glLoadIdentity();
		
		SRU();
		 
		 // seu desenho ...
		gl.glColor3f(0.0f, 1.0f, 1.0f);
		gl.glLineWidth(3.0f);	
		gl.glBegin(GL.GL_LINE_STRIP);		 
			gl.glVertex2d(dX, dY);
			gl.glVertex2d(cX, cY);
			gl.glVertex2d(bX, bY);			
			gl.glVertex2d(aX, aY);			
			gl.glColor3f(1.0f, 1.0f, 0.0f);				
			for (t = 0.0; t < 1.0; t += 0.01) {
				gl.glVertex2d(slineBezierX(), slineBezierY());
			}
			
		 gl.glEnd();
		 if (button == 0 || button == 1 ) {
			 desenhaPonto(aX, aY);
		 }
		 if (button == 2) {
			 desenhaPonto(bX, bY);
		 }
		 if (button == 3) {
			 desenhaPonto(cX, cY);
		 }
		 if (button == 4) {
			 desenhaPonto(dX, dY);
		 }		 
		 
		 gl.glFlush();
	}	

	public void keyPressed(KeyEvent e) {
		System.out.println(" --- keyPressed ---");
		switch (e.getKeyCode()) {
		case KeyEvent.VK_1:			
				valorX = aX;
				valorY = aY;
				button = 1;
				glDrawable.display();					
			break;
		case KeyEvent.VK_2:
				valorX = bX;
				valorY = bY;
				button = 2;
				glDrawable.display();					
			break;
		case KeyEvent.VK_3:
				valorX = cX;
				valorY = cY;
				button = 3;
				glDrawable.display();					
			break;
		case KeyEvent.VK_4:
				valorX = dX;
				valorY = dY;
				button = 4;
				glDrawable.display();					
			break;
		}
		
	}

	public void reshape(GLAutoDrawable drawable, int x, int y, int width, int height) {
		System.out.println(" --- reshape ---");
	    gl.glMatrixMode(GL.GL_PROJECTION);
	    gl.glLoadIdentity();
		gl.glViewport(0, 0, width, height);
	}

	public void displayChanged(GLAutoDrawable arg0, boolean arg1, boolean arg2) {
		System.out.println(" --- displayChanged ---");
	}

	public void keyReleased(KeyEvent arg0) {
		System.out.println(" --- keyReleased ---");
	}

	public void keyTyped(KeyEvent arg0) {
		System.out.println(" --- keyTyped ---");
	}
	
	public void mouseEntered(MouseEvent e) {}
	  
	public void mouseExited(MouseEvent e) {}

	public void mousePressed(MouseEvent e) {
//	    if ((e.getModifiers() & e.BUTTON1_MASK) != 0) {
	        antigoX = e.getX();
	        antigoY = e.getY();
//	    }
	}
	    
	public void mouseReleased(MouseEvent e) {}
	    
	public void mouseClicked(MouseEvent e) {}
	    
	public void mouseDragged(MouseEvent e) {
	    int movtoX = e.getX() - antigoX;
	    int movtoY = e.getY() - antigoY;
	    
	    if (button == 0 || button == 1) {
	    	aX += movtoX;
		    aY -= movtoY;
		}
	    if (button == 2) {
	    	bX += movtoX;
		    bY -= movtoY;
	    }
	    if (button == 3) {
	    	cX += movtoX;
		    cY -= movtoY;
	    }
	    if (button == 4) {
	    	dX += movtoX;
		    dY -= movtoY;
	    }
	    
	    //Dump ...
	    System.out.println("posMouse: "+movtoX+" / "+movtoY);
	   
	    antigoX = e.getX();
		antigoY = e.getY();

		glDrawable.display();
	}
	    
	public void mouseMoved(MouseEvent e) {}

	public void SRU() {
//		gl.glDisable(gl.GL_TEXTURE_2D);
//		gl.glDisableClientState(gl.GL_TEXTURE_COORD_ARRAY);
//		gl.glDisable(gl.GL_LIGHTING); //TODO: [D] FixMe: check if lighting and texture is enabled

		// eixo x
		gl.glColor3f(1.0f, 0.0f, 0.0f);
		gl.glLineWidth(1.0f);
		gl.glBegin( GL.GL_LINES );
			gl.glVertex2f( -200.0f, 0.0f );
			gl.glVertex2f(  200.0f, 0.0f );
			gl.glEnd();
		// eixo y
		gl.glColor3f(0.0f, 1.0f, 0.0f);
		gl.glBegin( GL.GL_LINES);
			gl.glVertex2f(  0.0f, -200.0f);
			gl.glVertex2f(  0.0f, 200.0f );
		gl.glEnd();
	}
	
		
	public void desenhaPonto(double x, double y){		
		gl.glColor3f(1.0f, 0.0f, 0.0f);
		gl.glPointSize(8.0f);	
		gl.glBegin(GL.GL_POINTS);		 
			gl.glVertex2d(x, y);
		 gl.glEnd();
			
		}
	
	public void desenhaSpline(double x, double y){		
		gl.glColor3f(1.0f, 0.0f, 0.0f);
		gl.glPointSize(8.0f);	
		gl.glBegin(GL.GL_LINE_STRIP);		 
			gl.glVertex2d(x, y);
		 gl.glEnd();
			
		}
	
	public double slineBezierX(){
		return Math.pow(1-t, 3) * aX + 3 * t * Math.pow(1 - t, 2)* bX + 3 * Math.pow(t, 2) * (1-t) * cX + Math.pow(t, 3) * dX;
	}
	
	public double slineBezierY(){
		return Math.pow(1-t, 3) * aY + 3 * t * Math.pow(1 - t, 2)* bY + 3 * Math.pow(t, 2) * (1-t) * cY + Math.pow(t, 3) * dY;
	}

}
