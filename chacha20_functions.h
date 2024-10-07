#ifndef FUNCTIONS_H
#define FUNCTIONS_H

void quarter_round(uint32_t state[], int a, int b, int c, int d);

void columns(uint32_t state[]);	

void diagonals(uint32_t state[]);

void state_init(uint32_t state[16], const char *constant, const uint8_t key[32], uint32_t blockcount, const uint8_t nonce[12]);

void permute_block(uint32_t original_state[16], uint32_t state[16]);

#endif // CHACHA20_FUNCTIONS_H