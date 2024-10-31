# include <stdio.h>
# include <stdint.h>
# include <string.h>
# include "chacha20_functions.h"

void permute_state(uint32_t state[16], uint32_t output_keystream[64])
{
    // Make copy of the original state, for later addition to the permuted state
    uint32_t original_state[16];
    for (int i = 0; i < 16; i++) {
        original_state[i] = state[i];
    }

/* TEST:
    printf("\n");
    for (int a = 0; a < 4; a++) 
    {
        for (int b = 0; b < 4; b++)
        {
            printf("%08x ", state[a * 4 + b]);  
        }
        printf("\n");  
    }
    printf("\n");
*/

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

/* TEST:
    for (int a = 0; a < 4; a++) 
    {
        for (int b = 0; b < 4; b++)
        {
            printf("%08x ", state[a * 4 + b]);  
        }
        printf("\n");  
    }
    printf("\n");
*/

    // Serialize the permuted state into the output keystream
    for (size_t i = 0; i < 16; i++) {

        uint32_t word = state[i];
        output_keystream[i * 4] = (word >> 0)  & 0xFF;
        output_keystream[i * 4 + 1] = (word >> 8)  & 0xFF;
        output_keystream[i * 4 + 2] = (word >> 16) & 0xFF;
        output_keystream[i * 4 + 3] = (word >> 24) & 0xFF;
    }
    
/* TEST:
    for (int i = 0; i < 64; i++) {
        printf("%02x", output_keystream[i]);
        printf(":");
    }
    printf("\b \b");
    printf("\n");
*/
}
