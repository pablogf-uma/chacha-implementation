#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "chacha20_functions.h"

void decrypt_custom_input(char *plaintext)
{
    uint32_t state[16];
    uint8_t key[32];
    char key_char[32];
    uint8_t nonce[12];
    char nonce_char[12];
    char input[256];
    uint8_t translated_input[256] = {0};

    printf("Enter key (32 bytes):\n");
    // Read key as a string
    scanf("%s", key_char);
    int key_char_len = strlen(key_char);
    // Convert each character of the string to hex and load it to the key array
    for (size_t i = 0; i < key_char_len; i++)
    {   
        key[i] = (uint8_t)key_char[i];
    }
    
    // Same operation for the nonce
    printf("Enter nonce (12 bytes):\n");
    scanf("%s", nonce_char);
    int nonce_char_len = strlen(nonce_char);
    for (size_t i = 0; i < nonce_char_len; i++)
    {   
        nonce[i] = (uint8_t)nonce_char[i];
    }

    printf("Ciphertext (hex string):\n");
    scanf("%s", input);
    size_t input_len = strlen(input);
    size_t translated_len = input_len / 2;
    for (size_t i = 0; i < translated_len; i++) {
        char hex_pair[3] = { input[2 * i], input[2 * i + 1], '\0' };
        translated_input[i] = (uint8_t)strtol(hex_pair, NULL, 16);
    }

    decrypt(state, "expand 32-byte k", key, 0, nonce, plaintext, (char *)translated_input);

    printf("\nPLAINTEXT:\n");
    for (size_t j = 0; j < strlen(plaintext); j++) {
        printf("%02x", (unsigned char)plaintext[j]);
    }

    printf("%s", plaintext);
}