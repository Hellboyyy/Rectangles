#include <windows.h>
#include <GL/glut.h>

int n = 5;
double angle = 0.0;
double delta_angle = 0.1;
double angle_mult[] = { 1.0, -2.0, 4.0, 8.0, 16.0 };
double width[] = { 0.3, 0.25, 0.2, 0.1, 0.05 };
double height[] = { 0.05, 0.05, 0.05, 0.05, 0.05 };
double color[] = { 1.0, 0.0, 0.0,
					  1.0, 1.0, 0.0,
					  0.0, 1.0, 0.0,
					  0.0, 1.0, 1.0,
					  0.0, 0.0, 1.0 };


void display() 
{
	// double r, g, b, k;
	glClear(GL_COLOR_BUFFER_BIT); 
	// glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	for (int i = 0; i < n; i++) 
	{
		/* k = (abs(((int)angle) % 360 - 180)) / 180.0;
		r = color[i * 3] * k;
		g = color[i * 3 + 1] * k;
		b = color[i * 3 + 2] * k; */
		glColor3d(color[i * 3], color[i * 3 + 1], color[i * 3 + 2]);
		if (i != 0) 
			glTranslated(width[i - 1], height[i - 1], 0.0);
		glRotated(angle*angle_mult[i], 0.0, 0.0, 1.0);
		glRectd(0.0, 0.0, width[i], height[i]);
	}

	glFinish();
	angle += delta_angle;
}

void idle() {
	glutPostRedisplay(); 
}

void keyboard(unsigned char key, int x, int y) {
	if (key == 'q') {
		exit(0);
	}
	else if (key == 'w') {
		delta_angle += 0.1;
	}
	else if (key == 's') {
		delta_angle -= 0.1;
	}
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(640, 640);
	glutCreateWindow("Hello world!");

	glutDisplayFunc(display);
	glutIdleFunc(idle);
	glutKeyboardFunc(keyboard);
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glutMainLoop();
	return 0;
}
