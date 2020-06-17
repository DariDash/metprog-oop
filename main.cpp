#include <iostream>

#include "MatrixList.h"
#include "UnitTests.h"

using std::cout;
using std::cerr;
using std::endl;
using std::string;


int main(int argc, char* argv[]) {

//    UnitTests *unitTests = new UnitTests();
//    unitTests->run();

    if (argc != 3) {
        cerr << "Type input and output files." << endl;
        return -1;
    }

    MatrixList *matrixList = new MatrixList();

    string inputPath = argv[1];
    try {
        matrixList->readMatricesFromFile(inputPath);
    } catch (const char* msg) {
        cerr << msg << endl;
        return -1;
    }

    string outputPath = argv[2];
    try {
        matrixList->writeMatricesToFile(outputPath);
    } catch (const char* msg) {
        cerr << msg << endl;
        return -1;
    }

    cout << "Success" << endl;
    return 0;
}
