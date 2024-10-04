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
