#include <iostream>
#include "Kogs.hpp"
int main(int argc, char** argv) {
    LOG("Welcome to the Kogs CLI!");
    Kogs::ByteChunk chunk;
    chunk.write(Kogs::KOGS_RETURN);
    chunk.disassemble("Test Chunk");
}