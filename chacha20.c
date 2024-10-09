# include <stdio.h>
# include <string.h>
# include <stdint.h>
# include <string.h>
# include "chacha20_functions.h"

int main()
{
    char constant[16] = "expand 32-byte k";

uint8_t key[32] = { 0x00, 0x01, 0x02, 0x03,
                    0x04, 0x05, 0x06, 0x07,
                    0x08, 0x09, 0x0a, 0x0b,
                    0x0c, 0x0d, 0x0e, 0x0f,
                    0x10, 0x11, 0x12, 0x13,
                    0x14, 0x15, 0x16, 0x17,
                    0x18, 0x19, 0x1a, 0x1b,
                    0x1c, 0x1d, 0x1e, 0x1f };


    uint8_t nonce[12] = { 0x00, 0x00, 0x00, 0x00, 
                        0x00, 0x00, 0x00, 0x4a,
                        0x00, 0x00, 0x00, 0x00 };


    uint32_t blockcount = 1;

    uint32_t state[16];
    char plaintext[] = "Ladies and Gentlemen of the class of '99: If I could offer you only one tip for the future, sunscreen would be it.";
    char output[strlen(plaintext)];
    encrypt(state, constant, key, blockcount, nonce, plaintext, output);

    // OUTPUT:
    printf("\nPlaintext message:\n");
    for (size_t i = 0; i < strlen(plaintext); i++) {
        printf("%c", plaintext[i]);
    }
    printf("\n");

    printf("\nPlaintext message (in hex):\n");
    for (size_t i = 0; i < strlen(plaintext); i++) {
        printf("%02x", plaintext[i]);
        printf(" ");
    }
    printf("\n");

    printf("\nEncrypted message:\n");
    for (size_t i = 0; i < strlen(plaintext); i++) {
        printf("%02x", (unsigned char)output[i]);
        printf(" ");
    }

    return 0;
}