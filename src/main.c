#include "game.h"
#include <stdio.h>

int main() {
    iniciar_jogo();
    while (jogo_ativo()) {
        atualizar_jogo();
        desenhar_jogo();
    }
    finalizar_jogo();
    return 0;
}
