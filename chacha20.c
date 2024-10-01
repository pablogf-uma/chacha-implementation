# include <stdio.h>
# include <string.h>
# include "chacha20_functions.h"

int main()
{
    // Create the original decrypted matrix and the state matrix that will be trnsformed.

    int original_state[16];
    const char constant[16] = "apxe3 dnyb-2k et"; // Specified by the RFC, usually "expand 32-byte k"
    int key[8] = { 0x00000000, 0x00000000, 0x00000000, 0x00000000,
                    0x00000000, 0x00000000, 0x00000000, 0x00000000 };
    int blockcount = 0;
    int nonce[3] = {0x00000000, 0x00000000, 0x00000000};

    state_init(original_state, constant, key, blockcount, nonce);

    int state[16];
    memcpy(state, original_state, sizeof(original_state));
    
    // Permutations on the state: 20 total rounds (10 column-diagonal permutations)
    for (int i = 1; i < 10; i++)
    {
        columns(state);
        diagonals(state);
    }

    // Output state matrices:

        // Original state matrix:
    printf("Original state matrix:\n");

    for (int a = 0; a < 4; a++)
    {
        for (int b = 0; b < 4; b++)
        {
            printf("%08x", original_state[a * 4 + b]); // Output in hexadecimal format
            printf(" ");                               // Relationship between 1D array and 4x4 matrix: rows * 4 + columns
        }
        printf("\n");
    }
    
    printf("\n");

        // Permuted state matrix:
    printf("Encrypted state matrix:\n");
    for (int e = 0; e < 4; e++)
    {
        for (int d = 0; d < 4; d++)
        {
            printf("%08x", state[e * 4 + d]);
            printf(" ");
        }
        printf("\n");
    }

    printf("\n");

    // Ask for input for encryption:
    char msg[80];
    printf("Enter your message: \n");
    if (fgets(msg, sizeof(msg), stdin))
    {
        // Remove newline character from fgets if present:
        size_t len = strlen(msg);
        if (len > 0 && msg[len - 1] == '\n')
            msg[len - 1] = '\0';

    // Encrypt the message using XOR and state as key:
        char encrypted_msg[80];
        for (size_t i = 0; i < len; i++) {
            encrypted_msg[i] = msg[i] ^ ((char*)state)[i % sizeof(state)];
        }
        encrypted_msg[len] = '\0';
        printf("This is the encrypted message:\n");
        printf("%s\n", encrypted_msg);
    }

    return 0;
}