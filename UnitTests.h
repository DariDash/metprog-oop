#ifndef UNITTESTS_H
#define UNITTESTS_H

#include "MatrixList.h"
#include "SquareMatrix.h"
#include "DiagonalMatrix.h"
#include "LowerTriangularMatrix.h"
#include <cassert>


class UnitTests {
public:
    void run();
private:
    void testAddMatrix();
    void testReadWriteFromFile();
    void testGetSumElementsMatrix();
    void testSortMatrixList();
    void testFilterMatrixList();
};

#endif //UNITTESTS_H
