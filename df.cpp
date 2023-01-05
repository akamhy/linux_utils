#include <iostream>
#include <sys/statvfs.h>

int main(int argc, char* argv[]) {
  if (argc < 2) {
    std::cerr << "Error: no mount point passed" << std::endl;
    return 1;
  }

  struct statvfs info;
  if (statvfs(argv[1], &info) != 0) {
    perror("statvfs");
    return 1;
  }

  std::cout << "Filesystem      Size  Used  Avail  Use%  Mounted on" << std::endl;
  std::cout << "--------------  ----  ----  -----  ----  ----------" << std::endl;
  std::cout << argv[1] << "  ";
  std::cout << (info.f_blocks * info.f_frsize) << "  ";
  std::cout << ((info.f_blocks - info.f_bfree) * info.f_frsize) << "  ";
  std::cout << (info.f_bavail * info.f_frsize) << "  ";
  std::cout << (info.f_blocks > 0 ? ((info.f_blocks - info.f_bfree) * 100 / info.f_blocks) : 0) << "  ";
  std::cout << argv[1] << std::endl;

  return 0;
}

