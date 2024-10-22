#include <string>
#include <iostream>
#include <fstream>
#include "FileOpener.h"
#include "Pomiar.h"
#include "Matrix.h"
#include "Algorithms.h"

FileOpener::FileOpener(std::string filename) {
    this->filename = filename;
}

void FileOpener::AppRun() {
    std::ifstream infile(filename);
    int size, instances, randFloor, testSize;
    std::string testFile;
    std::getline(infile, testFile);
    std::cout << "Testing matrix: "<< testFile << std::endl;
    infile >> size;
    infile >> instances;
    infile >> randFloor;

    std::ifstream file2(testFile);
    file2 >> testSize;
    Matrix mx(testSize);
    mx.LoadMatrixFromFile(testFile);

    Algorithms alg(testSize);
    int testBF = alg.BruteForceSymm(mx);
    int testCN = alg.CloseNeighbor(mx);
    int testRand = alg.RandomAlgo(mx, testSize*testSize);

    std::cout << "Brute force: " << testBF << std::endl;
    std::cout << "Closest Neighbour: " << testCN << std::endl;
    std::cout << "Random: " << testRand  << std::endl;

    Pomiar pom(size, instances, randFloor);
    pom.Badanie();

}



