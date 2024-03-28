#include <stdio.h>
#include <string.h>

void encrypt(char *plaintext, char *ciphertext) {
    char map[26] = {'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a'};
    
    int i;
    for (i = 0; i < strlen(plaintext); i++) {
        if (plaintext[i] >= 'a' && plaintext[i] <= 'z') {
            ciphertext[i] = map[plaintext[i] - 'a'];
        } else {
            ciphertext[i] = plaintext[i];
        }
    }
    ciphertext[i] = '\0';
}

int main() {
    char plaintext[] = "hello";
    char ciphertext[100];
    
    encrypt(plaintext, ciphertext);
    
    printf("Plaintext: %s\n", plaintext);
    printf("Ciphertext: %s\n", ciphertext);
    
    return 0;
}
















//
