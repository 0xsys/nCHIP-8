#include "cpu.h"
#include "opcodes.h"

// Fetch decode execute
uint16_t fetchOpcode(Components *chip8) {

    uint16_t opcode;

    // First byte
    uint16_t fbyte = chip8->memory[chip8->PC];

    // Second byte
    uint8_t sbyte = chip8->memory[chip8->PC + 1];

    // Bitwise OR to get the opcode value
    opcode = (fbyte << 8) | sbyte;

    return opcode;
}

uint16_t incrementPC(Components *chip8) {
    return chip8->PC += 2;
}

Instructions loadInstructionStruct(uint16_t opcode) {
    Instructions instruction;

    instruction.opcode = opcode;

    instruction.I = opcode >> 12;

    instruction.X = (opcode & 0x0F00) >> 8;
    
    instruction.Y = (opcode & 0x00F0) >> 4;

}

// Opcode function definitions

// Clear screen
void opcode0x00E0(Components *chip8) {
    
    memset(chip8->display, 0, sizeof(bool) * (64 * 32));

    incrementPC(chip8);

}

// Pass opcode details to function, execute match from list of opcodes

