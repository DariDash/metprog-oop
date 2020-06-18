#ifndef DIAGONALMATRIX_H
#define DIAGONALMATRIX_H

#include "AbstractSquareMatrix.h"


class DiagonalMatrix : public AbstractSquareMatrix {
private:
    int *matrix;
public:
    DiagonalMatrix() {};
    string getClassName() override;
    void readFromFile(ifstream *fin) override;
    void writeToFile(ofstream *fout) override;
    string getTypeMatrix() override;
    int getSumElementsMatrix() override;
    void multiMethod(AbstractSquareMatrix* otherMatrix, ofstream *fout) override;
    void mMDiagonal(ofstream *fout) override;
    void mMSquare(ofstream *fout) override;
    void mMLowerTriangular(ofstream *fout) override;
};


#endif // DIAGONALMATRIX_H
