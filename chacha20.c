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
    uint8_t key[32] = { 0x00, 0x01, 0x02, 0x03,
                        0x04, 0x05, 0x06, 0x07,
                        0x08, 0x09, 0x0A, 0x0B,
                        0x0C, 0x0D, 0x0E, 0x0F,
                        0x10, 0x11, 0x12, 0x13,
                        0x14, 0x15, 0x16, 0x17,
                        0x18, 0x19, 0x1A, 0x1B,
                        0x1C, 0x1D, 0x1E, 0x1F};
    uint32_t blockcount = 1;
    uint8_t nonce[12] = { 0x00, 0x00, 0x00, 0x09, 
                        0x00, 0x00, 0x00, 0x4a,
                        0x00, 0x00, 0x00, 0x00 };

    // Initialize the state with the specified parameters
    state_init(original_state, constant, key, blockcount, nonce);

    // "state" will hold the permutated state:
    uint32_t state[16];
    memcpy(state, original_state, sizeof(uint32_t) * 16);

    // permute_block() function call:
    permute_block(state, state);







//     // Output the state matrix
//     printf("\nOriginal state matrix:\n");

//     for (int a = 0; a < 4; a++)  // Loop over rows
//     {
//         for (int b = 0; b < 4; b++)  // Loop over columns
//         {
//             printf("%08x ", original_state[a * 4 + b]);  // Finding each element's index: row * 4 + column
//         }
//         printf("\n");  // New line after each row
//     }

    
//     printf("\n");

//     // Output the state matrix
//     printf("Permuted state matrix:\n");

//     for (int a = 0; a < 4; a++)
//     {
//         for (int b = 0; b < 4; b++)
//         {
//             printf("%08x ", state[a * 4 + b]);
//         }
//         printf("\n");
//     }

//     printf("\n");
//     return 0;
}