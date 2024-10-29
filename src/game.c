#include "game.h"
#include "snake.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static int ativo = 1;
static int largura = 20, altura = 10;
static int comida_x, comida_y, pontos = 0;

void gerar_comida() {
    comida_x = rand() % largura;
    comida_y = rand() % altura;
}

void iniciar_jogo() {
    srand(time(NULL));
    iniciar_cobrinha(largura / 2, altura / 2);
    gerar_comida();
}

void atualizar_jogo() {
    mover_cobrinha();
    if (get_cabeca_x() == comida_x && get_cabeca_y() == comida_y) {
        crescer_cobrinha();
        pontos++;
        gerar_comida();
    }
    if (verificar_colisao(largura, altura)) {
        ativo = 0;
    }
}

void desenhar_jogo() {
    system("clear");
    for (int y = 0; y < altura; y++) {
        for (int x = 0; x < largura; x++) {
            if (x == comida_x && y == comida_y) {
                printf("*");
            } else if (verificar_posicao_cobrinha(x, y)) {
                printf("O");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    printf("Pontos: %d\n", pontos);
}

int jogo_ativo() {
    return ativo;
}

void finalizar_jogo() {
    printf("Game Over! Pontuação final: %d\n", pontos);
}
