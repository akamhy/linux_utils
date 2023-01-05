#include <iostream>
#include <stack>
#include <string>
#include <unistd.h>

int main(int argc, char* argv[]) {
  static std::stack<std::string> dirstack;
  if (dirstack.empty()) {
    std::cerr << "Error: directory stack is empty" << std::endl;
    return 1;
  }

  std::string dir = dirstack.top();
  dirstack.pop();

  if (chdir(dir.c_str()) != 0) {
    perror("chdir");
    return 1;
  }

  std::cout << dir << std::endl;
  std::cout << "Directory stack:" << std::endl;
  for (const auto& dir : dirstack) {
    std::cout << "  " << dir << std::endl;
  }

  return 0;
}

