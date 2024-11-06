#include "snake.h"
#include <stdlib.h>
#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <pthread.h>

#include "keyboard.h"

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

// Muda a direção com base na entrada do usuário
void mudar_direcao() {
    if (keyhit()){
        int ch = readch();
        if (ch == 'w' && direcao_y == 0) { direcao_x = 0; direcao_y = -1; } // cima
        if (ch == 's' && direcao_y == 0) { direcao_x = 0; direcao_y = 1; }  // baixo
        if (ch == 'a' && direcao_x == 0) { direcao_x = -1; direcao_y = 0; } // esquerda
        if (ch == 'd' && direcao_x == 0) { direcao_x = 1; direcao_y = 0; }  // direita
    }

}

void mover_cobrinha() {
    cabeca->x = cabeca->x + direcao_x;
    cabeca->y = cabeca->y + direcao_y;
}

void crescer_cobrinha() {
    // Cobra cresce naturalmente ao evitar remover o último nodo
}

int verificar_colisao(int largura, int altura) {
    // Colisão com paredes
    if (cabeca->x < 0 || cabeca->y < 0 || cabeca->x >= largura || cabeca->y >= altura) {
        return 1;
    }

    // Colisão com o corpo
    Nodo* atual = cabeca->prox;
    while (atual != NULL) {
        if (cabeca->x == atual->x && cabeca->y == atual->y) return 1;
        atual = atual->prox;
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
