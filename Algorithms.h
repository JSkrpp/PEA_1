//
// Created by Admin on 12.10.2024.
//

#ifndef CMAKE_INSTALL_CMAKE_ALGORITHMS_H
#define CMAKE_INSTALL_CMAKE_ALGORITHMS_H
#include "Matrix.h"


class Algorithms {
public:
    int V;
    Algorithms(int size);

    int BruteForceSymm(Matrix mx);

    int CloseNeighbor(Matrix mx);

    int RandomAlgo(Matrix mx, int randFloor);

};


#endif //CMAKE_INSTALL_CMAKE_ALGORITHMS_H
