#include <thread>
#include <mutex>
#include <iostream>

int main() {

    std::mutex a_mutex;
    std::mutex b_mutex;
    
    std::thread t_a([&a_mutex, &b_mutex] {
        a_mutex.lock();
        std::cout << "Thread-A locked mutex a\n";
        b_mutex.lock();
        std::cout << "Thread-A locked mutex b\n";

        a_mutex.unlock();
        std::cout << "Thread-A unlocked mutex a\n";
        b_mutex.unlock();
        std::cout << "Thread-A unlocked mutex b\n";
    });
    
    //порядок блокировки соотвествует трэду А
    std::thread t_b([&a_mutex, &b_mutex] {
        a_mutex.lock();
        std::cout << "Thread-B locked mutex a\n";
        b_mutex.lock();
        std::cout << "Thread-B locked mutex b\n";

        a_mutex.unlock();
        std::cout << "Thread-B unlocked mutex a\n";
        b_mutex.unlock();
        std::cout << "Thread-B unlocked mutex b\n";
    });


    t_a.join();
    t_b.join();
}