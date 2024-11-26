#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "chacha20_functions.h"

void encrypt_custom_input(char *ciphertext)
{
    uint32_t state[16];
    uint8_t key[32];
    char key_char[32];
    uint8_t nonce[12];
    char nonce_char[12];
    char input[256];

    printf("Enter key (32 bytes):\n");
    // Read key as a string
    scanf("%s", key_char);
    int key_char_len = strlen(key_char);
    // Convert each character of the string to hex and load it to the key array
    for (size_t i = 0; i < key_char_len; i++)
    {   
        key[i] = (uint8_t)key_char[i];
    }

    /* TEST
    printf("Hex Array:\n");
    for (size_t i = 0; i < key_char_len; i++) {
        printf("0x%02X ", key[i]);
    }
    printf("\n");*/
    
    // Same operation for the nonce
    printf("Enter nonce (12 bytes):\n");
    scanf("%s", nonce_char);
    int nonce_char_len = strlen(nonce_char);
    for (size_t i = 0; i < nonce_char_len; i++)
    {   
        nonce[i] = (uint8_t)nonce_char[i];
    }

    printf("Custom input:\n");
    scanf("%255s", input);

    encrypt(state, "expand 32-byte k", key, 0, nonce, input, ciphertext);

    printf("\nCIPHERTEXT:\n");
    for (size_t j = 0; j < strlen(ciphertext); j++) {
        printf("%02x", (unsigned char)ciphertext[j]);
    }
}