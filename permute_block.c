# include <stdio.h>
# include <stdint.h>
# include <string.h>
# include "chacha20_functions.h"

void permute_block(uint32_t state[16])
{
    uint32_t original_state[16];
    for (int i = 0; i < 16; i++) {
        original_state[i] = state[i];
    }

    // Perform permutations on the state: 20 total rounds (10 column-diagonal operations)
    for (int i = 0; i < 10; i++) {
        // Perform column operations
        quarter_round(state, 0, 4, 8, 12); // Index of the cells contained in the first column.
        quarter_round(state, 1, 5, 9, 13);
        quarter_round(state, 2, 6, 10, 14);
        quarter_round(state, 3, 7, 11, 15);
        // Perform diagonal operations
        quarter_round(state, 0, 5, 10, 15); // The first diagonal is the commplete middle one.
        quarter_round(state, 1, 6, 11, 12);  // The second is the one on top of the first one, etc.
        quarter_round(state, 2, 7, 8, 13); 
        quarter_round(state, 3, 4, 9, 14);
    }

    // Add the permuted state to the original state for pseudo-randomness:
    for (int i = 0; i < 16; i++) {
        state[i] = (state[i] + original_state[i]);
    }

    // Sequence the words one-by-one in little-endian order
    printf("Permutated serialized block:\n");
    for (size_t i = 0; i < 16; i++) {
        uint32_t word = state[i];
        state[i] = ((word & 0xFF000000) >> 24) |
                ((word & 0x00FF0000) >> 8)  |
                ((word & 0x0000FF00) << 8)  |
                ((word & 0x000000FF) << 24);
    
        uint8_t byte0 = (word >> 0)  & 0xFF;
        uint8_t byte1 = (word >> 8)  & 0xFF;
        uint8_t byte2 = (word >> 16) & 0xFF;
        uint8_t byte3 = (word >> 24) & 0xFF;
        
        // Print the 4 bytes in hexadecimal format
        printf("%02x %02x %02x %02x ", byte0, byte1, byte2, byte3);
        
        // Add a newline every 4 words (16 bytes)
        if ((i + 1) % 4 == 0) {
            printf("\n");
        }
    }
}
