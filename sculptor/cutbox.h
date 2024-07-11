#ifndef CUTBOX_H
#define CUTBOX_H

#include "figuraGeometrica.h"

class CutBox : public FiguraGeometrica
{
private:
    int x0;
    int x1;
    int y0;
    int y1;
    int z0;
    int z1;
public:
    explicit CutBox(int x0, int x1, int y0, int y1, int z0, int z1);
    virtual void draw(Sculptor &t);
};

#endif // CUTBOX_H
