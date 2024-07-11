#include "putellipsoid.h"

PutEllipsoid::PutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz, float r, float g, float b, float a)
{
    this->xcenter = xcenter;
    this->ycenter = ycenter;
    this->zcenter = zcenter;
    this->rx = rx;
    this->ry = ry;
    this->rz = rz;
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = a;
}

void PutEllipsoid::draw(Sculptor &t){
    float e1, e2, e3, soma;

    for (int i = 0; i < t.nx; i++) {
        for (int j = 0; j < t.ny; j++) {
            for (int k = 0; k < t.nz; k++) {
                e1 = ((i-xcenter)/rx);
                e2 = ((j-ycenter)/ry);
                e3 = ((k-zcenter)/rz);
                soma = (e1*e1) + (e2*e2) + (e3*e3);
                if (soma <= 1.0) {
                    t.v[i][j][k].show = true;
                    t.v[i][j][k].r = r;
                    t.v[i][j][k].g = g;
                    t.v[i][j][k].b = b;
                    t.v[i][j][k].a = a;
                }
            }
        }
    }
}
