#ifndef SQUAREMATRIX_H
#define SQUAREMATRIX_H

#include "AbstractSquareMatrix.h"

class SquareMatrix : public AbstractSquareMatrix {
private:
    int **matrix;
public:
    SquareMatrix() {};
    void readFromFile(ifstream *fin) override;
    void writeToFile(ofstream *fout) override;
    string getTypeMatrix() override;
};


#endif //SQUAREMATRIX_H
