#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/sysinfo.h>

int main(int argc, char* argv[]) {
  struct sysinfo info;
  if (sysinfo(&info) != 0) {
    perror("sysinfo");
    return 1;
  }

  printf("Up %ld days, %ld hours, %ld minutes\n", info.uptime / 86400, (info.uptime / 3600) % 24, (info.uptime / 60) % 60);
  return 0;
}

