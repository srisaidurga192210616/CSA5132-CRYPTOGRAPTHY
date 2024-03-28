#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to encrypt plaintext using polyalphabetic substitution cipher
void encrypt(char *plaintext, char *key, char *ciphertext) {
    int i, j, keylen;
    keylen = strlen(key);

    for (i = 0, j = 0; plaintext[i] != '\0'; ++i) {
        if (!isalpha(plaintext[i])) {
            ciphertext[i] = plaintext[i];
            continue;
        }

        int shift = tolower(key[j % keylen]) - 'a';

        if (isupper(plaintext[i])) {
            ciphertext[i] = 'A' + (plaintext[i] - 'A' + shift) % 26;
        } else {
            ciphertext[i] = 'a' + (plaintext[i] - 'a' + shift) % 26;
        }

        j++;
    }

    ciphertext[i] = '\0';
}

int main() {
    char plaintext[1000], key[100];
    char ciphertext[1000];

    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0'; // Remove newline character

    printf("Enter the key: ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = '\0'; // Remove newline character

    encrypt(plaintext, key, ciphertext);

    printf("Ciphertext: %s\n", ciphertext);

    return 0;
}
