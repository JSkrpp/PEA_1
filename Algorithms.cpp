//
// Created by Admin on 12.10.2024.
//

#include "Algorithms.h"
#include <vector>
#include <bits/stdc++.h>

Algorithms::Algorithms(int size){
    this->V = size;
}

void Algorithms::BruteForceSymm(Matrix mx) {
    std::vector<int> vertex;
    int start = 0;  // wierzcholek poczatkowy indeksowany 0; standaryzacja metodologii
    for(int i = 1; i < V; i++){
        vertex.push_back(i);
    } // tworzenie listy wierzcholkow do permutacji

    int min_path = INT_MAX;

    do{
        int current_path = 0;

        int k = start;

        for(int i = 0; i < vertex.size(); i++){
            current_path += mx.grid[k][vertex[i]];
            k = vertex[i];
        }
        current_path += mx.grid[k][start]; //powrot do wierzcholka startowego

        min_path = std::min(min_path, current_path);

    } while (std::next_permutation(vertex.begin(), vertex.end()));

    std::cout << min_path << std::endl;
}


void Algorithms::CloseNeighbor(Matrix mx) {
    int weight[V];
    bool queue[V];
    int current;

    int min_path = INT_MAX;


    for(int i = 0; i < V; i++){ // algorytm przeprowadzany V razy, gdzie V jest iloscia wierzcholkow
        for (int reset_bool = 0; reset_bool < V; reset_bool++){
            queue[reset_bool] = true;
            }
        queue[i] = false;
        current = i; // inicjalizacja wierzchołka poczatkowego
        int current_path = 0;
        int lowest_index;

        for(int s = 1; s<V; s++) {
            int current_lowest = INT_MAX;
            for (int w = 0; w < V; w++) {
                if (queue[w] && mx.grid[current][w] < current_lowest) {
                    current_lowest = mx.grid[current][w];
                    lowest_index = w;
                }
            }
            std::cout<< "Najbliszy wierzcholek: " << lowest_index << ", waga: " << current_lowest << std::endl;
            queue[lowest_index] = false;
            current_path += mx.grid[current][lowest_index];
            current = lowest_index;
        }
        current_path += mx.grid[lowest_index][i];
        std::cout << "Droga od wierzcholka " << i << " " << current_path << std::endl;
        min_path = std::min(min_path, current_path);

        }

    std::cout << min_path << std::endl;
}

void Algorithms::CloseNeighborAsymm(Matrix mx) {

}

void Algorithms::RandomSymm(Matrix mx) {

}

void Algorithms::RandomAsymm(Matrix mx) {

}

