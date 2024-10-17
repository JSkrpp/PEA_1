//
// Created by Admin on 17.10.2024.
//

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
    std::string extension = getExtension(filename);
    std::ifstream infile(filename);
    if (extension == "txt")
    {
        std::ifstream infile(filename);
        int size;
        infile >> size;
        Pomiar pom(size);
        pom.Badanie();
    }
    else if(extension == "atsp") {
        int size;
        infile >> size;
        Algorithms algo(size);
        Matrix mx(size);
        mx.LoadMatrixFromFile(filename);
        int BF = algo.BruteForceSymm(mx);
        int CN = algo.CloseNeighbor(mx);
        int RA = algo.RandomAlgo(mx);
        std::cout<<"Przeszukanie calkowite, droga: " << BF << std::endl;
        std::cout<<"Najblizszy sasiad, droga: " << CN << std::endl;
        std::cout<<"Algorytm losowy: " << RA << std::endl;
    }
}

std::string FileOpener::getExtension(std::string filename) {
    size_t dot = filename.rfind('.');
    if (dot == std::string::npos || dot == filename.size() - 1 ) return "";
    return filename.substr(dot+1);
}

