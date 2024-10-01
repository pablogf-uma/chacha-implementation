#ifndef FUNCTIONS_H
#define FUNCTIONS_H

void quarter_round(int state[], int a, int b, int c, int d);

void columns(int state[]);	

void diagonals(int state[]);

void state_init(int state[16], const char *constant, int key[8], int blockcount, int nonce[3]);

#endif // CHACHA20_FUNCTIONS_H