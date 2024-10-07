# include <stdio.h>
# include <stdint.h>
# include <string.h>
# include "chacha20_functions.h"

void permute_block(uint32_t original_state[16], uint32_t output_state[16])
{
    memcpy(output_state, original_state, sizeof(uint32_t) * 16);

    for (int a = 0; a < 4; a++)  // Loop over rows
    {
        for (int b = 0; b < 4; b++)  // Loop over columns
        {
            printf("%08x ", output_state[a * 4 + b]);  // Finding each element's index: row * 4 + column
        }
        printf("\n");  // New line after each row
    }

    printf("\n");
    
    // Perform permutations on the state: 20 total rounds (10 column-diagonal operations)
    for (int i = 0; i < 10; i++)
    {
        // Perform column operations
        quarter_round(output_state, 0, 4, 8, 12); // Index of the cells contained in the first column.
        quarter_round(output_state, 1, 5, 9, 13);
        quarter_round(output_state, 2, 6, 10, 14);
        quarter_round(output_state, 3, 7, 11, 15);
        // Perform diagonal operations
        quarter_round(output_state, 0, 5, 10, 15); // The first diagonal is the commplete middle one.
        quarter_round(output_state, 1, 6, 11, 12);  // The second is the one on top of the first one, etc.
        quarter_round(output_state, 2, 7, 8, 13); 
        quarter_round(output_state, 3, 4, 9, 14);
    }

    for (int a = 0; a < 4; a++)  // Loop over rows
    {
        for (int b = 0; b < 4; b++)  // Loop over columns
        {
            printf("%08x ", original_state[a * 4 + b]);  // Finding each element's index: row * 4 + column
        }
        printf("\n");  // New line after each row
    }

    printf("\n");

    // Add the permuted state to the original state for pseudo-randomness:
    for (int j = 0; j < 16; j++)
    {
        output_state[j] = (original_state[j] + output_state[j]) & 0xFFFFFFFF;  // Modulo 2^32
    }

    for (int a = 0; a < 4; a++)  // Loop over rows
    {
        for (int b = 0; b < 4; b++)  // Loop over columns
        {
            printf("%08x ", original_state[a * 4 + b]);  // Finding each element's index: row * 4 + column
        }
        printf("\n");  // New line after each row
    }

    printf("\n");

    // Sequence the words one-by-one in little-endian order
    for (size_t i = 0; i < 16; i++) {
    uint32_t word = output_state[i];
    output_state[i] = ((word & 0xFF000000) >> 24) |
                ((word & 0x00FF0000) >> 8)  |
                ((word & 0x0000FF00) << 8)  |
                ((word & 0x000000FF) << 24);
    }

    for (int a = 0; a < 4; a++)  // Loop over rows
    {
        for (int b = 0; b < 4; b++)  // Loop over columns
        {
            printf("%08x ", original_state[a * 4 + b]);  // Finding each element's index: row * 4 + column
        }
        printf("\n");  // New line after each row
    }

}
