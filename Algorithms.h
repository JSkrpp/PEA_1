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

    void BruteForceSymm(Matrix mx);

    void CloseNeighbor(Matrix mx);

    void CloseNeighborAsymm(Matrix mx);

    void RandomSymm(Matrix mx);

    void RandomAsymm(Matrix mx);

};


#endif //CMAKE_INSTALL_CMAKE_ALGORITHMS_H
