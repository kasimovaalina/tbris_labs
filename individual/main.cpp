#include <iostream>
#include "my_array.cpp"

bool check_my_array_creating(){
    My_array<int> a1;
    std::cout << "Массив а1:\n";
    std::cout << "Размер до добавления новых элементов: " << a1.get_size() << "\n";
    a1.insert(0,1);
    a1.insert(0,1);
    a1.insert(0,2);
    a1.insert(0,3);
    a1.insert(2,3);
    a1.insert(a1.get_size(), 100);
    std::cout << "Размер после добавления новых элементов: " << a1.get_size() << "\n";
    return a1.get_size()==6;
}

bool check_empty_array_erasing(){
    My_array<int> empty_array;
    try
    {
        empty_array.erase(0);
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
        return true;
    }
    return false;

}

bool check_my_array_erasing(){
    My_array<int> a1(10);
    for (int i =0; i < 10; i++){
        a1[i] = i;
    }
    a1.erase(9);
    a1.erase(0);
    return a1[0] == 1 && a1[7]==8 && a1.get_size()==8;
}

bool check_iterators(){
    My_array<int> array_to_test(5);
    int iterations_count = 0;
    for(int i = 0; i < array_to_test.get_size(); i++){
        array_to_test[i] = i;
    }
    for (auto it = array_to_test.begin(); it != array_to_test.end(); it++) {
        std::cout << *it << " ";
        iterations_count++;
    }
    return iterations_count==5;
}

bool check_iterators_on_empty_array(){
    My_array<double> array_to_test;
    int iterations_count = 0;
    for (auto it = array_to_test.begin(); it != array_to_test.end(); it++) {
        std::cout << *it << " ";
        iterations_count++;
    }
    return iterations_count==0;
}

bool check_resize_make_bigger(){
    My_array<double> array_to_test;
    array_to_test.resize(10);
    for (int i = 0; i < 10; i++){
        array_to_test[i] = 1;
    }
    return array_to_test.get_size()==10;
}

bool check_resize_make_smaller(){
    My_array<double> array_to_test(10);
    for (int i = 0; i < 10; i++){
        array_to_test[i] = 1;
    }
    array_to_test.resize(5);
    return array_to_test.get_size()==5;
}

bool check_resize_same(){
    My_array<double> array_to_test(2);
    for (int i = 0; i < 2; i++){
        array_to_test[i] = 1;
    }
    array_to_test.resize(2);
    return array_to_test.get_size()==2;
}

bool check_assignment(){
    My_array<double> array_to_test1(2);
    My_array<double> array_to_test2(10);
    array_to_test1 = array_to_test2;
    return array_to_test1.get_size() == 10;
}

bool check_assignment_equal(){
    My_array<double> array_to_test1(2);
    array_to_test1 = array_to_test1;
    return array_to_test1.get_size() == 2;
}

bool check_swap(){
    My_array<int> array_to_test1(2);
    My_array<int> array_to_test2(10);
    array_to_test1.swap(array_to_test2);
    return array_to_test2.get_size() == 2;
}

int main() {
    if (!check_my_array_creating()){
        std::cout<<"Размер массива не совпадает с ожидаемым\n";
    }

    if (!check_empty_array_erasing()){
        std::cout<<"Ничего не удаляется с пустого массива\n";
    }

    if (!check_my_array_erasing()){
        std::cout<<"Не удаляется элемент из полного массива\n";
    }

    if (!check_iterators()){
        std::cout<<"Итератор не проходит по всем элементам массива\n";
    }

    if (!check_iterators_on_empty_array()){
        std::cout<<"Итератор не проходит по всем элементам массива\n";
    }

    if (!check_resize_make_bigger()){
        std::cout<<"Не удалось увеличить массив\n";
    }

    if (!check_resize_make_smaller()){
        std::cout<<"Не удалось уменьшить массив\n";
    }

    if (!check_resize_same()){
        std::cout << "Ошибка при изменении массива  на тот же самый размер";
    }

    if (!check_assignment()){
        std::cout << "Ошибка при использовании оператора присвоения";
    }

    if (!check_assignment_equal()){
        std::cout << "Ошибка при использовании оператора присвоения";
    }

    if (!check_swap()){
        std::cout << "Ошибка при swap";
    }
    return 0;
}