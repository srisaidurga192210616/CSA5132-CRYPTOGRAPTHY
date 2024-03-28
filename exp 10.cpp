#include <stdio.h>
#include <string.h>

#define SIZE 5


void findPosition(char matrix[SIZE][SIZE], char ch, int *row, int *col) {
    if (ch == 'J')
        ch = 'I'; 

    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (matrix[i][j] == ch) {
                *row = i;
                *col = j;
                return;
            }
        }
    }
}


