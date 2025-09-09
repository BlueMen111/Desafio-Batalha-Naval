
# Batalha Naval — Código revisado

Esta revisão corrige o erro de compilação no **Novato** causado por inicialização de **VLA** (Variable Length Array).
Agora os tamanhos dos vetores foram substituídos por **constantes de tempo de compilação** (`#define`).

## O que foi revisado
- `novato_bn.c`: trocado `const int` por `#define` e removida a inicialização de VLA. **Compila com `-Wall -Wextra -O2`.**
- `aventureiro_bn.c`: sem VLAs inicializados; adicionei checagens de limites nas funções de posicionamento horizontal/vertical.
- `mestre_bn.c`: nenhuma alteração estrutural necessária; já usa `#define N 10` e não inicializa VLAs.

## Como compilar
```bash
gcc -std=c11 -Wall -Wextra -O2 novato_bn.c -o novato_bn
gcc -std=c11 -Wall -Wextra -O2 aventureiro_bn.c -o aventureiro_bn
gcc -std=c11 -Wall -Wextra -O2 mestre_bn.c -o mestre_bn
```

## Execução
```bash
./novato_bn
./aventureiro_bn
./mestre_bn
```

Se aparecer qualquer warning/erro no seu ambiente, me diga a mensagem exata que eu ajusto.
