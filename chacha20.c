# include <stdio.h>
# include <string.h>
# include "chacha20_functions.h"

int main()
{
    // Parameters for the initial state:
    // Use of unsigned int: Ensures that bit-wise operations are performed without sign extension
    unsigned int original_state[16];
    const char constant[16] = "apxe3 dnyb-2k et"; // Specified by the RFC, usually "expand 32-byte k"
    unsigned int key[8] = { 0x00000000, 0x00000000, 0x00000000, 0x00000000,
                    0x00000000, 0x00000000, 0x00000000, 0x00000000 };
    unsigned int blockcount = 0;
    unsigned int nonce[3] = {0x00000000, 0x00000000, 0x00000000};

    // Initialize the state with the specified parameters
    state_init(original_state, constant, key, blockcount, nonce);

    // "state" will hold the permutated state:
    unsigned int state[16];
    memcpy(state, original_state, sizeof(unsigned int) * 16);

    // permute_block() function call:
    permute_block(state, constant, key, blockcount, nonce, state);

    // Output state matrices:
    printf("Original state matrix:\n");

    for (int a = 0; a < 4; a++)
    {
        for (int b = 0; b < 4; b++)
        {
            printf("%08x", original_state[a * 4 + b]); // Output in hexadecimal format
            printf(" ");                              //  Relationship between 1D array and 4x4 matrix: rows * 4 + columns
        }
        printf("\n");
    }
    
    printf("\n");

    printf("Permuted state matrix:\n");
    for (int e = 0; e < 4; e++)
    {
        for (int d = 0; d < 4; d++)
        {
            printf("%08x", state[e * 4 + d]);
            printf(" ");
        }
        printf("\n");
    }

    printf("\n");

    return 0;
}