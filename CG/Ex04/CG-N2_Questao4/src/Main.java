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

public class Main implements GLEventListener, KeyListener {
	private GL gl;
	private GLU glu;
	private GLAutoDrawable glDrawable;
	private Ponto4D pto1 = new Ponto4D(  0.0,   0.0, 0.0, 1.0);
	private Ponto4D pto2 = new Ponto4D(200.0, 200.0, 0.0, 1.0);
	private double fPonto1, fPonto2 = 0.0;
	private double sPonto1 = 100.0, sPonto2 = 100.0;
	private double ang = 45;
	
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

		gl.glMatrixMode(GL.GL_MODELVIEW);
		gl.glLoadIdentity();
		glu.gluOrtho2D(-400.0f, 400.0f, -400.0f, 400.0f);

		SRU();
		 
		 // seu desenho ...
		 gl.glColor3f(0.0f, 0.0f, 0.0f);
		 gl.glLineWidth(2.0f);
		 gl.glBegin(GL.GL_LINES);   
		 	gl.glVertex2d(fPonto1,fPonto2);
		 	gl.glVertex2d(sPonto1,sPonto2);
		 gl.glEnd();
		 
		
		 
		 gl.glFlush();
	}	

	public void keyPressed(KeyEvent e) {
		//System.out.println(" --- keyPressed ---");
		double raio = 0.0;
		double d1 = 0.0;
		switch (e.getKeyCode()) {
			case KeyEvent.VK_Q:
				if(fPonto1 > -200.0){
		            fPonto1 -= 10.0;
		            sPonto1 -= 10.0;
		    		glDrawable.display();
				}
			break;
			case KeyEvent.VK_W:
				if(fPonto1 < 200.0){
		            fPonto1 += 10.0;
		            sPonto1 += 10.0;
		    		glDrawable.display();
				}
			break;
			case KeyEvent.VK_A:
				raio = RetornaRaio(sPonto1, sPonto2)+10;
				sPonto1 = RetornaX(ang, raio)+fPonto1;
				sPonto2 = RetornaY(ang, raio);
				//System.out.println("-----sPonto1 retornaX: "+sPonto1);
				//System.out.println("-----sPonto2 retornaY: "+sPonto2);
				glDrawable.display();
			break;
			case KeyEvent.VK_S:
				raio = RetornaRaio(sPonto1, sPonto2)-10;
				sPonto1 = RetornaX(ang, raio)+fPonto1;
				sPonto2 = RetornaY(ang, raio);
				glDrawable.display();
			break;
			case KeyEvent.VK_Z:
				raio = RetornaRaio(sPonto1, sPonto2);
				ang+=10;
				sPonto1 = RetornaX(ang, raio)+fPonto1;
				sPonto2 = RetornaY(ang, raio);
				glDrawable.display();
			break;
			case KeyEvent.VK_X:
				raio = RetornaRaio(sPonto1, sPonto2);
				ang-=10;
				sPonto1 = RetornaX(ang, raio)+fPonto1;
				sPonto2 = RetornaY(ang, raio);
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
		//System.out.println(" --- keyReleased ---");
	}

	
	public void keyTyped(KeyEvent arg0) {
		//System.out.println(" --- keyTyped ---"+arg0.getID());
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
	
	
	public double RetornaX(double angulo, double raio) {
		return (raio * Math.cos(Math.PI * angulo / 180.0));
	}
	
	public double RetornaY(double angulo, double raio) {
		return (raio * Math.sin(Math.PI * angulo / 180.0));
	}

	public double RetornaRaio(double x1, double y1){
		double soma = 0.0;
		double v1, v2 = 0.0;
		if(fPonto1 < x1){
			v1 = x1;
			v2 = fPonto1;
		}
		else if(fPonto1 > x1){
			v1 = fPonto1;
			v2 = x1;
		}
		else{
			v1 = v2 = 0.0;
		}
		
		soma = Math.pow(v1-v2, 2) + Math.pow(y1, 2);

		double result = Math.sqrt(soma);
		//System.out.println("sPonto1: "+sPonto1+"\nfPonto1: "+fPonto1+
		//		"\nv1: "+v1+"\nv2: "+v2+"\nv1-v2: "+(v1-v2)+"\nsPonto2: "+sPonto2+"\nraio: "+result);
		return result;
	}

}
