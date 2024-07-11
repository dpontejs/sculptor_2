#include "putsphere.h"

PutSphere::PutSphere(int xcenter, int ycenter, int zcenter, int radius, float r, float g, float b, float a)
{
    this->xcenter = xcenter;
    this->ycenter = ycenter;
    this->zcenter = zcenter;
    this->radius = radius;
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = a;
}

void PutSphere::draw(Sculptor &t){
    float r = radius*radius, e1, e2, e3, soma;

    for (int i = 0; i < t.nx; i++) {
        for (int j = 0; j < t.ny; j++) {
            for (int k = 0; k < t.nz; k++) {
                e1 = (i-xcenter);
                e2 = (j-ycenter);
                e3 = (k-zcenter);
                soma = (e1*e1) + (e2*e2) + (e3*e3);
                if (soma <= r) {
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
