#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
  if (argc < 2) {
	  char* home = getenv("HOME");
  if (home == NULL) {
    fprintf(stderr, "Error: HOME environment variable not set\n");
    return 1;
  }
  if (chdir(home) != 0) {
    perror("chdir");
    return 1;
  }
    return 0;
  }

  if (chdir(argv[1]) != 0) {
    perror("chdir");
    return 1;
  }

  return 0;
}

