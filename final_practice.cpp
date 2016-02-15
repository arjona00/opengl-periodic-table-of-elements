///////////////////////////////////////////////////////////////////////////////////////
//
//
// Antonio Jesús Arjona Rodríguez
// José Alberto García Pinteño
// Tatiana Person Montero
//
// Práctica final: Simulación del átomo de un elemento químico (del número atómico 1 al
// 18).
// Computación gráfica - Máster en Ingeniería Informática
// Curso 2015/2016
//
// Repartición de las tareas:
//
// En primer lugar, para poder compartir el trabajo y el código fuente, hemos creado
// un repositorio en GitHub, con esto también pretendemos tener un respaldo del trabajo
// realizado por cada miembro del equipo. Aunque realmente, todos hemos participado en
// las tareas de todos (aportando ideas y/o soluciones) para poder llegar a la versión
// final. Posteriormente, se muestra el desglose de tareas que se han llevado a cabo:
//
// 1 - Planteamiento del problema: En este paso, acordamos el ámbito que se iba a
// abarcar en la práctica. Como nuestro grupo estaba compuesto por tres personas,
//  acordamos generalizar el problema, es decir, realizar funciones que pintaran
// electrones en sus órbitas, y protones y neutrones unidos de tal forma que para cada
// elemento solo tuvieramos que realizar una simple llamada de la forma
// funcion(numeroDeObjetosAPintar) y que realizara el trabajo automáticamente para
// cualquier número.
//
// 2 - Representación de un elemento químico: En esta tarea, se ha realizado la
// implementación de las clases ElementoQuimico y ElementoQuimicoBD. La primera clase
// es la encargada de definir la estructura de un elemento químico recogiendo su
// información más relevante (número de protones, electrones y neutrones, masa atómica
// y número atómico). Por otro lado, la segunda clase es la encargada de crear una
// serie de elementos químicos (desde el número atómico 1 hasta el 30) y cargarlos en
// un vector para poderlos utilizar desde el programa principal.
//
// 3 - Colocación de electrones: En esta tarea, como se ha comentado anteriormente, se
// ha realizado una función que pinta electrones en sus órbitas automáticamente
// utilizando el número de los que se quiere pintar.

// 4 - Colocación de neutrones y protones: En esta tarea, al igual que en la anterior,
// se ha realizado una función que pinta neutrones y protones en conjunto
// automáticamente utilizando el número de los que se quiere pintar. En este caso, la
// dificultad encontrada ha sido reorganizar los protones y neutrones de tal forma que
// esten mezclados y en la que el crecimiento de la estructura que forman no fuese
// lineal. Finalmente, se ha conseguido realizar un mayor entrelazado entre éstos, pero
// el crecimiento sigue siendo lineal, ya que la repartición se realiza mediante un
// bucle (antes se realizó una versión recursiva pero la recursividad disminuía el
// rendimiento de la aplicación) y todas las iteraciones mantienen un mismo patrón.
// Por este motivo, se ha limitado el número atómico del elemento simulado hasta 18
// finalmente.
//
// 5 - Configuración de texturas y luces: Se ha realizado una configuración de las
// esferas que representan los protones, neutrones y electrones, de tal forma de que
// fuese descriptivo (siguiendo la "nomenclatura" aplicada en casi todas las webs o
// libros) y de que se pudieran diferenciar facilmente. En este caso:
//
//  a) Protones -> esferas de color rojo de 20px.
//  b) Neutrones -> esferas de color blanco de 20px.
//  c) Electrones -> esferas de color azul de 10px.
//
// Repositorio git: https://github.com/arjona00/opengl-periodic-table-of-elements/tree/20160214_VersionFinal
//
///////////////////////////////////////////////////////////////////////////////////////

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
            if (id < 0) id = 0;
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