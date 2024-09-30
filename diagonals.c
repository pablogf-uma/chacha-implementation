# include <stdio.h>
# include "chacha20_functions.h"

// quarter_round operates on the 4 diagonals of the initial state.
// Remember that in C, we can index 2D matrices lke a 1D array flat list of values.

void diagonals(int *state)
{
    quarter_round(state, 0, 5, 10, 15); // The first diagonal is the commplete middle one.
    quarter_round(state, 1, 6, 11, 12);  // The second is the one on top of the first one, etc.
    quarter_round(state, 2, 7, 8, 13); 
    quarter_round(state, 3, 4, 9, 14);
}
