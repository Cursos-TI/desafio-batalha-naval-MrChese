#include <stdio.h>

void mostrarTabuleiro(char tabuleiro[10][10], char linha[]) {
    printf("   ");
    for (int i = 0; i < 10; i++) {
        printf(" %c", linha[i]);
    }
    printf("\n");

    for (int i = 0; i < 10; i++) {
        printf("%2d ", i + 1);
        for (int j = 0; j < 10; j++) {
            printf(" %c", tabuleiro[i][j]);
        }
        printf("\n");
    }
}


void aplicarPoderCruz(char tabuleiro[10][10], int linha, int coluna) {
    if (linha >= 0 && linha < 10 && coluna >= 0 && coluna < 10) tabuleiro[linha][coluna] = '*'; 
    if (linha - 1 >= 0) tabuleiro[linha - 1][coluna] = '*'; 
    if (linha + 1 < 10) tabuleiro[linha + 1][coluna] = '*'; 
    if (coluna - 1 >= 0) tabuleiro[linha][coluna - 1] = '*'; 
    if (coluna + 1 < 10) tabuleiro[linha][coluna + 1] = '*'; 
}


void aplicarPoderOctaedro(char tabuleiro[10][10], int linha, int coluna) {
    if (linha >= 0 && linha < 10 && coluna >= 0 && coluna < 10) tabuleiro[linha][coluna] = '*';
    if (linha - 1 >= 0 && coluna - 1 >= 0) tabuleiro[linha - 1][coluna - 1] = '*';
    if (linha - 1 >= 0 && coluna + 1 < 10) tabuleiro[linha - 1][coluna + 1] = '*'; 
    if (linha + 1 < 10 && coluna - 1 >= 0) tabuleiro[linha + 1][coluna - 1] = '*'; 
    if (linha + 1 < 10 && coluna + 1 < 10) tabuleiro[linha + 1][coluna + 1] = '*';
}

    
void aplicarPoderCone(char tabuleiro[10][10], int linha, int coluna) {
    if (linha >= 0 && linha < 10 && coluna >= 0 && coluna < 10) tabuleiro[linha][coluna] = '*';
    if (linha + 1 >= 0 && coluna - 1 >= 0) tabuleiro[linha + 1][coluna - 1] = '*';
    if (linha + 1 >= 0 && coluna + 1 < 10) tabuleiro[linha + 1][coluna + 1] = '*'; 
    if (linha >= 0 && linha < 10 && coluna >= 0 && coluna < 10) tabuleiro[linha + 1][coluna ] = '*';
    if (linha + 2 < 10 && coluna - 2 >= 0) tabuleiro[linha + 2][coluna - 2] = '*'; 
    if (linha + 2 < 10 && coluna + 2 < 10) tabuleiro[linha + 2][coluna + 2] = '*'; 
    if (linha + 1 >= 0 && coluna - 1 >= 0) tabuleiro[linha + 2][coluna    ] = '*';
    if (linha + 2 >= 0 && coluna - 2 >= 0) tabuleiro[linha + 2][coluna - 1] = '*';
    if (linha + 2 >= 0 && coluna + 2 < 10) tabuleiro[linha + 2][coluna + 1] = '*';

}
int main() {
    char linha[10] = {'A','B','C','D','E','F','G','H','I','J'};
    char tabuleiro[10][10];
    int linhaOrigem, colunaOrigem, poderEscolhido;
    char letraColuna;

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = '.';
        }
    }

    tabuleiro[2][3] = '3';
    tabuleiro[2][4] = '3';
    tabuleiro[2][5] = '3';

    tabuleiro[5][6] = '3';
    tabuleiro[6][6] = '3';
    tabuleiro[7][6] = '3';

    tabuleiro[0][9] = '3';
    tabuleiro[1][8] = '3';
    tabuleiro[2][7] = '3';

    tabuleiro[8][0] = '3';
    tabuleiro[7][1] = '3';
    tabuleiro[6][2] = '3';

    
    printf("Tabuleiro inicial:\n");
    mostrarTabuleiro(tabuleiro, linha);

    
    printf("\nEscolha o ponto de origem do poder:\n");
    printf("Digite a linha (1 a 10): ");
    scanf("%d", &linhaOrigem);
    linhaOrigem--; 

    printf("Digite a coluna (A a J): ");
    scanf(" %c", &letraColuna);

   
    colunaOrigem = -1;
    for (int i = 0; i < 10; i++) {
        if (linha[i] == letraColuna || linha[i] == letraColuna - 32) { 
            colunaOrigem = i;
            break;
        }
    }

    
    if (colunaOrigem == -1 || linhaOrigem < 0 || linhaOrigem > 9) {
        printf("Posição inválida!\n");
        return 1;
    }

   
    printf("\nEscolha o poder:\n");
    printf("1. Cruz (+)\n");
    printf("2. Octaedro (diagonais)\n");
    printf("3. Cone (A)\n ");
    printf("Digite sua opção: ");
    scanf("%d", &poderEscolhido);

    
    if (poderEscolhido == 1) {
        aplicarPoderCruz(tabuleiro, linhaOrigem, colunaOrigem);
    } else if (poderEscolhido == 2) {
        aplicarPoderOctaedro(tabuleiro, linhaOrigem, colunaOrigem);
    } else if( poderEscolhido == 3){
        aplicarPoderCone(tabuleiro, linhaOrigem, colunaOrigem );
    }
    else {
        printf("Poder inválido!\n");
        return 1;
    }

    printf("\nTabuleiro após usar o poder:\n");
    mostrarTabuleiro(tabuleiro, linha);

    return 0;
}
