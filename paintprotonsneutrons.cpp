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

#include "paintprotonsneutrons.h"
#include<stdlib.h>

using namespace std;


/*void paintProtonsAndNeutronsRec(int protonsAmount, int neutronsAmount, float size, float positionXref, float positionYref, float positionZref, int protonsDrawed) {
    


    //Caso base
    if(protonsAmount > 0) {
        lightMaterialProtons();

        //Coloco el central y lo resto
        glTranslatef(positionXref, positionYref, positionZref);
        glutSolidSphere(size, 20, 20);
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
            
        /*while(neutronsAmount > 0) {
            
            //Neutron izquierda
            lightMaterialNeutrons();
            glTranslatef(positionXref - 0.6, positionYref - 0.8, positionZref);
            glutSolidSphere(size, 20, 20);
            glTranslatef((positionXref - 0.6) * -1, (positionYref - 0.8) * - 1, positionZref * -1);
            neutronsAmount = neutronsAmount - 1;
            
            if(neutronsAmount > 0) {
                //Neutron a la derecha
                lightMaterialNeutrons();
                glTranslatef(positionXref - 0.5, positionYref + 0.8, positionZref);
                glutSolidSphere(size, 20, 20);
                glTranslatef((positionXref - 0.5) * -1, (positionYref + 0.8) * - 1, positionZref * -1);
                neutronsAmount = neutronsAmount - 1;
            }
            
            if(neutronsAmount > 0) {
                
                //Neutron arriba
                lightMaterialNeutrons();
                glTranslatef(positionXref - 0.9, positionYref - 1.8, positionZref);
                glutSolidSphere(size, 20, 20);
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

}*/


void paintProtonsAndNeutrons(int protonsAmount, int neutronsAmount, float size) {
    
    //En este caso solo llamamos para pintar el primero en la posición inicial
    //paintProtonsAndNeutronsRec(protonsAmount, neutronsAmount, size, 0.0, 0.0, 0.0, 0);
    
    int positionXref = 0.0;
    int positionYref = 0.0;
    int positionZref = 0.0;
    
    for(int i=0; i<protonsAmount; i++) {
        //Pintamos el protón
        lightMaterialProtons();
        glTranslatef(positionXref, positionYref, positionZref);
        glutSolidSphere(size, 20, 20);
        glTranslatef(positionXref * -1, positionYref * -1, positionZref * -1);
        cout << "He pintado un protón" << endl;
        
        
        //Pintamos varios neutrones por cada protón (ya que siempre hay más neutrones).
        
        if(neutronsAmount > 0) {
            lightMaterialNeutrons();
            glTranslatef(positionXref - 0.6, positionYref - 0.8, positionZref);
            glutSolidSphere(size, 20, 20);
            glTranslatef((positionXref - 0.6) * -1, (positionYref - 0.8) * - 1, positionZref * -1);
            neutronsAmount = neutronsAmount - 1;
        }
        
        if(neutronsAmount > 0) {
            lightMaterialNeutrons();
            glTranslatef(positionXref - 0.4, positionYref + 0.8, positionZref);
            glutSolidSphere(size, 20, 20);
            glTranslatef((positionXref - 0.4) * -1, (positionYref + 0.8) * - 1, positionZref * -1);
            neutronsAmount = neutronsAmount - 1;
        }
        
        if(neutronsAmount > 0) {
            lightMaterialNeutrons();
            glTranslatef(positionXref - 0.9, positionYref - 1.9, positionZref);
            glutSolidSphere(size, 20, 20);
            glTranslatef((positionXref - 0.9) * -1, (positionYref - 1.9) * - 1, positionZref * -1);
            neutronsAmount = neutronsAmount - 1;
        }
        
        
        if(neutronsAmount > 0) {
            lightMaterialNeutrons();
            glTranslatef(positionXref - 0.9, positionYref - 1.9, positionZref - 1.0);
            glutSolidSphere(size, 20, 20);
            glTranslatef((positionXref - 0.9) * -1, (positionYref - 1.9) * - 1, (positionZref - 1.0) * -1);
            neutronsAmount = neutronsAmount - 1;
        }
        
        if(i < protonsAmount - 1) { //pintamos otro protón
            lightMaterialProtons();
            glTranslatef(positionXref, positionYref - 0.8, positionZref + 0.3);
            glutSolidSphere(size, 20, 20);
            glTranslatef(positionXref * -1, (positionYref - 0.8) * -1, (positionZref + 0.3) * -1);
            cout << "He pintado un protón" << endl;
            i = i + 1;
        }
        
        //if(i % 2 == 0) { //Lo conecto al último neutrón
            positionXref = (positionXref - 0.6) + 2.1;
            positionYref = positionYref;
            positionZref = positionZref + 0.1;
        /*} else { //Lo conecto al primer neutrón
            positionXref = (positionXref - 0.6) + 1.1;
            positionYref = (positionYref - 0.8) - 0.2;
            positionZref = positionZref;
        }*/
        
    }

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
