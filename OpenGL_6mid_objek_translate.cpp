#include <iostream>

#include <GL/glew.h>
#include <GL/freeglut.h> 
//#include<math.h>
//#include"shaderClass.h"
//#include"shaderClass.cpp"
//#include"VAO.h"
//#include"VBO.h"
//#include"EBO.h"
//#include"EBO.cpp"
//#include"VAO.cpp"
//#include"VBO.cpp"

static float X = 0.0;
static float Y = 0.0;
static float Z = -15.0;

// Drawing routine.
void drawScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 0.0);

	glLoadIdentity();

	glTranslatef(0.0, 0.0, -15.0);

	////meja dosen
	//glPushMatrix();
	glScalef(4.0, 1.0, 1.0);
	//glEnable(GL_TEXTURE_GEN_S); //enable texture coordinate generation
	//glEnable(GL_TEXTURE_GEN_T);
	//glBindTexture(GL_TEXTURE_2D, theTexture[2]);
	glutSolidCube(3.0);
	//glDisable(GL_TEXTURE_GEN_S); //enable texture coordinate generation
	//glDisable(GL_TEXTURE_GEN_T);
	//glPopMatrix();

	////meja tv 1
	/*glPushMatrix();*/
	glScalef(0.5, 1.0, 1.0);
	//glEnable(GL_TEXTURE_GEN_S); //enable texture coordinate generation
	//glEnable(GL_TEXTURE_GEN_T);
	//glBindTexture(GL_TEXTURE_2D, theTexture[2]);
	glTranslatef(-4.0, 5.0, 0.0);
	glutSolidCube(3.0);
	//glDisable(GL_TEXTURE_GEN_S); //enable texture coordinate generation
	//glDisable(GL_TEXTURE_GEN_T);
	//glPopMatrix();

	glFlush();
}

// Initialization routine.
void setup(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
}

// OpenGL window reshape routine.
void resize(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-5.0, 5.0, -5.0, 5.0, 5.0, 100.0);

	glMatrixMode(GL_MODELVIEW);
}

// Keyboard input processing routine.
void keyInput(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 27:
		exit(0);
		break;
	case 'a':
		X += 0.5;
		glutPostRedisplay();
		break;
	case 'd':
		X -= 0.5;
		glutPostRedisplay();
		break;
	case 's':
		Y -= 0.5;
		glutPostRedisplay();
		break;
	case 'w':
		Y += 0.5;
		glutPostRedisplay();
		break;
	case 'q':
		Z -= 0.5;
		glutPostRedisplay();
		break;
	case 'e':
		Z += 0.5;
		glutPostRedisplay();
		break;
	default:
		break;
	}
}

// Main routine.
int main(int argc, char** argv)
{
	glutInit(&argc, argv);

	glutInitContextVersion(4, 3);
	glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("box.cpp");
	glutDisplayFunc(drawScene);
	glutReshapeFunc(resize);
	glutKeyboardFunc(keyInput);

	//glewExperimental = GL_TRUE;
	//glewInit();

	setup();

	glutMainLoop();
}
