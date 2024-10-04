# include <stdio.h>
# include <string.h>
# include <stdint.h>
# include <string.h>
# include "chacha20_functions.h"

int main()
{
    // Parameters for the initial state:
    // Use of uint32_t (unsigned 32 int): Ensures that bit-wise operations are performed without sign extension
    uint32_t original_state[16];
    char constant[16] = "expand 32-byte k";
    uint32_t key[8] = { 0x00000000, 0x00000000, 0x00000000, 0x00000000,
                    0x00000000, 0x00000000, 0x00000000, 0x00000000 };
    uint32_t blockcount = 0;
    uint32_t nonce[3] = {0x00000000, 0x00000000, 0x00000000};

    // Initialize the state with the specified parameters
    state_init(original_state, constant, key, blockcount, nonce);

    // "state" will hold the permutated state:
    uint32_t state[16];
    memcpy(state, original_state, sizeof(uint32_t) * 16);

    // permute_block() function call:
    permute_block(state, constant, key, blockcount, nonce, state);

// Output state matrices:
    printf("Original state matrix (little-endian):\n");

    for (int a = 0; a < 4; a++)
    {
        for (int b = 0; b < 4; b++)
        {
            // To output bytes in little endian, since printf() outputs them in big-endian
            int x = original_state[a * 4 + b]; // Finding each element's index: row * 4 + column
            unsigned char* ptr = (unsigned char*)&x; // Access the address of the integer
            for(int i = 0; i < sizeof(int); i++)
            {
                printf("%02x", ptr[i]); // Output in hexadecimal format
            }                           
            printf(" ");                              
        }
        printf("\n");
    }
    
    printf("\n");

    printf("Permuted state matrix (little-endian):\n");
    for (int e = 0; e < 4; e++)
    {
        for (int d = 0; d < 4; d++)
        {
            int y = state[e * 4 + d];
            unsigned char* ptr2 = (unsigned char*)&y;
            for(int i = 0; i < sizeof(int); i++)
            {
                printf("%02x", ptr2[i]);
            }                           
            printf(" ");
        }
        printf("\n");
    }
    printf("\n");
    return 0;
}