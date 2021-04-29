#ifndef UTILITY_ATOMIC_COUT_H
#define UTILITY_ATOMIC_COUT_H

#include <iostream>
#include <sstream>

namespace utility {

class atomic_cout final
{
public:
  ~atomic_cout() {
    stream_ << std::endl;
    std::cout << stream_.str();
  }

  template <class T>
  atomic_cout& operator<<(const T& value) {
    stream_ << value;
    return *this;
  }
private:
  std::ostringstream stream_;
};

}
#endif
