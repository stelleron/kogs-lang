#ifndef DEBUG_HPP
    #define DEBUG_HPP
    #ifdef DEBUG
        #include <iostream>
        #define LOG_BASE(arg) std::cout << arg
        #define LOG(arg) std::cout << arg << std::endl
    #else
        #define LOG_BASE(arg)
        #define LOG(arg)
    #endif
#endif