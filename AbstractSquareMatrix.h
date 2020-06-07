#ifndef ABSTRACTSQUAREMATRIX_H
#define ABSTRACTSQUAREMATRIX_H

#include <iostream>
#include <fstream>

using std::ifstream;
using std::ofstream;
using std::string;


class AbstractSquareMatrix {
protected:
    enum TypePrint {ROW, COLUMN, ONE_DIMENSIONAL_MATRIX};
    int size;
    TypePrint type_print;
public:
    AbstractSquareMatrix() {};
    string getTypePrint();
    virtual string getClassName() = 0;
    virtual void readFromFile(ifstream *fin);
    virtual void writeToFile(ofstream *fout);
    virtual string getTypeMatrix() = 0;
    virtual int getSumElementsMatrix() = 0;
};


#endif //ABSTRACTSQUAREMATRIX_H
