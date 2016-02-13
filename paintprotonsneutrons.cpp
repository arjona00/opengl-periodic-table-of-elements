#include "paintprotonsneutrons.h"



void paintProtons (int protonsAmount, float size){
    //Aqui debe haber un bucle
   glTranslatef(-1.1, 0.0, 0.0); // Move the sphere.
   glutSolidSphere( 0.6, 200, 200);
   glTranslatef(-1.1, 1.0, 0.0); // Move the sphere. //Lo pongo en el mismo sitio y lo bajo (para que no se una con el otro protón)
   glutSolidSphere( 0.6, 200, 200);
   glTranslatef(2.2, 0.0, 0.0);
}

void paintNeutrons (int neutronsAmount, float size){
    //Aqui debe haber un bucle
    glTranslatef(-2.2, 0.0, 0.0);
    glTranslatef(1.1, 0.0, 0.0); // Move the sphere.
    glutSolidSphere( 0.6, 200, 200);
    glTranslatef(-1.0, -1.0, 0.0); // Move the sphere. //Lo pongo donde el protón y lo bajo (para que no se una al neutrón).
    glutSolidSphere( 0.6, 200, 200);
}

void lightMaterialProtons(){

    // Create protons
    // Material properties of sphere 1.  - Proton
    float matAmb[] = {0.6, 0.1, 0.05, 1.0};
    float matDif[] = {0.6, 0.1, 0.05, 1.0};
    float matSpec[] = { 0.5, 0.5, 0.5, 1.0 };
    float matShine[] = { 32 };
    float matEmission[] = {0.0, 0.0, 0.0, 1.0};

    glMaterialfv(GL_FRONT, GL_AMBIENT, matAmb);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, matDif);
    glMaterialfv(GL_FRONT, GL_SPECULAR, matSpec);
    glMaterialfv(GL_FRONT, GL_SHININESS, matShine);
    glMaterialfv(GL_FRONT, GL_EMISSION, matEmission);
}

void lightMaterialNeutrons(){
    // Create neutrons
    // Material properties of sphere 2.  - Neutron
    float matAmb2[] = {1.0, 1.0, 1.0, 1.0};
    float matDif2[] = {1.0, 1.0, 1.0, 1.0};
    float matSpec2[] = { 1.0, 1.0, 1.0, 1.0 };
    float matShine2[] = { 32 };
    float matEmission2[] = {0.0, 0.0, 0.0, 1.0};

    glMaterialfv(GL_FRONT, GL_AMBIENT, matAmb2);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, matDif2);
    glMaterialfv(GL_FRONT, GL_SPECULAR, matSpec2);
    glMaterialfv(GL_FRONT, GL_SHININESS, matShine2);
    glMaterialfv(GL_FRONT, GL_EMISSION, matEmission2);
}
