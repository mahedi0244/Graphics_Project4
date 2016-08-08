#ifdef __APPLE_CC__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

GLfloat pos[] = {-2, 4, 5, 1};
GLfloat amb[] = {0.3, 0.3, 0.3, 1};
GLfloat front_amb_diff[] = {0.7, 0.5, 0.1, 1.0};
GLfloat back_amb_diff[] = {0.4, 0.7, 0.1, 1.0};
GLfloat spe[] = {0.25, 0.25, 0.25, 1.0};
GLfloat theta = 0;
GLfloat dt = 0.5;
GLfloat axes[3][3] = {{1, 0, 0}, {0,1,0}, {0, 0, 1}};
int axis = 0;


//rotating torus
//void display (void){
//    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//    glPushMatrix();
//    glRotated(theta, axes[axis][0], axes[axis][1], axes[axis][2]);
//    glutSolidTorus(0.1, 0.5, 50, 100);
//    glPopMatrix();
//    glutSwapBuffers();
//}


//sun, earth and moon
void display(void){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    //big sphere
    glutSolidSphere(0.4, 48, 48);
    glPushMatrix();

    
    //only big torus as there is pop here
    glPushMatrix();
    glRotated(theta, 1, 0, 0);
    glutSolidTorus(0.005, 0.5, 50, 100);
    glPopMatrix();
    
    //medium and small
    glRotated(theta, 0, 0, 1);
    glTranslated(1.35, 0, 0);
    glutSolidSphere(0.18, 48, 48);
    glPushMatrix();
    
    //small sphere
    glRotated(theta, 0, 0, 1);
    glTranslated(0.4, 0, 0);
    glutSolidSphere(0.1, 48, 48);
    
    glPopMatrix();
    glPopMatrix();
    glutSwapBuffers();
}


void idle(void){
    if(theta >= 360)
        axis = (axis+1)%3;
    
    theta = (theta < 360) ? theta + dt : dt;
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(200, 100);
    glutCreateWindow("GLUT Objects");
    glClearColor(0.0, 0.0, 0.0, 0.0);
    
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45, 1.0, 2, 8);
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, front_amb_diff);
    glMaterialfv(GL_BACK, GL_AMBIENT_AND_DIFFUSE, front_amb_diff);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, spe);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 75);
    glLightfv(GL_LIGHT0, GL_AMBIENT, amb);
    glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslated(0, 0, -5);
    
    glLightfv(GL_LIGHT0, GL_POSITION, pos);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glutDisplayFunc(display);
    glutIdleFunc(idle);
    glutMainLoop();
    
}











