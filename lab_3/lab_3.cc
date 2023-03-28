#include <iostream>
#include <vector>
#include <chrono>
#include <omp.h>

#pragma region Печать массива
void print_matrix(std::vector<std::vector<double>>& m1)
{
    for (int i = 0; i < m1.size(); i++) {
        for (int j = 0; j < m1[i].size(); j++) {
            std::cout << m1[i][j] << "\t";
        }
        std::cout << "\n";
    }
}
#pragma endregion

int main()
{
    const int n = 200;

    std::vector<std::vector<double>> A(n, std::vector<double>(n, 0));
    std::vector<double> B(n, 0);
    std::vector<double> X(n, 0);

    #pragma region Заполнение массивов
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                A[i][j] = 2;
            } else if (i == j + 1 || i == j - 1) {
                A[i][j] = -1;
            }
        }
        B[i] = i + 1;
    }
    #pragma endregion

    #pragma region Печать массива
    // std::cout << "Исходный массив:\n";
    // print_matrix(A);
    // std::cout << "\n";
    // std::cout << "Свободные коэффиценты:\n";
    // for (int i = 0; i < n; i++) {
    //     std::cout << B[i] << "\t";
    // }
    // std::cout << "\n\n";
    #pragma endregion
    
    #pragma region Решение СЛАУ методом Гаусса
    auto start_time = std::chrono::high_resolution_clock::now();
    for (int k = 0; k < n; k++) {
        #pragma omp parallel for
        for (int i = k + 1; i < n; i++) {
            double coeff = A[i][k] / A[k][k];
            for (int j = k; j < n; j++) {
                A[i][j] -= coeff * A[k][j];
            }
            B[i] -= coeff * B[k];
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        double sum = 0;
        for (int j = i + 1; j < n; j++) {
            sum += A[i][j] * X[j];
        }
        X[i] = (B[i] - sum) / A[i][i];
    }
    auto end_time = std::chrono::high_resolution_clock::now();
    #pragma endregion

    #pragma region Печать результата
    // std::cout << "Корни системы уровнения:\n";
    // for (int i = 0; i < n; i++) {
    //     std::cout << X[i] << " ";
    // }
    // std::cout << "\n\n";
    #pragma endregion

    std::cout << "Время исполнения: " << std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count() << " микросекунд";

    return 0;
}