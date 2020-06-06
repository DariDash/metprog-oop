#ifndef ABSTRACTSQUAREMATRIX_H
#define ABSTRACTSQUAREMATRIX_H

#include <iostream>
#include <fstream>

using std::ifstream;
using std::ofstream;
using std::string;


class AbstractSquareMatrix {
protected:
    int size;
public:
    AbstractSquareMatrix() {};
    int getSize();
    virtual void readFromFile(ifstream *fin) = 0;
    virtual void writeToFile(ofstream *fout);
    virtual string getTypeMatrix() = 0;
};


#endif //ABSTRACTSQUAREMATRIX_H
