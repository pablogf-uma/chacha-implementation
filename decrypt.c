#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "chacha20_functions.h"
#include <emmintrin.h>

void decrypt(uint32_t state1[16], const char *constant, const uint8_t key[32], uint32_t blockcount, const uint8_t nonce[12], char *output_plaintext, char *ciphertext, unsigned long ciphertext_length)
{   
    size_t n_blocks = (ciphertext_length + 63) / 64; // Calculate the number of 64-byte blocks needed

    for (size_t i = 0; i < n_blocks; i++) {
        uint8_t keystream[64];
        state_init(state1, constant, key, blockcount + i, nonce);
        permute_state(state1, keystream);

        // XOR the plaintext with the keystream
        for (size_t j = 0; j < 64 && (i * 64 + j) < ciphertext_length; j++){
            output_plaintext[i * 64 + j] = ciphertext[i * 64 + j] ^ keystream[j];
        }

        /* TEST
        printf("\nBlock #%d\n", i + 1);
        for (size_t j = 0; j < 64; j++) {
            printf("%02x", (unsigned char)output_plaintext[i * 64 + j]);
            printf(" ");
        }

        printf("\nBlock #%d\n", i + 1);
        for (size_t j = 0; j < 64; j++) {
            printf("%02x", (unsigned char)ciphertext[i * 64 + j]);
            printf(" ");
        }*/
    }

    // Add null terminator
    output_plaintext[ciphertext_length] = '\0';

    /* TEST
    printf("\nPlaintext:\n");
    for (size_t i = 0; i < ciphertext_length; i++) {
        printf("%02x", (unsigned char)output_plaintext[i]);
        printf(" ");
    }
    printf("\n");*/
}