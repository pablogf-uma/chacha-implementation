#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "chacha20_functions.h"
#include <emmintrin.h>

void decrypt(uint32_t state1[16], const char *constant, const uint8_t key[32], uint32_t blockcount, const uint8_t nonce[12], char *output_plaintext, char *ciphertext)
{
    size_t ciphertext_len = strlen(ciphertext);
    // Calculate the number of full 128-byte blocks needed
    size_t n_blocks = (ciphertext_len + 63) / 64; // Calculate the number of 64-byte blocks needed

    for (size_t i = 0; i < n_blocks; i++) {
        uint8_t keystream[64];
        state_init(state1, constant, key, blockcount + i, nonce);
        permute_state(state1, keystream);

        // XOR the plaintext with the keystream
        for (int j = 0; j < 64; j++){
            output_plaintext[i * 64 + j] = ciphertext[i * 64 + j] ^ keystream[j];
        }
    }

    // Add null terminator
    output_plaintext[ciphertext_len] = '\0';

        /* TEST
    for (size_t i = 0; i < ciphertext_len; i++) {
        printf("%02x", (unsigned char)plaintext[i]);
        printf(" ");
    }
    printf("\n");
    */
}