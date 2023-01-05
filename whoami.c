#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>

int main(int argc, char* argv[]) {
  uid_t uid = getuid();

  struct passwd* pwd = getpwuid(uid);
  if (pwd == NULL) {
    perror("getpwuid");
    return 1;
  }

  puts(pwd->pw_name);
  return 0;
}

