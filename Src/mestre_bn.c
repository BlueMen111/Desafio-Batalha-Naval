
#include <stdio.h>
#include <stdlib.h>

/*
 * NÍVEL MESTRE — Batalha Naval
 * - Três "habilidades" representadas por matrizes (tabuleiros) com padrões:
 *     1) Cone (triângulo apontando para baixo)
 *     2) Cruz
 *     3) Octaedro (diamante / Manhattan <= raio)
 * - Usar loops aninhados para percorrer/preencher áreas afetadas:
 *     * 0 = não afetado
 *     * 1 = afetado
 * - Exemplos de saída: seguir estilo printf("%d ", matriz[i][j]);
 */

#define N 10

void limpa(int m[N][N]) {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            m[i][j] = 0;
}

void imprime(const char* titulo, int m[N][N]) {
    printf("=== %s ===\n", titulo);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf("%d ", m[i][j]); // como no enunciado, com espaço a cada número
        printf("\n");
    }
    printf("\n");
}

/*
 * Habilidade: CRUZ
 * - Marca linha e coluna que passam pelo centro (cx,cy) dentro de um raio r
 * - Padrão equivalente ao exemplo de cruz em 5x5 (aqui generalizado)
 */
void habilidade_cruz(int m[N][N], int cx, int cy, int r) {
    limpa(m);
    // Linha do centro
    for (int j = cy - r; j <= cy + r; j++) {
        if (j >= 0 && j < N) m[cx][j] = 1;
    }
    // Coluna do centro
    for (int i = cx - r; i <= cx + r; i++) {
        if (i >= 0 && i < N) m[i][cy] = 1;
    }
}

/*
 * Habilidade: OCTAEDRO (diamante)
 * - Marca todas as células cuja distância de Manhattan ao centro <= r
 *   |i - cx| + |j - cy| <= r
 * - Bate com o "octaedro" (diamante) do enunciado.
 */
void habilidade_octaedro(int m[N][N], int cx, int cy, int r) {
    limpa(m);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int manhattan = abs(i - cx) + abs(j - cy);
            if (manhattan <= r) {
                m[i][j] = 1;
            }
        }
    }
}

/*
 * Habilidade: CONE (triângulo para baixo)
 * - A partir do vértice (ax, ay) e altura h:
 *   linha ax + k recebe 1's de [ay - k .. ay + k], para k = 0..h-1
 * - Clipa nos limites do tabuleiro.
 * - É compatível com o exemplo dado (apex central e vai alargando).
 */
void habilidade_cone(int m[N][N], int ax, int ay, int h) {
    limpa(m);
    for (int k = 0; k < h; k++) {
        int x = ax + k;           // linha atual do "cone"
        int y_ini = ay - k;       // inicia expandindo à esquerda
        int y_fim = ay + k;       // e à direita
        if (x < 0 || x >= N) continue;
        if (y_ini < 0) y_ini = 0;
        if (y_fim >= N) y_fim = N - 1;
        for (int y = y_ini; y <= y_fim; y++) {
            m[x][y] = 1;
        }
    }
}

int main(void) {
    int cruz[N][N], octa[N][N], cone[N][N];

    // Exemplo 1: CRUZ centrada em (5,5) com raio 2
    habilidade_cruz(cruz, 5, 5, 2);
    imprime("Habilidade CRUZ (centro 5,5; raio 2)", cruz);

    // Exemplo 2: OCTAEDRO (diamante) centrado em (4,4) com raio 3
    habilidade_octaedro(octa, 4, 4, 3);
    imprime("Habilidade OCTAEDRO (centro 4,4; raio 3)", octa);

    // Exemplo 3: CONE com vértice em (2,5), altura 4 (cresce para baixo)
    habilidade_cone(cone, 2, 5, 4);
    imprime("Habilidade CONE (apice 2,5; altura 4)", cone);

    return 0;
}
