#ifndef MEMORY_HPP
    #define MEMORY_HPP
    #include <stdlib.h>
    #include "Debug.hpp"
    // Reallocation function
    template <typename T>
    T* reallocate(T* ptr, int oldSize, int newSize) {
        if (newSize == 0) {
            free(ptr);
            return nullptr;
        }
        T* result = (T*)realloc(ptr, newSize);
        if (result == NULL) {
            LOG("Error: Space unavailable for reallocation!");
            exit(1);
        }
        return result;
    }
#endif