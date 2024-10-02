# include <stdio.h>
# include <string.h>
# include "chacha20_functions.h"

void permute_block(int original_state[16], const char *constant, int key[8], int blockcount, int nonce[3], int output_state[16])
{
    memcpy(output_state, original_state, sizeof(int) * 16);
    
    // Perform permutations on the state: 20 total rounds (10 column-diagonal operations)
    for (int i = 1; i < 10; i++)
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
