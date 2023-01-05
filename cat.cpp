#include <iostream>
#include <fstream>
#include <string>

/*
 * cat implementain in C++
 * supports catting multiple files. 
 * usage ./cat foo.txt bar.txt
 */

int main(int argc, char* argv[]) {
  if (argc < 2) {
    std::cerr << "Error: no file provided" << std::endl;
    return 1;
  }

  for (int i = 1; i < argc; i++) {
    std::ifstream file(argv[i]);
    if (!file.is_open()) {
      std::cerr << "Error: Can not open file '" << argv[i] << "'" << std::endl;
      continue;
    }

    std::string line;
    while (std::getline(file, line)) {
      std::cout << line << std::endl;
    }

    file.close();
  }

  return 0;
}

