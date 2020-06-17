#include "MatrixList.h"

#include <fstream>

using std::ifstream;
using std::ofstream;
using std::endl;


MatrixList::MatrixList() {
    this->size = 0;
    this->firstMatrix = nullptr;
    this->lastMatrix = nullptr;
}

void MatrixList::addMatrix(AbstractSquareMatrix *squareMatrix) {
    MatrixItem *newMatrixItem = new MatrixItem();
    newMatrixItem->matrix = squareMatrix;
    newMatrixItem->nextMatrix = nullptr;

    if (this->size == 0) {
        this->firstMatrix = newMatrixItem;
    } else if (this->size == 1) {
        this->firstMatrix->nextMatrix = newMatrixItem;
        this->lastMatrix = newMatrixItem;
    } else {
        this->lastMatrix->nextMatrix = newMatrixItem;
        this->lastMatrix = newMatrixItem;
    }

    this->size++;
}

bool MatrixList::readMatricesFromFile(string filename) {

    ifstream fin(filename);

    if (!fin.is_open()) {
        return false;
    }

    int numMatrices;
    string typeMatrix;
    fin >> numMatrices; // Кол-во матриц

    for (int i = 0; i < numMatrices; ++i) {
        fin >> typeMatrix;  // Тип матрицы
        AbstractSquareMatrix *squareMatrix;
        if (typeMatrix == "Square") {
            squareMatrix = new SquareMatrix();
        } else if (typeMatrix == "Diagonal") {
            squareMatrix = new DiagonalMatrix();
        } else {
            fin.close();
            return false;
        }

        squareMatrix->readFromFile(&fin);

        this->addMatrix(squareMatrix);
    }
    fin.close();
    return true;
}

bool MatrixList::writeMatricesToFile(string filename) {
    if (!this->size) {
        return true;
    }

    ofstream fout(filename);

    fout << "Number of matrices is " << this->size << endl;

    MatrixItem *currentMatrixItem = this->firstMatrix; // инициализация текущего элемента списка

    for (int i = 0; i < this->size; ++i) {

        currentMatrixItem->matrix->writeToFile(&fout);

        currentMatrixItem = currentMatrixItem->nextMatrix;
    }

    this->multiMethod(&fout);

    fout.close();
    return true;
}

void MatrixList::multiMethod(ofstream *fout) {
    *fout << endl << endl << "Multimethod" << endl;
    if (!this->size) {
        return;
    }

    for(MatrixItem* matrixItem1 = this->firstMatrix; matrixItem1->nextMatrix; matrixItem1 = matrixItem1->nextMatrix) {
        for(MatrixItem* matrixItem2 = matrixItem1->nextMatrix; matrixItem2; matrixItem2 = matrixItem2->nextMatrix) {
            matrixItem1->matrix->multiMethod(matrixItem2->matrix, fout);
        }
    }

}
