#include "config.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

void Config::readConfigFile(const char *filename)
{
    std::ifstream file(filename);
    std::string line;

    if (!file.is_open())
    {
        std::cerr << "Não foi possível abrir o arquivo " << filename << std::endl;
        return;
    }

    while (std::getline(file, line))
    {
        std::istringstream iss(line);
        std::string comando;

        if (comando == "dim")
        {
            int x, y, z;
            iss >> x >> y >> z;
            this->dimx = x;
            this->dimy = y;
            this->dimz = z;
        }

        else if (comando == "putvoxel")
        {
            int x, y, z;
            float r, g, b, a;
            iss >> x >> y >> z >> r >> g >> b >> a;
            draws.push_back(new PutVoxel(x,y,z,r,g,b,a));
        }

        else if (comando == "cutvoxel")
        {
            int x, y, z;
            iss >> x >> y >> z;
            draws.push_back(new CutVoxel(x,y,z));
        }

        else if (comando == "putbox")
        {
            int x0, x1, y0, y1, z0, z1;
            float r, g, b, a;
            iss >> x0 >> x1 >> y0 >> y1 >> z0 >> z1 >> r >> g >> b >> a;
            draws.push_back(new PutBox(x0,x1,y0,y1,z0,z1,r,g,b,a));
        }

        else if (comando == "cutbox")
        {
            int x0, x1, y0, y1, z0, z1;
            iss >> x0 >> x1 >> y0 >> y1 >> z0 >> z1;
            draws.push_back(new CutBox(x0,x1,y0,y1,z0,z1));
        }

        else if (comando == "putsphere")
        {
            int xc, yc, zc, radius;
            float r, g, b, a;
            iss >> xc >> yc >> zc >> radius >> r >> g >> b >> a;
            draws.push_back(new PutSphere(xc,yc,zc,radius,r,g,b,a));
        }

        else if (comando == "cutsphere")
        {
            int xc, yc, zc, radius;
            iss >> xc >> yc >> zc >> radius;
            draws.push_back(new CutSphere(xc,yc,zc,radius));
        }

        else if (comando == "putellipsoid")
        {
            int xc, yc, zc, rx, ry, rz;
            float r, g, b, a;
            iss >> xc >> yc >> zc >> rx >> ry >> rz >> r >> g >> b >> a;
            draws.push_back(new PutEllipsoid(xc,yc,zc,rx,ry,rz,r,g,b,a));
        }

        else if (comando == "cutellipsoid")
        {
            int xc, yc, zc, rx, ry, rz;
            iss >> xc >> yc >> zc >> rx >> ry >> rz;
            draws.push_back(new CutEllipsoid(xc,yc,zc,rx,ry,rz));
        }

        else
        {
            std::cerr << "Comando desconhecido " << comando << std::endl;
        }
    }

    file.close();

}

Config::~Config()
{
    for (FiguraGeometrica* fig : draws)
    {
        delete fig;
    }
}
