//g++ -o timer_test_smartptrs timer_test_smartptrs.cpp -O2 -DNDEBUG

#include <array>
#include <iostream>
#include <memory>
#include "timer.h"

struct point {
  int x;
  int y;
};

int main()
{
  std::cout << "Measure the unique_ptr using new" << std::endl;
  {
    std::array<std::unique_ptr<point>, 1000> unique_ptrs;
    utility::timer timer;
    for (int i = 0; i < unique_ptrs.size(); ++i) {
      unique_ptrs[i] = std::unique_ptr<point>(new point());
    }
  }
  std::cout << "Measure the unique_ptr using make_unique" << std::endl;
  {
    std::array<std::unique_ptr<point>, 1000> unique_ptrs;
    utility::timer timer;
    for (int i = 0; i < unique_ptrs.size(); ++i) {
      unique_ptrs[i] = std::make_unique<point>();
    }
  }
  std::cout << "Measure the shared_ptr using new" << std::endl;
  {
    std::array<std::shared_ptr<point>, 1000> shared_ptrs;
    utility::timer timer;
    for (int i = 0; i < shared_ptrs.size(); ++i) {
      shared_ptrs[i] = std::shared_ptr<point>(new point());
    }
  }
  std::cout << "Measure the shared_ptr using make_shared" << std::endl;
  {
    std::array<std::shared_ptr<point>, 1000> shared_ptrs;
    utility::timer timer;
    for (int i = 0; i < shared_ptrs.size(); ++i) {
      shared_ptrs[i] = std::make_shared<point>();
    }
  }
}
