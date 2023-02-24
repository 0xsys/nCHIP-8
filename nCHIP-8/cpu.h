#include <inttypes.h>
#include <stdlib.h>

typedef struct {

uint8_t *memory;    // 4kB of memory (4096)

uint16_t PC;       // Program Counter

uint16_t I;        // Index Register

uint16_t *stack;    // Used to return from subroutines

uint8_t delay;      

uint8_t sound;

uint8_t *V;         // 16 8-bit general registers

} Components;