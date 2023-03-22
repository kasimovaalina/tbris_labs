#include <chrono>
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <math.h>
#include <algorithm>

int main(){
    std::srand(std::time(nullptr));

    long long capacity = std::pow(2,30);
    std::cout << "Array capacity: " << capacity << "\n";
    int* numbers = new int[capacity] {};

    for (long long i=0; i < capacity; i++) {
         numbers[i] = std::rand()%1000-500;
    }

    std::cout << "Array type\t" << "|Positive numbers count\t" << "|Time\n";
    std::cout << "-----------------------------------------------\n";

    int count_unsort = 0;
    auto start = std::chrono::high_resolution_clock::now();
    for (long long i = 0; i < capacity; i++){
        if (numbers[i] >= 0){
            count_unsort++;
        }
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto duration_unsort = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "Unsorted\t|" << count_unsort << "\t\t|" << duration_unsort.count() << "\n";

    std::sort(numbers, numbers+capacity);

    int count_sort = 0;
    start = std::chrono::high_resolution_clock::now();
    for (long long i = 0; i < capacity; i++){
        if (numbers[i] >= 0){
            count_sort++;
        }
    }
    end = std::chrono::high_resolution_clock::now();
    auto duration_sort = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "Sorted\t\t|" << count_sort << "\t\t|"<< duration_sort.count() << "\n";

    delete[] numbers;
    return 0;

}