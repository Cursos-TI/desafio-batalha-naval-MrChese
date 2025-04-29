#include <stdio.h>

int main() {
  char linha[10] = {'A','B','C','D','F','G','H','I','J',};
int tabuleiro [10] [10];
for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
        tabuleiro[i][j] = '0';
    }
}
//3, D, F, G
tabuleiro[2][3] = '3';
tabuleiro[2][4] = '3';
tabuleiro[2][5] = '3';
//H 6, 7, 8
tabuleiro[5] [6] = '3';
tabuleiro[6] [6] = '3';
tabuleiro[7] [6] = '3';
//j-1, i-2, h-3
tabuleiro[0] [9] = '3';
tabuleiro[1] [8] = '3';
tabuleiro[2] [7] = '3';

printf("   ");
for (int i = 0; i < 10; i++) {
    printf(" %c", linha[i]);
}
printf("\n");

for (int i = 0; i < 10; i++) {
    printf("%d ", i + 1); 
    for (int j = 0; j < 10; j++) {
        printf(" %c", tabuleiro[i][j]); 
    }
    printf("\n");
}

return 0;
}