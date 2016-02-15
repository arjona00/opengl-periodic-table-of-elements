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
///////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "paintelectrons.h"
using namespace std;

void paintElectrons (int electronAmount, float electronSize, float angles[3] )
{

    // Create electrons

    // Material properties of sphere 3 - electron.
    float matAmb3[] = {0.18275f, 0.17f, 0.62525f, 1.0};
    float matDif3[] = {0.332741f, 0.328634f, 0.746435f, 1.0};
    float matSpec3[] = { 0.25, 0.13, 0.08, 1.0 };
    float matShine3[] = { 2.3 };
    float matEmission3[] = {0.0, 0.0, 0.0, 1.0};
    glMaterialfv(GL_FRONT, GL_AMBIENT, matDif3);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, matSpec3);
    glMaterialfv(GL_FRONT, GL_SPECULAR, matAmb3);
    glMaterialfv(GL_FRONT, GL_SHININESS, matShine3);
    glMaterialfv(GL_FRONT, GL_EMISSION, matEmission3);



    if (electronAmount != 0)
    {
        glRotatef(angles[0], 0.0, 1.0, 0.0); //Base rotation Y

        //Layer 1
        if (electronAmount > 0)
        {
            glTranslatef(3.0, 0.0, 0.0);
            glutSolidSphere( electronSize, 10, 10);
            glTranslatef(-3.0, 0.0, 0.0); // center the spin
            electronAmount--;
        }

        if (electronAmount > 0)
        {
            glRotatef(180, 0.0, 1.0, 0.0);

            glTranslatef(3, 0.0, 0.0);
            glutSolidSphere( electronSize, 10, 10);
            glTranslatef(-3.0, 0.0, 0.0); // center the spin
            electronAmount--;
            }

        //Layer 2
        // Changed rotation plane
        glRotatef(-angles[0], 0.0, 1.0, 0.0); //Base rotation Y centered
        glRotatef(angles[1], 1.0, 0.0, 0.0); //Base rotation X

        if (electronAmount > 0)
        {
            glTranslatef(0.0, 4.0, 0.0);
            glutSolidSphere(electronSize, 10, 10);
            glTranslatef(0.0, -4.0, 0.0); // center the spin

            electronAmount--;
            }

        if (electronAmount > 0)
        {
            glRotatef(180, 1.0, 0.0, 0.0); //rotation X 180

            glTranslatef(0.0, 4.0, 0.0);
            glutSolidSphere( electronSize, 10, 10);
            glTranslatef(0.0, -4.0, 0.0); // center the spin
            electronAmount--;
        }

        if (electronAmount > 0)
        {
            glRotatef(90, 1.0, 0.0, 0.0); //rotation X 90

            glTranslatef(0.0, 4.0, 0.0);
            glutSolidSphere( electronSize, 10, 10);
            glTranslatef(0.0, -4.0, 0.0);
            electronAmount--;
        }

        if (electronAmount > 0)
        {
            glRotatef(180, 1.0, 0.0, 0.0); //rotation X 270
            glTranslatef(0.0, 4.0, 0.0);
            glutSolidSphere( electronSize, 10, 10);
            glTranslatef(0.0, -4.0, 0.0);
            electronAmount--;
        }

        //Layer 3
        // Changed rotation plane
        glRotatef(-angles[1], 1.0, 0.0, 0.0); //Base rotation X centered
        glRotatef(angles[2], 0.0, 1.0, 1.0); //Base rotation YZ

        if (electronAmount > 0)
        {
            glTranslatef(5.0, 0.0, 0.0);
            glutSolidSphere(electronSize, 10, 10);
            glTranslatef(-5.0, 0.0, 0.0); // center the spin

            electronAmount--;
        }

        if (electronAmount > 0)
        {
            glRotatef(180, 0.0, 1.0, 1.0); //rotation YZ 180

            glTranslatef(5.0, 0.0, 0.0);
            glutSolidSphere( electronSize, 10, 10);
            glTranslatef(-5.0, 0.0, 0.0); // center the spin
            electronAmount--;
        }
        if (electronAmount > 0)
        {
            glRotatef(90, 0.0, 1.0, 1.0); //rotation YZ 90

            glTranslatef(5.0, 0.0, 0.0);
            glutSolidSphere( electronSize, 10, 10);
            glTranslatef(-5.0, 0.0, 0.0);
            electronAmount--;
        }

        if (electronAmount > 0)
        {
            glRotatef(180, 0.0, 1.0, 1.0); //rotation YZ 180
            glTranslatef(5.0, 0.0, 0.0);
            glutSolidSphere( electronSize, 10, 10);
            glTranslatef(-5.0, 0.0, 0.0);
            electronAmount--;
        }

        // Change rotation plane
        glRotatef(-angles[2], 0.0, 1.0, 1.0); //Base rotation ZY centered
        glRotatef(angles[2], 1.0, 1.0, 0.0); //Base rotation XY
        if (electronAmount > 0)
        {
            glTranslatef(0.0, 0.0, 5.0);
            glutSolidSphere(electronSize, 10, 10);
            glTranslatef(0.0, 0.0, -5.0); // center the spin

            electronAmount--;
        }

        if (electronAmount > 0)
        {
            glRotatef(180, 1.0, 1.0, 0.0); //rotation YZ 180

            glTranslatef(0.0, 0.0, 5.0);
            glutSolidSphere( electronSize, 10, 10);
            glTranslatef(0.0, 0.0, -5.0); // center the spin
            electronAmount--;
        }
        if (electronAmount > 0)
        {
            glRotatef(90, 1.0, 1.0, 0.0); //rotation YZ 90

            glTranslatef(0.0, 0.0, 5.0);
            glutSolidSphere( electronSize, 10, 10);
            glTranslatef(0.0, 0.0, -5.0);
            electronAmount--;
        }

        if (electronAmount > 0)
        {
            glRotatef(180, 1.0, 1.0, 0.0); //rotation YZ 180
            glTranslatef(0.0, 0.0, 5.0);
            glutSolidSphere( electronSize, 10, 10);
            glTranslatef(0.0, 0.0, -5.0);
            electronAmount--;
        }

        // Change rotation plane
        glRotatef(-angles[2], 1.0, 1.0, 0.0); //Base rotation X centered
        glRotatef(angles[2], 1.0, 0.0, 1.0); //Base rotation XZ
        if (electronAmount > 0)
        {
            glTranslatef(0.0, 5.0, 0.0);
            glutSolidSphere(electronSize, 10, 10);
            glTranslatef(0.0, -5.0, 0.0); // center the spin

            electronAmount--;
        }

        if (electronAmount > 0)
        {
            glRotatef(180, 1.0, 0.0, 1.0); //rotation YZ 180

            glTranslatef(0.0, 5.0, 0.0);
            glutSolidSphere( electronSize, 10, 10);
            glTranslatef(0.0, -5.0, 0.0); // center the spin
            electronAmount--;
        }
        if (electronAmount > 0)
        {
            glRotatef(90, 1.0, 0.0, 1.0); //rotation YZ 90

            glTranslatef(0.0, 5.0, 0.0);
            glutSolidSphere( electronSize, 10, 10);
            glTranslatef(0.0, -5.0, 0.0);
            electronAmount--;
        }

        if (electronAmount > 0)
        {
            glRotatef(180, 1.0, 0.0, 1.0); //rotation YZ 180
            glTranslatef(0.0, 5.0, 0.0);
            glutSolidSphere( electronSize, 10, 10);
            glTranslatef(0.0, -5.0, 0.0);
            electronAmount--;
        }
    }
}
