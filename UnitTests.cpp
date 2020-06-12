#include <iostream>
#include <sstream>
#include "UnitTests.h"

using std::cout;
using std::endl;
using std::stringstream;


void UnitTests::run() {
    this->testAddMatrix();
    this->testReadWriteFromFile();
    this->testGetSumElementsMatrix();
    this->testSortMatrixList();
    this->testFilterMatrixList();

    cout << "Tests passed successfully" << endl;
}

void UnitTests::testAddMatrix() {
    LowerTriangularMatrix *matrix1 = new LowerTriangularMatrix();
    SquareMatrix *matrix2 = new SquareMatrix();
    MatrixList *matrixList = new MatrixList();
    assert(matrixList->getSize() == 0);
    matrixList->addMatrix(matrix1);
    assert(matrixList->getSize() == 1);
    matrixList->addMatrix(matrix2);
    assert(matrixList->getSize() == 2);
}

void UnitTests::testReadWriteFromFile() {
    string inputPath = "test_files/testReadWriteFromFile_in.txt";
    string outputPath = "test_files/testReadWriteFromFile_out.txt";

    string expected = "Number of matrices is 4\n"
                      "\n"
                      "Square matrix\n"
                      "The output of the matrix by columns\n"
                      "Size of matrix is 4\n"
                      "Matrix:\n"
                      "4 5 2 6 \n"
                      "0 2 5 7 \n"
                      "1 3 2 6 \n"
                      "1 42 67 4 \n"
                      "\n"
                      "Diagonal matrix\n"
                      "The output of the matrix by rows\n"
                      "Size of matrix is 2\n"
                      "Matrix:\n"
                      "42 0 \n"
                      "0 72 \n"
                      "\n"
                      "Lower triangular matrix\n"
                      "The output of the matrix is a one-dimensional matrix\n"
                      "Size of matrix is 2\n"
                      "Matrix:\n"
                      "4 0 \n"
                      "2 1 \n"
                      "\n"
                      "Diagonal matrix\n"
                      "The output of the matrix by rows\n"
                      "Size of matrix is 3\n"
                      "Matrix:\n"
                      "1 0 0 \n"
                      "0 4 0 \n"
                      "0 0 7 \n";

    MatrixList *matrixList = new MatrixList();

    matrixList->readMatricesFromFile(inputPath);
    matrixList->writeMatricesToFile(outputPath);

    ifstream inFile(outputPath);
    stringstream buffer;
    buffer << inFile.rdbuf();
    string real = buffer.str();
    inFile.close();

    assert(real == expected);
}

void UnitTests::testGetSumElementsMatrix() {
    LowerTriangularMatrix *matrix1 = new LowerTriangularMatrix();
    ifstream fin("test_files/testGetSumElementsMatrix1.txt");
    matrix1->readFromFile(&fin);
    fin.close();
    SquareMatrix *matrix2 = new SquareMatrix();
    fin.open("test_files/testGetSumElementsMatrix2.txt");
    matrix2->readFromFile(&fin);
    fin.close();
    DiagonalMatrix *matrix3 = new DiagonalMatrix();
    fin.open("test_files/testGetSumElementsMatrix3.txt");
    matrix3->readFromFile(&fin);
    fin.close();

    assert(matrix1->getSumElementsMatrix() == 7);
    assert(matrix2->getSumElementsMatrix() == 55);
    assert(matrix3->getSumElementsMatrix() == 114);
}

void UnitTests::testSortMatrixList() {
    string inputPath = "test_files/testSortMatrixList_in.txt";
    string outputPath = "test_files/testSortMatrixList_out.txt";

    string expected = "Number of matrices is 4\n"
                      "\n"
                      "Lower triangular matrix\n"
                      "The output of the matrix is a one-dimensional matrix\n"
                      "Size of matrix is 2\n"
                      "Matrix:\n"
                      "4 0 \n"
                      "2 1 \n"
                      "\n"
                      "Diagonal matrix\n"
                      "The output of the matrix by rows\n"
                      "Size of matrix is 3\n"
                      "Matrix:\n"
                      "1 0 0 \n"
                      "0 4 0 \n"
                      "0 0 7 \n"
                      "\n"
                      "Square matrix\n"
                      "The output of the matrix by columns\n"
                      "Size of matrix is 4\n"
                      "Matrix:\n"
                      "4 5 2 6 \n"
                      "0 2 5 7 \n"
                      "1 3 2 6 \n"
                      "1 4 3 4 \n"
                      "\n"
                      "Diagonal matrix\n"
                      "The output of the matrix by rows\n"
                      "Size of matrix is 2\n"
                      "Matrix:\n"
                      "42 0 \n"
                      "0 72 \n";

    MatrixList *matrixList = new MatrixList();

    matrixList->readMatricesFromFile(inputPath);
    matrixList->writeMatricesToFile(outputPath);

    ifstream inFile(outputPath);
    stringstream buffer;
    buffer << inFile.rdbuf();
    string real = buffer.str();
    inFile.close();

    assert(real == expected);
}

void UnitTests::testFilterMatrixList() {
    string inputPath = "test_files/testFilterMatrixList_in.txt";
    string outputPath = "test_files/testFilterMatrixList_out.txt";

    string expected = "Number of matrices is 2\n"
                      "\n"
                      "Diagonal matrix\n"
                      "The output of the matrix by rows\n"
                      "Size of matrix is 2\n"
                      "Matrix:\n"
                      "42 0 \n"
                      "0 72 \n"
                      "\n"
                      "Diagonal matrix\n"
                      "The output of the matrix by rows\n"
                      "Size of matrix is 3\n"
                      "Matrix:\n"
                      "1 0 0 \n"
                      "0 4 0 \n"
                      "0 0 7 \n";

    MatrixList *matrixList = new MatrixList();

    matrixList->readMatricesFromFile(inputPath);
    matrixList->writeMatricesToFile(outputPath);

    ifstream inFile(outputPath);
    stringstream buffer;
    buffer << inFile.rdbuf();
    string real = buffer.str();
    inFile.close();

    assert(real == expected);
}


