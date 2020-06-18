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
    virtual void readMatricesFromFile(string filename);
    virtual void writeMatricesToFile(string filename);
    virtual void sortList();
    virtual void multiMethod(ofstream *fout);
};


#endif //MATRIXLIST_H
