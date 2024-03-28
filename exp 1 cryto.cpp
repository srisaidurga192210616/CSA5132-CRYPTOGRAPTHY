#include <stdio.h>

void caesarCipher(char *str, int shift) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = 'a' + (str[i] - 'a' + shift) % 26;
        } else if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = 'A' + (str[i] - 'A' + shift) % 26;
        }
    }
}

int main() {
    char message[] = "Hello, World!";
    int shift = 3;

    printf("Original message: %s\n", message);
    caesarCipher(message, shift);
    printf("Encrypted message: %s\n", message);

    return 0;
}
