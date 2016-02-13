#include "paintprotonsneutrons.h"
#include<stdlib.h>

using namespace std;


void paintProtonsAndNeutronsRec(int protonsAmount, int neutronsAmount, float size, float positionXref, float positionYref, float positionZref, int protonsDrawed) {
    
    //Caso base
    if(protonsAmount > 0) {
        lightMaterialProtons();
        //Coloco el central y lo resto
        glTranslatef(positionXref, positionYref, positionZref);
        glutSolidSphere(size, 100, 100);
        glTranslatef(positionXref * -1, positionYref * -1, positionZref * -1);
        protonsAmount = protonsAmount - 1;
        protonsDrawed = protonsDrawed + 1;
        
        /*if(protonsAmount > 0) { //Ya se pintó el primero
            glTranslatef(positionXref - 0.3, positionYref - 0.9, positionZref - 1);
            glutSolidSphere(size, 100, 100);
            glTranslatef((positionXref - 0.3) * -1, (positionYref - 0.9) * -1, (positionZref - 1) * -1);
            protonsAmount = protonsAmount - 1;
            protonsDrawed = protonsDrawed + 1;
        }*/
            
        while(neutronsAmount > 0) {
            
            //Neutron izquierda
            lightMaterialNeutrons();
            glTranslatef(positionXref - 0.6, positionYref - 0.8, positionZref);
            glutSolidSphere(size, 100, 100);
            glTranslatef((positionXref - 0.6) * -1, (positionYref - 0.8) * - 1, positionZref * -1);
            neutronsAmount = neutronsAmount - 1;
            
            if(neutronsAmount > 0) {
                //Neutron a la derecha
                lightMaterialNeutrons();
                glTranslatef(positionXref - 0.5, positionYref + 0.8, positionZref);
                glutSolidSphere(size, 100, 100);
                glTranslatef((positionXref - 0.5) * -1, (positionYref + 0.8) * - 1, positionZref * -1);
                neutronsAmount = neutronsAmount - 1;
            }
            
            if(neutronsAmount > 0) {
                
                //Neutron arriba
                lightMaterialNeutrons();
                glTranslatef(positionXref - 0.9, positionYref - 1.8, positionZref);
                glutSolidSphere(size, 100, 100);
                glTranslatef((positionXref - 0.9) * -1, (positionYref - 1.8) * - 1, positionZref * -1);
                neutronsAmount = neutronsAmount - 1;
            }
            
            //Llamamos para que pinte protones alrededor
            paintProtonsAndNeutronsRec(protonsAmount- (protonsDrawed - 1), neutronsAmount, size, (positionXref - 0.6) + 1.1, (positionYref - 0.8), positionZref + 0.6, protonsDrawed);
        }
        
        //Llamamos para que pinte los protones restantes (hacemos dos llamadas para dividirlos en varios lugares y que no queden unidos).
            paintProtonsAndNeutronsRec(protonsAmount- protonsDrawed, neutronsAmount, size, (positionXref - 0.6) - 0.5, (positionYref - 0.1), positionZref, protonsDrawed);
            
    } else if(neutronsAmount > 0) {
        lightMaterialNeutrons();
        //Coloco el central y lo resto (en este caso sabemos que no hay protones)
        glTranslatef((positionXref - 0.6), (positionYref - 0.2), positionZref);
        glutSolidSphere(size, 100, 100);
        glTranslatef((positionXref - 0.6) * -1, (positionYref - 0.2) * -1, positionZref * -1);
        neutronsAmount = neutronsAmount - 1;
    }
}


void paintProtonsAndNeutrons(int protonsAmount, int neutronsAmount, float size) {
    
    //En este caso solo llamamos para pintar el primero en la posición inicial
    
    paintProtonsAndNeutronsRec(protonsAmount, neutronsAmount, size, -1.0, 0.0, 0.0, 0);

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
