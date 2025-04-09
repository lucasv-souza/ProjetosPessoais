#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int numeroAleatorio, palpite, tentativas = 0;
    
    // Inicializa o gerador de números aleatórios
    srand(time(NULL));
    
    // Gera um número aleatório entre 1 e 100
    numeroAleatorio = rand() % 100 + 1;
    
    printf("Bem-vindo ao jogo de Adivinhação!\n");
    printf("Estou pensando em um número entre 1 e 100.\n");
    printf("Tente adivinhar qual é!\n");

    // Loop de tentativas
    do {
        printf("Digite seu palpite: ");
        scanf("%d", &palpite);
        tentativas++;

        if (palpite > numeroAleatorio) {
            printf("Muito alto! Tente um número menor.\n");
        } else if (palpite < numeroAleatorio) {
            printf("Muito baixo! Tente um número maior.\n");
        } else {
            printf("Parabéns! Você acertou o número em %d tentativas!\n", tentativas);
        }
    } while (palpite != numeroAleatorio);

    return 0;
}
