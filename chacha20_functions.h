#ifndef FUNCTIONS_H
#define FUNCTIONS_H

void quarter_round(int *state, int a, int b, int c, int d);

void columns(int *state);

void diagonals(int *state);

void state_init(char *constant, int key, int position, int nonce);

#endif // CHACHA20_FUNCTIONS_H