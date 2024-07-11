#include "sculptor.h"
#include "voxel.h"
#include <iostream>
#include <fstream>

Sculptor::Sculptor(int _nx, int _ny, int _nz)
{
    nx = _nx; ny = _ny; nz = _nz;

    if (nx > 0 || ny > 0 || nz > 0) {

        v = new Voxel**[nx];

        for(int i = 0; i < nx; i++) {
            v[i] = new Voxel*[ny];
            for (int j = 0; j < ny; j++) {
                v[i][j] = new Voxel[nz];
            }
        }
    }
}

Sculptor::~Sculptor()
{
    if (v!= nullptr) {
        for (int i = 0;  i < nx; i++) {
            for (int j = 0; j < ny; j++) {
                delete[] v[i][j];
            }
            delete[] v[i];
        }
        delete [] v;
    }

}

void Sculptor::writeOFF(const char* filename) {
    std::ofstream ofs(filename);
    if (!ofs.is_open()) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return;
    }

    ofs << "OFF\n";

    int nVoxels = 0;
    for (int i = 0; i < nx; i++) {
        for (int j = 0; j < ny; j++) {
            for (int k = 0; k < nz; k++) {
                if (v[i][j][k].show) {
                    nVoxels++;
                }
            }
        }
    }

    int nVertices = nVoxels * 8;
    int nFaces = nVoxels * 6;
    ofs << nVertices << " " << nFaces << " 0\n";

    for (int i = 0; i < nx; i++) {
        for (int j = 0; j < ny; j++) {
            for (int k = 0; k < nz; k++) {
                if (v[i][j][k].show) {
                    float x = i - 0.5, y = j - 0.5, z = k - 0.5;
                    ofs << x << " " << y << " " << z << "\n";
                    ofs << x + 1 << " " << y << " " << z << "\n";
                    ofs << x + 1 << " " << y + 1 << " " << z << "\n";
                    ofs << x << " " << y + 1 << " " << z << "\n";
                    ofs << x << " " << y << " " << z + 1 << "\n";
                    ofs << x + 1 << " " << y << " " << z + 1 << "\n";
                    ofs << x + 1 << " " << y + 1 << " " << z + 1 << "\n";
                    ofs << x << " " << y + 1 << " " << z + 1 << "\n";
                }
            }
        }
    }

    int voxelIndex = 0;
    for (int i = 0; i < nx; i++) {
        for (int j = 0; j < ny; j++) {
            for (int k = 0; k < nz; k++) {
                if (v[i][j][k].show) {
                    int baseIndex = voxelIndex * 8;
                    ofs << "4 " << baseIndex << " " << baseIndex + 1 << " " << baseIndex + 2 << " " << baseIndex + 3 << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << "\n";
                    ofs << "4 " << baseIndex + 4 << " " << baseIndex + 5 << " " << baseIndex + 6 << " " << baseIndex + 7 << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << "\n";
                    ofs << "4 " << baseIndex << " " << baseIndex + 1 << " " << baseIndex + 5 << " " << baseIndex + 4 << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << "\n";
                    ofs << "4 " << baseIndex << " " << baseIndex + 4 << " " << baseIndex + 7 << " " << baseIndex + 3 << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << "\n";
                    ofs << "4 " << baseIndex + 3 << " " << baseIndex + 7 << " " << baseIndex + 6 << " " << baseIndex + 2 << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << "\n";
                    ofs << "4 " << baseIndex + 1 << " " << baseIndex + 2 << " " << baseIndex + 6 << " " << baseIndex + 5 << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << "\n";
                    voxelIndex++;
                }
            }
        }
    }

    ofs.close();
}
