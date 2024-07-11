#include "cutellipsoid.h"

CutEllipsoid::CutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz)
{
    this->xcenter = xcenter;
    this->ycenter = ycenter;
    this->zcenter = zcenter;
    this->rx = rx;
    this->ry = ry;
    this->rz = rz;
}

void CutEllipsoid::draw(Sculptor &t){
    float e1, e2, e3, soma;

    for (int i = 0; i < t.nx; i++) {
        for (int j = 0; j < t.ny; j++) {
            for (int k = 0; k < t.nz; k++) {
                e1 = ((i-xcenter)/rx);
                e2 = ((j-ycenter)/ry);
                e3 = ((k-zcenter)/rz);
                soma = (e1*e1) + (e2*e2) + (e3*e3);
                if (soma <= 1.0) {
                    t.v[i][j][k].show = false;
                }
            }
        }
    }
}
