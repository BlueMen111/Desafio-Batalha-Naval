
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
 */

int main(void) {
    // Tamanho de cada navio (pode ajustar se quiser)
    const int tam_vertical = 4;   // navio vertical com 4 células
    const int tam_horizontal = 3; // navio horizontal com 3 células

    // NAVIO VERTICAL: vetor de pares (x,y)
    // Começa em (2,5) e ocupa 4 células para baixo
    int navio_vertical[tam_vertical][2] = {
        {2, 5},
        {3, 5},
        {4, 5},
        {5, 5}
    };

    // NAVIO HORIZONTAL: vetor de pares (x,y)
    // Começa em (7,1) e ocupa 3 células para a direita
    int navio_horizontal[tam_horizontal][2] = {
        {7, 1},
        {7, 2},
        {7, 3}
    };

    // Exibe as coordenadas de cada parte (VERTICAL)
    printf("=== Navio Vertical (tamanho %d) ===\n", tam_vertical);
    for (int i = 0; i < tam_vertical; i++) {
        printf("Parte %d -> (x=%d, y=%d)\n",
               i+1, navio_vertical[i][0], navio_vertical[i][1]);
    }

    // Exibe as coordenadas de cada parte (HORIZONTAL)
    printf("\n=== Navio Horizontal (tamanho %d) ===\n", tam_horizontal);
    for (int i = 0; i < tam_horizontal; i++) {
        printf("Parte %d -> (x=%d, y=%d)\n",
               i+1, navio_horizontal[i][0], navio_horizontal[i][1]);
    }

    return 0;
}
