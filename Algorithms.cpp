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

        min_path = std::min(min_path, current_path); // przypisanie dlugosci najkrotszego dotychczas cyklu

    } while (std::next_permutation(vertex.begin(), vertex.end())); // wykonuje sie do momentu wykorzystania wszystkich permutacji
    return min_path;
}


int Algorithms::CloseNeighbor(Matrix mx) {
    bool queue[V]; // tablica sprawdzajaca, czy dany wierzcholek moze zostac przylaczony do cyklu
    int current;

    int min_path = INT_MAX;

    for(int i = 0; i < V; i++){ // algorytm przeprowadzany V razy, sprawdzana jest droga wychodzaca z kazdego wierzcholka
        for (int reset_bool = 0; reset_bool < V; reset_bool++){
            queue[reset_bool] = true;
            } // odlaczenie wszystkich wierzcholkow od cyklu

        queue[i] = false; // wierzcholek startowy wlaczany jest do cyklu
        current = i; // inicjalizacja wierzchołka startowego
        int current_path = 0;
        int lowest_index;

        for(int s = 0; s<V-1; s++) { // wyszukiwanie V-1 najblizszych sasiadow
            int current_lowest = INT_MAX;
            for (int w = 0; w < V; w++) {
                if (queue[w] && mx.grid[current][w] < current_lowest) { // sprawdzanie czy dlugosc od wyjscia do sprawdzanego wierzcholka jest krotsza od tymczasowerj najkrotszej
                    current_lowest = mx.grid[current][w];
                    lowest_index = w;
                }
            }
            queue[lowest_index] = false;
            current_path += mx.grid[current][lowest_index];
            current = lowest_index; // dodanie najkrotszej krawedzi do cyklu i przydzielenie nowego wierzcholka startowego
        }
        current_path += mx.grid[lowest_index][i];  //dodanie ostatniej krawedzi do cyklu
        min_path = std::min(min_path, current_path);
        }
    return min_path;
}

int Algorithms::RandomAlgo(Matrix mx, int randFloor) {
    int start = 0;
    bool set[V]; // set sprawdzajacy wystapienie wierzcholka w cyklu
    int curr;
    int next;
    int higher_count = 0; // licznik ilosci wykonań algorytmu bez poprawy pod rząd
    bool higher = false; // flaga rozwiązania gorszego od dotychczasowego najlepszego
    int min_path = INT_MAX;
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
            } while (true); //instrukcja do-while losujaca nastepny nieuzyty wierzcholek do cyklu
                set[next] = true;
                current_path += mx.grid[curr][next];
                curr = next;
            if (current_path >= min_path){
                higher_count++;
                higher = true;
                break;
            } // przerwanie algorytmu w przypadku uzyskania sciezki dluzszej od najkrotszej
        }
        if(!higher) {
            current_path += mx.grid[curr][start];
            if(current_path <= min_path) {
                min_path = std::min(current_path, min_path);
                higher_count = 0; // reset zmiennej zliczajacej ilosc instancji bez poprawy wyniku
            } else {
                higher_count++;
            }
        }
        higher = false;
    } while (higher_count < randFloor);
    return min_path;
}

