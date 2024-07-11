#include "putvoxel.h"

PutVoxel::PutVoxel(int x, int y, int z, float r, float g, float b, float a)
{
    this->x = x;
    this->y = y;
    this->z = z;
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = a;
}

void PutVoxel::draw(Sculptor &t) {
    t.v[x][y][z].show = true;
    t.v[x][y][z].r = r;
    t.v[x][y][z].g = g;
    t.v[x][y][z].b = b;
    t.v[x][y][z].a = a;
}
