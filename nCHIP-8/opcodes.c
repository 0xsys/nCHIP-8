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

    instruction.NNN = opcode & 0x0FFF;

    instruction.NN = opcode & 0x00FF;

}

// Opcode function definitions

// Clear screen
void opcode0x00E0(Components *chip8) {
    
    memset(chip8->display, 0, sizeof(bool) * (64 * 32));

    incrementPC(chip8);

}

// Jump to instruction NNN
void opcode0x1NNN(Components *chip8, Instructions instruction) {

    chip8->PC = instruction.NNN;

}

void opcode0x6XNN(Components *chip8, Instructions instruction) {

    chip8->V[instruction.X] = instruction.NN;
    
    incrementPC(chip8);

}

void opcode0x7XNN(Components *chip8, Instructions instruction) {

    state->v[instruction.X] += instruction.KK;

    incrementPC(chip8);

}

void opcodeANNN(Components *chip8, Instructions instruction) {

    chip8->I = instruction.NNN;

    incrementPC(chip8);

}

// Pass opcode details to function, execute match from list of opcodes
void executeOpcode(Components *chip8, Instructions instruction) {
    switch(instruction.I) {
        
        case 0x0:
            switch (instruction.full_opcode) {
            case 0x00E0:
                
                opcode0x00E0(chip8);
                break;

            }
    
        case 0x1: 
            opcode0x1NNN(chip8, instruction);
            break;
    
        case 0x6:
            opcode0x6XNN(chip8, instruction);
            break;

        case 0x7:
            opcode0x7XNN(chip8, instruction);
            break;

        case 0xA:
            opcodeANNN(chip8, instruction);

        case default:
            printf("Opcode unrecognised: %x\n", instruction.opcode);
            exit(1);

    }
}
