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
        iss >> comando;

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
            int xcenter, ycenter, zcenter, radius;
            float r, g, b, a;
            iss >> xcenter >> ycenter >> zcenter >> radius >> r >> g >> b >> a;
            draws.push_back(new PutSphere(xcenter,ycenter,zcenter,radius,r,g,b,a));
        }

        else if (comando == "cutsphere")
        {
            int xcenter, ycenter, zcenter, radius;
            iss >> xcenter >> ycenter >> zcenter >> radius;
            draws.push_back(new CutSphere(xcenter,ycenter,zcenter,radius));
        }

        else if (comando == "putellipsoid")
        {
            int xcenter, ycenter, zcenter, rx, ry, rz;
            float r, g, b, a;
            iss >> xcenter >> ycenter >> zcenter >> rx >> ry >> rz >> r >> g >> b >> a;
            draws.push_back(new PutEllipsoid(xcenter,ycenter,zcenter,rx,ry,rz,r,g,b,a));
        }

        else if (comando == "cutellipsoid")
        {
            int xcenter, ycenter, zcenter, rx, ry, rz;
            iss >> xcenter >> ycenter >> zcenter >> rx >> ry >> rz;
            draws.push_back(new CutEllipsoid(xcenter,ycenter,zcenter,rx,ry,rz));
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
