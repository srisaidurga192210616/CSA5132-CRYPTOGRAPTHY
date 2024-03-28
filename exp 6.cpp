#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Function to calculate the greatest common divisor of two integers
int gcd(int a, int b) {
    int temp;
    while (b != 0) {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to calculate the modular multiplicative inverse of a number
int modInverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1) {
            return x;
        }
    }
    return -1;
}

// Function to decrypt ciphertext using affine cipher
void decrypt(char *ciphertext, int a, int b, char *plaintext) {
    int i;
    for (i = 0; ciphertext[i] != '\0'; ++i) {
        if (isalpha(ciphertext[i])) {
            char base = isupper(ciphertext[i]) ? 'A' : 'a';
            int inv_a = modInverse(a, 26);
            int x = (inv_a * ((ciphertext[i] - base) - b + 26)) % 26;
            plaintext[i] = (x + 26) % 26 + base;
        } else {
            plaintext[i] = ciphertext[i];
        }
    }
    plaintext[i] = '\0';
}

int main() {
    char ciphertext[] = "BUABABUABABA";
    char plaintext[1000];

    int freqB = 0, freqU = 0;
    for (int i = 0; ciphertext[i] != '\0'; ++i) {
        if (ciphertext[i] == 'B') {
            freqB++;
        } else if (ciphertext[i] == 'U') {
            freqU++;
        }
    }

    // Guessing 'b' value based on the most frequent letter
    int b = ('B' - 'A' - 1 + 26) % 26; // Shift 'B' back by one position

    // Guessing 'a' value based on the second most frequent letter
    int uShift = ('U' - 'A' + 26 - b) % 26; // Shift required to convert 'U' to 'B'
    int a = (uShift * modInverse(1, 26)) % 26;

    printf("Guessed a: %d\n", a);
    printf("Guessed b: %d\n", b);

    decrypt(ciphertext, a, b, plaintext);

    printf("Plaintext: %s\n", plaintext);

    return 0;
}
