#ifndef DYNARRAY_HPP
    #define DYNARRAY_HPP
    // Dynamic array struct
    template <typename T>
    struct DynArray {
        T* array;
        DynArray() {
            array = nullptr;
        }
        void write(T data) {
            
        }
        ~DynArray() {

        }
    };
#endif