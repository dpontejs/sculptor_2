#ifndef CUTVOXEL_H
#define CUTVOXEL_H

#include "figuraGeometrica.h"

class CutVoxel : public FiguraGeometrica
{
private:
    int x;
    int y;
    int z;
public:
    explicit CutVoxel(int x, int y, int z);
    virtual void draw(Sculptor &t);
};

#endif // CUTVOXEL_H
