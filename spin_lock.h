#ifndef UTILITY_SPIN_LOCK_H
#define UTILITY_SPIN_LOCK_H

#include <atomic>
#include <thread>

namespace utility {

class spin_lock final
{
public:
  void lock() {
    while (flag_.test_and_set(std::memory_order_acquire));
  }
  void unlock() {
    flag_.clear(std::memory_order_release);
  }
private:
  std::atomic_flag flag_{ATOMIC_FLAG_INIT};
};

}
#endif
