
#include <stdio.h>

/*
 * NÍVEL NOVATO — Batalha Naval
 * - Objetivo: simular a localização de DOIS navios usando vetores bidimensionais (coordenadas X,Y)
 * - Um navio posicionado VERTICALMENTE e outro HORIZONTALMENTE
 * - Exibir no console (printf) as coordenadas de cada parte dos navios
 * - As "entradas" são variáveis no próprio código (sem scanf)
 *
 * Convenção de coordenadas:
 *   - Usaremos (linha, coluna) = (x, y), com origem (0,0) no canto superior esquerdo
 *
 * Correção aplicada:
 *   - Substituímos tamanhos de arrays definidos por variáveis por constantes de tempo de compilação (#define),
 *     pois arrays de tamanho variável (VLA) não podem ser inicializados com listas de inicialização.
 */

#define TAM_VERTICAL   4  // navio vertical com 4 células
#define TAM_HORIZONTAL 3  // navio horizontal com 3 células

int main(void) {
    // NAVIO VERTICAL: vetor de pares (x,y)
    // Começa em (2,5) e ocupa 4 células para baixo
    int navio_vertical[TAM_VERTICAL][2] = {
        {2, 5},
        {3, 5},
        {4, 5},
        {5, 5}
    };

    // NAVIO HORIZONTAL: vetor de pares (x,y)
    // Começa em (7,1) e ocupa 3 células para a direita
    int navio_horizontal[TAM_HORIZONTAL][2] = {
        {7, 1},
        {7, 2},
        {7, 3}
    };

    // Exibe as coordenadas de cada parte (VERTICAL)
    printf("=== Navio Vertical (tamanho %d) ===\n", TAM_VERTICAL);
    for (int i = 0; i < TAM_VERTICAL; i++) {
        printf("Parte %d -> (x=%d, y=%d)\n",
               i + 1, navio_vertical[i][0], navio_vertical[i][1]);
    }

    // Exibe as coordenadas de cada parte (HORIZONTAL)
    printf("\n=== Navio Horizontal (tamanho %d) ===\n", TAM_HORIZONTAL);
    for (int i = 0; i < TAM_HORIZONTAL; i++) {
        printf("Parte %d -> (x=%d, y=%d)\n",
               i + 1, navio_horizontal[i][0], navio_horizontal[i][1]);
    }

    return 0;
}
