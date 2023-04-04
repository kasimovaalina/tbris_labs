#include <iostream>
#include <ctime>
#include <chrono>
#define SIZE 200

#pragma region OpenMPI
void multiply_matrices_with_OpenMPI(){
    std::srand(std::time(nullptr)); 
    int m1[SIZE][SIZE] = {0};
    int m2[SIZE][SIZE] = {0};
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++){
            m1[i][j] = std::rand() % 10;
            m2[i][j] = std::rand() % 10;
        }
    }

    int result[SIZE][SIZE]={0};
    int i, j, k;
    auto start = std::chrono::high_resolution_clock::now();
    #pragma omp parallel for shared(m1,m2,result) private(i, j, k)
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            for (int inner = 0; inner < SIZE; inner++) {
                result[row][col] += m1[row][inner] * m2[inner][col];
            }
        }
    }
    
    auto end = std::chrono::high_resolution_clock::now();
    auto time_consumed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "With OpenMP: " << time_consumed.count() << " microseconds" << "\n";

}
#pragma endregion

void multiply_matrices_linear(){
    std::srand(std::time(nullptr));

    #pragma region Заполняем массивы
    int m1[SIZE][SIZE] = {0};
    int m2[SIZE][SIZE] = {0};
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++){
            m1[i][j] = std::rand() % 10;
            m2[i][j] = std::rand() % 10;
        }
    }

    int result[SIZE][SIZE] = {0};
    #pragma endregion

    #pragma region Последовательное
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < SIZE; k++) {
                result[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto time_consumed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "Linear (IJK): " << time_consumed.count() << " microseconds" << "\n";
    #pragma endregion

    #pragma region Зануляем массив result
        for (int i = 0; i < SIZE; i++){
        for (int j = 0; j <SIZE; j++){
            result[i][j] = 0;
        }
    }
    #pragma endregion

    #pragma region KIJ
    start = std::chrono::high_resolution_clock::now();
    for (int k = 0; k < SIZE; k++) {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                result[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
    end = std::chrono::high_resolution_clock::now();
    time_consumed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "Optimal linear (KIJ): " << time_consumed.count() << " microseconds\n";
    #pragma endregion

    #pragma region Зануляем массив result
        for (int i = 0; i < SIZE; i++){
        for (int j = 0; j <SIZE; j++){
            result[i][j] = 0;
        }
    }
    #pragma endregion

}

int main(){
    multiply_matrices_linear();
    multiply_matrices_with_OpenMPI();
    return 0;
}