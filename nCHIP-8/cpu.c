#include "cpu.h"

// Initialise memory for components of CHIP-8
void cpuInitialise(Components *chip8) {

    // Chose calloc for memory allocation, as sets to 0 instead of garbage value.
    
    chip8->memory = calloc(4096, sizeof(uint8_t));

    chip8->stack = calloc(16, sizeof(uint16_t));

    chip8->V = calloc(16, sizeof(uint8_t));

    chip8->PC = 0x200;

}
// Fetch decode execute

// Free components resources
