
# Batalha Naval — Três Níveis (Novato, Aventureiro, Mestre)

Este pacote implementa os **três níveis** do desafio Batalha Naval em C, usando vetores e matrizes, com **comentários claros** e saída no console via `printf`.

## ✅ O que está incluso
- `novato_bn.c` — posiciona **2 navios** (um vertical e um horizontal) usando **vetores bidimensionais de coordenadas** e imprime as coordenadas. Entradas fixas no código.
- `aventureiro_bn.c` — cria uma **matriz 10x10**, posiciona **4 navios** (horizontal, vertical e **2 diagonais**) e **imprime a matriz completa** (`0` = vazio, `3` = navio).
- `mestre_bn.c` — implementa **habilidades** em matrizes: **cruz**, **octaedro (diamante)** e **cone**, marcando **1** nas áreas afetadas e **0** fora. Usa **loops aninhados** e imprime os padrões.

## 🧪 Compilar e executar
```bash
# Novato
gcc -std=c11 -Wall -Wextra -O2 novato_bn.c -o novato_bn
./novato_bn

# Aventureiro
gcc -std=c11 -Wall -Wextra -O2 aventureiro_bn.c -o aventureiro_bn
./aventureiro_bn

# Mestre
gcc -std=c11 -Wall -Wextra -O2 mestre_bn.c -o mestre_bn
./mestre_bn
```

## 📌 Como cada nível atende ao enunciado

### Nível Novato
- Posiciona **2 navios** (vertical e horizontal) por meio de **vetores 2D de coordenadas**.
- **Entrada**: valores definidos em variáveis no código.
- **Saída**: listas de coordenadas com `printf`, uma por linha.

### Nível Aventureiro
- Usa **matriz 10x10**.
- Posiciona **4 navios** (inclui **2 diagonais**).
- **Exibe** a **matriz completa**, com `0` para vazio e `3` para navio, usando `printf("%d ", ...)`.

### Nível Mestre
- Cria matrizes de **habilidades** com padrões: **cruz**, **octaedro** e **cone**.
- Usa **estruturas de repetição aninhadas** para preencher as áreas (1 = afetado, 0 = não).
- **Imprime** cada tabuleiro resultante, linha por linha, conforme exemplo do enunciado.

## 📝 Observações
- As posições/centros/raios escolhidos nos exemplos podem ser ajustados facilmente alterando variáveis nas funções.
- O código está **documentado** para facilitar manutenção e expansão.
- A saída segue o formato pedido (números separados por espaço), pronta para validação visual.
