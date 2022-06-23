#ifndef KOGS_BYTECODE_HPP
    #define KOGS_BYTECODE_HPP
    namespace Kogs {
        // Enum to store operation codes
        enum Operation {
            KOGS_RETURN, // Return command
        };

        // Bytecode chunks
        struct ByteChunk {
            DynArray<uint8_t> code;
            // Methods
            ByteChunk(){}
            ~ByteChunk(){}

            void write(uint8_t opcode); // Write code to a chunk
            #ifdef DEBUG
                void disassemble(const char* name); // Disassemble a chunk to get its instructions
                void readOpCode(int& x); // Read an operation code
            #endif
        };
    }
#endif