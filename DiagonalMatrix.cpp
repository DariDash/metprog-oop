#include "DiagonalMatrix.h"

using std::endl;

void DiagonalMatrix::readFromFile(ifstream *fin) {
    AbstractSquareMatrix::readFromFile(fin);
    int size;

    *fin >> size;

    int *_matrix = new int[size];
    for (int col = 0; col < size; ++col) {
        *fin >> _matrix[col];
    }

    this->matrix = _matrix;
    this->size = size;
}

void DiagonalMatrix::writeToFile(ofstream *fout) {
    AbstractSquareMatrix::writeToFile(fout);
    for (int row = 0; row < this->size; ++row) {
        for (int col = 0; col < this->size; ++col) {
            if (row == col) {
                *fout << this->matrix[col];
            } else {
                *fout << "0";
            }
            *fout << " ";
        }
        *fout << endl;
    }
}

string DiagonalMatrix::getTypeMatrix() {
    return "Diagonal";
}
