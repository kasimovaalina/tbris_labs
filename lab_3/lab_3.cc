#include <iostream>
#include <vector>
#include <chrono>
#include <omp.h>

int main()
{
    const int N =  200;

    std::vector<std::vector<double>> A(N, std::vector<double>(N, 0));
    std::vector<double> b(N, 0);
    std::vector<double> x(N, 0);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) {
                A[i][j] = 2;
            } else if (i == j + 1 || i == j - 1) {
                A[i][j] = -1;
            }
        }
        b[i] = i + 1;
    }
    
    #pragma region Решение СЛАУ методом Гаусса
    auto start_time = std::chrono::high_resolution_clock::now();
    for (int k = 0; k < N; k++) {
        #pragma omp parallel for
        for (int i = k + 1; i < N; i++) {
            double coeff = A[i][k] / A[k][k];
            for (int j = k; j < N; j++) {
                A[i][j] -= coeff * A[k][j];
            }
            b[i] -= coeff * b[k];
        }
    }

    for (int i = N - 1; i >= 0; i--) {
        double sum = 0;
        for (int j = i + 1; j < N; j++) {
            sum += A[i][j] * x[j];
        }
        x[i] = (b[i] - sum) / A[i][i];
    }
    auto end_time = std::chrono::high_resolution_clock::now();

    std::cout << "Время исполнения мяу: " << std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count() << " микросекунд";

    return 0;
}