#include "AbstractSquareMatrix.h"

using std::endl;

int AbstractSquareMatrix::getSize() {
    return this->size;
}

void AbstractSquareMatrix::writeToFile(ofstream *fout) {

    *fout << endl; // Пустая строка для читабельности

    *fout << this->getTypeMatrix() << " matrix" << endl;
    *fout << "Size of matrix is " << this->getSize() << endl;
    *fout << "Matrix:" << endl;
}

void AbstractSquareMatrix::multiMethod(AbstractSquareMatrix *otherMatrix, ofstream *fout) {
    *fout << "Unknown type of matrix" << endl;
}

void AbstractSquareMatrix::mMDiagonal(ofstream *fout) {
    *fout << "DIAGONAL and unknown type of matrix" << endl;
}

void AbstractSquareMatrix::mMSquare(ofstream *fout) {
    *fout << "SQUARE and unknown type of matrix" << endl;
}
