#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "chacha20_functions.h"
#include <x86intrin.h>

// Function to run a single test
int run_encrypt_test(test_vector_t *test) {

    uint32_t state[16];
    unsigned long plaintext_length = test->plaintext_length;
    char ciphertext[plaintext_length];

    // Start cycle counting.
    unsigned long long start_cycles = __rdtsc();
    
    encrypt(state, "expand 32-byte k", test->key, test->blockcount, test->nonce, test->plaintext, ciphertext, plaintext_length);

    // End cycle counting.
    unsigned long long end_cycles = __rdtsc();

    // Calculate cycles per byte
    unsigned long long cycles = end_cycles - start_cycles;   
    double cycles_per_byte = (double)cycles / plaintext_length;
    printf("Total input bytes: %lu", plaintext_length);
    printf("\nClock cycles per byte: %.2f\n", cycles_per_byte);

    // Compare output with expected ciphertext.
    if (memcmp(ciphertext, test->expected_ciphertext, plaintext_length) == 0) {
        return 1; // Test passed.
    } else {
        return 0; // Test failed.
    }
}
