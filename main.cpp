# include <iostream>
#ifdef __APPLE_CC__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
using namespace std;

GLfloat pos[] = {-2, 4, 5, 1};
GLfloat amb[] = {0.3, 0.3, 0.3, 1};
GLfloat spe[] = {0.25, 0.25, 0.25, 1.0};

GLfloat red[] = {1.0, 0, 0, 1.0};
GLfloat green[] = {0, 0.5, 0, 1.0};
GLfloat blue[] = {0, 0, 1.0, 1.0};
GLfloat white[] = {1.0, 1.0, 1.0, 1.0};
GLfloat purple[] = {1.0, 0, 1.0, 1.0};
GLfloat gray[] = {0.5, 0.5, 0.5, 1.0};
GLfloat cyan[] = {0, 1.0, 1.0, 1.0};
GLfloat yellow[] = {1, 0.5, 0, 1.0};
GLfloat front_amb_diff[] = {0.5, 0.5, 0.1, 1.0};
GLfloat back_amb_diff[] = {0.4, 0.7, 0.1, 1.0};

GLfloat theta = 0;
GLfloat theta4 = 0;

GLfloat x = 1.0;
GLfloat dt = 0.5;

int theta1 = 0;
int theta2 = 0;
int theta3 = 0;
int theta5 = 0;
int y = 0;

int cameraX = 0;
int cameraY = 0;
int cameraZ = -15;

bool juggling = false;

void draw_toy(void){
    GLUquadricObj * quadObj = gluNewQuadric();
    gluQuadricDrawStyle(quadObj, GLU_FILL);
    
    //sphere head
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, front_amb_diff);
    glPushMatrix();
    //glRotated(theta, 0, 1, 0);
    glTranslated(0, 1.35, 0);
    glutSolidSphere(0.45, 48, 48);
    glPopMatrix();
    
    //right eye
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, red);
    glPushMatrix();
    glTranslated(.15, 1.45, .4);
    glutSolidSphere(0.05, 48, 48);
    glPopMatrix();
    
    //left eye
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, red);
    glPushMatrix();
    glTranslated(-.15, 1.45, .4);
    glutSolidSphere(0.05, 48, 48);
    glPopMatrix();
    
    //nose
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, blue);
    glPushMatrix();
    glTranslated(0, 1.28, .3);
    glutSolidCone(.1, .3, 50, 50);
    glPopMatrix();
    
    //mouth
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, green);
    glPushMatrix();
    glTranslated(0, 1.15, .3);
    glutSolidTorus(.06, .14, 50, 50);
    glPopMatrix();
    
    //cylinder neck and leg
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, front_amb_diff);
    glPushMatrix();
    glTranslated(0, 1, 0);
    glRotated(90, 1, 0, 0);
    gluCylinder(quadObj, 0.1, 0.1, 4, 50, 50);
    glPopMatrix();
    
    //upper body
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, blue);
    glPushMatrix();
    glTranslated(0, .2, 0);
    glutSolidCube(.8);
    glPopMatrix();
    
    //lower body
    glPushMatrix();
    glTranslated(0, -0.6, 0);
    glutSolidCube(.8);
    glPopMatrix();
    
    //right arm
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, front_amb_diff);
    glPushMatrix();
    glTranslated(0.5, 0.45, 0);
    glutSolidCube(.3);
    glPopMatrix();
    
    //right arm
    glPushMatrix();
    glTranslated(0.8, 0.45, 0);
    glutSolidCube(.3);
    glPopMatrix();
    
    //right arm
    glPushMatrix();
    glTranslated(0.8, 0.15, 0);
    glutSolidCube(.3);
    glPopMatrix();
    
    //right arm
    glPushMatrix();
    glTranslated(0.8, -0.15, 0);
    glutSolidCube(.3);
    glPopMatrix();
    
    glPushMatrix();
    glRotated(theta3, 1, 0, 0);
    
    //right arm
    glPushMatrix();
    glTranslated(0.8, -0.3, .2);
    glutSolidCube(.3);
    glPopMatrix();
    
    //right arm
    glPushMatrix();
    glTranslated(0.8, -0.3, .5);
    glutSolidCube(.3);
    glPopMatrix();
    
    //right arm
    glPushMatrix();
    glTranslated(0.8, -0.3, .8);
    glutSolidCube(.3);
    glPopMatrix();
    
    //right arm
    glPushMatrix();
    glTranslated(0.8, -0.3, 1.1);
    glutSolidCube(.3);
    glPopMatrix();
    
    glPopMatrix();
    
    //left arm
    glPushMatrix();
    glTranslated(-0.5, 0.45, 0);
    glutSolidCube(.3);
    glPopMatrix();
    
    //left arm
    glPushMatrix();
    glTranslated(-0.8, 0.45, 0);
    glutSolidCube(.3);
    glPopMatrix();
    
    //left arm
    glPushMatrix();
    glTranslated(-0.8, 0.15, 0);
    glutSolidCube(.3);
    glPopMatrix();
    
    //left arm
    glPushMatrix();
    glTranslated(-0.8, -0.15, 0);
    glutSolidCube(.3);
    glPopMatrix();
    
    glPushMatrix();
    glRotated(theta3, 1, 0, 0);
    
    //left arm
    glPushMatrix();
    glTranslated(-0.8, -0.3, .2);
    glutSolidCube(.3);
    glPopMatrix();
    
    
    //left arm
    glPushMatrix();
    glTranslated(-0.8, -0.3, .5);
    glutSolidCube(.3);
    glPopMatrix();
    
    //left arm
    glPushMatrix();
    glTranslated(-0.8, -0.3, .8);
    glutSolidCube(.3);
    glPopMatrix();
    
    //left arm
    glPushMatrix();
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
    gluCylinder(quadObj, 0.15, 0.15, 9, 50, 50);
    glPopMatrix();
    
    //cone umbrella lower
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, purple);
    glPushMatrix();
    glTranslated(0, x, 0);
    glRotated(-90, 1, 0, 0);
    glutWireCone(5.0, 3.0, 50, 50);
    glPopMatrix();
    
    //cone umbrella mid
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, blue);
    glPushMatrix();
    glTranslated(0, x, 0);
    glTranslated(0, .8, 0);
    glRotated(-90, 1, 0, 0);
    glutWireCone(4.0, 2.5, 40, 40);
    glPopMatrix();
    
    //cone umbrella lower
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, red);
    glPushMatrix();
    glTranslated(0, x, 0);
    glTranslated(0, 1.6, 0);
    glRotated(-90, 1, 0, 0);
    glutWireCone(3.0, 2, 30, 30);
    glPopMatrix();
}

void draw_floor(void){
    GLUquadricObj * quadObj = gluNewQuadric();
    gluQuadricDrawStyle(quadObj, GLU_FILL);
    
    //disc floor
    glMaterialfv(GL_BACK, GL_AMBIENT_AND_DIFFUSE, yellow);
    glPushMatrix();
    glTranslated(0, -3, 0);
    glRotated(90, 1, 0, 0);
    gluDisk(quadObj, .4, 1.4, 50, 50);
    glPopMatrix();
    
    //disc floor
    glMaterialfv(GL_BACK, GL_AMBIENT_AND_DIFFUSE, gray);
    glPushMatrix();
    glTranslated(0, -3, 0);
    glRotated(90, 1, 0, 0);
    gluDisk(quadObj, 1.6, 2.6, 50, 50);
    glPopMatrix();
    
    //disc floor
    glMaterialfv(GL_BACK, GL_AMBIENT_AND_DIFFUSE, yellow);
    glPushMatrix();
    glTranslated(0, -3, 0);
    glRotated(90, 1, 0, 0);
    gluDisk(quadObj, 2.8, 3.8, 50, 50);
    glPopMatrix();
    
    //disc floor
    glMaterialfv(GL_BACK, GL_AMBIENT_AND_DIFFUSE, gray);
    glPushMatrix();
    glTranslated(0, -3, 0);
    glRotated(90, 1, 0, 0);
    gluDisk(quadObj, 4, 5, 50, 50);
    glPopMatrix();
    
    //disc floor
    glMaterialfv(GL_BACK, GL_AMBIENT_AND_DIFFUSE, yellow);
    glPushMatrix();
    glTranslated(0, -3, 0);
    glRotated(90, 1, 0, 0);
    gluDisk(quadObj, 5.2, 6.2, 50, 50);
    glPopMatrix();
    
}


void draw_rocket(void){
    GLUquadricObj * quadObj = gluNewQuadric();
    gluQuadricDrawStyle(quadObj, GLU_FILL);
    
    glPushMatrix();
    
    
    //upper cone
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, front_amb_diff);
    glMaterialfv(GL_BACK, GL_AMBIENT_AND_DIFFUSE, white);
    glPushMatrix();
    glTranslated(-3, 2, 5);
    glRotated(-90, 1, 0, 0);
    glutSolidCone(0.3, 0.5, 50, 50);
    glPopMatrix();
    
    //mid cylinder
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, red);
    glMaterialfv(GL_BACK, GL_AMBIENT_AND_DIFFUSE, white);
    glPushMatrix();
    glTranslated(-3, 2, 5);
    glRotated(90, 1, 0, 0);
    gluCylinder(quadObj, 0.3, 0.3, 1.3, 50, 50);
    glPopMatrix();
    
    //mid-upper cone
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, white);
    glMaterialfv(GL_BACK, GL_AMBIENT_AND_DIFFUSE, white);
    glPushMatrix();
    glTranslated(-3, .7, 5);
    glRotated(270, 1, 0, 0);
    glutSolidCone(0.4, .8, 10, 10);
    glPopMatrix();
    
    //mid-lower cone
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, blue);
    glMaterialfv(GL_BACK, GL_AMBIENT_AND_DIFFUSE, white);
    glPushMatrix();
    glTranslated(-3, .6, 5);
    glRotated(270, 1, 0, 0);
    glutSolidCone(0.3, 0.6, 10, 10);
    glPopMatrix();
    
    //lower cone
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, white);
    glPushMatrix();
    glTranslated(-3, .5, 5);
    glRotated(270, 1, 0, 0);
    glutSolidCone(0.3, 0.5, 10, 10);
    glPopMatrix();
    
    glPopMatrix();
}


void draw_moon(){
    
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, white);
    glPushMatrix();
    glTranslated(-11, 11, -18);
    glutSolidSphere(1.5, 60, 60);
    glPopMatrix();
    
}

void draw_satelite(void){
    
    glPushMatrix();
    glTranslated(-12, 11, -15);
    
    //left cone
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, gray);
    glPushMatrix();
    glRotated(theta, 1, 0, 0);
    glRotated(theta, 0, 1, 0);
    glTranslated(0, 2, 5);
    glRotated(90, 0, 1, 0);
    glutWireCone(0.6, 0.6, 10, 10);
    glPopMatrix();
    
    //right cone
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, gray);
    glPushMatrix();
    glRotated(theta, 1, 0, 0);
    glRotated(theta, 0, 1, 0);
    glTranslated(.6, 2, 5);
    glRotated(-90, 0, 1, 0);
    glutWireCone(0.6, 0.6, 10, 10);
    glPopMatrix();
    
    glPopMatrix();
}

void keyboard(unsigned char key, int x, int y){
    
    switch(key){
            
        case 's' :  juggling = true; break;
            
        case 'd' :  juggling = false; break;
        
        //case 'x' :  cameraX= cameraX + .01; glTranslated(cameraX, cameraY, cameraZ); break;
        
    }
    
    glutPostRedisplay();
}

void display(void){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    draw_moon();
    
    glPushMatrix();
    glRotated(theta4, 0, 1, 0);
    glTranslated(7, 6, 9);
    glRotated(-90, 0, 0, 1);
    draw_rocket();
    glPopMatrix();
    
    glPushMatrix();
    glRotated(theta5, 0, 1, 0);
    glTranslated(7, 14, 16);
    glRotated(90, 0, 0, 1);
    draw_rocket();
    glPopMatrix();
    
    glPushMatrix();
    
    draw_satelite();
    glPopMatrix();
    
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
    
    glutSwapBuffers();
    
}

void idle(void){
    
    if (x <= 2.5)
        x = x + .003;
    
    //toys animation start after the shed is all the way up
    if (x > 2.5){
        
        theta = (theta < 360) ? theta + dt : dt;
        theta4 = (theta4 < 360) ? theta4 + .2 : .2;
        
        if (theta5 < 360)
            theta5 = (theta5-1) % 360;
    
    }
    
    if (juggling == true){
        
        //hand movement
        if (theta3 <= 45)
            theta3 = (theta3+1) % 45;
        
        //ball juggling
        if (theta1 <= 180 )
            theta1 = (theta1 + 4) % 180;
        
        if (theta2 <= 180 )
            theta2 = (theta2 - 4) % 180;
    }
    
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(0, 100);
    glutCreateWindow("Alien Ball Juggling'");
    glClearColor(0, 0, 0.1, 1);
    
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45, 1.0, 2, 40);
    
    glMaterialfv(GL_BACK, GL_AMBIENT_AND_DIFFUSE, back_amb_diff);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, spe);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 75);
    glLightfv(GL_LIGHT0, GL_AMBIENT, amb);
    glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslated(cameraX, cameraY, cameraZ);
    
    glLightfv(GL_LIGHT0, GL_POSITION, pos);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutIdleFunc(idle);
    glutMainLoop();
    
}
