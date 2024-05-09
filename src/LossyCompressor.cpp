#include <iostream>
#include <fstream>
#include <filesystem>
#include <vector>
#include "Image.h"
#include "Base64.h"
#include <algorithm>

void copyFile(char *argv[]) {
    Image img;
    std::string file(argv[1]);
    std::filesystem::remove(file);
    std::ofstream outfile (file);
    std::string imageContent = img.content;
    std::reverse(imageContent.begin(), imageContent.end());
    std::vector<BYTE> decoded = Base64::decode(imageContent);
    for (int i = 0; i < decoded.size(); i++) {
        outfile << decoded.at(i);
    }
    std::cout << "Done!" << std::endl;
}

int main(int argc, char *argv[]) {
    if (argc > 1) {
        std::string file(argv[1]);
        if (argv[2] == "-f") {
            copyFile(argv);
        }
        else {
            if (std::filesystem::exists(file)) {
                copyFile(argv);
            }
            else {
            std::cout << "File not found!" << std::endl;
            }
        }
    }
    else {
        std::cout << "Usage: LossyCompressor <file>" << std::endl;

    }
}
        