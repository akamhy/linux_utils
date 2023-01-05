#include <iostream>
#include <stack>
#include <string>
#include <unistd.h>

int main(int argc, char* argv[]) {
  if (argc < 2) {
    std::cerr << "Error: no directory provided" << std::endl;
    return 1;
  }

  if (chdir(argv[1]) != 0) {
    perror("chdir");
    return 1;
  }

  char cwd[1024];
  if (getcwd(cwd, sizeof(cwd)) == NULL) {
    perror("getcwd");
    return 1;
  }
  std::string current_dir(cwd);

  static std::stack<std::string> dirstack;
  dirstack.push(current_dir);

  std::cout << current_dir << std::endl;
  std::cout << "Directory stack:" << std::endl;
  for (const auto& dir : dirstack) {
    std::cout << "  " << dir << std::endl;
  }

  return 0;
}

