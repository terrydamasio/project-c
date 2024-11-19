#include "snake.h"
#include <stdlib.h> // Pra malloc e free
#include "screen.h"

typedef struct Nodo {
    int x, y;             
    struct Nodo* prox; 
} Nodo;

// Variáveis globais da cobra
static Nodo* cabeca = NULL;
static Nodo* cauda = NULL;
static int direcao_x = 1, direcao_y = 0; // Direção inicial: direita

// Inicializa a cobra na posição (x, y)
void iniciar_cobrinha(int x, int y) {
    cabeca = (Nodo*)malloc(sizeof(Nodo));
    cabeca->x = x;
    cabeca->y = y;
    cabeca->prox = NULL;
    cauda = cabeca;
}

// Altera a direção da cobra com base na entrada do usuário
void mudar_direcao() {
    if (keyhit()) {
        int ch = readch();
        if (ch == 'w' && direcao_y == 0) { direcao_x = 0; direcao_y = -1; } // Cima
        if (ch == 's' && direcao_y == 0) { direcao_x = 0; direcao_y = 1; }  // Baixo
        if (ch == 'a' && direcao_x == 0) { direcao_x = -1; direcao_y = 0; } // Esquerda
        if (ch == 'd' && direcao_x == 0) { direcao_x = 1; direcao_y = 0; }  // Direita
    }
}

// Move a cobra na direção atual
void mover_cobrinha() {
    // Cria um novo segmento para a cabeça
    Nodo* novo = (Nodo*)malloc(sizeof(Nodo));
    novo->x = cabeca->x + direcao_x;
    novo->y = cabeca->y + direcao_y;
    novo->prox = cabeca;
    cabeca = novo;

    // Remove o último segmento (cauda)
    Nodo* temp = cauda;
    if (cabeca->prox != NULL) {
        Nodo* atual = cabeca;
        while (atual->prox != cauda) {
            atual = atual->prox;
        }
        cauda = atual;
        cauda->prox = NULL;
        free(temp);
    }
}

// Verifica se a cobra colidiu com as bordas
int verificar_colisao(int largura, int altura) {
    // Verifica colisão com as bordas
    if (cabeca->x < 1 || cabeca->x >= largura - 1 || cabeca->y < 1 || cabeca->y >= altura - 1) {
        return 1; // Colidiu com as bordas
    }

    // Verifica colisão com o corpo 
    /*Nodo* atual = cabeca->prox;
    while (atual != NULL) {
        if (cabeca->x == atual->x && cabeca->y == atual->y) {
            return 1; // Colidiu com o corpo
        }
        atual = atual->prox;
    }*/

    return 0; // Sem colisão
}

// Verifica se a posição (x, y) está ocupada
int verificar_posicao_cobrinha(int x, int y) {
    Nodo* atual = cabeca;
    while (atual != NULL) {
        if (atual->x == x && atual->y == y) {
            return 1; // Posição ocupada
        }
        atual = atual->prox;
    }
    return 0; // Posição livre
}

// Retorna a coordenada x da cabeça da cobra
int get_cabeca_x() {
    return cabeca->x;
}

// Retorna a coordenada y da cabeça da cobra
int get_cabeca_y() {
    return cabeca->y;
}

// Retorna a direção atual no eixo x
int get_direcao_x() {
    return direcao_x;
}

// Retorna a direção atual no eixo y
int get_direcao_y() {
    return direcao_y;
}
