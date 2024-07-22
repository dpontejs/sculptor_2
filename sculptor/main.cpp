#include "sculptor.h"
#include "putbox.h"
#include "config.h"
#include "putsphere.h"
#include "putellipsoid.h"
#include <vector>

int main(void)
{
    Config *conf = new Config();
    conf->readConfigFile("input.txt");

    Sculptor *s = new Sculptor(conf->dimx, conf->dimy, conf->dimz);

    for (FiguraGeometrica* fig : conf->draws)
    {
        fig->draw(*s);
    }

    s->writeOFF("output.off");

    delete s;
    delete conf;

    return 0;
}
