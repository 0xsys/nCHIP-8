#include "cpu.h"

// Fetch decode execute
uint16_t fetchOpcode(Components *chip8) {

    uint16_t opcode;

    // First byte
    uint16_t fbyte = chip8->memory[chip8->PC];

    // Second byte
    uint8_t sbyte = chip8->memory[chip8->PC + 1];

    // Bitwise OR to get the opcode value
    opcode = (fbyte << 8) | sbyte;

    chip8->PC += 2;

    return opcode;
}


// Pass opcode details to function, execute match from list of opcodes
