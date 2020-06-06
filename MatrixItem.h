#ifndef MATRIXITEM_H
#define MATRIXITEM_H

#include "AbstractSquareMatrix.h"


class MatrixItem {
public:
    AbstractSquareMatrix *matrix;
    MatrixItem *nextMatrix;
};


#endif //MATRIXITEM_H
