#ifndef MATRIXLIST_H
#define MATRIXLIST_H

#include <string>

#include "AbstractSquareMatrix.h"
#include "MatrixItem.h"

using std::string;


class MatrixList {
private:
    int size;
    MatrixItem *firstMatrix;
    MatrixItem *lastMatrix;
public:
    MatrixList();
    virtual void addMatrix(AbstractSquareMatrix *squareMatrix);
    virtual bool readMatricesFromFile(string filename);
    virtual bool writeMatricesToFile(string filename);
};


#endif //MATRIXLIST_H
