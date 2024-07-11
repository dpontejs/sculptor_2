#ifndef SCULPTOR_H
#define SCULPTOR_H
#include "voxel.h"

//! Classe Sculptor
/*!
 * Classe que gera diferentes estruturas com o uso de Voxels, um struct que possui caracteristicas de cor, transparencia e inclusao.
    A classe usa diferentes métodos para inserir objetos, como um unico voxel, um retangulo, uma esfera e uma elipsoide.
*/

class Sculptor
{
public:
    Voxel*** v;
    int nx, ny, nz;
    float r, g, b, a;
    //! Construtor
    /*!
      O construtor realiza o processo de alocacao dinamica de uma matriz 3D de Voxels com as dimensoes especificadas.
      \param _nx dimensao no eixo x
      \param _ny dimensao no eixo y
      \param _nz dimensao no eixo z
    */

    explicit Sculptor(int _nx, int _ny, int _nz);

    //! Destrutor
    /*!
      O destrutor realiza o processo de desalocacao dinamica de uma matriz 3D de Voxels.
    */

    ~Sculptor();

    //! Metodo utilizado para criar um arquivo .off e escrever nele a representacao do desenho
    /*!
      \param filename nome do arquivo
    */

    void writeOFF(const char* filename);
};

#endif // SCULPTOR_H
