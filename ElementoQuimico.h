//
//  ElementoQuimico.h
//  Elementos_Quimicos
//
//  Created by Taty Person on 12/2/16.
//  Copyright © 2016 Tatiana Person Montero. All rights reserved.
//

#include<iostream>

using namespace std;

class ElementoQuimico {

    private: //Declaración de los atributos
    
        int protones, electrones, neutrones, numeroAtomico;
        string nombre, simbolo;
    
    public: //Métodos de acceso a los atributos
    
    ElementoQuimico(string nombre, string simbolo, int protones, int eletrones, int neutrones, int numeroAtomico);
    
    ElementoQuimico() {}
    
    inline int getProtones() { return protones; }
    inline int getElectrones() { return electrones; }
    inline int getNeutrones() { return electrones; }
    inline int getNumeroAtomico() { return numeroAtomico; }
    inline string getNombre() { return nombre; }
    inline string getSimbolo() { return simbolo; }
    inline void setProtones(int protones) { this->protones = protones; }
    inline void setElectrones(int electrones) { this->electrones = electrones; }
    inline void setNeutrones(int neutrones) { this->neutrones = neutrones; }
    inline void setNumeroAtomico(int numeroAtomico) { this->numeroAtomico = numeroAtomico; }
    inline void setNombre(string nombre) { this->nombre = nombre; }
    inline void setSimbolo(string simbolo) { this->simbolo = simbolo; }
    
};

ElementoQuimico::ElementoQuimico(string nombre, string simbolo, int protones, int electrones, int neutrones, int numeroAtomico) {
    
    this->nombre = nombre;
    this->simbolo = simbolo;
    this->protones = protones;
    this->electrones = electrones;
    this->neutrones = neutrones;
    this->numeroAtomico = numeroAtomico;
    
}
