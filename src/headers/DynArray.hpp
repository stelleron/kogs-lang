#ifndef DYNARRAY_HPP
    #define DYNARRAY_HPP
    #include "Memory.hpp"
    #define GROWTH_FACTOR 2 // How much to grow the dynamic array's size by
    #define GROW_CAPACITY(capacity) \
        ((capacity) < 8 ? 8 : (capacity) * 2) 
    
    // Dynamic array struct
    template <typename T>
    struct DynArray {
        T* array;
        int count;
        int capacity;
        DynArray() {
            array = nullptr;
        }
        void write(T data) {
            if (capacity < count + 1) {
                int oldCapcity = capacity;
                capacity = GROW_CAPACITY(oldCapcity);
                array = reallocate<T>(array, sizeof(T) * oldCapcity, sizeof(T) * capacity);
            }
            array[count] = data;
            count++;
        }
        ~DynArray() {
            array = reallocate<T>(array, sizeof(T) * capacity, 0);
        }
    };
#endif