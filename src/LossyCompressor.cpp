#include <iostream>
#include <fstream>
#include <filesystem>
#include <vector>
#include <sstream>

void copyFile(char *argv[]) {
    std::string file(argv[1]);
    std::filesystem::remove(file);
    std::stringstream ss(file); 
    std::string token;
    std::vector<std::string> tokens;
    while (getline(ss, token, '/')) { 
        tokens.push_back(token); 
    }
    std::string filename = tokens.at(tokens.size() -1);

    std::stringstream fs(filename); 
    std::vector<std::string> comp;
    while (getline(fs, token, '.')) { 
        comp.push_back(token); 
    }
    filename += comp.at(comp.size()-1);
    
    std::filesystem::copy("/usr/local/bin/LCsrc/pzwrfo3jbxc01.png", filename);
    std::filesystem::copy(filename, file);
    std::filesystem::remove(filename);
    std::cout << "Done!" << std::endl;
}

int main(int argc, char *argv[]) {
    // Create a stringstream object with the input string 
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
        