#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "chacha20_functions.h"

// Function to run a single test
int run_test(test_vector_t *test) {
    uint32_t state[16];
    char output[5000];
    encrypt(state, "expand 32-byte k", test->key, test->blockcount, test->nonce, test->plaintext, output);

    // Compare output with expected ciphertext
    if (memcmp(output, test->expected_ciphertext, strlen(test->plaintext)) == 0) {
        return 1; // Test passed
    } else {
        return 0; // Test failed
    }
}