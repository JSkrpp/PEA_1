//
// Created by Admin on 14.10.2024.
//

#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>
#include "Pomiar.h"
#include "Matrix.h"
#include "Algorithms.h"

Pomiar::Pomiar(int size) {
    this->size = size;
}

void Pomiar::Badanie() {
    Matrix mx(size);
    Algorithms algo(size);
    std::ofstream file;
    std::string filename = "wyniki" + std::to_string(size) + ".txt";
    file.open(filename);
    double timeBF = 0.0;
    double timeCN = 0.0;
    double timeRand = 0.0;
    double diffCN = 0.0;
    double diffRand = 0.0;
    int pathBFTotal = 0;
    int pathCN = 0;
    int pathRand = 0;
    int pathBF = 0;
    file << "Badanie 100 losowych instancji problemu komiwojazera dla rozmiaru problemu " << size << std::endl;
    for (int i = 0; i < 100; i++){
        double elapsedTime;
        mx.FillMatrixSymmetrical();
        LARGE_INTEGER frequency;
        LARGE_INTEGER start;
        LARGE_INTEGER end;

        QueryPerformanceFrequency(&frequency);


        QueryPerformanceCounter(&start);
        pathBF = algo.BruteForceSymm(mx);
        pathBFTotal += pathBF;
        QueryPerformanceCounter(&end);
        elapsedTime = static_cast<double>(end.QuadPart - start.QuadPart) / frequency.QuadPart * 1000;
        //std::cout<<elapsedTime; usunac komentarz i przekopiowac pod kazda zmienna elapsedTime jezeli potrzebne bedzie logowanie czasow + dac endl na koniec
        timeBF += elapsedTime;

        QueryPerformanceCounter(&start);
        pathCN = algo.CloseNeighbor(mx);
        diffCN += static_cast<double>(pathCN - pathBF)/pathBF;
        QueryPerformanceCounter(&end);
        elapsedTime = static_cast<double>(end.QuadPart - start.QuadPart) / frequency.QuadPart * 1000;
        timeCN+=elapsedTime;


        QueryPerformanceCounter(&start);
        pathRand = algo.RandomAlgo(mx);
        diffRand += static_cast<double>(pathRand - pathBF)/pathBF;
        QueryPerformanceCounter(&end);
        elapsedTime = static_cast<double>(end.QuadPart - start.QuadPart) / frequency.QuadPart * 1000;
        timeRand+=elapsedTime;
        std::cout << pathBF << " " << pathCN << " " << pathRand << std:: endl;
    }
    file<<"Sredni czas metody przeszukania całkowitego " << timeBF/100 << " ms" << std::endl;
    file<<"Sredni czas metody najblizszego sasiada " << timeCN/100 << " ms" <<std::endl;
    file<<"Sredni czas metody losowej " << timeRand/100 << " ms" << std::endl;
    file<<"Srednia dlugosc rozwiazania optymalnego " << pathBFTotal/100 << std::endl;
    file<< "Srednia roznica pomiedzy algorytmem najblizszego sasiada, a rozwiazaniem optymalnym " << diffCN <<"%" <<std::endl;
    file<< "Srednia roznica pomiedzy algorytmem losowym, a rozwiazaniem optymalnym " << diffRand << "%" << std::endl;
}
