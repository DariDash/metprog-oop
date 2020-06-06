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
