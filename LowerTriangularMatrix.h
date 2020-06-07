#ifndef LOWERTRIANGULARMATRIX_H
#define LOWERTRIANGULARMATRIX_H

#include "AbstractSquareMatrix.h"


class LowerTriangularMatrix : public AbstractSquareMatrix {
private:
    int *matrix;
public:
    LowerTriangularMatrix() {};
    string getClassName() override;
    void readFromFile(ifstream *fin) override;
    void writeToFile(ofstream *fout) override;
    string getTypeMatrix() override;
    int getSumElementsMatrix();
};

#endif //LOWERTRIANGULARMATRIX_H