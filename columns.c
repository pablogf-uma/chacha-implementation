# include <stdio.h>
# include "chacha20_functions.h"

// quarter_round operates on the 4 columns of the initial state.
// Remember that in C, we can index 2D matrices lke a 1D array flat list of values.

void columns(int state[])
{
    quarter_round(state, 0, 4, 8, 12); // Index of the cells contained in the first column.
    quarter_round(state, 1, 5, 9, 13);
    quarter_round(state, 2, 6, 10, 14);
    quarter_round(state, 3, 7, 11, 15);
}