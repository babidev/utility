#ifndef UTILITY_LOCKED_COUT_H
#define UTILITY_LOCKED_COUT_H

#include <iostream>
#include <mutex>
#include <sstream>

namespace utility {

class locked_cout final
{
public:
  locked_cout() {
    mutex_.lock();
  }
  ~locked_cout() {
    *stream_ << std::endl;
    mutex_.unlock();
  }

  template <class T>
  locked_cout& operator<<(const T& value) {
    *stream_ << value;
    return *this;
  }
private:
  static std::mutex mutex_;
  static std::ostream *stream_;
};

std::mutex locked_cout::mutex_;
std::ostream* locked_cout::stream_ = &std::cout;

}
#endif
