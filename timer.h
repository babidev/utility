#ifndef UTILITY_TIMER_H
#define UTILITY_TIMER_H

#include <chrono>
#include <iostream>

namespace utility {

class timer final
{
public:
  timer() {
    start = std::chrono::high_resolution_clock::now();
  }
  ~timer() {
    stop = std::chrono::high_resolution_clock::now();
    auto duration = stop - start;
    std::string message = std::string{"Timer: "} +
                          std::to_string(0.000001 * duration.count()) +
                          " ms\n";
    std::cout << message;
  }
private:
  std::chrono::high_resolution_clock::time_point start;
  std::chrono::high_resolution_clock::time_point stop;
};

}
#endif
