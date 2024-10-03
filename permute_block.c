# include <stdio.h>
# include <stdint.h>
# include <string.h>
# include "chacha20_functions.h"

void permute_block(uint32_t original_state[16], const char *constant, uint32_t key[8], uint32_t blockcount, uint32_t nonce[3], uint32_t output_state[16])
{
    memcpy(output_state, original_state, sizeof(uint32_t) * 16);
    
    // Perform permutations on the state: 20 total rounds (10 column-diagonal operations)
    for (int i = 0; i < 10; i++)
    {
        columns(output_state);
        diagonals(output_state);
    }

    // Add the permuted state to the original state for pseudo-randomness:
    for (int j = 0; j < 16; j++)
    {
        output_state[j] += original_state[j];
    }
}
