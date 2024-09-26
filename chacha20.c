# include <stdio.h>
# include "chacha20_functions.h"


int main()
{
    // Load the initial state.
    int state[] = { 0, 1, 2, 3,
                    4, 5, 6, 7,
                    8, 9, 10, 11,
                    12, 13, 14, 15 };

    int i;
    
    for (i = 1; i <= 20; i++)
    {
        // Operate on columns for even rounds.
        if(i % 2 == 0){

            columns(state);
        }

        // Operate on diagonals for odd rounds.
        else {
            diagonals(state);
        }
    }

    // Output:
    int len = sizeof(state) / sizeof(state[0]);  // Calculate the length of the array
    int e;

    for (e = 0; e < len; e++) {
        printf("%d\n", state[e]);  // Print each element in the array
    }

    return 0;
}