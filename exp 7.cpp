#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define ALPHABET_SIZE 26

// Function to initialize an array to store letter frequencies
void initializeFrequencyArray(int frequency[]) {
    for (int i = 0; i < ALPHABET_SIZE; ++i) {
        frequency[i] = 0;
    }
}

// Function to update letter frequencies in the ciphertext
void updateFrequency(char *ciphertext, int frequency[]) {
    for (int i = 0; ciphertext[i] != '\0'; ++i) {
        if (isalpha(ciphertext[i])) {
            char c = tolower(ciphertext[i]);
            frequency[c - 'a']++;
        }
    }
}

// Function to find the most frequent letter in the ciphertext
char findMostFrequent(int frequency[]) {
    int maxCount = 0;
    char mostFrequent = 'a'; // Initialize with 'a'
    for (int i = 0; i < ALPHABET_SIZE; ++i) {
        if (frequency[i] > maxCount) {
            maxCount = frequency[i];
            mostFrequent = 'a' + i;
        }
    }
    return mostFrequent;
}

// Function to decrypt the ciphertext using a substitution key
void decrypt(char *ciphertext, char *key) {
    for (int i = 0; ciphertext[i] != '\0'; ++i) {
        if (isalpha(ciphertext[i])) {
            char c = tolower(ciphertext[i]);
            ciphertext[i] = isupper(ciphertext[i]) ? toupper(key[c - 'A']) : key[c - 'a'];
        }
    }
}

int main() {
    char ciphertext[] = "53‡‡†305))6*;4826)4‡.)4‡);806*;48†8¶60))85;;]8*;:‡8†83 (88)5†;46(;88*96*?;8)‡(;485);5†2:‡(;4956*2(5—4)8¶8* ;4069285);)6†8)4‡‡;1(‡9;48081;8:8‡1;48†85;4)485†528806*81 (‡9;48;(88;4(‡?34;48)4‡;161;:188;‡?;";
    int frequency[ALPHABET_SIZE];
    char mostFrequent, substitutionKey[ALPHABET_SIZE];

    initializeFrequencyArray(frequency);
    updateFrequency(ciphertext, frequency);

    mostFrequent = findMostFrequent(frequency);
    // Assuming 'e' as the most frequent letter in English, we can deduce the substitution key
    int shift = mostFrequent - 'e';
    for (int i = 0; i < ALPHABET_SIZE; ++i) {
        int index = (i + shift) % ALPHABET_SIZE;
        substitutionKey[i] = 'A' + index;
    }
    substitutionKey[ALPHABET_SIZE] = '\0';

    printf("Most frequent letter in the ciphertext: %c\n", mostFrequent);
    printf("Substitution key: %s\n", substitutionKey);

    // Decrypt the ciphertext using the substitution key
    decrypt(ciphertext, substitutionKey);
    printf("Decrypted ciphertext: %s\n", ciphertext);

    return 0;
}
