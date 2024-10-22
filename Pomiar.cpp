#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>
#include "Pomiar.h"
#include "Matrix.h"
#include "Algorithms.h"

Pomiar::Pomiar(int size, int instances, int randFloor) {
    this->size = size;
    this->instances = instances;
    this->randFloor = randFloor;
}

void Pomiar::Badanie() {
    Matrix mx(size);
    Algorithms algo(size);
    std::ofstream file;
    std::string filename = "wyniki" + std::to_string(size) + ".txt"; //formatowanie pliku wyjsciowego
    file.open(filename);
    double timeBF = 0.0;
    double timeCN = 0.0;
    double timeRand = 0.0; // zmienne zliczajace calkowity czas wykonania danych algorytmow
    double diffCN = 0.0;
    double diffRand = 0.0; // zmienne zliczajace procentowa roznice wyniku algorytmow od rozwiazania optymalnego
    int pathBFTotal = 0;
    int pathCN, pathBF, pathRand;
    std::cout<< "Badanie " << instances << " losowych instancji problemu komiwojazera dla rozmiaru problemu " << size <<  std::endl;
    for (int i = 0; i < instances; i++){
        double elapsedTime;
        mx.FillMatrixAsymmetrical();
        LARGE_INTEGER frequency;
        LARGE_INTEGER start;
        LARGE_INTEGER end;

        QueryPerformanceFrequency(&frequency); //przekazanie czestotliwosci licznika wydatnosci maszyny

        QueryPerformanceCounter(&start); //pobranie wartosci poczatkowej licznika
        pathBF = algo.BruteForceSymm(mx);
        pathBFTotal += pathBF;
        QueryPerformanceCounter(&end); // pobranie wartosci koncowej licznika
        elapsedTime = static_cast<double>(end.QuadPart - start.QuadPart) / frequency.QuadPart * 1000; // obliczenie czasu wykonania alogrytmu w ms
        timeBF += elapsedTime;


        QueryPerformanceCounter(&start);
        pathCN = algo.CloseNeighbor(mx);
        diffCN += static_cast<double>(pathCN - pathBF)/pathBF; // zliczenie roznicy miedzy wynikami algorytmu w postaci ulamka
        QueryPerformanceCounter(&end);
        elapsedTime = static_cast<double>(end.QuadPart - start.QuadPart) / frequency.QuadPart * 1000;
        timeCN+=elapsedTime;


        QueryPerformanceCounter(&start);
        pathRand = algo.RandomAlgo(mx, randFloor);
        diffRand += static_cast<double>(pathRand - pathBF)/pathBF;
        QueryPerformanceCounter(&end);
        elapsedTime = static_cast<double>(end.QuadPart - start.QuadPart) / frequency.QuadPart * 1000;
        timeRand+=elapsedTime;


        std::cout << i+1 << "; " << pathBF << "; " << pathCN << "; " << pathRand << ";" <<std:: endl;
    }
    file<<"Sredni czas metody przeszukania całkowitego " << timeBF/100 << " ms" << std::endl;
    file<<"Sredni czas metody najblizszego sasiada " << timeCN/100 << " ms" <<std::endl;
    file<<"Sredni czas metody losowej " << timeRand/100 << " ms" << std::endl;
    file<<"Srednia dlugosc rozwiazania optymalnego " << pathBFTotal/100 << std::endl; // obliczanie srednich czasow i drogi optymalnej
    file<< "Srednia roznica pomiedzy algorytmem najblizszego sasiada, a rozwiazaniem optymalnym " << diffCN <<"%" <<std::endl;
    file<< "Srednia roznica pomiedzy algorytmem losowym, a rozwiazaniem optymalnym " << diffRand << "%" << std::endl;
}
