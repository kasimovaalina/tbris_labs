#include <iostream>
#include "my_array.cpp"

int main() {
    My_array<int> a1;
    std::cout << "Массив а1:\n";
    std::cout << "Размер до добавления новых элементов: " << a1.get_size() << "\n";
    a1.insert(0,1);
    a1.insert(0,1);
    a1.insert(0,2);
    a1.insert(0,3);
    a1.insert(a1.get_size(), 100);
    std::cout << "Размер после добавления новых элементов: " << a1.get_size() << "\n";

    std::cout << "Содержание массива a1:\n";
    for (int i = 0; i < a1.get_size(); i++){
        std::cout << a1[i] << " ";
    }

    a1.erase(0);

    std::cout << "\nСодержание массива a1 после удаления элемента №0:\n";
    for (int i = 0; i < a1.get_size(); i++){
        std::cout << a1[i] << " ";
    }
    std::cout << "\n";

    My_array<double> a2(5);

    for(int i = 0; i < a2.get_size(); i++){
        a2[i] = i*M_PI;
    }


    std::cout << "Прохождение массива a2, используя итераторы:\n";
    for (auto it = a2.begin(); it != a2.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << "\n";

    a2.resize(10);

    for(int i = 0; i < 10; i++){
        a2[i] =  i*M_PI;
    }

    for(int i = 0; i < 10; i++){
        a2[i] =  i*M_PI;
    }

    std::cout << "Массив a2, увеличен:\n";
    for (auto it = a2.begin(); it != a2.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << "\n" << a2.get_size() <<"\n";

    a2.resize(3);

    std::cout << "Массив a2, уменьшен:\n";
    for (auto it = a2.begin(); it != a2.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << "\n";

    std::cout << "Массив a3:\n";
    My_array<int> a3(15);
    for (int i = 0; i < 15; i++){
        a3[i] = i;
        std::cout << a3[i] << " ";
    }
    std::cout << "\n";

    a1.swap(a3);
    std::cout << "Массив a1 после swap:\n";
    for (auto it = a1.begin(); it != a1.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << "\n";

    std::cout << "Массив a3 после swap:\n";
    for (auto it = a3.begin(); it != a3.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << "\n";

    return 0;
}