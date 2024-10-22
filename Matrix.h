//
// Created by Admin on 12.10.2024.
//

#ifndef PEA1_MATRIX_H
#define PEA1_MATRIX_H
#include <vector>
#include <string>


class Matrix {
    public:
        std::vector<std::vector<int>> grid;
       Matrix(int size);

        void FillMatrixSymmetrical();

        void Display();

        void FillMatrixAsymmetrical();

        void LoadMatrixFromFile(const std::string& filename);

};


#endif //PEA1_MATRIX_H
