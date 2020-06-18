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
    void multiMethod(AbstractSquareMatrix* otherMatrix, ofstream *fout) override;
    void mMDiagonal(ofstream *fout) override;
    void mMSquare(ofstream *fout) override;
    void mMLowerTriangular(ofstream *fout) override;
};

#endif //LOWERTRIANGULARMATRIX_H