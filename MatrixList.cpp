#include "MatrixList.h"
#include "SquareMatrix.h"
#include "DiagonalMatrix.h"
#include "LowerTriangularMatrix.h"

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

    bool doSort = false;
    int numMatrices;
    string typeMatrix, sort, filter;
    fin >> numMatrices; // Кол-во матриц

    fin >> sort;

    if (sort == "Sort") {
        doSort = true;
    } else if (sort != "NoSort") {
        return false;
    }

    fin >> filter;

    for (int i = 0; i < numMatrices; ++i) {
        fin >> typeMatrix;  // Тип матрицы
        AbstractSquareMatrix *squareMatrix;
        if (typeMatrix == "Square") {
            squareMatrix = new SquareMatrix();
        } else if (typeMatrix == "Diagonal") {
            squareMatrix = new DiagonalMatrix();
        } else if (typeMatrix == "LowerTriangular") {
            squareMatrix = new LowerTriangularMatrix();
        } else {
            fin.close();
            return false;
        }

        squareMatrix->readFromFile(&fin);

        if (filter == "All" or filter == squareMatrix->getClassName()) {
            this->addMatrix(squareMatrix);
        }
    }

    if (doSort) {
        this->sortList();
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

    fout.close();
    return true;
}

void MatrixList::sortList() {
    for(MatrixItem* matrixItem2 = this->firstMatrix; matrixItem2; matrixItem2 = matrixItem2->nextMatrix) {
        for(MatrixItem* matrixItem1 = this->firstMatrix; matrixItem1->nextMatrix; matrixItem1 = matrixItem1->nextMatrix) {
            if(matrixItem1->matrix->getSumElementsMatrix() > matrixItem1->nextMatrix->matrix->getSumElementsMatrix()) {
                std::iter_swap(&matrixItem1->matrix, &matrixItem1->nextMatrix->matrix);
            }
        }
    }
}

int MatrixList::getSize() {
    return this->size;
}
