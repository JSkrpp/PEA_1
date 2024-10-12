//
// Created by Admin on 12.10.2024.
//

#include "Matrix.h"
#include <vector>
#include <iostream>


void Matrix::FillMatrix() {
    for (int i = 0; i < grid.size(); i++){
        for (int j = 0; j < grid.size(); j++){
            grid[i][j] = 0;
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
}
