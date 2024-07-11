#ifndef CONFIG_H
#define CONFIG_H

#include "vector"

#include "putvoxel.h"
#include "cutvoxel.h"
#include "putbox.h"
#include "cutbox.h"
#include "putsphere.h"
#include "cutsphere.h"
#include "putellipsoid.h"
#include "cutellipsoid.h"

class Config
{
public:
    explicit Config() { };
    virtual void readConfigFile(const char* filename);
    ~Config();
    std::vector<FiguraGeometrica *> draws;
    int dimx;
    int dimy;
    int dimz;
};

#endif // CONFIG_H
