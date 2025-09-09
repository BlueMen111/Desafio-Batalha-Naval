
#include <stdio.h>

/*
 * NÍVEL AVENTUREIRO — Batalha Naval
 * - Tabuleiro 10x10 (matriz)
 * - Posicionar QUATRO navios:
 *     * 1 horizontal
 *     * 1 vertical
 *     * 2 diagonais (uma na diagonal principal e outra na anti-diagonal)
 * - Exibir toda a matriz:
 *     * 0 = célula vazia
 *     * 3 = célula ocupada por navio
 */

#define N 10

// Marca uma sequência horizontal de comprimento len começando em (x,y)
void coloca_horizontal(int m[N][N], int x, int y, int len) {
    for (int j = 0; j < len && (y + j) < N; j++) {
        m[x][y + j] = 3;
    }
}

// Marca uma sequência vertical de comprimento len começando em (x,y)
void coloca_vertical(int m[N][N], int x, int y, int len) {
    for (int i = 0; i < len && (x + i) < N; i++) {
        m[x + i][y] = 3;
    }
}

// Marca uma sequência na diagonal principal (↘) de comprimento len, a partir de (x,y)
void coloca_diag_principal(int m[N][N], int x, int y, int len) {
    for (int k = 0; k < len && x + k < N && y + k < N; k++) {
        m[x + k][y + k] = 3;
    }
}

// Marca uma sequência na anti-diagonal (↙) de comprimento len, a partir de (x,y)
void coloca_diag_anti(int m[N][N], int x, int y, int len) {
    for (int k = 0; k < len && x + k < N && y - k >= 0; k++) {
        m[x + k][y - k] = 3;
    }
}

int main(void) {
    int tab[N][N] = {0}; // inicializa tudo com 0

    // 1) Navio horizontal — linha 2, col 1..5 (comprimento 5)
    coloca_horizontal(tab, 2, 1, 5);

    // 2) Navio vertical — coluna 7, linha 4..8 (comprimento 5)
    coloca_vertical(tab, 4, 7, 5);

    // 3) Navio diagonal principal (↘) — a partir de (0,0), comprimento 4
    coloca_diag_principal(tab, 0, 0, 4);

    // 4) Navio anti-diagonal (↙) — a partir de (1,8), comprimento 4
    coloca_diag_anti(tab, 1, 8, 4);

    // Exibe a matriz completa
    printf("=== Tabuleiro 10x10 (0 = vazio, 3 = navio) ===\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", tab[i][j]); // conforme exemplo, usar "%d "
        }
        printf("\n");
    }

    return 0;
}
