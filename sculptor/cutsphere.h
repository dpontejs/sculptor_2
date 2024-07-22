#ifndef CUTSPHERE_H
#define CUTSPHERE_H

#include "figuraGeometrica.h"

class CutSphere : public FiguraGeometrica
{
private:
    int xcenter;
    int ycenter;
    int zcenter;
    int radius;
public:
    explicit CutSphere(int xcenter, int ycenter, int zcenter, int radius);
    void draw(Sculptor &t);
};

#endif // CUTSPHERE_H
