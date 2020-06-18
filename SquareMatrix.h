#ifndef SQUAREMATRIX_H
#define SQUAREMATRIX_H

#include "AbstractSquareMatrix.h"

class SquareMatrix : public AbstractSquareMatrix {
private:
    int **matrix;
public:
    SquareMatrix() {};
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


#endif //SQUAREMATRIX_H
