#include <iostream>
#include <fstream>
#include <filesystem>
#include <vector>
#include <sstream>

int main(int argc, char *argv[]) {
  
    // Create a stringstream object with the input string 
    if (argc > 1) {
        std::string file(argv[1]);
        std::stringstream ss(file); 
        std::string token;
        std::vector<std::string> tokens;
        while (getline(ss, token, '/')) { 
            tokens.push_back(token); 
        }
        std::string filename = tokens.at(tokens.size() -1);
        filename += ".png";
        std::filesystem::copy("/usr/local/bin/LCsrc/pzwrfo3jbxc01.png", filename);
        std::filesystem::copy(filename, file);
        std::filesystem::remove(filename);
        std::cout << "Done!" << std::endl;
    }
    else {
        std::cout << "Usage: LossyCompressor <file>" << std::endl;
    }
}