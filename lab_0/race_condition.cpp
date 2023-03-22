#include <thread>
#include <iostream>
#include <mutex>

std::mutex a_mutex;
std::mutex b_mutex;

void func1(int &a) {
  for(int i = 0;i < 500000;  i++){
    a_mutex.lock();
    a++;
    a_mutex.unlock();
  }
}

void func2(int &a) {
  for(int i = 0;i < 500000;  i++){
    a_mutex.lock();
    a++;
    a_mutex.unlock();
  }
}

int main() {
    std::cout<< "task1 says: ";
    int a = 0;
    std::thread thr1(func1 , std::ref(a));
    std::thread thr2(func2 , std::ref(a));

    thr1.join();
    thr2.join();
    
    std::cout << "Expected 1 000 000 but actual: \n" << a;
}