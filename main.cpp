#include <iostream>
#include "FileOpener.h"


int main() {
    FileOpener fileOpener("config.txt");
    fileOpener.AppRun();
    std::system("pause");
    return 0;
}
