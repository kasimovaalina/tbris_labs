#include <stdexcept>
#pragma once

template <typename T>
class My_array {
    private:
        T *_data;
        size_t _size;
        size_t _capacity;
    public:
        My_array();
        //тут была ошибка 
        My_array(size_t size);
        My_array(const My_array& other);
        ~My_array();
        My_array& operator=(const My_array& other);
        T& operator[](size_t index);
        size_t get_size();
        T* begin();
        T* end();
        void resize(size_t new_size);
        void insert(size_t index, const T& value);
        void erase(size_t index);
        void swap(My_array& other);
        void reserve(size_t new_capacity);
};