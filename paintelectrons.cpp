#include "paintelectrons.h"

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


    glRotatef(angles[0], 0.0, 1.0, 0.0); //Base rotation Y

    if (electronAmount != 0)
    {
        //Layer 1
        if (electronAmount > 0)
        {
            glTranslatef(4.0, 0.0, 0.0);
            glutSolidSphere( electronSize, 150, 150);
            glTranslatef(-4.0, 0.0, 0.0); // center the spin
            glRotatef(120, 0.0, 1.0, 0.0);
            electronAmount--;
        }

        if (electronAmount > 0)
        {
            glTranslatef(2, 0.0, 0.0);
            glutSolidSphere( electronSize, 150, 150);
            glTranslatef(-2.0, 0.0, 0.0); // center the spin
            glRotatef(120, 0.0, 1.0, 0.0);
            electronAmount--;
            }

        //Layer 2
        if (electronAmount > 0)
        {
            glTranslatef(6.0, 0.0, 0.0);
            glutSolidSphere(electronSize, 150, 150);
            glTranslatef(-6.0, 0.0, 0.0); // center the spin

            electronAmount--;
            }

        // Changed rotation plane
        glRotatef(-angles[0], 0.0, 1.0, 0.0); //Base rotation Y centered
        glRotatef(angles[1], 1.0, 0.0, 0.0); //Base rotation X

        if (electronAmount > 0)
        {
            // Rotation X

            glTranslatef(0.0, 5.0, 0.0);
            glutSolidSphere( electronSize, 150, 150);
            glTranslatef(0.0, -5.0, 0.0); // center the spin
            electronAmount--;
        }

        if (electronAmount > 0)
        {
            glRotatef(180, 1.0, 0.0, 0.0);
            glTranslatef(0.0, 3.0, 0.0);
            glutSolidSphere( electronSize, 150, 150);
            glTranslatef(0.0, -3.0, 0.0);
            electronAmount--;
        }
    }
}
