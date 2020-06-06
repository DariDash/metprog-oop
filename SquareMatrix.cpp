#include "AbstractSquareMatrix.h"
#include "SquareMatrix.h"

using std::endl;


void SquareMatrix::readFromFile(ifstream *fin) {
    AbstractSquareMatrix::readFromFile(fin);
    int size;
    *fin >> size;

    int **_matrix = new int *[size];
    for (int row = 0; row < size; ++row) {
        _matrix[row] = new int[size];
        for (int col = 0; col < size; ++col) {
            *fin >> _matrix[row][col];
        }
    }

    this->matrix = _matrix;
    this->size = size;
}

void SquareMatrix::writeToFile(ofstream *fout) {
    AbstractSquareMatrix::writeToFile(fout);
    for (int row = 0; row < this->size; ++row) {
        for (int col = 0; col < this->size; ++col) {
            *fout << this->matrix[row][col] << " ";
        }
        *fout << endl;
    }
}

string SquareMatrix::getTypeMatrix() {
    return "Square";
}
