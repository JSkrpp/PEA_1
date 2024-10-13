//
// Created by Admin on 12.10.2024.
//

#include "Matrix.h"
#include <vector>
#include <iostream>
#include <random>
#include <fstream>

void Matrix::FillMatrixSymmetrical() {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(1, 100);
    for (int i = 0; i < grid.size(); i++){
        for (int j = 0; j <= i; j++){
            int weight = dist(mt);
            if (i == j)
            {
                grid [i][j] = -1;
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
        std::cout << size << std::endl;
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                infile >> grid[i][j];
            }
        }
        infile.close();
    }
    else std::cout << "Blad otwierania pliku" << std::endl;
}
