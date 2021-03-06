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

void MatrixList::readMatricesFromFile(string filename) {

    ifstream fin(filename);

    if (!fin.is_open()) {
        throw "Failed to open file for reading";
    }

    bool doSort = false;
    int numMatrices;
    string typeMatrix, sort, filter;
    fin >> numMatrices; // Кол-во матриц

    fin >> sort;

    if (sort == "Sort") {
        doSort = true;
    } else if (sort != "NoSort") {
        throw "Invalid values for the sort field in the input file";
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
            throw "Unrecognized matrix type";
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
}

void MatrixList::writeMatricesToFile(string filename) {

    ofstream fout(filename);

    if (!fout.is_open()) {
        throw "Failed to open file for writing";
    }

    fout << "Number of matrices is " << this->size << endl;

    if (!this->size) {
        return;
    }

    MatrixItem *currentMatrixItem = this->firstMatrix; // инициализация текущего элемента списка

    for (int i = 0; i < this->size; ++i) {
        currentMatrixItem->matrix->writeToFile(&fout);
        currentMatrixItem = currentMatrixItem->nextMatrix;
    }

    this->multiMethod(&fout);

    fout.close();
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
