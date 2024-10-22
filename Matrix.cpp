#include "Matrix.h"
#include <vector>
#include <iostream>
#include <random>
#include <fstream>

Matrix::Matrix(int size) { // konstruktor klasy Matrix, alokujacy miejsce w pamieci dla tablicy
    grid.resize(size);
    for (int i = 0; i < size; i++){
        grid[i].resize(size);
    }
}

void Matrix::FillMatrixSymmetrical() { // Metoda wypelniajaca tablice w sposob symetryczny
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(1, 100); // generator liczb losowych z zasiegu 1-100
    for (int i = 0; i < grid.size(); i++){
        for (int j = 0; j <= i; j++){
            int weight = dist(mt);
            if (i == j)
            {
                grid [i][j] = -1; // brak krawedzi wchodzacej do wierzcholka wyjsciowego
            }
            else {
                grid[i][j] = weight;
                grid[j][i] = weight;
            }
        }
    }
}

void Matrix::Display() {
    for (int i = 0; i< grid.size(); i++ ){
        for (int j = 0; j < grid.size(); j++){
            std::cout << grid[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout<< std::endl;
}

void Matrix::FillMatrixAsymmetrical() {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(1, 100);
    for (int i = 0; i < grid.size(); i++){
        for (int j = 0; j < grid.size(); j++){
            int weight = dist(mt);
            if (i == j)
            {
                grid [i][j] = -1;
            }
            else {
                grid[i][j] = weight;
            }
        }
    }
}

void Matrix::LoadMatrixFromFile(const std::string& filename) {
    int size;
    std::ifstream infile(filename);
    if (infile.is_open()) {
        infile >> size;
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                infile >> grid[i][j];
            }
        }
        infile.close();
    }
    else std::cout << "Blad otwierania pliku" << std::endl;
}
