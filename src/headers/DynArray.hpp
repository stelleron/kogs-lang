#ifndef DYNARRAY_HPP
    #define DYNARRAY_HPP
    #include "Debug.hpp"
    #include "Memory.hpp"
    #define GROWTH_FACTOR 2 // How much to grow the dynamic array's size by
    #define GROW_CAPACITY(capacity) \
        ((capacity) < 8 ? 8 : (capacity) * GROWTH_FACTOR) 
    // Dynamic array struct
    template <typename T>
    struct DynArray {
        T* array;
        int count;
        int capacity;
        DynArray() {
            array = nullptr;
        }
        void append(T data) {
            if (capacity < count + 1) {
                int oldCapcity = capacity;
                capacity = GROW_CAPACITY(oldCapcity);
                array = reallocate<T>(array, sizeof(T) * oldCapcity, sizeof(T) * capacity);
            }
            array[count] = data;
            count++;
        }
        T& operator[](int index) {
            if (index >= count) {
                LOG("Error: Accessed item fron unavailable index!");
                exit(0);
            }
            return array[index];
        }
        ~DynArray() {
            array = reallocate<T>(array, sizeof(T) * capacity, 0);
        }
    };
#endif