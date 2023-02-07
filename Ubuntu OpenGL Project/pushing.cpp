#include "shader.h"
#include "Mesh.h"
#include "stb_image.h"
#ifdef __APPLE_CC__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <cstdlib>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include "Texture.h"
#define STB_IMAGE_IMPLEMENTATION




// Camera position
float x = 2.0, y = -4.15; // initially 5 units south of origin
float deltaMove = 0.0; // initially camera doesn't move

// Camera direction
float lx = -0.5, ly = 1.0; // camera points initially along y-axis
float angle = 0.0; // angle of rotation for the camera direction
float deltaAngle = 0.0; // additional angle change when dragging

// Mouse drag control
int isDragging = 0; // true when dragging
int xDragStart = 0; // records the x-coordinate when dragging starts



#define PI 3.1415927
#define ESC 27


void display();
void reshape(int,int);
void timer(int);


void init()
{
	glClearColor(1.0,1.0,1.0,1.0);
	glEnable(GL_DEPTH_TEST);
}


void plot_rect(float xmax, float xmin, float ymax, float ymin, float zmax, float zmin, float colors[][3]) {
    glColor3f(colors[0][0], colors[0][1], colors[0][2]);
    glVertex3f(xmin,ymax,zmax);
    glVertex3f(xmin,ymin,zmax);
    glVertex3f(xmax,ymin,zmax);
    glVertex3f(xmax,ymax,zmax);
    //back
    glColor3f(colors[1][0], colors[1][1], colors[1][2]);
    glVertex3f(xmax,ymax,zmin);
    glVertex3f(xmax,ymin,zmin);
    glVertex3f(xmin,ymin,zmin);
    glVertex3f(xmin,ymax,zmin);
    //right
    glColor3f(colors[2][0], colors[2][1], colors[2][2]);
    glVertex3f(xmax,ymax,zmax);
    glVertex3f(xmax,ymin,zmax);
    glVertex3f(xmax,ymin,zmin);
    glVertex3f(xmax,ymax,zmin);
    //left
    glColor3f(colors[3][0], colors[3][1], colors[3][2]);
    glVertex3f(xmin,ymax,zmin);
    glVertex3f(xmin,ymin,zmin);
    glVertex3f(xmin,ymin,zmax);
    glVertex3f(xmin,ymax,zmax);
    //top
    glColor3f(colors[4][0], colors[4][1], colors[4][2]);
    glVertex3f(xmin,ymax,zmin);
    glVertex3f(xmin,ymax,zmax);
    glVertex3f(xmax,ymax,zmax);
    glVertex3f(xmax,ymax,zmin);
    //bottom
    glColor3f(colors[5][0], colors[5][1], colors[5][2]);
    glVertex3f(xmin,ymin,zmin);
    glVertex3f(xmin,ymin,zmax);
    glVertex3f(xmax,ymin,zmax);
    glVertex3f(xmax,ymin,zmin);	
}



float x_position =0.0;
int state =1;


void draw_cylinder(GLfloat radius,
                   GLfloat height,
                   GLfloat R,
                   GLfloat G,
                   GLfloat B,
                   bool shade)
{
    GLfloat x              = 0.0;
    GLfloat y              = 0.0;
    GLfloat angle          = 0.0;
    GLfloat angle_stepsize = 0.1;

    /** Draw the tube */
    if(!shade) {
        glColor3f(R,G,B);
    }
    else {
        glColor3f(R-.05,G-.05,B-.05);
    }
    
    glBegin(GL_QUAD_STRIP);
    angle = 0.0;
        while( angle < 2*PI ) {
            x = radius * cos(angle);
            y = radius * sin(angle);
            glVertex3f(x, y , height);
            glVertex3f(x, y , 0.0);
            angle = angle + angle_stepsize;
        }
        glVertex3f(radius, 0.0, height);
        glVertex3f(radius, 0.0, 0.0);
    glEnd();

    /** Draw the circle on top of cylinder */
    glColor3f(R,G,B);
    glBegin(GL_POLYGON);
    angle = 0.0;
        while( angle < 2*PI ) {
            x = radius * cos(angle);
            y = radius * sin(angle);
            glVertex3f(x, y , height);
            angle = angle + angle_stepsize;
        }
        glVertex3f(radius, 0.0, height);
    glEnd();
}


void drawLamp()
{


	//neck of lamp
	glTranslatef(2.78,1.0,-0.2);
	glRotatef(90.0,1.0,0.0,0.0);
    draw_cylinder(0.09,0.4,0.38,0.36,.35, true);
    
    //Lamp Shade
    glRotatef(-90.0,1.0,0.0,0.0);
    glTranslatef(0.0,0.5,0.0);
    glRotatef(90.0,1.0,0.0,0.0);
    draw_cylinder(0.4,0.65,0.98,0.86,0.75, false);
    draw_cylinder(0.41,0.03,0.97,0.84,0.73, true);
    glTranslatef(0.0,0.0,0.62);
    draw_cylinder(0.41,0.03,0.97,0.84,0.73, true);
    glTranslatef(0.0,0.0,-0.62);
    glColor3f(0.94,0.80,0.69);
    glBegin(GL_LINES);
      glVertex3f(0.0,0.411,0.0);
      glVertex3f(0.0,0.411,0.65);
    glEnd();
    
    
    //Lamp top
    glRotatef(-90.0,1.0,0.0,0.0);
    glTranslatef(0.0,0.07,0.0);
    glRotatef(90.0,1.0,0.0,0.0);
    draw_cylinder(0.04,0.03,0.3,0.3,0.3, true);
    
    
    
     //cone upright
     glRotatef(-90.0,1.0,0.0,0.0);
    glPushMatrix();
   glColor3f(0.38,0.36,0.35);
  glTranslatef(0.0, -1.35, 0.0);
  glRotatef(270.0, 1.0, 0.0, 0.0);
  glutSolidCone(0.26, 0.735, 70, 12);
  glPopMatrix();
  
  
  //cone upside down
    glPushMatrix();
   glColor3f(0.32,0.33,0.32);
  glTranslatef(0.0, -1.35, 0.0);
  glRotatef(450.0, 1.0, 0.0, 0.0);
  glutSolidCone(0.26, 0.7, 70, 12);
  glPopMatrix();
	
}

void make_painting(float xmax, float xmin, float ymax, float ymin) {
  glBegin(GL_POLYGON);
    	

    glVertex3f(xmax,ymax,0.0);
    	glVertex3f(xmax,ymin,0.0);
    	glVertex3f(xmin,ymin,0.0);
    	glVertex3f(xmin,ymax,0.0);
  glEnd();
}

void draw_rect(float xmax, float xmin, float ymax, float ymin) {
  glBegin(GL_POLYGON);
    	glVertex3f(xmax,ymax,0.0);
    	glVertex3f(xmax,ymin,0.0);
    	glVertex3f(xmin,ymin,0.0);
    	glVertex3f(xmin,ymax,0.0);
	
	 glEnd();
}


void drawPillows()
{

 glTranslatef(1.8,0.0,-0.15);
    glRotatef(90.0,0.0,0.0,1.0);
    
    draw_cylinder(0.25,0.8,0.34,0.27,0.20, true);
    glRotatef(-90.0,0.0,0.0,1.0);
    glTranslatef(-1.8,0.0,0.15);

    glTranslatef(-1.8,0.0,-0.15);
    glRotatef(90.0,0.0,0.0,1.0);
    
    draw_cylinder(0.25,0.8,0.34,0.27,0.20, true);
    glRotatef(-90.0,0.0,0.0,1.0);
    glTranslatef(1.8,0.0,0.15);

}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	
		// Set the camera centered at (x,y,1) and looking along directional
	// vector (lx, ly, 0), with the z-axis pointing up
	gluLookAt(
			x,      y,      2.0,
			x + lx, y + ly, 2.0,
			0.0,    0.0,    2.0);
	
	
	
	
	
	glTranslatef(2.0,0.0,-8.0);
	glRotatef(90.0,1.0,0.0,0.0);
	glTranslatef(0.0,8.0,-2.0);
	
	
	
	//vertices are -1 to 1
	Vertex vertices[] = {
	
		Vertex(glm::vec3(-0.5,-0.5,0)),
		Vertex(glm::vec3(-0.5,0.5,0)),
		Vertex(glm::vec3(0,0.5,0)),
		Vertex(glm::vec3(0.0,-0.5,0))
	
	};
	
	
	
	
	
	//Shader shader("res/basicShader");
	//shader.Bind();
	
	
	
	
	//Cube1	
	glBegin(GL_QUADS);
    float colors[][3] = {{0.3098,0.2353,0.1765}, {0.309,0.247,0.188}, {0.309,0.247,0.188}, {0.3098,0.2353,0.1765}, {0.3087,0.233,0.171}, {0.3089,0.243,0.176}};
    float tableBase[][3] = {{0.5,0.5,0.5}, {0.5,0.5,0.5}, {0.5,0.5,0.5}, {0.5,0.5,0.5}, {0.5,0.5,0.5}, {0.5,0.5,0.5}};
    float table[][3] = {{0.1,0.1,0.1}, {0.1,0.1,0.1}, {0.0,0.0,0.0}, {0.0,0.0,0.0}, {0.2,0.2,0.2}, {0.0,0.0,0.0}};
    plot_rect(0.5,-0.5,0.25,-0.85,0.5,-0.5, table);
    glEnd();
    // cube1 base
    glBegin(GL_QUADS);
    plot_rect(0.475,-0.475,-0.85,-1.0,0.475,-0.475, tableBase);
   
    glEnd();
    
    //Cube2
    
    glTranslatef(-5.8,0.0,0.0);
    glBegin(GL_QUADS);
    plot_rect(0.5,-0.5,0.25,-0.85,0.5,-0.5, table);
    glEnd();
    // cube1 base
    glBegin(GL_QUADS);
    plot_rect(0.475,-0.475,-0.85,-1.0,0.475,-0.475, tableBase);
    glEnd();
    
   
    glTranslatef(2.9,0.0,0.0);
    
    // create cushion of the couch
    glBegin(GL_QUADS);
    plot_rect(2.1,-2.1,-0.25,-0.65,0.7,-0.5, colors);
    glEnd();
    
    // create right arm rest
    glBegin(GL_QUADS);
    plot_rect(2.3,2.1,0.6,-0.85,0.7,-0.5, colors);
    glEnd();

    // create the bottom board of the couch
    float colors2[][3] = {{0.34,0.27,0.20}, {0.309,0.247,0.188}, {0.309,0.247,0.188}, {0.3098,0.2353,0.1765}, {0.3087,0.233,0.171}, {0.3089,0.243,0.176}};
    glBegin(GL_QUADS);
    plot_rect(2.1,-2.1,-0.65,-0.85,0.7,-0.5, colors2);
    glEnd();

    // create the left arm rest of the couch
    glBegin(GL_QUADS);
    plot_rect(-2.1,-2.3,0.6,-0.85,0.7,-0.5, colors);
    glEnd();
    
    // create the backboard of the couch
    glBegin(GL_QUADS);
    plot_rect(2.3,-2.3,0.6,-0.75,-0.2,-0.5, colors);
    glEnd();
    
    //create the right leg
    glBegin(GL_QUADS);
    plot_rect(1.9,1.8,-0.75,-1.0,0.65,0.55, tableBase);
    glEnd();
    
    //create the left leg
    glBegin(GL_QUADS);
    plot_rect(-1.8,-1.9,-0.75,-1.0,0.65,0.55, tableBase);
    glEnd();

    
   
    
    
  //  glRotatef(-30.0,1.0,0.0,0.0);
    
    glBegin(GL_POLYGON);
    
    //floor
    glColor3f(0.5098, 0.4275, 0.3451);
    glVertex3f(-5.0,-1.0,-1.0);
    glVertex3f(12.0,-1.0,-1.0);
    glVertex3f(12.0,-1.0,12.0);
    glVertex3f(-5.0,-1.0,12.0);
    
    glEnd();
	
    
    glBegin(GL_POLYGON);
    
    //wall
    glColor3f(.823,0.76,0.651);
    glVertex3f(-5.0,12.0,-1.0);
    glVertex3f(12.0,12.0,-1.0);
    glVertex3f(12.0,-1.0,-1.0);
    glVertex3f(-5.0,-1.0,-1.0);
    
    glEnd();

    // create base board for the back wall
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    	glVertex3f(12.0,-0.75,-0.99);
    	glVertex3f(12.0,-1.0,-0.99);
    	glVertex3f(-5.0,-1.0,-0.99);
    	glVertex3f(-5.0,-0.75,-0.99);
	
	 glEnd();

   
    
    


    glBegin(GL_POLYGON);
    
    //side wall
    glColor3f(.81,0.75,0.64);
    glVertex3f(-5.0,12.0,-1.0);
    glVertex3f(-5.0,12.0,12.0);
    glVertex3f(-5.0,-1.0,12.0);
    glVertex3f(-5.0,-1.0,-1.0);
    
    glEnd();

    // create base board for the side wall
    glColor3f(0.01,0.02,0.02);
   glBegin(GL_POLYGON);
    	glVertex3f(-4.99,-1.0,-1.0);
    	glVertex3f(-4.99,-1.0,12.0);
    	glVertex3f(-4.99,-0.75,12.0);
    	glVertex3f(-4.99,-0.75,-1.0);
	
	 glEnd();
    
    
	
	
	glTranslatef(0,0.23,0);
	
	
	drawLamp();


  
	
	// create the painting
    	glTranslatef(0.0,0.3,0);
      glColor3f(0.95,0.95,0.95);
      make_painting(-0.8, -4.8, 1.5, -0.4);

      // create the frame for the painting
	    glColor3f(0.20000, 0.10196, 0.00000);
      draw_rect(-4.8, -4.9, 1.5, -0.4);
      draw_rect(-0.7, -4.9, 1.6, 1.5);
      draw_rect(-0.7, -0.8, 1.5, -0.4);
      draw_rect(-0.7, -4.9, -0.5, -0.4);
      
      
      
      
      
      //cushions
      
       glTranslatef(-4.9,-2.5,0.6);
    glRotatef(90.0,0.0,1.0,0.0);
    draw_cylinder(0.35,4.2,0.36, .30, .22, false);
    glTranslatef(0,0,1.35);
    draw_cylinder(0.36,0.01,0.34,0.27,0.20, false);
    glTranslatef(0,0,1.5);
    draw_cylinder(0.36,0.01,0.34,0.27,0.20, false);
    glTranslatef(0,0,-2.85);
    glColor3f(0.34,0.27,0.20);
    glBegin(GL_LINE_STRIP);
      glVertex3f(0.41,0.6,0.0);
      glVertex3f(0.4125,0.62,1.0625);
      glVertex3f(0.415,0.64,2.125);
      glVertex3f(0.4125,0.62,3.1875);
      glVertex3f(0.41,0.6,4.25);
    glEnd();
    for(int i = 0; i < 5; i++){
        glBegin(GL_LINE_STRIP);
          glVertex3f(0.55,1.0,0.75+ i*.75);
          glVertex3f(0.44,0.75,0.75+ i*.75);
          glVertex3f(0.41,0.6,0.75+i*.75);
          glVertex3f(0.45,0.45,0.75+i*.75);
          glVertex3f(0.5,0.3,0.75+i*.75);
        glEnd();
    }
    
    
      glRotatef(-90.0,0.0,1.0,0.0);
	glTranslatef(0,0,-0.4);
    glRotatef(90.0,0.0,1.0,0.0);
    draw_cylinder(0.35,4.2,0.36, .30, .22, false);
    glTranslatef(0,0,1.35);
    draw_cylinder(0.36,0.01,0.34,0.27,0.20, false);
    glTranslatef(0,0,1.5);
    draw_cylinder(0.36,0.01,0.34,0.27,0.20, false);
    glTranslatef(0,0,-2.85);

    
     glRotatef(-90.0,0.0,1.0,0.0);
	glTranslatef(0,0.62,-0.4);
    glRotatef(90.0,0.0,1.0,0.0);
    draw_cylinder(0.38,4.3,0.36, .30, .22, false);
    
    
     glRotatef(-90.0,0.0,1.0,0.0);
     glTranslatef(2.1,0,0.5);
    
    drawPillows();
    
    
     glColor3f(0.2,0.2,0.2); 
    glPointSize(20.0);
	
	
	/* glBegin(GL_LINES);
    glVertex3d(-4, 0,3);
    glVertex3d(-3,0,3 );
    glEnd();
    
    */


	Texture texture("Container1.jpg");

	


	glTranslatef(0,4.5,0.6);
	Mesh mesh(vertices, sizeof(vertices)/sizeof(vertices[0]));
  texture.Bind(0);
	mesh.Draw();



	glutSwapBuffers();
}

void update(void) 
{
	if (deltaMove) { // update camera position
		x += deltaMove * lx * 0.1;
		y += deltaMove * ly * 0.1;
	}
	glutPostRedisplay(); // redisplay everything
}


void processNormalKeys(unsigned char key, int xx, int yy)
{
	if (key == ESC || key == 'q' || key == 'Q') exit(0);
} 

void pressSpecialKey(int key, int xx, int yy)
{
	switch (key) {
		case GLUT_KEY_UP : deltaMove = 1.0; break;
		case GLUT_KEY_DOWN : deltaMove = -1.0; break;
	}
} 

void releaseSpecialKey(int key, int x, int y) 
{
	switch (key) {
		case GLUT_KEY_UP : deltaMove = 0.0; break;
		case GLUT_KEY_DOWN : deltaMove = 0.0; break;
	}
} 

void mouseMove(int x, int y) 
{ 	
	if (isDragging) { // only when dragging
		// update the change in angle
		deltaAngle = (x - xDragStart) * 0.005;

		// camera's direction is set to angle + deltaAngle
		lx = -sin(angle + deltaAngle);
		ly = cos(angle + deltaAngle);
	}
}

void mouseButton(int button, int state, int x, int y) 
{
	if (button == GLUT_LEFT_BUTTON) {
		if (state == GLUT_DOWN) { // left mouse button pressed
			isDragging = 1; // start dragging
			xDragStart = x; // save x where button first pressed
		}
		else  { /* (state = GLUT_UP) */
			angle += deltaAngle; // update camera turning angle
			isDragging = 0; // no longer dragging
		}
	}
}


void reshape(GLint w, GLint h)
{
	glViewport(0,0,w,h);
	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	
        gluPerspective(70,(GLfloat(w)+2)/GLfloat(h),4.8,40.0);
	glMatrixMode(GL_MODELVIEW);
	
}

// The MAIN function, from here we start the application and run the game loop
int main(int argc, char** argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
  
  glutInitWindowSize(1000, 1000);
  glutInitWindowPosition(100, 100);
  
 
 
 
 
 	
  
  
  
  
  glutCreateWindow("Cube Test");
  glutReshapeFunc(reshape);
  glutDisplayFunc(display);
  glutIdleFunc(update); // incremental update 
  glutIgnoreKeyRepeat(1); // ignore key repeat when holding key down
  glutMouseFunc(mouseButton);
  glutMotionFunc(mouseMove); // process mouse dragging motion
  glutKeyboardFunc(processNormalKeys);
  glutSpecialFunc(pressSpecialKey); // process special key pressed
						// Warning: Nonstandard function! Delete if desired.
						
  glutSpecialUpFunc(releaseSpecialKey); // process special key release
  
  


  
  
  
  
  
  //glutTimerFunc(0,timer,0);
  
  
  
  init();
  glutMainLoop();
 
 return 0; 
  
  
}


void timer(int)
{
	glutPostRedisplay();
	glutTimerFunc(1000/60,timer,0);
}
