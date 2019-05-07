#ifndef LOADTEXTURE_H_INCLUDED
#define LOADTEXTURE_H_INCLUDED

#include <GL/glut.h>
#include <cstdlib>
#include <cstdio>

typedef struct                       /**** BMP file info structure ****/
{
    unsigned int   biSize;           /* Size of info header */
    int            biWidth;          /* Width of image */
    int            biHeight;         /* Height of image */
    unsigned short biPlanes;         /* Number of color planes */
    unsigned short biBitCount;       /* Number of bits per pixel */
    unsigned int   biCompression;    /* Type of compression to use */
    unsigned int   biSizeImage;      /* Size of image data */
    int            biXPelsPerMeter;  /* X pixels per meter */
    int            biYPelsPerMeter;  /* Y pixels per meter */
    unsigned int   biClrUsed;        /* Number of colors used */
    unsigned int   biClrImportant;   /* Number of important colors */
    char *data;
} BITMPINFOHEADER;

GLuint LoadBitmap(const char *);

#endif // LOADTEXTURE_H_INCLUDED
