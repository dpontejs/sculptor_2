#ifndef PUTSPHERE_H
#define PUTSPHERE_H

#include "figuraGeometrica.h"

class PutSphere : public FiguraGeometrica
{
private:
    int xcenter;
    int ycenter;
    int zcenter;
    int radius;
    float r;
    float g;
    float b;
    float a;
public:
    explicit PutSphere(int xcenter, int ycenter, int zcenter, int radius, float r, float g, float b, float a);
    virtual void draw(Sculptor &t);
};

#endif // PUTSPHERE_H
