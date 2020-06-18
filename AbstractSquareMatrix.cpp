#include "AbstractSquareMatrix.h"

using std::endl;


string AbstractSquareMatrix::getTypePrint() {
    string type_print;
    switch (this->type_print) {
        case AbstractSquareMatrix::ROW:
            return "by rows";
        case AbstractSquareMatrix::COLUMN:
            return "by columns";
        case AbstractSquareMatrix::ONE_DIMENSIONAL_MATRIX:
            return "is a one-dimensional matrix";
        default:
            return "";
    }
}

void AbstractSquareMatrix::readFromFile(ifstream *fin) {
    string type_print;
    *fin >> type_print;

    if (type_print == "Row") {
        this->type_print = AbstractSquareMatrix::ROW;
    } else if (type_print == "Column") {
        this->type_print = AbstractSquareMatrix::COLUMN;
    } else if (type_print == "One-dimensional") {
        this->type_print = AbstractSquareMatrix::ONE_DIMENSIONAL_MATRIX;
    }
}

void AbstractSquareMatrix::writeToFile(ofstream *fout) {

    *fout << endl; // Пустая строка для читабельности

    *fout << this->getTypeMatrix() << " matrix" << endl;
    *fout << "The output of the matrix " << this->getTypePrint() << endl;
    *fout << "Size of matrix is " << this->size << endl;
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

void AbstractSquareMatrix::mMLowerTriangular(ofstream *fout) {
    *fout << "LOWER TRIANGULAR and unknown type of matrix" << endl;
}
