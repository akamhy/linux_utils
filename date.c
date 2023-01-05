#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char* argv[]) {
  time_t t = time(NULL);
  if (t == (time_t)-1) {
    perror("time");
    return 1;
  }

  struct tm* local = localtime(&t);
  if (local == NULL) {
    perror("localtime");
    return 1;
  }

  char date[32];
  if (strftime(date, sizeof(date), "%a %b %e %H:%M:%S %Z %Y", local) == 0) {
    fprintf(stderr, "strftime: string too large\n");
    return 1;
  }
  puts(date);
  return 0;
}

