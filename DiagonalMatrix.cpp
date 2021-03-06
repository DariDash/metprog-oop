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

int DiagonalMatrix::getSumElementsMatrix() {
    int sum = 0;

    for (int col = 0; col < this->size; ++col) {
        sum += this->matrix[col];
    }

    return sum;
}

string DiagonalMatrix::getClassName() {
    return "Diagonal";
}

void DiagonalMatrix::multiMethod(AbstractSquareMatrix *otherMatrix, ofstream *fout) {
    otherMatrix->mMDiagonal(fout);
}

void DiagonalMatrix::mMDiagonal(ofstream *fout) {
    *fout << "DIAGONAL and DIAGONAL" << endl;
}

void DiagonalMatrix::mMSquare(ofstream *fout) {
    *fout << "SQUARE and DIAGONAL" << endl;
}

void DiagonalMatrix::mMLowerTriangular(ofstream *fout) {
    *fout << "LOWER TRIANGULAR and DIAGONAL" << endl;
}
