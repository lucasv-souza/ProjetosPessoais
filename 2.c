#include <stdio.h>

char tabuleiro[3][3];

void inicializarTabuleiro() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            tabuleiro[i][j] = ' ';
}

void exibirTabuleiro() {
    printf("\n  0   1   2\n");
    for (int i = 0; i < 3; i++) {
        printf("%d ", i);
        for (int j = 0; j < 3; j++) {
            printf(" %c ", tabuleiro[i][j]);
            if (j < 2) printf("|");
        }
        if (i < 2) printf("\n  ---+---+---\n");
    }
    printf("\n");
}

int verificarVitoria(char jogador) {
    for (int i = 0; i < 3; i++) {
        if (tabuleiro[i][0] == jogador && tabuleiro[i][1] == jogador && tabuleiro[i][2] == jogador) return 1;
        if (tabuleiro[0][i] == jogador && tabuleiro[1][i] == jogador && tabuleiro[2][i] == jogador) return 1;
    }
    if (tabuleiro[0][0] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][2] == jogador) return 1;
    if (tabuleiro[0][2] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][0] == jogador) return 1;

    return 0;
}

void jogadaComputador() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (tabuleiro[i][j] == ' ') {
                tabuleiro[i][j] = 'O';
                return;
            }
        }
    }
}

int main() {
    int linha, coluna, jogadas = 0;
    inicializarTabuleiro();

    while (jogadas < 9) {
        exibirTabuleiro();
        printf("Sua vez (X). Digite linha e coluna: ");
        scanf("%d %d", &linha, &coluna);

        if (linha < 0 || linha > 2 || coluna < 0 || coluna > 2 || tabuleiro[linha][coluna] != ' ') {
            printf("Jogada invalida. Tente novamente.\n");
            continue;
        }

        tabuleiro[linha][coluna] = 'X';
        jogadas++;

        if (verificarVitoria('X')) {
            exibirTabuleiro();
            printf("Voce venceu!\n");
            return 0;
        }

        if (jogadas == 9) break;

        printf("Vez do computador...\n");
        jogadaComputador();
        jogadas++;

        if (verificarVitoria('O')) {
            exibirTabuleiro();
            printf("Computador venceu!\n");
            return 0;
        }
    }

    exibirTabuleiro();
    printf("Empate!\n");
    return 0;
}