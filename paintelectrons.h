#ifndef PAINTELECTRONS_H
#define PAINTELECTRONS_H

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

#endif // PAINTELECTRONS_H

void paintElectrons (int electronAmount, float electronSize, float angles[3] );
