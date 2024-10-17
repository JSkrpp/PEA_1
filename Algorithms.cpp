//
// Created by Admin on 12.10.2024.
//

#include "Algorithms.h"
#include <vector>
#include <bits/stdc++.h>

Algorithms::Algorithms(int size){
    this->V = size;
}

int Algorithms::BruteForceSymm(Matrix mx) {
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
    return min_path;
}


int Algorithms::CloseNeighbor(Matrix mx) {
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
            queue[lowest_index] = false;
            current_path += mx.grid[current][lowest_index];
            current = lowest_index;
        }
        current_path += mx.grid[lowest_index][i];
        min_path = std::min(min_path, current_path);
        }
    return min_path;
}

int Algorithms::RandomAlgo(Matrix mx) {
    int start = 0;
    bool set[V]; // set sprawdzajacy wystapienie wierzcholka w cyklu
    int curr;
    int next;
    int higher_count = 0; // licznik ilosci wykonań algorytmu bez poprawy pod rząd
    bool higher = false; // flaga rozwiązania gorszego od dotychczasowego najlepszego
    int min_path = INT_MAX;
    int benchamrk = V*V; // ustalenie maksymalnej ilości wykonań algorytmu bez poprawy: V^2
    std::random_device rd;
    std::mt19937 mt(rd());

    do {
        int current_path = 0;
        curr = start;
        for (int i = 1; i < V; i++) {
            set[i] = false;
        }

        for (int w = 1; w < V; w++) {
            std::uniform_int_distribution<int> dist(1, V-1);
            do {
                next = dist(mt);
                if (!set[next]) break;
            } while (true);
                set[next] = true;
                current_path += mx.grid[curr][next];
                curr = next;
            if (current_path >= min_path){
                higher_count++;
                higher = true;
                break;
            }
        }
        if(!higher) {
            current_path += mx.grid[curr][start];
            if(current_path <= min_path) {
                min_path = std::min(current_path, min_path);
                higher_count = 0;
            } else {
                higher_count++;
            }
        }
        higher = false;
    } while (higher_count < benchamrk);
    return min_path;
}

