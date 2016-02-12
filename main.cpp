//
//  main.cpp
//  Elementos_Quimicos
//
//  Created by Taty Person on 12/2/16.
//  Copyright © 2016 Tatiana Person Montero. All rights reserved.
//

#include <iostream>
#include "ElementosQuimicosBD.h"

using namespace std;

int main(int argc, const char * argv[]) {
    
    cout << "Creando bateria de elementos químicos.." << endl;
    ElementosQuimicosBD elementos = ElementosQuimicosBD();
    elementos.loadBD(); //Cargamos los 30 elementos
    
    //Llamadas a los métodos de la clase de prueba
    cout << "Nombre: " << elementos.getElemento(0).getNombre() << endl;
    cout << "Size: " << elementos.size() << endl;
    cout << "Empty? " << elementos.empty() << endl;
    
    //Tests para la masa atomica y número de neutrones:
    for(int i=0; i<elementos.size(); i++) {
        cout << "-------------------------------------------------------" << endl;
        cout << "Nombre: " << elementos.getElemento(i).getNombre() << endl;
        cout << "Masa atómica sin redondear: " << elementos.getElemento(i).getMasaAtomica() << endl;
        cout << "Masa atómica redondeada: " << round(elementos.getElemento(i).getMasaAtomica()) << endl;
        cout << "Neutrones: " << elementos.getElemento(i).getNeutrones() << endl;
    }
    
    return 0;
}