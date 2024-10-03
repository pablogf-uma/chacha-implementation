# include <stdio.h>
# include <stdint.h>

// Performs a quarter round on a given state.
// Parameters: The initial state and the 4 indexes of the cells that will be used to operate.
void quarter_round(uint32_t state[], int a, int b, int c, int d)
{
    state[a] += state[b];
    state[d] ^= state[a];
    state[d] <<= 16;
    state[c] += state[d];
    state[b] ^= state[c];
    state[b] <<= 12;
    state[a] += state[b];
    state[d] ^= state[a];
    state[d] <<= 8;
    state[c] += state[d];
    state[b] ^= state[c];
    state[b] <<= 7;   
}