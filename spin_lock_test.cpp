//g++ -o spin_lock_test spin_lock_test.cpp -pthread

#include <iostream>
#include "spin_lock.h"

utility::spin_lock spin;

void f1()
{
  for (int i=0; i < 10; ++i) {
    spin.lock();
    std::cout << "F1 i=" << i << std::endl;
    spin.unlock();
  }
}

void f2()
{
  for (int i=0; i < 10; ++i) {
    spin.lock();
    std::cout << "F2 i=" << i << std::endl;
    spin.unlock();
  }
}

int main()
{
  std::thread t1(f1);
  std::thread t2(f2);
  t1.join();
  t2.join();
}
