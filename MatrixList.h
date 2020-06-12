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
    int getSize();
    virtual void addMatrix(AbstractSquareMatrix *squareMatrix);
    virtual bool readMatricesFromFile(string filename);
    virtual bool writeMatricesToFile(string filename);
    virtual void sortList();
};


#endif //MATRIXLIST_H
