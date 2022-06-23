#include <stdint.h>
#include <stdio.h>
#include "DynArray.hpp"
#include "KogsBytecode.hpp"
namespace Kogs {
    void ByteChunk::write(uint8_t opcode) {
        code.append(opcode);
    }
    #ifdef DEBUG
        void basicOpCode(const char* name, int& x) {
            LOG(name);
            x += 1;
        }

        void ByteChunk::readOpCode(int& x) {
            printf("%04d ", x);
            uint8_t opcode = code[x];
            switch (opcode) {
                case KOGS_RETURN: basicOpCode("KOGS_RETURN", x); break;
                default:
                    LOG("Unknown opcode");
                    x += 1;
                    break;
            }
        }
        void ByteChunk::disassemble(const char* name) {
            LOG("== " << name << " ==");
            for (int x = 0; x < code.count;) {
                readOpCode(x);
            }
        }
    #endif
}