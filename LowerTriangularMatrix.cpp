#include "LowerTriangularMatrix.h"

using std::endl;


void LowerTriangularMatrix::readFromFile(ifstream *fin) {
    AbstractSquareMatrix::readFromFile(fin);
    int size, valuesNumber;
    *fin >> size;

    valuesNumber = (size - 1)*size/2 + size; // Кол-во элементов которые необходимо считать

    int *_matrix = new int [valuesNumber];
    for (int col = 0; col < valuesNumber; ++col) {
        *fin >> _matrix[col];
    }

    this->matrix = _matrix;
    this->size = size;
}

void LowerTriangularMatrix::writeToFile(ofstream *fout) {
    AbstractSquareMatrix::writeToFile(fout);
    int count = 0;
    for (int row = 0; row < this->size; ++row) {
        for (int col = 0; col < this->size; ++col) {
            if (row >= col) {
                *fout << this->matrix[count];
                count++;
            } else {
                *fout << "0";
            }
            *fout << " ";
        }
        *fout << endl;
    }
}

string LowerTriangularMatrix::getTypeMatrix() {
    return "Lower triangular";
}

int LowerTriangularMatrix::getSumElementsMatrix() {

    int valuesNumber = (this->size - 1)*this->size/2 + this->size; // Кол-во элементов которые необходимо считать

    int sum = 0;

    for (int col = 0; col < valuesNumber; ++col) {
        sum += this->matrix[col];
    }

    return sum;
}

string LowerTriangularMatrix::getClassName() {
    return "LowerTriangular";
}

void LowerTriangularMatrix::multiMethod(AbstractSquareMatrix *otherMatrix, ofstream *fout) {
    otherMatrix->mMLowerTriangular(fout);
}

void LowerTriangularMatrix::mMDiagonal(ofstream *fout) {
    *fout << "DIAGONAL and LOWER TRIANGULAR" << endl;
}

void LowerTriangularMatrix::mMSquare(ofstream *fout) {
    *fout << "SQUARE and LOWER TRIANGULAR" << endl;

}

void LowerTriangularMatrix::mMLowerTriangular(ofstream *fout) {
    *fout << "LOWER TRIANGULAR and LOWER TRIANGULAR" << endl;

}
