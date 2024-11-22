# include <stdio.h>
# include <string.h>
# include <stdint.h>
# include <string.h>
# include "chacha20_functions.h"

void encrypt(uint32_t state[16], const char *constant, const uint8_t key[32], uint32_t blockcount, const uint8_t nonce[12], char *plaintext, char *ciphertext) {
    
    size_t plaintext_len = strlen(plaintext);
    size_t n_blocks = (plaintext_len + 63) / 64; // Calculate the number of 64-byte blocks needed


    // Each block of ciphertext is 64 bytes long, each xored with  a state containing a different counter value
    for (int i = 0; i < n_blocks; i++) {
        
        // Generate the keystream for the current block
        uint8_t keystream[64];
        state_init(state, constant, key, blockcount + i, nonce);
        permute_state(state, keystream);

        for (size_t j = 0; j < 64 && (i * 64 + j) < plaintext_len; j++) {
            ciphertext[i * 64 + j] = plaintext[i * 64 + j] ^ keystream[j];
        }

        
      /*TEST:
        printf("\nBlock #%d\n", number_of_blocks + 1);
        for (size_t j = 0; j < 64; j++) {
            printf("%02x", (unsigned char)ciphertext[number_of_blocks * 64 + j]);
            printf(" ");
        }*/
    }
    
    // Add the null terminator to the output string
    ciphertext[plaintext_len] = '\0';

    /*TEST:
    for (size_t j = 0; j < plaintext_len; j++) {
        printf("%02x", (unsigned char)ciphertext[j]);
        printf(" ");
    }*/
}