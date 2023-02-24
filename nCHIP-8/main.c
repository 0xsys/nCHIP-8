// Call all required functions from .c files

// UNDECIDED: Draw graphics to terminal with ncurses library. Perhaps seperate into graphics.c/h file

// ToDo / Want to implement:
// 
// Idea for graphics - not sure of if possible with ncurses, perhaps only SDL2 / OpenGL.
// __________________________________
// |                   |            |
// |                   | Stack      |
// |                   |            |
// |                   |------------|
// |  Program gameplay |            |   UNSURE OF IF THIS IS THE HEIGHT OF DIVIDER YET, ROUGH PLAN.
// |                   | Registers  |
// |                   |            |
// |                   |------------|
// |                   |            |
// |                   | Debugger   |
// |                   |            |
// ----------------------------------

#include "rom.h"
#include <stdbool.h>

int main(int argc, char **argv) {

    if(argc != 2) {
        printf("Usage: ./nCHIP-8 PATH/TO/ROM");
    }
    
    uint16_t opcode;
    Components chip8;

    // Initialise the chip8 components struct 
    cpuInitialise(&chip8);

    // Load fontset from cpu.h into memory
    // Load ROM into memory of chip8
    loadROM(argv, &chip8);

    // Fetch, Decode, Execute ; including ncurses graphics and keyboard input, and sound emulation
    for( int i = 0; i < 20; i++) {

    opcode = fetchOpcode(&chip8);

    printf("Opcode: %x\n", opcode);
    }
    //while(true) {







    //}

}