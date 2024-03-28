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

// Function to encrypt plaintext using affine Caesar cipher
void encrypt(char *plaintext, int a, int b, char *ciphertext) {
    int i;
    for (i = 0; plaintext[i] != '\0'; ++i) {
        if (isalpha(plaintext[i])) {
            char base = isupper(plaintext[i]) ? 'A' : 'a';
            ciphertext[i] = ((a * (plaintext[i] - base) + b) % 26) + base;
        } else {
            ciphertext[i] = plaintext[i];
        }
    }
    ciphertext[i] = '\0';
}

int main() {
    char plaintext[1000], ciphertext[1000];
    int a, b;

    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);

    printf("Enter the value of 'a' (must be co-prime with 26): ");
    scanf("%d", &a);

    // Checking if 'a' is co-prime with 26
    if (gcd(a, 26) != 1) {
        printf("Error: 'a' must be co-prime with 26 for the cipher to be one-to-one.\n");
        return 1;
    }

    printf("Enter the value of 'b' (0 <= b < 26): ");
    scanf("%d", &b);

    // Checking if 'b' is within the range
    if (b < 0 || b >= 26) {
        printf("Error: 'b' must be within the range 0 <= b < 26.\n");
        return 1;
    }

    encrypt(plaintext, a, b, ciphertext);

    printf("Ciphertext: %s\n", ciphertext);

    return 0;
}
