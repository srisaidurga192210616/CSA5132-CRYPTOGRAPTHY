#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define ALPHABET_SIZE 26

// Function to generate the cipher sequence based on the keyword
void generateCipherSequence(char *keyword, char *cipherSequence) {
    int used[ALPHABET_SIZE] = {0};
    int len = strlen(keyword);
    int index = 0;

    // Copy the keyword to the cipher sequence
    for (int i = 0; i < len; i++) {
        char ch = toupper(keyword[i]);
        if (isalpha(ch) && !used[ch - 'A']) {
            cipherSequence[index++] = ch;
            used[ch - 'A'] = 1;
        }
    }


    for (char ch = 'A'; ch <= 'Z'; ch++) {
        if (!used[ch - 'A']) {
            cipherSequence[index++] = ch;
        }
    }

    cipherSequence[index] = '\0';
}

// Function to encrypt plaintext using monoalphabetic cipher
void encrypt(char *plaintext, char *cipherSequence, char *ciphertext) {
    int len = strlen(plaintext);
    for (int i = 0; i < len; i++) {
        if (isalpha(plaintext[i])) {
            char ch = toupper(plaintext[i]);
            if (isupper(plaintext[i])) {
                ciphertext[i] = cipherSequence[ch - 'A'];
            } else {
                ciphertext[i] = tolower(cipherSequence[ch - 'A']);
            }
        } else {
            ciphertext[i] = plaintext[i];
        }
    }
    ciphertext[len] = '\0';
}

int main() {
    char keyword[] = "CIPHER";
    char plaintext[] = "Hello, World!";
    char cipherSequence[ALPHABET_SIZE + 1];
    char ciphertext[100];

    generateCipherSequence(keyword, cipherSequence);

    printf("Cipher Sequence: %s\n", cipherSequence);

    encrypt(plaintext, cipherSequence, ciphertext);

    printf("Plaintext: %s\n", plaintext);
    printf("Ciphertext: %s\n", ciphertext);

    return 0;
}
