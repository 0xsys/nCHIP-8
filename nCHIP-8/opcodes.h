#include "cpu.h"

typedef struct {
    
    uint16_t opcode;
    
    uint8_t I;
    
    uint8_t X; // Second nibble  }--|
               //                   |-- Used to look up one of the 16 registers (VX & VY) from V0 - VF.
    uint8_t Y; // Third nibble   }--|
    
    uint8_t J;
    
    uint16_t NNN;
    
    uint8_t KK; 

} Instructions;


uint16_t fetchOpcode(Components *chip8);

uint16_t incrementPC(Components *chip8);

Instructions loadInstructionStruct(uint16_t opcode);

// Opcode Instructions;

void opcode0x00E0(Components *chip8);