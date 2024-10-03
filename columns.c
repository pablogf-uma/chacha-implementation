# include <stdio.h>
# include <stdint.h>
# include "chacha20_functions.h"

// Performs a quarter_round operation on the 4 columns of the state.
// Remember that in C, we can index 2D matrices like a 1D array flat list of values.

void columns(uint32_t state[])
{
    quarter_round(state, 0, 4, 8, 12); // Index of the cells contained in the first column.
    quarter_round(state, 1, 5, 9, 13);
    quarter_round(state, 2, 6, 10, 14);
    quarter_round(state, 3, 7, 11, 15);
}