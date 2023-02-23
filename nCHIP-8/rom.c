#include <stdio.h>

// Read ROM ; Need to do a check for if .ch8 extension.
FILE* openROM(const char **argv) {
    FILE *rom = fopen(argv, "rb");
    
    if(!rom) {
        perror("Could not open ROM file");
        return 1;
    }

    return rom;
}

// Load ROM into component memory (0x200)


// Free ROM memory