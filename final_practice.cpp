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
#include <ostream>
#include <fstream>
#include <string>
#include <sstream>

#ifdef __APPLE__
#  include <OpenGL/gl3.h>
#  include <GLUT/glut.h>
#  include <OpenGL/glext.h>
#else
#  include <GL/glew.h>
#  include <GL/freeglut.h>
#  include <GL/glext.h>
#pragma comment(lib, "glew32.lib")
#endif

#include "ElementosQuimicosBD.h"
#include "paintelectrons.h"
#include "paintprotonsneutrons.h"

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
static ElementosQuimicosBD elementos;
//Para las pruebas vamos a usar el Helio (que tiene algo más que el hidrógeno).
static ElementoQuimico elementoActual;

struct elenemt{
    string name;
    int protons;
    int neutrons;
    int electrons;
};

//Convert int to string
string toString(int i) {
    ostringstream os;
    os << i;
    return os.str();
}

//Convert float to string
string toString(float f) {
    ostringstream os;
    os << f;
    return os.str();
}

//Convert string to char* writable
char* convertString(string s) {
    char * writable = new char[s.size() + 1];
    std::copy(s.begin(), s.end(), writable);
    writable[s.size()] = '\0';
    return writable;
}

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
    
    
    floatToString(theStringBuffer, 4, t);
    glRasterPos3f(-1.0, 1.05, -2);
    string nombreElemento = "Elemento quimico: " + elementoActual.getNombre();
    writeBitmapString((void*)font, convertString(nombreElemento));
    
    floatToString(theStringBuffer, 4, t);
    glRasterPos3f(-1.0, 1.0, -2);
    string simbolo = "Simbolo: " + elementoActual.getSimbolo();
    writeBitmapString((void*)font, convertString(simbolo));
    
    floatToString(theStringBuffer, 4, t);
    glRasterPos3f(-1.0, 0.95, -2);
    string numeroAtomico = "Numero atomico: " + toString(elementoActual.getNumeroAtomico());
    writeBitmapString((void*)font, convertString(numeroAtomico));
    
    floatToString(theStringBuffer, 4, t);
    glRasterPos3f(-1.0, 0.9, -2);
    string masa = "Masa atomica: " + toString(elementoActual.getMasaAtomica());
    writeBitmapString((void*)font, convertString(masa));
    
    floatToString(theStringBuffer, 4, t);
    glRasterPos3f(-1.0, 0.85, -2);
    string protones = "Protones: " + toString(elementoActual.getProtones());
    writeBitmapString((void*)font, convertString(protones));
    
    floatToString(theStringBuffer, 4, t);
    glRasterPos3f(-1.0, 0.8, -2);
    string electrones = "Electrones: " + toString(elementoActual.getElectrones());
    writeBitmapString((void*)font, convertString(electrones));
    
    floatToString(theStringBuffer, 4, t);
    glRasterPos3f(-1.0, 0.75, -2);
    string neutrones = "Neutrones: " + toString(elementoActual.getNeutrones());
    writeBitmapString((void*)font, convertString(neutrones));
    
    glEnable(GL_LIGHTING); // Re-enable lighting.
}


// Timer function.
void animate(int value)
{
    if (isAnimate)
    {
        latAngle += 5.0;
        if (latAngle > 360.0) latAngle -= 360.0;
        longAngle += 5.0;
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

void createLights(){
    
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
}

// Drawing routine.
void drawScene()
{
    
    createLights();
    
    /*
     Muy importante, si vais a pintar algo usar primero glTranslatef para colocar en la posición deseada, luego pintais el objeto
     y luego centrar con otro glTranslatef negativo. Si no hacemos esto es muy difícil centrar después las órbitas ya que los traslados glTranslatef se acumulan
     */

    //Llamamos a la función que pinta los neutrones y protones según el número
    
    paintProtonsAndNeutrons(elementoActual.getProtones(), elementoActual.getNeutrones(), 0.6);
    
    
    // Sphere.3 - electron
    float angles[3] = {latAngle, longAngle, longAngle};
    paintElectrons(elementoActual.getElectrones(), 0.1, angles );
    
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
    
    int id;
    
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
        case '+':
            id = elementoActual.getNumeroAtomico();
            id++;
            if (id > 18) id = 1;
            elementoActual = elementos.getElemento(id);
            glutPostRedisplay();
            break;
        case '-':
            id = elementoActual.getNumeroAtomico();
            id--;
            if (id < 0) id = 18;
            elementoActual = elementos.getElemento(id);
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
    << "Press the +/- keys to change element." << endl
    << "Press the up/down arrow keys to speed up/slow down animation." << endl
    << "Press the x, X, y, Y, z, Z keys to rotate the scene." << endl;
}

// Main routine.
int main(int argc, char **argv)
{
    
    //Instanciamos los elementos:
    elementos = ElementosQuimicosBD();
    //Cargamos los elementos químicos:
    elementos.loadBD();
    elementoActual = elementos.getElemento(1); //Cogemos uno para las pruebas
    
    printInteraction();
    glutInit(&argc, argv);
    
    //glutInitContextVersion(4, 3);
    //glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);
    
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize (1024, 1024);
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
