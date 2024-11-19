#include "game.h"
#include "timer.h"

int main() {
    iniciar_jogo();

    while (jogo_ativo()) {
        if (timerTimeOver()) {
            atualizar_jogo();
            desenhar_jogo();
        }
    }

    finalizar_jogo();
    return 0;
}
