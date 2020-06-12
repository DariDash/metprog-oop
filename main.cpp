#include <iostream>

#include "MatrixList.h"
#include "UnitTests.h"

using std::cout;
using std::endl;
using std::string;


int main(int argc, char* argv[]) {

    UnitTests *unitTests = new UnitTests();
    unitTests->run();

    if (argc != 3) {
        cout << "Type input and output files." << endl;
        return -1;
    }

    MatrixList *matrixList = new MatrixList();

    string inputPath = argv[1];
    bool isSuccessRead = matrixList->readMatricesFromFile(inputPath);
    if (!isSuccessRead) {
        cout << "Failed to open file for reading" << endl;
        return -1;
    }

    string outputPath = argv[2];
    bool isSuccessWrite = matrixList->writeMatricesToFile(outputPath);
    if (!isSuccessWrite) {
        cout << "Failed to open file for writing" << endl;
        return -1;
    }

    cout << "Success" << endl;
    return 0;
}
