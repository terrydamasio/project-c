#include <stdlib.h> // Pra rand() e srand()
#include <time.h>   // Pra time()
#include "game.h"
#include "snake.h"
#include "screen.h"
#include "timer.h"


static int ativo = 1;
static int largura = MAXX;
static int altura = MAXY;
static int comida_x, comida_y, pontos = 0;

void gerar_comida() {
    do {
        comida_x = (rand() % (largura - 2)) + 1;
        comida_y = (rand() % (altura - 2)) + 1;
    } while (verificar_posicao_cobrinha(comida_x, comida_y));
}

void iniciar_jogo() {
    srand(time(NULL));
    iniciar_cobrinha(largura / 2, altura / 2);
    gerar_comida();
    screenInit(0);          // Inicializa a tela sem bordas automáticas
    screenDrawBorders();    // Desenha as bordas
    timerInit(100);         // Configura o timer
}

void atualizar_jogo() {
    mudar_direcao();
    mover_cobrinha();

    if (get_cabeca_x() == comida_x && get_cabeca_y() == comida_y) {
        pontos++;
        gerar_comida();
    }

    if (verificar_colisao(largura, altura)) {
        ativo = 0;  // Finaliza o jogo se tiver colisão
    }
}

void desenhar_jogo() {
    screenClear();
    screenDrawBorders();  // Redesenha as bordas

    // Desenha comida
    screenSetColor(RED, BLACK);
    screenGotoxy(comida_x, comida_y);
    printf("*");

    // Desenha a cobra
    for (int y = MINY; y < altura; y++) {
        for (int x = MINX; x < largura; x++) {
            if (x == get_cabeca_x() && y == get_cabeca_y()) {
                screenSetColor(GREEN, BLACK);
                screenGotoxy(x, y);
                // Cabeça em forma de seta
                if (get_direcao_x() == 1) printf(">");  // Direita
                else if (get_direcao_x() == -1) printf("<");  // Esquerda
                else if (get_direcao_y() == 1) printf("v");  // Baixo
                else if (get_direcao_y() == -1) printf("^");  // Cima
            } else if (verificar_posicao_cobrinha(x, y)) {
                screenSetColor(GREEN, BLACK);
                screenGotoxy(x, y);
                printf("O");  // Corpo da cobra
            }
        }
    }

    // Pontuação
    screenGotoxy(MINX, MAXY + 1);
    printf("Pontos: %d", pontos);
    screenUpdate();
}

int jogo_ativo() { return ativo; }

void finalizar_jogo() {
    screenDestroy();
    printf("Game Over! Pontuação final: %d\n", pontos);
}
