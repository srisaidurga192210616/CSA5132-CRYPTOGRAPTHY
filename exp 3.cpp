#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 5

// Function to remove duplicates from the key and fill the rest of the matrix with remaining alphabets
void prepareKey(char key[], char *matrix) {
    int i, j, k, len;
    int exists[26] = {0};

    len = strlen(key);
    j = 0;

    // Fill matrix with unique characters from the key
    for (i = 0; i < len; i++) {
        if (!isalpha(key[i])) {
            continue;
        }
        if (key[i] == 'J') {
            key[i] = 'I'; // Replacing 'J' with 'I' as per Playfair Cipher rules
        }
        if (!exists[key[i] - 'A']) {
            matrix[j++] = toupper(key[i]);
            exists[key[i] - 'A'] = 1;
        }
    }

    // Fill the rest of the matrix with remaining alphabets
    for (i = 0; i < 26; i++) {
        if (i != ('J' - 'A') && !exists[i]) {
            matrix[j++] = i + 'A';
        }
    }
}

// Function to find the positions of characters in the matrix
void findPosition(char *matrix, char ch, int *row, int *col) {
    int i;
    for (i = 0; i < SIZE * SIZE; i++) {
        if (matrix[i] == ch) {
            *row = i / SIZE;
            *col = i % SIZE;
            return;
        }
    }
}

// Function to encrypt a pair of characters using Playfair cipher
void encryptPair(char *matrix, char a, char b, char *encrypted) {
    int row1, col1, row2, col2;

    findPosition(matrix, a, &row1, &col1);
    findPosition(matrix, b, &row2, &col2);

    // If both characters are in the same row
    if (row1 == row2) {
        encrypted[0] = matrix[row1 * SIZE + (col1 + 1) % SIZE];
        encrypted[1] = matrix[row2 * SIZE + (col2 + 1) % SIZE];
    }
    // If both characters are in the same column
    else if (col1 == col2) {
        encrypted[0] = matrix[((row1 + 1) % SIZE) * SIZE + col1];
        encrypted[1] = matrix[((row2 + 1) % SIZE) * SIZE + col2];
    }
    // If characters form a rectangle in the matrix
    else {
        encrypted[0] = matrix[row1 * SIZE + col2];
        encrypted[1] = matrix[row2 * SIZE + col1];
    }
}

// Function to encrypt the plaintext using Playfair cipher
void encrypt(char *matrix, char *plaintext, char *ciphertext) {
    int i, j, len;
    len = strlen(plaintext);
    j = 0;
    for (i = 0; i < len; i++) {
        if (!isalpha(plaintext[i])) {
            continue;
        }
        if (plaintext[i] == 'J') {
            plaintext[i] = 'I'; // Replacing 'J' with 'I' as per Playfair Cipher rules
        }
        if (i < len - 1 && plaintext[i] == plaintext[i + 1]) {
            encryptPair(matrix, plaintext[i], 'X', &ciphertext[j]);
            j += 2;
            i++; // Skip the next character
        } else if (i == len - 1) {
            encryptPair(matrix, plaintext[i], 'X', &ciphertext[j]);
            j += 2;
        } else {
            encryptPair(matrix, plaintext[i], plaintext[i + 1], &ciphertext[j]);
            j += 2;
            i++; // Skip the next character
        }
    }
    ciphertext[j] = '\0';
}

int main() {
    char key[100], plaintext[100], ciphertext[100];
    char matrix[SIZE * SIZE];

    printf("Enter the key: ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = '\0'; // Remove newline character

    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0'; // Remove newline character

    prepareKey(key, matrix);

    encrypt(matrix, plaintext, ciphertext);

    printf("Ciphertext: %s\n", ciphertext);

    return 0;
}
