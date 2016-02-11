///////////////////////////////////////////////////////////////////////////////////////////      
// lightAndMaterial1.cpp
// 
// This program draws a blue sphere lit by two positional lights, one white and one green,
// the location of each shown by a smaller wire sphere. Various material properties of the
// sphere can be controlled and also the distance attenuation of the light.
// 
// Interaction:
// Press 'a/A' to decrease/increase the sphere's blue ambient reflectance.
// Press 'd/D' to decrease/increase the sphere's blue diffuse reflectance.
// Press 's/S' to decrease/increase the sphere's white specular reflectance.
// Press 'h/H' to decrease/increase the sphere's shininess.
// Press 'e/E' to decrease/increase the sphere's blue emittance.
// Press 't/T' to decrease/increase the quadratic attenuation parameter.
// Press the up/down arrow keys to move the sphere.
//
// Sumanta Guha.
/////////////////////////////////////////////////////////////////////////////////////////// 

#include <iostream>
#include <fstream>

#ifdef __APPLE__
#  include <GL/glew.h>
#  include <GL/freeglut.h>
#  include <OpenGL/glext.h>
#else
#  include <GL/glew.h>
#  include <GL/freeglut.h>
#  include <GL/glext.h>
#pragma comment(lib, "glew32.lib") 
#endif

using namespace std;

// Globals.
static float latAngle = 0.0; // Latitudinal angle.
static float longAngle = 0.0; // Longitudinal angle.
static float Xangle = 0.0, Yangle = 0.0, Zangle = 0.0; // Angles to rotate scene.
static int isAnimate = 0; // Animated?
static int animationPeriod = 100; // Time interval between frames.

static float a = 1.0; // Blue ambient reflectance.
static float d = 1.0; // Blue diffuse reflectance.
static float s = 1.0; // White specular reflectance. 
static float h = 50.0; // Shininess.
static float e = 0.0; // Blue emittance.
static float t = 0.0; // Quadratic attenuation factor.
static float zMove = 0.0; // z-direction component.
static char theStringBuffer[10]; // String buffer.
static long font = (long)GLUT_BITMAP_8_BY_13; // Font selection.

// Routine to draw a bitmap character string.
void writeBitmapString(void *font, char *string)
{  
   char *c;

   for (c = string; *c != '\0'; c++) glutBitmapCharacter(font, *c);
}

// Routine to convert floating point to char string.
void floatToString(char * destStr, int precision, float val) 
{
   sprintf(destStr,"%f",val);
   destStr[precision] = '\0';
}

// Write data.
void writeData(void)
{
   glDisable(GL_LIGHTING); // Disable lighting.
   glColor3f(1.0, 1.0, 1.0); 
   
   floatToString(theStringBuffer, 4, latAngle);
   glRasterPos3f(-1.0, 1.05, -2.0);
   writeBitmapString((void*)font, "Blue ambient reflectance: ");
   writeBitmapString((void*)font, theStringBuffer);
   
   floatToString(theStringBuffer, 4, d);
   glRasterPos3f(-1.0, 1.0, -2.0);
   writeBitmapString((void*)font, "Blue diffuse reflectance: ");
   writeBitmapString((void*)font, theStringBuffer);

   floatToString(theStringBuffer, 4, s);
   glRasterPos3f(-1.0, 0.95, -2.0);
   writeBitmapString((void*)font, "White specular reflectance: ");  
   writeBitmapString((void*)font, theStringBuffer);

   floatToString(theStringBuffer, 4, h);
   glRasterPos3f(-1.0, 0.9, -2.0);
   writeBitmapString((void*)font, "Shininess: ");  
   writeBitmapString((void*)font, theStringBuffer);

   floatToString(theStringBuffer, 4, e);
   glRasterPos3f(-1.0, 0.85, -2.0);
   writeBitmapString((void*)font, "Blue emittance: ");
   writeBitmapString((void*)font, theStringBuffer);

   floatToString(theStringBuffer, 4, t);
   glRasterPos3f(-1.0, 0.8, -2.0);
   writeBitmapString((void*)font, "Quadratic attenuation: ");
   writeBitmapString((void*)font, theStringBuffer);

   glEnable(GL_LIGHTING); // Re-enable lighting.
}


// Timer function.
void animate(int value)
{
   if (isAnimate)
   {
      latAngle += 5.0;
      if (latAngle > 360.0) latAngle -= 360.0;
      longAngle += 1.0;
      if (longAngle > 360.0) longAngle -= 360.0;

      glutPostRedisplay();
      glutTimerFunc(animationPeriod, animate, 1);
   }
}

// Initialization routine.
void setup(void)
{
   glClearColor(0.0, 0.0, 0.0, 0.0);
   glEnable(GL_DEPTH_TEST); // Enable depth testing.

   // Turn on OpenGL lighting.
   glEnable(GL_LIGHTING);

   // Light property vectors.
   float lightAmb[] = { 0.0, 0.0, 0.0, 1.0 };
   float lightDifAndSpec0[] = { 0.8, 0.8, 0.8, 1.0 };
   float lightDifAndSpec1[] = { 0.0, 0.0, 0.3, 1.0 };
   float globAmb[] = { 0.2, 0.2, 0.2, 1.0 };
   
   // Light0 properties.
   glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmb);
   glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDifAndSpec0);
   glLightfv(GL_LIGHT0, GL_SPECULAR, lightDifAndSpec0);

   // Light1 properties.
   glLightfv(GL_LIGHT1, GL_AMBIENT, lightAmb);
   glLightfv(GL_LIGHT1, GL_DIFFUSE, lightDifAndSpec1);
   glLightfv(GL_LIGHT1, GL_SPECULAR, lightDifAndSpec1);
   
   glEnable(GL_LIGHT0); // Enable particular light source.
   glEnable(GL_LIGHT1); // Enable particular light source.
   glLightModelfv(GL_LIGHT_MODEL_AMBIENT, globAmb); // Global ambient light.
   glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE); // Enable local viewpoint

   // Cull back faces.
   glEnable(GL_CULL_FACE);
   glCullFace(GL_BACK);
}

// Drawing routine.
void drawScene()
{  


   // Light position vectors.	
   float lightPos0[] = { 0.0, 2.0, 2.5, 1.0 };
   float lightPos1[] = { 1.0, 2.0, 0.0, 1.0 };

   glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   glLoadIdentity();
   writeData();
   glTranslatef(0.0, 0.0, -8.0);

   // Rotate scene.
   glRotatef(Zangle, 0.0, 0.0, 1.0);
   glRotatef(Yangle, 0.0, 1.0, 0.0);
   glRotatef(Xangle, 1.0, 0.0, 0.0);


   // Light quadratic attenuation factor.
   glLightf(GL_LIGHT0, GL_QUADRATIC_ATTENUATION, t);
   glLightf(GL_LIGHT1, GL_QUADRATIC_ATTENUATION, t);

   gluLookAt(0.0, 3.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

   // Draw light source spheres after disabling lighting.
   glDisable(GL_LIGHTING);

   // Light0 and its sphere positioned.
   glLightfv(GL_LIGHT0, GL_POSITION, lightPos0);

   // Light1 and its sphere positioned.
   glLightfv(GL_LIGHT1, GL_POSITION, lightPos1);

   glEnable(GL_LIGHTING);

   glTranslatef(0.55, 0.0, 0.0);

   // Create protons

   // Material properties of sphere 1.  - Proton
   float matAmb[] = {0.6, 0.1, 0.05, 1.0};
   float matDif[] = {0.6, 0.1, 0.05, 1.0};
   float matSpec[] = { 0.5, 0.5, 0.5, 1.0 };
   float matShine[] = { 32 };
   float matEmission[] = {0.0, 0.0, e, 1.0};

   glMaterialfv(GL_FRONT, GL_AMBIENT, matAmb);
   glMaterialfv(GL_FRONT, GL_DIFFUSE, matDif);
   glMaterialfv(GL_FRONT, GL_SPECULAR, matSpec);
   glMaterialfv(GL_FRONT, GL_SHININESS, matShine);
   glMaterialfv(GL_FRONT, GL_EMISSION, matEmission);

   glTranslatef(-1.1, 0.0, 0.0); // Move the sphere.
   glutSolidSphere( 0.6, 200, 200);


   // Create neutrons

   // Material properties of sphere 2.  - Neutron
   float matAmb2[] = {1.0, 1.0, 1.0, 1.0};
   float matDif2[] = {1.0, 1.0, 1.0, 1.0};
   float matSpec2[] = { 1.0, 1.0, 1.0, 1.0 };
   float matShine2[] = { 32 };
   float matEmission2[] = {0.0, 0.0, e, 1.0};

   glMaterialfv(GL_FRONT, GL_AMBIENT, matAmb2);
   glMaterialfv(GL_FRONT, GL_DIFFUSE, matDif2);
   glMaterialfv(GL_FRONT, GL_SPECULAR, matSpec2);
   glMaterialfv(GL_FRONT, GL_SHININESS, matShine2);
   glMaterialfv(GL_FRONT, GL_EMISSION, matEmission2);

   glTranslatef(1.1, 0.0, 0.0); // Move the sphere.
   glutSolidSphere( 0.6, 200, 200);


   // System centered
   glTranslatef(-0.55, 0.0, 0.0);
   glRotatef(latAngle, 0.0, 1.0, 0.0); //Base rotation


   // Create electrons

   // Material properties of sphere 3 - electron.
   float matAmb3[] = {0.18275f, 0.17f, 0.62525f, 1.0};
   float matDif3[] = {0.332741f, 0.328634f, 0.746435f, 1.0};
   float matSpec3[] = { 0.25, 0.13, 0.08, 1.0 };
   float matShine3[] = { 2.3 };
   float matEmission3[] = {0.0, 0.0, e, 1.0};
   glMaterialfv(GL_FRONT, GL_AMBIENT, matDif3);
   glMaterialfv(GL_FRONT, GL_DIFFUSE, matSpec3);
   glMaterialfv(GL_FRONT, GL_SPECULAR, matAmb3);
   glMaterialfv(GL_FRONT, GL_SHININESS, matShine3);
   glMaterialfv(GL_FRONT, GL_EMISSION, matEmission3);

   // Sphere.3 - electron
   glTranslatef(4.0, 0.0, 0.0);
   glutSolidSphere( 0.3, 150, 150);


   glTranslatef(-4.0, 0.0, 0.0); // center the spin
   glRotatef(120, 0.0, 1.0, 0.0);

   glTranslatef(2, 0.0, 0.0);
   glutSolidSphere( 0.3, 150, 150);

   glTranslatef(-2.0, 0.0, 0.0); // center the spin
   glRotatef(120, 0.0, 1.0, 0.0);

   glTranslatef(6.0, 0.0, 0.0);
   glutSolidSphere( 0.3, 150, 150);


   glutSwapBuffers();
}

// OpenGL window reshape routine.
void resize (int w, int h)
{
   glViewport (0, 0, w, h);
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity();
   gluPerspective(60.0, (float)w/(float)h, 1.0, 20.0);
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
       case ' ':
          if (isAnimate) isAnimate = 0;
          else
          {
             isAnimate = 1;
             animate(1);
          }
            break;
       case 'x':
          Xangle += 5.0;
          if (Xangle > 360.0) Xangle -= 360.0;
          glutPostRedisplay();
          break;
       case 'X':
          Xangle -= 5.0;
          if (Xangle < 0.0) Xangle += 360.0;
          glutPostRedisplay();
          break;
       case 'y':
          Yangle += 5.0;
          if (Yangle > 360.0) Yangle -= 360.0;
          glutPostRedisplay();
          break;
       case 'Y':
          Yangle -= 5.0;
          if (Yangle < 0.0) Yangle += 360.0;
          glutPostRedisplay();
          break;
       case 'z':
          Zangle += 5.0;
          if (Zangle > 360.0) Zangle -= 360.0;
          glutPostRedisplay();
          break;
       case 'Z':
          Zangle -= 5.0;
          if (Zangle < 0.0) Zangle += 360.0;
          glutPostRedisplay();
          break;
       default:
      break;
   }
}

// Callback routine for non-ASCII key entry.
void specialKeyInput(int key, int x, int y)
{
   if (key == GLUT_KEY_DOWN) animationPeriod += 5;
   if( key == GLUT_KEY_UP) if (animationPeriod > 5) animationPeriod -= 5;
   glutPostRedisplay();
}

// Routine to output interaction instructions to the C++ window.
void printInteraction(void)
{
    cout << "Interaction:" << endl;
    cout << "Press space to toggle between animation on and off." << endl
         << "Press the up/down arrow keys to speed up/slow down animation." << endl
         << "Press the x, X, y, Y, z, Z keys to rotate the scene." << endl;
}

// Main routine.
int main(int argc, char **argv) 
{
   printInteraction();
   glutInit(&argc, argv);
 
   //glutInitContextVersion(4, 3);
   //glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);
   
   glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH); 
   glutInitWindowSize (500, 500);
   glutInitWindowPosition (100, 100);
   glutCreateWindow ("elementsTableMain.cpp");
   glutDisplayFunc(drawScene);
   glutReshapeFunc(resize);
   glutKeyboardFunc(keyInput);
   glutSpecialFunc(specialKeyInput);
   
   //glewExperimental = GL_TRUE;
   //glewInit();
   
   setup(); 

   glutMainLoop();
}
