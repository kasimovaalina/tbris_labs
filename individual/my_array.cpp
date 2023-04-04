#include "my_array.h"

#pragma region Конструктор и деструкторы
template <typename T>
My_array<T>::My_array(){
    _data = nullptr;
    _size = 0;
    _capacity = 0;
}

template <typename T>
My_array<T>::My_array(int size){
    _size = size;
    _capacity = size;
    _data = new T[_capacity];
}

template <typename T>
My_array<T>::My_array(const My_array& other){
    _size = other._size;
    _capacity = other._capacity;
    _data = new T[_capacity];
    for (size_t i = 0; i < _size; i++) {
        _data[i] = other._data[i];
    }
}

template <typename T>     
My_array<T>::~My_array(){
    delete[] _data;
}
#pragma endregion

template <typename T>
My_array<T> My_array<T>::operator=(My_array other){
    swap(*this, other);
    return *this;
}

template <typename T>
T& My_array<T>::operator[](size_t index){
    if (index >= _size || index < 0) {
        throw std::out_of_range("Индекс вне границ массива!");
    }
    return _data[index];
}

template <typename T>
size_t My_array<T>::get_size() {
    return _size;
}


#pragma region Для итераторов
template <typename T>
T*  My_array<T>::begin() {
    return _data;
}
template <typename T>
T*  My_array<T>::end(){
    return _data + _size;
}
#pragma endregion

template <typename T>
void My_array<T>::resize(size_t new_size){
    if (new_size > _capacity) {
        reserve(new_size);
    }
    for (size_t i = _size; i < new_size; i++) {
        _data[i] = T();
    }
    _size = new_size;
}

template <typename T>
void My_array<T>::insert(size_t index, const T& value){
    if (index > _size || index < 0){
        throw std::out_of_range("Индекс вне границ массива!");
    }
    if (_size == _capacity) {
        if (_capacity == 0){
            reserve(1);
        } else {
            reserve(_capacity*2);
        }

    }
    for (size_t i=_size; i > index; i--){
        _data[i] = _data[i-1];
    }
    _data[index] = value;
    _size++;
}
        
template <typename T>
void My_array<T>::erase(size_t index){
    if (index >= _size || index < 0){
        throw std::out_of_range("Индекс вне границ массива!");
    }
    for (size_t i = index; i < _size - 1; i++) {
        _data[i] = _data[i + 1];
    }
    _size--;
}


template <typename T>
void My_array<T>::reserve(size_t new_capacity){
    if (new_capacity > _capacity) {
        T* new_data = new T[new_capacity];
        for (size_t i = 0; i < _size; i++) {
            new_data[i] = _data[i];
        }
        delete[] _data;
        _data = new_data;
        _capacity = new_capacity;
    }
}