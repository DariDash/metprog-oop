#ifndef LOWERTRIANGULARMATRIX_H
#define LOWERTRIANGULARMATRIX_H

#include "AbstractSquareMatrix.h"


class LowerTriangularMatrix : public AbstractSquareMatrix {
private:
    int *matrix;
public:
    LowerTriangularMatrix() {};
    void readFromFile(ifstream *fin) override;
    void writeToFile(ofstream *fout) override;
    string getTypeMatrix() override;
};

#endif //LOWERTRIANGULARMATRIX_H