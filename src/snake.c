#include "snake.h"
#include <stdlib.h>

typedef struct Nodo {
    int x, y;
    struct Nodo* prox;
} Nodo;

static Nodo* cabeca = NULL;
static Nodo* cauda = NULL;
static int direcao_x = 1, direcao_y = 0;

void iniciar_cobrinha(int x, int y) {
    cabeca = (Nodo*)malloc(sizeof(Nodo));
    cabeca->x = x;
    cabeca->y = y;
    cabeca->prox = NULL;
    cauda = cabeca;
}

void mover_cobrinha() {
    int novo_x = cabeca->x + direcao_x;
    int novo_y = cabeca->y + direcao_y;

    Nodo* novo_nodo = (Nodo*)malloc(sizeof(Nodo));
    novo_nodo->x = novo_x;
    novo_nodo->y = novo_y;
    novo_nodo->prox = cabeca;
    cabeca = novo_nodo;
}

void crescer_cobrinha() {
    // Cobra cresce naturalmente ao evitar remover o último nodo
}

int verificar_colisao(int largura, int altura) {
    if (cabeca->x < 0 || cabeca->y < 0 || cabeca->x >= largura || cabeca->y >= altura) {
        return 1;
    }
    return 0;
}

int verificar_posicao_cobrinha(int x, int y) {
    Nodo* atual = cabeca;
    while (atual != NULL) {
        if (atual->x == x && atual->y == y) return 1;
        atual = atual->prox;
    }
    return 0;
}

int get_cabeca_x() {
    return cabeca->x;
}

int get_cabeca_y() {
    return cabeca->y;
}
