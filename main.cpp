#ifdef __APPLE_CC__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

GLfloat pos[] = {-2, 4, 5, 1};
GLfloat amb[] = {0.3, 0.3, 0.3, 1};
GLfloat front_amb_diff[] = {0.5, 0.5, 0.1, 1.0};
GLfloat red[] = {1.0, 0, 0, 1.0};
GLfloat green[] = {0, 0.5, 0, 1.0};
GLfloat blue[] = {0, 0, 1.0, 1.0};
GLfloat white[] = {1.0, 1.0, 1.0, 1.0};
GLfloat purple[] = {1.0, 0, 1.0, 1.0};
GLfloat gray[] = {0.5, 0.5, 0.5, 1.0};
GLfloat cyan[] = {0, 1.0, 1.0, 1.0};
GLfloat back_amb_diff[] = {0.4, 0.7, 0.1, 1.0};

GLfloat spe[] = {0.25, 0.25, 0.25, 1.0};
GLfloat theta = 0;
int theta1 = 0;
int theta2 = 0;
int theta3 = 0;
int theta4 = 0;
GLfloat x = 1;
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





void draw_toy(void){
    GLUquadricObj * quadObj = gluNewQuadric();
    gluQuadricDrawStyle(quadObj, GLU_FILL);
    
    //sphere head
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, front_amb_diff);
    glPushMatrix();
    //glRotated(theta, 0, 1, 0);
    glTranslated(0, 1.35, 0);
    glutSolidSphere(0.4, 48, 48);
    glPopMatrix();
    
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, blue);
    //right eye
    glPushMatrix();
    glTranslated(.15, 1.4, .4);
    glutSolidSphere(0.05, 48, 48);
    glPopMatrix();
    
    
    //left eye
    glPushMatrix();
    glTranslated(-.15, 1.4, .4);
    glutSolidSphere(0.05, 48, 48);
    glPopMatrix();
    
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, front_amb_diff);
    //cylinder neck
    glPushMatrix();
    glTranslated(0, 1, 0);
    //glRotated(theta, 0, 1, 0);
    glRotated(90, 1, 0, 0);
    gluCylinder(quadObj, 0.1, 0.1, 4, 50, 50);
    glPopMatrix();
    
    //upper body
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, blue);
    glPushMatrix();
    //glRotated(theta, 0, 1, 0);
    glTranslated(0, .2, 0);
    glutSolidCube(.8);
    glPopMatrix();
    
    //lower body
    glPushMatrix();
    //glRotated(theta, 0, 1, 0);
    glTranslated(0, -0.6, 0);
    glutSolidCube(.8);
    glPopMatrix();
    
    
    //right arm
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, front_amb_diff);
    glPushMatrix();
    //glRotated(theta, 0, 1, 0);
    glTranslated(0.5, 0.45, 0);
    glutSolidCube(.3);
    glPopMatrix();
    
    //right arm
    glPushMatrix();
    //glRotated(theta, 0, 1, 0);
    glTranslated(0.8, 0.45, 0);
    glutSolidCube(.3);
    glPopMatrix();
    
    //right arm
    glPushMatrix();
    //glRotated(theta, 0, 1, 0);
    glTranslated(0.8, 0.15, 0);
    glutSolidCube(.3);
    glPopMatrix();
    
    //right arm
    glPushMatrix();
    //glRotated(theta, 0, 1, 0);
    glTranslated(0.8, -0.15, 0);
    glutSolidCube(.3);
    glPopMatrix();
    
    glPushMatrix();
    glRotated(theta3, 1, 0, 0);
    
    //right arm
    glPushMatrix();
    //glRotated(theta, 0, 1, 0);
    glTranslated(0.8, -0.3, .2);
    glutSolidCube(.3);
    glPopMatrix();
    
    //right arm
    glPushMatrix();
    //glRotated(theta, 0, 1, 0);
    glTranslated(0.8, -0.3, .5);
    glutSolidCube(.3);
    glPopMatrix();
    
    //right arm
    glPushMatrix();
    //glRotated(theta, 0, 1, 0);
    glTranslated(0.8, -0.3, .8);
    glutSolidCube(.3);
    glPopMatrix();
    
    //right arm
    glPushMatrix();
    //glRotated(theta, 0, 1, 0);
    glTranslated(0.8, -0.3, 1.1);
    glutSolidCube(.3);
    glPopMatrix();
    
    glPopMatrix();
    
    //left arm
    glPushMatrix();
    //glRotated(theta, 0, 1, 0);
    glTranslated(-0.5, 0.45, 0);
    glutSolidCube(.3);
    glPopMatrix();
    
    
    //left arm
    glPushMatrix();
    //glRotated(theta, 0, 1, 0);
    glTranslated(-0.8, 0.45, 0);
    glutSolidCube(.3);
    glPopMatrix();
    
    //left arm
    glPushMatrix();
    //glRotated(theta, 0, 1, 0);
    glTranslated(-0.8, 0.15, 0);
    glutSolidCube(.3);
    glPopMatrix();
    
    //left arm
    glPushMatrix();
    //glRotated(theta, 0, 1, 0);
    glTranslated(-0.8, -0.15, 0);
    glutSolidCube(.3);
    glPopMatrix();
    
    glPushMatrix();
    glRotated(theta3, 1, 0, 0);
    
    //left arm
    glPushMatrix();
    //glRotated(theta, 0, 1, 0);
    glTranslated(-0.8, -0.3, .2);
    glutSolidCube(.3);
    glPopMatrix();
    
    
    //left arm
    glPushMatrix();
    //glRotated(theta, 0, 1, 0);
    glTranslated(-0.8, -0.3, .5);
    glutSolidCube(.3);
    glPopMatrix();
    
    //left arm
    glPushMatrix();
    //glRotated(theta, 0, 1, 0);
    glTranslated(-0.8, -0.3, .8);
    glutSolidCube(.3);
    glPopMatrix();
    
    //left arm
    glPushMatrix();
    //glRotated(theta, 0, 1, 0);
    glTranslated(-0.8, -0.3, 1.1);
    glutSolidCube(.3);
    glPopMatrix();
    
    glPopMatrix();
    
    //right ball
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, blue);
    glPushMatrix();
    glRotated(theta1, 0, 0, 1);
    glTranslated(0.8, -0.35, 1.2);
    glutSolidSphere(.2, 50, 50);
    glPopMatrix();
    
    //left ball
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, red);
    glPushMatrix();
    glRotated(theta2, 0, 0, 1);
    glTranslated(-0.8, -0.35, 1.2);
    glutSolidSphere(.2, 50, 50);
    glPopMatrix();
    
}

void draw_shed(){
    GLUquadricObj * quadObj = gluNewQuadric();
    gluQuadricDrawStyle(quadObj, GLU_FILL);
    
    //cylinder handle
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, gray);
    glPushMatrix();
    glTranslated(0, 6, 0);
    glRotated(90, 1, 0, 0);
    gluCylinder(quadObj, 0.1, 0.1, 9, 50, 50);
    glPopMatrix();
    
    
    //cone umbrella
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, purple);
    glPushMatrix();
    glTranslated(0, x, 0);
    glRotated(-90, 1, 0, 0);
    glutWireCone(5.0, 3.0, 50, 50);
    glPopMatrix();
    
    
}

void draw_floor(void){
    
    GLUquadricObj * quadObj = gluNewQuadric();
    gluQuadricDrawStyle(quadObj, GLU_FILL);
    
    //disc floor
    glMaterialfv(GL_BACK, GL_AMBIENT_AND_DIFFUSE, cyan);
    glPushMatrix();
    glTranslated(0, -3, 0);
    glRotated(90, 1, 0, 0);
    gluDisk(quadObj, .4, 1.4, 50, 50);
    glPopMatrix();
    
    //disc floor
    glMaterialfv(GL_BACK, GL_AMBIENT_AND_DIFFUSE, green);
    glPushMatrix();
    glTranslated(0, -3, 0);
    glRotated(90, 1, 0, 0);
    gluDisk(quadObj, 1.6, 2.6, 50, 50);
    glPopMatrix();
    
    //disc floor
    glMaterialfv(GL_BACK, GL_AMBIENT_AND_DIFFUSE, cyan);
    glPushMatrix();
    glTranslated(0, -3, 0);
    glRotated(90, 1, 0, 0);
    gluDisk(quadObj, 2.8, 3.8, 50, 50);
    glPopMatrix();
    
    //disc floor
    glMaterialfv(GL_BACK, GL_AMBIENT_AND_DIFFUSE, green);
    glPushMatrix();
    glTranslated(0, -3, 0);
    glRotated(90, 1, 0, 0);
    gluDisk(quadObj, 4, 5, 50, 50);
    glPopMatrix();
    
    //disc floor
    glMaterialfv(GL_BACK, GL_AMBIENT_AND_DIFFUSE, cyan);
    glPushMatrix();
    glTranslated(0, -3, 0);
    glRotated(90, 1, 0, 0);
    gluDisk(quadObj, 5.2, 6.2, 50, 50);
    glPopMatrix();
    
}


void display(void){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    
    glPushMatrix();
    glRotated(theta, 0, 1, 0);
    
    draw_shed();
    draw_floor();
    
    glPushMatrix();
    glTranslated(0, 0, 2);
    draw_toy();
    glPopMatrix();
    
    glPushMatrix();
    glTranslated(2, 0, 0);
    glRotated(90, 0, 1, 0);
    draw_toy();
    glPopMatrix();
    
    glPushMatrix();
    glTranslated(0, 0, -2);
    glRotated(180, 0, 1, 0);
    draw_toy();
    glPopMatrix();
    
    glPushMatrix();
    glTranslated(-2, 0, 0);
    glRotated(-90, 0, 1, 0);
    draw_toy();
    glPopMatrix();
    
    
    
    glPopMatrix();
    
    
    
    
    
    
    
    
    
    
//    glutSolidSphere(0.8, 48, 48);
//    
//    glPushMatrix();
//    glRotated(theta, 0, 1, 0);
//    
//    glPushMatrix();
//    glTranslated(0.8, 0, 0);
//    glutSolidSphere(0.8, 48, 48);
//    glPopMatrix();
//    
//    glPushMatrix();
//    glTranslated(-0.8, 0, 0);
//    glutSolidSphere(0.8, 48, 48);
//    glPopMatrix();
//    
//    glPushMatrix();
//    glTranslated(0, -0.8, 0);
//    glutSolidSphere(0.8, 48, 48);
//    glPopMatrix();
//    
//    glPushMatrix();
//    glTranslated(0, 0.8, 0);
//    glutSolidSphere(0.8, 48, 48);
//    glPopMatrix();
//    
//    glPushMatrix();
//    glTranslated(0, 0, 0.8);
//    glutSolidSphere(0.8, 48, 48);
//    glPopMatrix();
//    
//    glPushMatrix();
//    glTranslated(0, 0, -0.8);
//    glutSolidSphere(0.8, 48, 48);
//    glPopMatrix();
//    
//
//    glPopMatrix();
    glutSwapBuffers();
}


void idle(void){
    
    if (x <= 3)
        x = x + .003;
    
    if (x > 3){
        
        theta = (theta < 360) ? theta + dt : dt;
        
        if (theta1 <= 180 )
            theta1 = (theta1 + 4) % 180;
        
        if (theta2 <= 180 )
            theta2 = (theta2 - 4) % 180;
        
        if (theta3 <= 45)
            theta3 = (theta3+1) % 45;
    }
    
    glutPostRedisplay();
}

void hand_rotate(){
    
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(200, 100);
    glutCreateWindow("GLUT Objects");
    glClearColor(0, 0, 0, 0.0);
    
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45, 1.0, 2, 30);
    
    glMaterialfv(GL_BACK, GL_AMBIENT_AND_DIFFUSE, back_amb_diff);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, spe);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 75);
    glLightfv(GL_LIGHT0, GL_AMBIENT, amb);
    glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslated(0, 0, -15);
    
    glLightfv(GL_LIGHT0, GL_POSITION, pos);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glutDisplayFunc(display);
    glutIdleFunc(idle);
    glutMainLoop();
    
}











