#include <iostream>
#include "Matrix.h"
#include "Algorithms.h"
#include <string>
#include <fstream>

int main() {
    std::string filename = "matrix_11x11.atsp";
    int size;
    std::ifstream infile(filename);
    infile >> size;
    infile.close();
    Matrix mx(size);
    Algorithms algo(size);
    mx.LoadMatrixFromFile(filename);
    mx.Display();
    algo.CloseNeighbor(mx);
    return 0;
}
