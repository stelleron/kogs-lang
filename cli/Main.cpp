#include <iostream>
#include "Kogs.hpp"
int main(int argc, char** argv) {
    LOG("Welcome to the Kogs CLI!");
    DynArray<int> dyn;
    dyn.write(3);
    dyn.write(5);
}