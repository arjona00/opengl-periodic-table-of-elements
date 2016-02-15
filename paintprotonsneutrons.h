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

#ifndef PAINTPROTONSNEUTRONS_H
#define PAINTPROTONSNEUTRONS_H

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

#endif // PAINTPROTONSNEUTRONS_H

#include <iostream>

void paintProtonsAndNeutrons(int protonsAmount, int neutronsAmount, float size);
void lightMaterialProtons();
void lightMaterialNeutrons();

