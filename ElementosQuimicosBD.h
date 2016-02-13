//
//  ElementosQuimicosBD.h
//  Elementos_Quimicos
//
//  Created by Taty Person on 12/2/16.
//  Copyright © 2016 Tatiana Person Montero. All rights reserved.
//

#include "ElementoQuimico.h"
#include <vector>

class ElementosQuimicosBD {

    private: //Lista de elementos químicos para utilizarlos desde la aplicación de OpenGL.

        vector<ElementoQuimico> elementos;

    public: //Operaciones para acceder a la lista.

        ElementosQuimicosBD() {}

        void addElemento(ElementoQuimico e);
        void removeElemento(int i);
        ElementoQuimico getElemento(int i);
        int size();
        bool empty();
        void loadBD();
};

void ElementosQuimicosBD::addElemento(ElementoQuimico e) {
    this->elementos.push_back(e);
}

void ElementosQuimicosBD::removeElemento(int i) {
    this->elementos.erase(elementos.begin() + i - 1);
}

ElementoQuimico ElementosQuimicosBD::getElemento(int i) {
    return elementos[i];
}

int ElementosQuimicosBD::size() {
    return elementos.size();
}

bool ElementosQuimicosBD::empty() {
    return elementos.empty();
}

void ElementosQuimicosBD::loadBD() {

    ElementoQuimico elemento_cero = ElementoQuimico("---", "---", 0, 0, 0, 0);
    addElemento(elemento_cero);

    cout << "1 - Hidrógeno: " << endl;
    ElementoQuimico hidrogeno = ElementoQuimico("Hidrógeno", "H", 1, 1, 1.00794, 1);
    addElemento(hidrogeno);
    cout << "Hidrógeno OK." << endl;

    cout << "2 - Helio: " << endl;
    ElementoQuimico helio = ElementoQuimico("Helio", "He", 2, 2, 4.002602, 2);
    addElemento(helio);
    cout << "Helio OK." << endl;

    cout << "3 - Litio: " << endl;
    ElementoQuimico litio = ElementoQuimico("Litio", "Li", 3, 3, 6.941, 3);
    addElemento(litio);
    cout << "Litio OK." << endl;

    cout << "4 - Berilio: " << endl;
    ElementoQuimico berilio = ElementoQuimico("Berilio", "Be", 4, 4, 9.021182, 4);
    addElemento(berilio);
    cout << "Berilio OK." << endl;

    cout << "5 - Boro: " << endl;
    ElementoQuimico boro = ElementoQuimico("Boro", "B", 5, 5, 10.811, 5);
    addElemento(boro);
    cout << "Boro OK." << endl;

    cout << "6 - Carbono: " << endl;
    ElementoQuimico carbono = ElementoQuimico("Carbono", "C", 6, 6, 12.0107, 6);
    addElemento(carbono);
    cout << "Carbono OK." << endl;

    cout << "7 - Nitrógeno: " << endl;
    ElementoQuimico nitrogeno = ElementoQuimico("Nitrógeno", "N", 7, 7, 14.00674, 7);
    addElemento(nitrogeno);
    cout << "Nitrógeno OK." << endl;

    cout << "8 - Oxígeno: " << endl;
    ElementoQuimico oxigeno = ElementoQuimico("Oxígeno", "O", 8, 8, 15.9994, 8);
    addElemento(oxigeno);
    cout << "Oxígeno OK." << endl;

    cout << "9 - Flúor: " << endl;
    ElementoQuimico fluor = ElementoQuimico("Flúor", "F", 9, 9, 18.9984032, 9);
    addElemento(fluor);
    cout << "Flúor OK." << endl;

    cout << "10 - Neón: " << endl;
    ElementoQuimico neon = ElementoQuimico("Neón", "Ne", 10, 10, 20.1797, 10);
    addElemento(neon);
    cout << "Neón OK." << endl;

    cout << "11 - Sodio: " << endl;
    ElementoQuimico sodio = ElementoQuimico("Sodio", "Na", 11, 11, 22.989770, 11);
    addElemento(sodio);
    cout << "Sodio OK." << endl;

    cout << "12 - Magnesio: " << endl;
    ElementoQuimico magnesio = ElementoQuimico("Magnesio", "Mg", 12, 12, 24.3050, 12);
    addElemento(magnesio);
    cout << "Magnesio OK." << endl;

    cout << "13 - Aluminio: " << endl;
    ElementoQuimico aluminio = ElementoQuimico("Aluminio", "Al", 13, 13, 26.981538, 13);
    addElemento(aluminio);
    cout << "Aluminio OK." << endl;

    cout << "14 - Silicio: " << endl;
    ElementoQuimico silicio = ElementoQuimico("Silicio", "Si", 14, 14, 28.0855, 14);
    addElemento(silicio);
    cout << "Silicio OK." << endl;

    cout << "15 - Fósforo: " << endl;
    ElementoQuimico fosforo = ElementoQuimico("Fósforo", "P", 15, 15, 30.973761, 15);
    addElemento(fosforo);
    cout << "Fósforo OK." << endl;

    cout << "16 - Azufre: " << endl;
    ElementoQuimico azufre = ElementoQuimico("Azufre", "S", 16, 16, 32.066, 16);
    addElemento(azufre);
    cout << "Azufre OK." << endl;

    cout << "17 - Cloro: " << endl;
    ElementoQuimico cloro = ElementoQuimico("Cloro", "Cl", 17, 17, 35.453, 17);
    addElemento(cloro);
    cout << "Cloro OK." << endl;

    cout << "18 - Argón: " << endl;
    ElementoQuimico argon = ElementoQuimico("Argón", "A", 18, 18, 39.948, 18);
    addElemento(argon);
    cout << "Argón OK." << endl;

    cout << "19 - Potasio: " << endl;
    ElementoQuimico potasio = ElementoQuimico("Potasio", "K", 19, 19, 39.0983, 19);
    addElemento(potasio);
    cout << "Potasio OK." << endl;

    cout << "20 - Calcio: " << endl;
    ElementoQuimico calcio = ElementoQuimico("Calcio", "Ca", 20, 20, 40.078, 20);
    addElemento(calcio);
    cout << "Calcio OK." << endl;

    cout << "21 - Escandio: " << endl;
    ElementoQuimico escandio = ElementoQuimico("Escandio", "Sc", 21, 21, 44.955910, 21);
    addElemento(escandio);
    cout << "Escandio OK." << endl;

    cout << "22 - Titanio: " << endl;
    ElementoQuimico titanio = ElementoQuimico("Titanio", "Ti", 22, 22, 47.867, 22);
    addElemento(titanio);
    cout << "Titanio OK." << endl;

    cout << "23 - Vanadio: " << endl;
    ElementoQuimico vanadio = ElementoQuimico("Vanadio", "V", 23, 23, 50.9415, 23);
    addElemento(vanadio);
    cout << "Vanadio OK." << endl;

    cout << "24 - Cromo: " << endl;
    ElementoQuimico cromo = ElementoQuimico("Cromo", "Cr", 24, 24, 51.9961, 24);
    addElemento(cromo);
    cout << "Cromo OK." << endl;

    cout << "25 - Manganeso: " << endl;
    ElementoQuimico manganeso = ElementoQuimico("Manganeso", "Mn", 25, 25, 54.938049, 25);
    addElemento(manganeso);
    cout << "Manganeso OK." << endl;

    cout << "26 - Hierro: " << endl;
    ElementoQuimico hierro = ElementoQuimico("Hierro", "Fe", 26, 26, 55.8457, 26);
    addElemento(hierro);
    cout << "Hierro OK." << endl;

    cout << "27 - Cobalto: " << endl;
    ElementoQuimico cobalto = ElementoQuimico("Cobalto", "Co", 27, 27, 58.933200, 27);
    addElemento(cobalto);
    cout << "Cobalto OK." << endl;

    cout << "28 - Níquel: " << endl;
    ElementoQuimico niquel = ElementoQuimico("Níquel", "Ni", 28, 28, 58.6934, 28);
    addElemento(niquel);
    cout << "Níquel OK." << endl;

    cout << "29 - Cobre: " << endl;
    ElementoQuimico cobre = ElementoQuimico("Cobre", "Cu", 29, 29, 63.546, 29);
    addElemento(cobre);
    cout << "Cobre OK." << endl;

    cout << "30 - Cinc: " << endl;
    ElementoQuimico cinc = ElementoQuimico("Cinc", "Zn", 30, 30, 65.409, 30);
    addElemento(cinc);
    cout << "Cinc OK." << endl;

}


