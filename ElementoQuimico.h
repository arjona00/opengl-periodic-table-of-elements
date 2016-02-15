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


#include<iostream>
#include<cmath>

using namespace std;

class ElementoQuimico {

    private: //Declaración de los atributos

        int protones, electrones, neutrones, numeroAtomico;
        string nombre, simbolo;

        float masaAtomica;
    
    public: //Métodos de acceso a los atributos
    
    ElementoQuimico(string nombre, string simbolo, int protones, int eletrones, float masaAtomica, int numeroAtomico);

    ElementoQuimico() {}

    inline int getProtones() { return protones; }
    inline int getElectrones() { return electrones; }
    inline int getNeutrones() { return neutrones; }
    inline int getNumeroAtomico() { return numeroAtomico; }
    inline float getMasaAtomica() { return masaAtomica; }
    inline string getNombre() { return nombre; }
    inline string getSimbolo() { return simbolo; }
    inline void setProtones(int protones) { this->protones = protones; }
    inline void setElectrones(int electrones) { this->electrones = electrones; }
    inline void setNeutrones(int neutrones) { this->neutrones = neutrones; }
    inline void setNumeroAtomico(int numeroAtomico) { this->numeroAtomico = numeroAtomico; }
    inline void setMasaAtomica(float masaAtomica) { this->masaAtomica = masaAtomica;}
    inline void setNombre(string nombre) { this->nombre = nombre; }
    inline void setSimbolo(string simbolo) { this->simbolo = simbolo; }

};


ElementoQuimico::ElementoQuimico(string nombre, string simbolo, int protones, int electrones, float masaAtomica, int numeroAtomico) {

    this->nombre = nombre;
    this->simbolo = simbolo;
    this->protones = protones;
    this->electrones = electrones;
    this->masaAtomica = masaAtomica;
    int roundMasaAtomica = round(masaAtomica);
    this->neutrones = roundMasaAtomica - protones;
    this->numeroAtomico = numeroAtomico;

}
