#ifndef PUTBOX_H
#define PUTBOX_H

#include "figuraGeometrica.h"

class PutBox : public FiguraGeometrica
{
private:
    int x0;
    int x1;
    int y0;
    int y1;
    int z0;
    int z1;
    float r;
    float g;
    float b;
    float a;
public:
    explicit PutBox(int x0, int x1, int y0, int y1, int z0, int z1, float r, float g, float b, float a);
    void draw(Sculptor &t);
};

#endif // PUTBOX_H
