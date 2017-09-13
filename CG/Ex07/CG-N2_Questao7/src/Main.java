/// \file Exemplo_N2_Jogl_Eclipse.java
/// \brief Exemplo_N2_Jogl_Eclipse: desenha uma linha na diagonal.
/// \version $Revision: 1.0 $
/// \author Dalton Reis.
/// \date 03/05/13.
/// Obs.: variaveis globais foram usadas por questoes didaticas mas nao sao recomendas para aplicacoes reais.

import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.event.MouseMotionListener;

import javax.media.opengl.DebugGL;
import javax.media.opengl.GL;
import javax.media.opengl.GLAutoDrawable;
import javax.media.opengl.GLEventListener;
import javax.media.opengl.glu.GLU;

public class Main implements GLEventListener, KeyListener, MouseListener, MouseMotionListener {
	private GL gl;
	private GLU glu;
	private GLAutoDrawable glDrawable;
	private Point4D pto1 = new Point4D(29.28, 29.28, 0.0, 1.0);
	private Point4D pto2 = new Point4D(170.171, 170.171, 0.0, 1.0);
	
	private int raioMe = 40;
	private int raioMa = 100;
	private int antigoX, antigoY = 0;
	private double valorX = 100.0, valorY = 100.0;
	private boolean pintabBox = false;
	private boolean limite = false;
	
	private BoundingBox bBox = new BoundingBox(pto1.GetX(),pto1.GetY(),pto1.GetZ(),pto1.GetX(),pto1.GetY(),pto1.GetZ());

	public void init(GLAutoDrawable drawable) {
		System.out.println(" --- init ---");
		glDrawable = drawable;
		gl = drawable.getGL();
		glu = new GLU();
		glDrawable.setGL(new DebugGL(gl));
		System.out.println("Espaco de desenho com tamanho: " + drawable.getWidth() + " x " + drawable.getHeight());
		gl.glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
		
		bBox.atualizarBBox(pto2);
		bBox.processarCentroBBox();
	}
	
	//exibicaoPrincipal
	public void display(GLAutoDrawable arg0) {
		gl.glClear(GL.GL_COLOR_BUFFER_BIT);
		glu.gluOrtho2D(-100.0f, 300.0f, -100.0f, 300.0f);

		gl.glMatrixMode(GL.GL_MODELVIEW);
		gl.glLoadIdentity();

		SRU();
		 
		 // seu desenho ...
		 gl.glColor3f(0.0f, 0.0f, 0.0f);
		 gl.glLineWidth(1.5f);
		 
		 gl.glBegin(GL.GL_LINE_LOOP);		 
		 	for (int i = 0; i < 180; i++) {
				gl.glVertex2d(RetornaX(i*2, raioMa)+100, RetornaY(i*2, raioMa)+100);
			}
		 gl.glEnd();
		 gl.glBegin(GL.GL_LINE_LOOP);
		 	for (int i = 0; i < 180; i++) {
				gl.glVertex2d(RetornaX(i*2, raioMe)+valorX, RetornaY(i*2, raioMe)+valorY);
			}
		 gl.glEnd();
		 gl.glPointSize(6.0f);
		 gl.glBegin(GL.GL_POINTS);
			gl.glVertex2d(valorX, valorY);
		 gl.glEnd();
		 
		 gl.glLineWidth(2.0f);		 

		 if(pintabBox){
			 gl.glColor3f(1.0f, 1.0f, 0.0f);
			 pintabBox = false;
		 }
		 else
			 gl.glColor3f(0.93f, 0.5f, 0.93f);
		 
		 if(limite){
			gl.glColor3f(0.0f, 1.0f, 1.0f); 
		 }
		 
		 bBox.desenharOpenGLBBox(gl); 
		 
		 gl.glFlush();
	}	

	private void recalculaBBox () {
		bBox.atribuirBoundingBox(pto1.GetX(), pto1.GetY(), pto1.GetZ(), pto2.GetX(), pto2.GetY(), pto2.GetZ());
		bBox.atualizarBBox(pto2);
		bBox.processarCentroBBox();
	}

	public void keyPressed(KeyEvent e) {}

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

	public void mouseDragged(MouseEvent e) {
		// TODO Auto-generated method stub
		
		int movtoX = e.getX() - antigoX;
	    int movtoY = e.getY() - antigoY;
	    valorX += movtoX;
	    valorY -= movtoY;
	    if(cantosbBox(valorX, valorY)){
	 	    pintabBox = true;
	    }
	    else if(valorX > bBox.obterMaiorX() || valorX < bBox.obterMenorX()){
	    	pintabBox = true;
	    }
	    else if(valorY > bBox.obterMaiorY() || valorY < bBox.obterMenorY()){
	    	pintabBox = true;
	    }
	    
//	    //Dump ...
//	    System.out.println("posMouse: "+movtoX+" / "+movtoY);
	    antigoX = e.getX();
		antigoY = e.getY();
		
		double d = Math.pow((valorX - 100), 2) + Math.pow((valorY - 100), 2);
		if(d <= Math.pow(raioMa, 2)){
			glDrawable.display();
			limite = false;
		}
		else{
			valorX -= movtoX;
			valorY += movtoY;
			limite = true;			
		}
		
	}

	private boolean cantosbBox(double x, double y){
		if(x >= bBox.obterMaiorX() && y >= bBox.obterMaiorY())
			return true;
		else if(x >= bBox.obterMaiorX() && y <= bBox.obterMenorY())
			return true;
		else if(x <= bBox.obterMenorX() && y <= bBox.obterMenorY())
			return true;
		else if(x <= bBox.obterMenorX() && y >= bBox.obterMaiorY())
			return true;
		else 
			return false;
	}
	
	public void mouseMoved(MouseEvent arg0) {}

	public void mouseClicked(MouseEvent arg0) {}

	public void mouseEntered(MouseEvent arg0) {}

	public void mouseExited(MouseEvent arg0) {}

	public void mousePressed(MouseEvent e) {
		antigoX = e.getX();
        antigoY = e.getY();
        
	}

	public void mouseReleased(MouseEvent arg0) {
		valorX = valorY = 100.0;
		limite = pintabBox = false;
		glDrawable.display();
	}
	
	public double RetornaX(double angulo, double raio) {
		return (raio * Math.cos(Math.PI * angulo / 180.0));
	}
	
	public double RetornaY(double angulo, double raio) {
		return (raio * Math.sin(Math.PI * angulo / 180.0));
	}

}
