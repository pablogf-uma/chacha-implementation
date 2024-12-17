#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "chacha20_functions.h"
#include <x86intrin.h>

// Function to run a single test and measure clock cyles per byte for each test
int run_decrypt_test(test_vector_t *test) {
    
    uint32_t state1[16];
    unsigned long plaintext_length = strlen(test->plaintext);
    char ciphertext[plaintext_length];
    
    encrypt(state1, "expand 32-byte k", test->key, test->blockcount, test->nonce, test->plaintext, ciphertext);

    unsigned long ciphertext_length = strlen(ciphertext);
    char output_plaintext[ciphertext_length];

    // Start cycle counting.
    unsigned long long start_cycles = __rdtsc();

    decrypt(state1, "expand 32-byte k", test->key, test->blockcount, test->nonce, output_plaintext, ciphertext);
    
    // End cycle counting.
    unsigned long long end_cycles = __rdtsc();

    // Calculate cycles per byte
    unsigned long long cycles = end_cycles - start_cycles;   
    double cycles_per_byte = (double)cycles / plaintext_length;
    printf("Total input bytes: %lu", plaintext_length);
    printf("\nClock cycles per byte: %.2f\n", cycles_per_byte);

    // Compare output plaintext with expected original plaintext.
    if (memcmp(test->plaintext, output_plaintext, ciphertext_length) == 0) {
        return 1;
    } else {
        return 0;
    }
}