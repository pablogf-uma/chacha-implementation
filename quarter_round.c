# include <stdio.h>
# include <stdint.h>

// Performs a quarter round on a given state.
// Parameters: The initial state and the 4 indexes of the cells that will be used to operate.
void quarter_round(uint32_t state[], int a, int b, int c, int d)
{
    state[a] += state[b];
    state[d] ^= state[a];
    state[d] = (state[d] << 16) | (state[d] >> (32 - 16));  // rotate-left 16 bits

    state[c] += state[d];
    state[b] ^= state[c];
    state[b] = (state[b] << 12) | (state[b] >> (32 - 12));  // rotate-left 12 bits

    state[a] += state[b];
    state[d] ^= state[a];
    state[d] = (state[d] << 8) | (state[d] >> (32 - 8));    // rotate-left 8 bits

    state[c] += state[d];
    state[b] ^= state[c];
    state[b] = (state[b] << 7) | (state[b] >> (32 - 7));    // rotate-left 7 bits
}

/* 

// RFC 7539 (Page 5) - CHACHA Quarter Round Test Vector


{
    uint32_t state[16] = { 0x879531e0,  0xc5ecf37d,  0x516461b1, 0xc9a62f8a,
                            0x44c20ef3,  0x3390af7f,  0xd9fc690b,  0x2a5f714c,
                            0x53372767,  0xb00a5631,  0x974c541a,  0x359e9963,
                            0x5c971061,  0x3d631689,  0x2098d9d6,  0x91dbd320 };

    quarter_round(state, 2, 7, 8, 13);

    // TESTING: Output the state matrix.
    printf("\nOriginal state matrix:\n");

    for (int a = 0; a < 4; a++)  // Loop over rows
    {
        for (int b = 0; b < 4; b++)  // Loop over columns
        {
            printf("%08x ", state[a * 4 + b]);  // Finding each element's index: row * 4 + column
        }
        printf("\n");
    }

    return 0;
}

*/