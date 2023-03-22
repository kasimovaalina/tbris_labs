#include <thread>
#include <iostream>

void multiply_matrices(){
    int m1[5][5] = 
    {
        {1,2,3,4,5},
        {5,4,3,2,1},
        {1,2,3,4,5},
        {5,4,3,2,1},
        {1,2,3,4,5}};

    int m2[5][5] = {
        {5,4,3,2,1},
        {1,2,3,4,5},
        {5,4,3,2,1},
        {1,2,3,4,5},
        {5,4,3,2,1},
    };

    int result[5][5]={0};

    for (int row = 0; row < 5; row++) {
        for (int col = 0; col < 5; col++) {
            for (int inner = 0; inner < 5; inner++) {
                result[row][col] += m1[row][inner] * m2[inner][col];
            }
            std::cout << result[row][col] << "  ";
        }
        std::cout << "\n\n";
    }


}

int main(){
    multiply_matrices();

    return 0;
}
