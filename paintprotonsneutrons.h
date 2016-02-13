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

void paintProtonsAndNeutrons(int protonsAmount, int neutronsAmount, float size);
void lightMaterialProtons();
void lightMaterialNeutrons();

