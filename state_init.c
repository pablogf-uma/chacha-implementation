# include <stdio.h>
# include <string.h>

// Parameters:
// Constant: 16 bytes ASCII-encoded string “expand 32-byte k”.
// Key: 32 bytes.
// Nonce: 16 bytes.
void state_init(int state[4][4], const char *constant, int key[8],int nonce[4])
{
    // Load the initial state of 0s.
    int i, j;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            state[i][j] = 0;
        }
    }

    // Separate the constant into 4 bytes (4 letters) and assign them to the first column of the state.
    // Left shift operation << moves the bits to the left by the specified number of positions.
    // Bitwise OR operation | combines the 4 bytes into a single 32-bit integer.
    for (i = 0; i < 4; i++)
    {
        state[0][i] = ((unsigned int)constant[i * 4] << 24) |
                      ((unsigned int)constant[i * 4 + 1] << 16) |
                      ((unsigned int)constant[i * 4 + 2] << 8) |
                      ((unsigned int)constant[i * 4 + 3]);
    }

    // Output the state matrix.
    int a, b;
    for (a = 0; a < 4; a++)
    {
        for (b = 0; b < 4; b++)
        {
            printf("%d ", state[a][b]);
        }
        printf("\n");
    }
}

int main()
{
    int state[4][4];
    state_init(state, "expand 32-byte k", 0, 0);

    return 0;
}