# include <stdio.h>
# include <string.h>
# include <stdint.h>
# include <string.h>
# include "chacha20_functions.h"

int main()
{
    // Parameters for the initial state:
    // Use of uint32_t (unsigned 32 int): Ensures that bit-wise operations are performed without sign extension
    
    uint32_t state[16];
    char constant[16] = "expand 32-byte k";

    uint8_t key[32] = { 0x00, 0x00, 0x00, 0x00,
                        0x00, 0x00, 0x00, 0x00,
                        0x00, 0x00, 0x00, 0x00,
                        0x00, 0x00, 0x00, 0x00,
                        0x00, 0x00, 0x00, 0x00,
                        0x00, 0x00, 0x00, 0x00,
                        0x00, 0x00, 0x00, 0x00,
                        0x00, 0x00, 0x00, 0x00 };

    uint8_t nonce[12] = { 0x00, 0x00, 0x00, 0x00, 
                        0x00, 0x00, 0x00, 0x00,
                        0x00, 0x00, 0x00, 0x00 };


    uint32_t blockcount = 0;

    // Initialize the state with the specified parameters
    state_init(state, constant, key, blockcount, nonce);

    // permute_block() function call:
    permute_block(state);

     return 0;
}