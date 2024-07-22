#ifndef PUTELLIPSOID_H
#define PUTELLIPSOID_H

#include "figuraGeometrica.h"

class PutEllipsoid : public FiguraGeometrica
{
private:
    int xcenter;
    int ycenter;
    int zcenter;
    int rx;
    int ry;
    int rz;
    float r;
    float g;
    float b;
    float a;
public:
    explicit PutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz, float r, float g, float b, float a);
    void draw(Sculptor &t);
};

#endif // PUTELLIPSOID_H
