#ifndef DIAGONALMATRIX_H
#define DIAGONALMATRIX_H

#include "AbstractSquareMatrix.h"


class DiagonalMatrix : public AbstractSquareMatrix {
private:
    int *matrix;
public:
    DiagonalMatrix() {};
    void readFromFile(ifstream *fin) override;
    void writeToFile(ofstream *fout) override;
    string getTypeMatrix() override;
    void multiMethod(AbstractSquareMatrix* otherMatrix, ofstream *fout) override;
    void mMDiagonal(ofstream *fout) override;
    void mMSquare(ofstream *fout) override;
};


#endif // DIAGONALMATRIX_H
