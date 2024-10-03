#ifndef FUNCTIONS_H
#define FUNCTIONS_H

void quarter_round(uint32_t state[], int a, int b, int c, int d);

void columns(uint32_t state[]);	

void diagonals(uint32_t state[]);

void state_init(uint32_t state[16], const char *constant, uint32_t key[8], uint32_t blockcount, uint32_t nonce[3]);

void permute_block(uint32_t original_state[16], const char *constant, uint32_t key[8], uint32_t blockcount, uint32_t nonce[3], uint32_t state[16]);

#endif // CHACHA20_FUNCTIONS_H