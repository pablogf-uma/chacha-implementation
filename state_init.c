# include <stdio.h>
# include <string.h>

// Parameters:
// Constant: 16 bytes ASCII-encoded string “expand 32-byte k”
// Key: 32 bytes.
// Block Counter: 4 bytes.
// Nonce: 12 bytes.
void state_init(int state[16], const char *constant, const int key[8], int blockcount, const int nonce[3])
{
    // Load the initial state of 0s.
    int i, j;
    for (i = 0; i < 16; i++)
    {
        for (j = 0; j < 4; j++)
        {
            state[i] = 0;
        }
    }

    // Separate the constant into 4 bytes (4 letters) and assign them to the first column of the state.
    // Left shift operation << moves the bits to the left by the specified number of positions.
    // Bitwise OR operation | combines the 4 bytes into a single 32-bit integer.
    for (i = 0; i < 4; i++)
    {
        state[i] = ((unsigned int)constant[i * 4] << 24) |
                      ((unsigned int)constant[i * 4 + 1] << 16) |
                      ((unsigned int)constant[i * 4 + 2] << 8) |
                      ((unsigned int)constant[i * 4 + 3]);
    }

    // Separate the key into 2 groups of 16 bytes (one for each row)
    for (i = 0; i < 4; i++)
    {
        state[4 + i] = key[i];
    }

    for (i = 4; i < 8; i++)
    {
        state[8 + (i - 4)] = key[i];
    }

    // Assign the blockcount to the first element of the last row of the state.
    state[12] = blockcount;

    // Assign each element of the nonce to the last row of the state.
    for (i = 1; i < 4; i++)
    {
        state[13 + i] = nonce[i];
    }


    /*

    //USED FOR TESTING: Output the state matrix.
    int a, b;
    for (a = 0; a < 4; a++)
    {
        for (b = 0; b < 4; b++)
        {
            printf("%08x", state[a][b]); // Output in hexadecimal format (without the 0x prefix).
            printf(" ");
        }
        printf("\n");
    }
    
    */  
}


/*

//USED FOR TESTING: Main function to test the state_init function.
int main()
{
    int state[4][4];
    const char constant[16] = "expand 32-byte k";
    int key[8] = {0x00010203, 0x04050607, 0x08090a0b, 0x0c0d0e0f, 0x10111213, 0x14151617, 0x18191a1b, 0x1c1d1e1f};
    int blockcount = 0;
    int nonce[4] = {0x00000009, 0x0000004a, 0x00000000, 0x00000000};
    state_init(state, constant, key, blockcount, nonce);

    return 0;
}

*/