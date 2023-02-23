#include <stdio.h>
#include <stdlib.h>
#include "cpu.h"

// Load ROM into component memory (0x200) ; Need to do a check for if .ch8 extension.
int loadROM(const char **argv, Components *chip8) {
    
    int romSize;

    FILE *rom = fopen(argv[1], "rb");
    
    if(!rom) {
        perror("Could not open ROM file");
        return 1;
    }

    // Get ROM size in bytes
    fseek(rom, 0, SEEK_END);
    romSize = ftell(rom);
    fseek(rom, 0, SEEK_SET);

    fread(chip8->memory +0x200, sizeof(int), romSize, rom);    

    fclose(rom);

}