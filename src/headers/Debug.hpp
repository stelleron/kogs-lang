#ifndef DEBUG_HPP
    #define DEBUG_HPP
    #ifdef DEBUG
        #include <iostream>
        #define LOG(arg) std::cout << arg << std::endl;
    #else
        #define LOG(arg)
    #endif
#endif