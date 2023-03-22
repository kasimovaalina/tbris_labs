#include <chrono>
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <math.h>

int main(){
    std::srand(std::time(nullptr));
    int steps[] = { 1, 2, 4, 8, 16, 32, 64, 128 };

    long long capacity = std::pow(2,30);
    std::cout << "Array capacity: " << capacity << "\n";
    unsigned* numbers = new unsigned[capacity] {};

    for (long long i=0; i < capacity; i++) {
         numbers[i] = std::rand();
    }

    std::cout << "Step\t" << "|Sum\t\t\t" << "|Time total\t"<< "|Average time spend per element\n";
    std::cout << "------------------------------------------------------------\n";

    for (int j = 0; j < 8; j++){
        long long sum = 0;
        auto start = std::chrono::high_resolution_clock::now();

        for (int k = 0; k < capacity; k+=steps[j]){
            sum += numbers[k];
        }
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

        std::cout << steps[j] << "\t|" << sum << "\t| " << duration.count() << "\t|" << (double)duration.count() / ((double)capacity/steps[j]) << "\n";

    }

    delete[] numbers;
    return 0;

}