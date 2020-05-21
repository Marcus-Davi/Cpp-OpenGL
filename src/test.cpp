#include <iostream>

#include "GL/freeglut.h"
#include "GL/gl.h"

//Rotate x,y
double angle = 0;
double rY = 0;

//coordiates for the vertices
double x = 0.6;
double y = 0.6;
double z = 0.6;

void drawCube(){
		    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Reset transformations
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

//        glTranslatef(0.0, 0.0, -5.0);

        // Add an ambient light
        GLfloat ambientColor[] = {0.2, 0.2, 0.2, 1.0};
        glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientColor);

        // Add a positioned light
        GLfloat lightColor0[] = {0.5, 0.5, 0.5, 1.0};
        GLfloat lightPos0[] = {4.0, 0.0, 8.0, 1.0};
        glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor0);
        glLightfv(GL_LIGHT0, GL_POSITION, lightPos0);

 //       glTranslatef(0.5, 1.0, 0.0);
        glRotatef(angle, 1.0, 1.0, 1.0);
		glRotatef(rY,0.0,1.0,0.0);

   // glRotatef( angle, 1.0, 0.0, 1.0 );
  //  glRotatef( angle, 0.0, 1.0, 1.0 );
  //      glTranslatef(-0.5, -1.0, 0.0);

        // Create the 3D cube

    // BACK
    glBegin(GL_POLYGON);
    glColor3f(0.5, 0.3, 0.2);
    glVertex3f(x, -y, z);
    glVertex3f(x, y, z);
    glVertex3f(-x, y, z);
    glVertex3f(-x, -y, z);
    glEnd();

        // FRONT
        glBegin(GL_POLYGON);
        glColor3f(0.0, 0.5, 0.0);
        glVertex3f(-x, y, -z);
        glVertex3f(-x, -y, -z);
        glVertex3f(x, -y, -z);
        glVertex3f(x, y, -z);
        glEnd();

        // LEFT
        glBegin(GL_POLYGON);
        glColor3f(0.5, 0.5, 0.5);
        glVertex3f(-x, -y, -z);
        glVertex3f(-x, -y, z);
        glVertex3f(-x, y, z);
        glVertex3f(-x, y, -z);
        glEnd();


        // RIGHT
        glBegin(GL_POLYGON);
        glColor3f(0.0, 0.0, 0.0);
        glVertex3f(x, -y, -z);
        glVertex3f(x, -y, z);
        glVertex3f(x, y, z);
        glVertex3f(x, y, -z);
        glEnd();

        // TOP
        glBegin(GL_POLYGON);
        glColor3f(0.6, 0.0, 0.0);
        glVertex3f(x, y, z);
        glVertex3f(-x, y, z);
        glVertex3f(-x, y, -z);
        glVertex3f(x, y, -z);
        glEnd();


        // BOTTOM
        glBegin(GL_POLYGON);
        glColor3f(0.3, 0.0, 0.3);
        glVertex3f(-x, -y, -z);
        glVertex3f(-x, -y, z);
        glVertex3f(x, -y, z);
        glVertex3f(x, -y, -z);
        glEnd();

        glFlush();
    glutSwapBuffers();
}

void update(int value)
{
		angle += 5;
		if(angle > 360){
				angle -= 360;
		}

		glutPostRedisplay();
		 glutTimerFunc(25,update,0);

}
void drawTriangle(){
	
		glClearColor(0.4, 0.4,0.4, 0.4);
		glClear(GL_COLOR_BUFFER_BIT);

		glColor3f(1.0,1.0,1.0);
		glOrtho(-1.0,1.0,-1.0,1.0,-1.0,1.0);

		glBegin(GL_TRIANGLES);
		glVertex3f(-0.7,0.7,0);
		glVertex3f(0.7,0.7,0);
		glVertex3f(0,-1,0);
		glEnd();

		glFlush();
}
void keyboard(int key, int x, int y)
{
    if (key == GLUT_KEY_RIGHT)
        {
                rY += 15;
        }
    else if (key == GLUT_KEY_LEFT)
        {
                rY -= 15;
        }
    else if (key == GLUT_KEY_DOWN)
        {
                // angle -= 15;
        }
    else if (key == GLUT_KEY_UP)
        {
                // angle += 15;
        }

    // Request display update
    glutPostRedisplay();
}
void handleResize(int w,int h){
		glViewport(0,0,w,h);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		// gluPerspective(90,(double)w / (double)h,1.0,2.1);

//		gluPerspective(45.0,(double)w / (double)h,1.0,200.0);
	}
void initRendering(){
		glEnable(GL_DEPTH_TEST);
		glEnable(GL_COLOR_MATERIAL);

		glClearColor(0.7f,0.8f,1.0f,1.0f);
		glEnable(GL_LIGHTING);
		glEnable(GL_LIGHT0);
		glEnable(GL_NORMALIZE);
}
int main(int argc, char **argv){
	glutInit(&argc,argv);
//	glutInitDisplayMode(GLUT_SINGLE);
//	glutInitWindowSize(500,500);
//	glutInitWindowPosition(100,100);
//	glutCreateWindow("OpenGL - Creating a triangle!");
//	glutDisplayFunc(drawTriangle);
//	glutMainLoop();
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(700,700);
	glutInitWindowPosition(2626,100);
	glutCreateWindow("OpenGL - Rotating Cube");
	initRendering();


	glutDisplayFunc(drawCube);
	glutReshapeFunc(handleResize);
	glutSpecialFunc(keyboard);

	glutTimerFunc(5,update,0);
	glutMainLoop();
	return 0;
	
		
}
