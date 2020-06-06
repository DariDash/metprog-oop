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
    int getSumElementsMatrix() override;
};


#endif // DIAGONALMATRIX_H
