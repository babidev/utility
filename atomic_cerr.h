#ifndef UTILITY_ATOMIC_CERR_H
#define UTILITY_ATOMIC_CERR_H

#include <iostream>
#include <sstream>

namespace utility {

class atomic_cerr final
{
public:
  ~atomic_cerr() {
    stream_ << std::endl;
    std::cerr << stream_.str();
  }

  template <class T>
  atomic_cerr& operator<<(const T& value) {
    stream_ << value;
    return *this;
  }
private:
  std::ostringstream stream_;
};

}
#endif
