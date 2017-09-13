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
import javax.swing.JFrame;

public class Main implements GLEventListener, KeyListener {
	private float ortho2D_minX = -400.0f, ortho2D_maxX =  400.0f, ortho2D_minY = -400.0f, ortho2D_maxY =  400.0f;
	private GL gl;
	private GLU glu;
	private GLAutoDrawable glDrawable;
	private double valorX = 0.0;
	private double[] p1 = {-200.0, 200.0};
	private double[] p2 = {200.0, 200.0};
	private double[] p3 = {-200.0, -200.0};
	private double[] p4 = {200.0, -200.0};
	private int nprimitivas = 0;
	private int[] primitivas = {GL.GL_POINTS,  GL.GL_LINES,  GL.GL_LINE_LOOP,  
			GL.GL_LINE_STRIP,  GL.GL_TRIANGLES,  GL.GL_TRIANGLE_FAN,  
			GL.GL_TRIANGLE_STRIP,  GL.GL_QUADS, GL.GL_QUAD_STRIP, GL.GL_POLYGON};
	private JFrame frame;
	
	public Main(JFrame frame){
		this.frame = frame;
	}
	
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
		 
		 gl.glLineWidth(3.0f);
		 gl.glPointSize(4.0f);
		 
		 int pr = primitivas[nprimitivas];
		 gl.glBegin(pr);
		 	switch (pr) {
			case GL.GL_POINTS:
				gl.glColor3f(1.0f, 1.0f, 0.0f);
				gl.glVertex2d(p1[0], p1[1]);
				gl.glColor3f(0.0f, 1.0f, 0.0f);
				gl.glVertex2d(p2[0], p2[1]);
				gl.glColor3f(1.0f, 0.0f, 1.0f);
				gl.glVertex2d(p3[0], p3[1]);
				gl.glColor3f(1.0f, 0.0f, 0.0f);
				gl.glVertex2d(p4[0], p4[1]);
				frame.setTitle("CG-N2_Questao5 - GL_POINTS");
			break;
			
			case GL.GL_LINES:
				gl.glColor3f(1.0f, 1.0f, 0.0f);
				gl.glVertex2d(p1[0], p1[1]);
				gl.glColor3f(1.0f, 0.0f, 1.0f);
				gl.glVertex2d(p3[0], p3[1]);
				gl.glColor3f(0.0f, 1.0f, 0.0f);
				gl.glVertex2d(p2[0], p2[1]);
				gl.glColor3f(1.0f, 0.0f, 0.0f);
				gl.glVertex2d(p4[0], p4[1]);
				frame.setTitle("CG-N2_Questao5 - GL_LINES");
			break;
			
			case GL.GL_LINE_LOOP:
				gl.glColor3f(1.0f, 1.0f, 0.0f);
				gl.glVertex2d(p1[0], p1[1]);
				gl.glColor3f(0.0f, 1.0f, 0.0f);
				gl.glVertex2d(p2[0], p2[1]);
				gl.glColor3f(1.0f, 0.0f, 0.0f);
				gl.glVertex2d(p4[0], p4[1]);
				gl.glColor3f(1.0f, 0.0f, 1.0f);
				gl.glVertex2d(p3[0], p3[1]);
				gl.glColor3f(1.0f, 1.0f, 0.0f);
				gl.glVertex2d(p1[0], p1[1]);
				frame.setTitle("CG-N2_Questao5 - GL_LINE_LOOP");
			break;
			
			case GL.GL_LINE_STRIP:
				gl.glColor3f(1.0f, 1.0f, 0.0f);
				gl.glVertex2d(p1[0], p1[1]);
				gl.glColor3f(0.0f, 1.0f, 0.0f);
				gl.glVertex2d(p2[0], p2[1]);
				gl.glColor3f(1.0f, 0.0f, 0.0f);
				gl.glVertex2d(p4[0], p4[1]);
				gl.glColor3f(1.0f, 0.0f, 1.0f);
				gl.glVertex2d(p3[0], p3[1]);
				frame.setTitle("CG-N2_Questao5 - GL_LINE_STRIP");
			break;
			
			case GL.GL_TRIANGLES:
				gl.glColor3f(1.0f, 1.0f, 0.0f);
				gl.glVertex2d(p1[0], p1[1]);
				gl.glColor3f(0.0f, 1.0f, 0.0f);
				gl.glVertex2d(p2[0], p2[1]);
				gl.glColor3f(1.0f, 0.0f, 1.0f);
				gl.glVertex2d(p3[0], p3[1]);
				gl.glColor3f(1.0f, 1.0f, 0.0f);
				gl.glVertex2d(p1[0], p1[1]);
				frame.setTitle("CG-N2_Questao5 - GL_TRIANGLES");
			break;
			
			case GL.GL_TRIANGLE_FAN:
				gl.glColor3f(1.0f, 1.0f, 0.0f);
				gl.glVertex2d(p1[0], p1[1]);
				gl.glColor3f(1.0f, 0.0f, 1.0f);
				gl.glVertex2d(p3[0], p3[1]);
				gl.glColor3f(1.0f, 0.0f, 0.0f);
				gl.glVertex2d(p4[0]-100, p4[1]+100);
				gl.glColor3f(0.0f, 1.0f, 0.0f);
				gl.glVertex2d(p2[0]-30, p2[1]-30);
				frame.setTitle("CG-N2_Questao5 - GL_TRIANGLE_FAN");
			break;
			
			case GL.GL_TRIANGLE_STRIP:
				gl.glColor3f(1.0f, 1.0f, 0.0f);
				gl.glVertex2d(p1[0], p1[1]);
				gl.glColor3f(1.0f, 0.0f, 1.0f);
				gl.glVertex2d(p3[0], p3[1]);
				gl.glColor3f(0.0f, 1.0f, 0.0f);
				gl.glVertex2d(p2[0], p2[1]);
				gl.glColor3f(1.0f, 1.0f, 0.0f);
				gl.glVertex2d(p1[0], p1[1]);
				gl.glColor3f(1.0f, 0.0f, 0.0f);
				gl.glVertex2d(p4[0], p4[1]);
				frame.setTitle("CG-N2_Questao5 - GL_TRIANGLE_STRIP");
			break;
			
			case GL.GL_QUADS:
				gl.glColor3f(1.0f, 1.0f, 0.0f);
				gl.glVertex2d(p1[0], p1[1]);
				gl.glColor3f(0.0f, 1.0f, 0.0f);
				gl.glVertex2d(p2[0], p2[1]);
				gl.glColor3f(1.0f, 0.0f, 0.0f);
				gl.glVertex2d(p4[0], p4[1]);
				gl.glColor3f(1.0f, 0.0f, 1.0f);
				gl.glVertex2d(p3[0], p3[1]);
				gl.glColor3f(1.0f, 1.0f, 0.0f);
				gl.glVertex2d(p1[0], p1[1]);
				frame.setTitle("CG-N2_Questao5 - GL.GL_QUADS");
			break;
			
			case GL.GL_QUAD_STRIP:
				gl.glColor3f(1.0f, 1.0f, 0.0f);
				gl.glVertex2d(p1[0], p1[1]);
				gl.glColor3f(0.0f, 1.0f, 0.0f);
				gl.glVertex2d(p2[0], p2[1]);
				gl.glColor3f(1.0f, 0.0f, 1.0f);
				gl.glVertex2d(p3[0]+150, p3[1]+150);
				gl.glColor3f(1.0f, 0.0f, 0.0f);
				gl.glVertex2d(p4[0]-150, p4[1]+150);
				gl.glColor3f(0.0f, 1.0f, 1.0f);
				gl.glVertex2d(p3[0], p3[1]);
				gl.glColor3f(1.0f, 1.0f, 0.0f);
				gl.glVertex2d(p4[0], p4[1]);
				frame.setTitle("CG-N2_Questao5 - GL.GL_QUAD_STRIP");
			break;
			
			case GL.GL_POLYGON:
				gl.glColor3f(1.0f, 1.0f, 0.0f);
				gl.glVertex2d(p1[0]+100, p1[1]);
				gl.glColor3f(0.0f, 1.0f, 0.0f);
				gl.glVertex2d(p2[0]-100, p2[1]);
				gl.glColor3f(1.0f, 0.0f, 1.0f);
				gl.glVertex2d(p4[0], 0.0);
				gl.glColor3f(1.0f, 0.0f, 0.0f);
				gl.glVertex2d(p4[0]-100, p4[1]);
				gl.glColor3f(0.0f, 1.0f, 1.0f);
				gl.glVertex2d(p3[0]+100, p3[1]);
				gl.glColor3f(1.0f, 1.0f, 0.0f);
				gl.glVertex2d(p3[0], 0.0);
				frame.setTitle("CG-N2_Questao5 - GL.GL_POLYGON");
			break;
			
			default:
				break;
			}
		 gl.glEnd();

		 gl.glFlush();
	}	

	@Override
	public void keyPressed(KeyEvent e) {
		switch (e.getKeyCode()) {
			case KeyEvent.VK_SPACE:
	            if(nprimitivas == 9)
	            	nprimitivas = 0;
	            else
	            	nprimitivas++;
	            
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

	@Override
	public void keyReleased(KeyEvent arg0) {
		System.out.println(" --- keyReleased ---");
	}

	@Override
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




}
