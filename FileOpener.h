//
// Created by Admin on 17.10.2024.
//

#ifndef CMAKE_INSTALL_CMAKE_FILEOPENER_H
#define CMAKE_INSTALL_CMAKE_FILEOPENER_H

#include <string>

class FileOpener {
public:
    std::string filename;

    FileOpener(std::string filename);

    void AppRun();

    static std::string getExtension(std::string filename);
};


#endif //CMAKE_INSTALL_CMAKE_FILEOPENER_H
