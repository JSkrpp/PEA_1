#include <iostream>
#include "FileOpener.h"
#include "Matrix.h"
#include "Algorithms.h"
#include "Pomiar.h"
#include <string>
#include <fstream>

int main() {
    std::string filename;
    std::cout << "Podaj nazwe pliku wejsciowego/testowego" << std::endl;
    std::cin >> filename;
    FileOpener fileOpener(filename);
    fileOpener.AppRun();
    system("break");
    return 0;
}
